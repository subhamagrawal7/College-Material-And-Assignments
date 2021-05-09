package org.cloudbus.cloudsim;

import java.util.ArrayList;
import java.util.List;

import org.cloudbus.cloudsim.core.CloudSim;
import org.cloudbus.cloudsim.core.CloudSimTags;
import org.cloudbus.cloudsim.lists.VmList;

public class SJFDataCenterBroker extends DatacenterBroker{
	public SJFDataCenterBroker(String name) throws Exception {
        super(name);
    }
	
	@Override
	protected void submitCloudlets() {
		int vmIndex = 0;
		
		// Logic of SJF
		List<Cloudlet> sortList = new ArrayList<Cloudlet>();
		ArrayList<Cloudlet> tempList = new ArrayList<Cloudlet>();
		
		for (Cloudlet cloudlet : getCloudletList()) {
			tempList.add(cloudlet);
		}
		
		int totalCloudlets = tempList.size();
		for(int i=0; i<totalCloudlets; i++) {
			
			Cloudlet smallestCloudlet = tempList.get(0);
			
			for(Cloudlet checkCloudlet: tempList) {
				if(smallestCloudlet.getCloudletLength() > checkCloudlet.getCloudletLength()) {
					smallestCloudlet = checkCloudlet;
				}
			}
			sortList.add(smallestCloudlet);
			tempList.remove(smallestCloudlet);
		}
		
		int count = 1;
		for(Cloudlet printCloudlet : sortList) {
			Log.printLine(count + ". Cloudlet ID: " + printCloudlet.getCloudletId() + ", Cloudlet Length: " + printCloudlet.getCloudletLength());
			count++;
		}
		// Logic of SJF ends here
		
		for (Cloudlet cloudlet : sortList) {
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
			getCloudletList().remove(cloudlet);
		}
	}
	
}
