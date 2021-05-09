import sys
from omniORB import CORBA, PortableServer
import ChatApplication

orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
ior = sys.argv[1]
obj = orb.string_to_object(ior)
moderator = obj._narrow(ChatApplication.Moderator)

if moderator is None:
    print("Can't narrow reference.")
    sys.exit(1)

username = input("[+] Enter your name: ")
result = moderator.login(username)
print(result)

choice = 0
isRunning = True

while isRunning:

    choice = int(input("\nChoose any 1 of below:\n1.Send Mssg\n2.Fetch all messages in room\n3.Logout\n"));
    
    if choice == 1:
        mssg = input("[+] Enter your message: ")
        response = moderator.sendMessage(username, mssg)
        print("\n{}\n".format(response))
    elif choice == 2:
        response = moderator.getMessages()
        print("\n{}\n".format(response))
    elif choice == 3:
        response = moderator.logout(username)
        print("\n{}\n".format(response))
        isRunning = False
    else:
        print("[+] No such option.")
