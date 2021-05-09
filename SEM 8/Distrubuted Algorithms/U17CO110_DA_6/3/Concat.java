import java. rmi.*;

public interface Concat extends Remote {
    public String concatStrings(String a, String b) throws RemoteException;
}
