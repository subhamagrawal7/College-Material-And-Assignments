#!/home/subham7/anaconda3/bin/python3
import socket 
import threading
import psutil

HEADER = 64
PORT = 5050
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "DISCONNECT"
STATUS_MESSAGE = "CPU_LOAD"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")

    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                connected = False
            if msg == STATUS_MESSAGE:
            	x = psutil.cpu_percent(percpu=True)
            	reply = str(x) + "\n"+str(psutil.virtual_memory())
            	if sum(x) >= 10:
            		reply += "\nClient is OVERLOAD"
            	else:
            		reply += "\nClient is UNDERLOAD"
            	print(reply)
            	conn.send("\nMsg received".encode(FORMAT))
            	continue

            print(f"[{addr}] {msg}")
            conn.send("Msg received".encode(FORMAT))
    print(f"[ACTIVE CONNECTIONS] {threading.activeCount() - 1}")
    conn.close()
        

def start():
    server.listen()
    print(f"[LISTENING] Server is listening on {SERVER}")
    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.activeCount() - 1}")


print("[STARTING] server is starting...")
start()
