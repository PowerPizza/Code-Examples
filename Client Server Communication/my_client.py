import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = "127.0.0.1"
port = 4444
s.connect((ip, port))

print("Received :- ", s.recv(1024).decode("utf-8"))

msg = input("Enter the message : ")
s.send(msg.encode("utf-8"))

print("\nCommunication End")