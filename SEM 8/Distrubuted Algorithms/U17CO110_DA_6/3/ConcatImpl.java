import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class ConcatImpl extends UnicastRemoteObject implements Concat {
  public ConcatImpl() throws RemoteException {}

  public String concatStrings(String a, String b) {
    System.out.println(">>> concatStrings("+ a + "," + b +") invoked");
    return a + b;
  }
}