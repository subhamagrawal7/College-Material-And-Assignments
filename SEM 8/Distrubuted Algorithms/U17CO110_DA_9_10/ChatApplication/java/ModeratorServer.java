import ChatApplication.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;

import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.util.Properties;

class ModeratorImpl extends ModeratorPOA {
    
    private ORB orb;
    String allMssg = "";
    
    public void setORB(ORB orb_val){
        orb = orb_val;
    }

    public String login(String username){
        allMssg = allMssg + "**** " + username + " joined the room ****\n";
        System.out.println("[+] " + username + " joined the room.");
        return "[+] You have been logged in!!\n";
    }

    public String sendMessage(String username, String mssg){
        allMssg = allMssg + "[+]" + username + ": " + mssg + "\n";
        return "[+] Your message was sent to all users\n";
    }

    public String getMessages(){
        return allMssg;
    }

    public String logout(String username){
        allMssg = allMssg + "---- " + username + " left the room ----\n";
        System.out.println("[+] " + username + " left the room.");
        try{
            FileOutputStream fos = new FileOutputStream("../chatLog.txt");
            DataOutputStream dos = new DataOutputStream(fos);
            dos.writeUTF(allMssg);
        } catch(Exception e){
            System.out.println("[+] Some issue in logging: ");
        }
        return "[+] You have been logged out!!\n";
    }
}

public class ModeratorServer {
    public static void main(String[] args) {
        try{
            // create and initialize the ORB
            ORB orb = ORB.init(args, null);

            // get reference to rootpoa & activate the POAManager
            POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
            rootpoa.the_POAManager().activate();
            
            // create servant and register it with the ORB
            ModeratorImpl moderatorImpl = new ModeratorImpl();
            moderatorImpl.setORB(orb);

            // get object reference from the servant
            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(moderatorImpl);
            Moderator href = ModeratorHelper.narrow(ref);

            // get the root naming context
            // NameService invokes the name service
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            // Use NamingContextExt which is part of the Interoperable
            // Naming Service (INS) specification.
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            // bind the Object Reference in Naming
            String name = "Moderator";
            NameComponent path[] = ncRef.to_name(name);
            
            ncRef.rebind(path, href);

            System.out.println("\n[+] The moderator is ready and waiting ...");

            // wait for invocations from clients
            orb.run();
        } catch(Exception e){
            System.err.println("ERROR: " + e);
            e.printStackTrace(System.out);
        }

        System.out.println("[+] ChatApplicaiton Closing...");
    }
}