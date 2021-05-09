import java.rmi.*;

public interface IsSubstr extends Remote {
    public boolean isSubstr(String a, String b) throws RemoteException;
}
