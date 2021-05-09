import java.net.*;
import java.rmi.*;

public class Server {
  public static void main(String args[]) {
    try {
      IsSubstrImpl locObj = new IsSubstrImpl();
      Naming.rebind("rmi://localhost/IsSubstr", locObj);
    } catch (RemoteException re) {
      re.printStackTrace();
    } catch (MalformedURLException mfe) {
      mfe.printStackTrace();
    }
  }
}