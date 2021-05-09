import java.net.*;
import java.rmi.*;

public class Server {
  public static void main(String args[]) {
    try {
      CompareImpl locObj = new CompareImpl();
      Naming.rebind("rmi://localhost/Compare", locObj);
    } catch (RemoteException re) {
      re.printStackTrace();
    } catch (MalformedURLException mfe) {
      mfe.printStackTrace();
    }
  }
}