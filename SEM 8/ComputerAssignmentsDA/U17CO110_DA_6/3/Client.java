import java.rmi.*;
import java.net.*;
import java.io.*;
import java.util.*;

public class Client {
  public static void main(String args[]) {
    String host = "localhost";
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter First String:");
    String a = sc.nextLine();
    System.out.println("Enter Second String:");
    String b = sc.nextLine();
    try {
      Concat remObj = (Concat) Naming.lookup("rmi://localhost/Concat");
      System.out.println(">>>" + remObj.concatStrings(a, b));
    } catch (RemoteException re) {
      re.printStackTrace();
    } catch (NotBoundException nbe) {
      nbe.printStackTrace();
    } catch (MalformedURLException mfe) {
      mfe.printStackTrace();
    }
  }
}