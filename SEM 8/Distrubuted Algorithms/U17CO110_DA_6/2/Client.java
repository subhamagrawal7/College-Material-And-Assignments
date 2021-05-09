import java.rmi.*;
import java.net.*;
import java.io.*;
import java.util.*;

public class Client {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter First String:");
    String a = sc.nextLine();
    System.out.println("Enter Second String:");
    String b = sc.nextLine();
    try {
      IsSubstr remObj = (IsSubstr) Naming.lookup("rmi://localhost/IsSubstr");
      System.out.println(remObj.isSubstr(a, b) ? ">>> True" : ">>> False");
    } catch (RemoteException re) {
      re.printStackTrace();
    } catch (NotBoundException nbe) {
      nbe.printStackTrace();
    } catch (MalformedURLException mfe) {
      mfe.printStackTrace();
    }
  }
}