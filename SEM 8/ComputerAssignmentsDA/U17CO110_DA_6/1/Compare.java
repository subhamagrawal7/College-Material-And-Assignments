import java. rmi.*;

public interface Compare extends Remote {
    public boolean compareStrings(String a, String b) throws RemoteException;
}
