import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class IsSubstrImpl extends UnicastRemoteObject implements IsSubstr {
  public IsSubstrImpl() throws RemoteException {}

  public boolean isSubstr(String a, String b) {
    System.out.println(">>> isSubstr("+ a + "," + b +") invoked");
    return a.contains(b);
  }
}