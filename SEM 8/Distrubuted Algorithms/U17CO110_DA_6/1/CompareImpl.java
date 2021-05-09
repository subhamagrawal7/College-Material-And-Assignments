import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
public class CompareImpl extends UnicastRemoteObject implements Compare {
  public CompareImpl() throws RemoteException {}
  public boolean compareStrings(String a, String b) {
    System.out.println(">>> compareStrings("+ a + "," + b +") invoked");
    return a.equals(b);
  }
}