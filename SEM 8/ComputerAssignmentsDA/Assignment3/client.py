#!/home/subham7/anaconda3/bin/python3
import socket
import sys
import psutil

HEADER = 64
PORT = 5050
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "DISCONNECT"
STATUS_MESSAGE = "CPU_LOAD"

SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length))
    client.send(send_length)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))

msg = sys.argv[1]
while msg != DISCONNECT_MESSAGE:
    send(msg)
    if msg == STATUS_MESSAGE:
    	x = psutil.cpu_percent(percpu=True)
    	reply = str(x) + "\n" + str(psutil.virtual_memory())
    	if sum(x) > 10:
    		reply += "\nServer is OVERLOADED"
    	else:
    		reply += "\nServer is UNDERLOADED"
    	print(reply)

    msg = input(">>")

print("[DISCONNECTED]")
