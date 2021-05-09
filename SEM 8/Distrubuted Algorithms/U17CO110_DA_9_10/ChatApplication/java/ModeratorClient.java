import ChatApplication.*;

import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;

import java.util.Scanner;

public class ModeratorClient {

    static Moderator moderatorImpl;
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
    
        try{
            // create and initialize the ORB
            ORB orb = ORB.init(args, null);
            
            // get the root naming context
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            // Use NamingContextExt instead of NamingContext. This is 
            // part of the Interoperable naming Service.  
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
            

            // resolve the Object Reference in Naming
            String name = "Moderator";
            moderatorImpl = ModeratorHelper.narrow(ncRef.resolve_str(name));

            System.out.println("[+] Connected to the moderator server: ");
            System.out.println(moderatorImpl);
            
            String username;
            System.out.print("[+] Enter your name: ");
            username = sc.nextLine();
            String reply = moderatorImpl.login(username);
            System.out.println(reply);
            
            boolean isRunning = true;

            while(isRunning){
                int choice;
                String mssg;
                String response;
                System.out.println("Choose one of below\n1.Send Mssg\n2.Fetch all messages in room\n3.Logout\n");
                choice = Integer.parseInt(sc.nextLine());

                switch(choice){
                    
                    case 1: System.out.print("[+] Enter your message: ");
                            mssg = sc.nextLine();
                            response = moderatorImpl.sendMessage(username, mssg);
                            System.out.print("\n" + response + "\n");
                            break;

                    case 2: response = moderatorImpl.getMessages();
                            System.out.print("\n" + response + "\n");
                            break;
                    
                    case 3: response = moderatorImpl.logout(username);
                            System.out.print("\n" + response + "\n");
                            isRunning = false;
                            break;

                    default: System.out.println("\n[+] No such option available\n");
                            break;
                }
            }
        } catch (Exception e) {
            System.err.println("Error: " + e);
            e.printStackTrace(System.out);
        }
    }

}
