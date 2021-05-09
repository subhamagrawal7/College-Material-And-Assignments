import java.net.*;
import java.rmi.*;

public class Server {
  public static void main(String args[]) {
    try {
      ConcatImpl locObj = new ConcatImpl();
      Naming.rebind("rmi://localhost/Concat", locObj);
    } catch (RemoteException re) {
      re.printStackTrace();
    } catch (MalformedURLException mfe) {
      mfe.printStackTrace();
    }
  }
}