package org.cloudbus.cloudsim;

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

import org.cloudbus.cloudsim.core.CloudSim;
import org.cloudbus.cloudsim.core.CloudSimTags;
import org.cloudbus.cloudsim.lists.VmList;

public class RoundRobinDataCenterBroker extends DatacenterBroker{
	public RoundRobinDataCenterBroker(String name) throws Exception {
        super(name);
    }
	
	@Override
	protected void submitCloudlets() {
		int vmIndex = 0;
		
		// Logic of RoundRobin
		List<Cloudlet> finalList = new ArrayList<Cloudlet>();
		ArrayList<Cloudlet> tempList = new ArrayList<Cloudlet>();
		
		for (Cloudlet cloudlet : getCloudletList()) {
			tempList.add(cloudlet);
		}
		
		int count = 1;
		for(Cloudlet printCloudlet : tempList) {
			Log.printLine(count + ". Cloudlet ID: " + printCloudlet.getCloudletId() + ", Cloudlet Length: " + printCloudlet.getCloudletLength());
			count++;
		}
		int timequantum = 1000;
		int total=tempList.size();
		Boolean[] boolArray = new Boolean[total];
		Arrays.fill(boolArray, Boolean.FALSE);
		count=0;
		while(count<total)
		{
			for(int i=0;i<total;i++)
			{
				Cloudlet checkCloudlet = tempList.get(i);
				long temp=checkCloudlet.getCloudletLength();
				if(temp>timequantum)
				{
				
					checkCloudlet.setCloudletLength(timequantum);
					finalList.add(checkCloudlet);
					checkCloudlet.setCloudletLength(temp-timequantum);
					//Log.printLine("Reduced . Cloudlet ID: " + checkCloudlet.getCloudletId() + ", Cloudlet Length: " + checkCloudlet.getCloudletLength());
					
				}
				else if (!boolArray[i])
				{
					count++;
					finalList.add(checkCloudlet);
					//Log.printLine("Finished . Cloudlet ID: " + checkCloudlet.getCloudletId() + ", Cloudlet Length: " + checkCloudlet.getCloudletLength());
					boolArray[i]=!boolArray[i];
				}
				
			}
		}
		
		
		// Logic of Round Robin ends here
		
		for (Cloudlet cloudlet : finalList) {
			Vm vm;
			// if user didn't bind this cloudlet and it has not been executed yet
			if (cloudlet.getVmId() == -1) {
				vm = getVmsCreatedList().get(vmIndex);
			} else { // submit to the specific vm
				vm = VmList.getById(getVmsCreatedList(), cloudlet.getVmId());
				if (vm == null) { // vm was not created
					Log.printLine(CloudSim.clock() + ": " + getName() + ": Postponing execution of cloudlet "
							+ cloudlet.getCloudletId() + ": bount VM not available");
					continue;
				}
			}

			Log.printLine(CloudSim.clock() + ": " + getName() + ": Sending cloudlet "
					+ cloudlet.getCloudletId() + " to VM #" + vm.getId());
			cloudlet.setVmId(vm.getId());
			sendNow(getVmsToDatacentersMap().get(vm.getId()), CloudSimTags.CLOUDLET_SUBMIT, cloudlet);
			cloudletsSubmitted++;
			vmIndex = (vmIndex + 1) % getVmsCreatedList().size();
			getCloudletSubmittedList().add(cloudlet);
		}

		// remove submitted cloudlets from waiting list
		for (Cloudlet cloudlet : getCloudletSubmittedList()) {
			finalList.remove(cloudlet);
		}
	}
	
}
