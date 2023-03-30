import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = "127.0.0.1"
port = 4444
s.bind((ip, port))
print(f"Server running on : IP - {ip}, PORT - {port}")

s.listen(5)
cli, addr = s.accept()
print("New client connected :- ", addr)

msg = input("Enter a message : ")
cli.send(msg.encode("utf-8"))
print("Received :- ", cli.recv(1024).decode("utf-8"))

print("\nCommunication End")