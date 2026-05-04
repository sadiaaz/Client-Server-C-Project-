# C++ Client-Server Project

A simple client-server application built in **C++** that successfully communicates between **two different PCs**:

* **Server PC** runs the server program.
* **Client PC** runs the client program.
* The **client uses the server’s IP address** to connect and exchange messages/data.

This project was developed with the help of AI and is fully working.

## Description

This project is a C++-based client-server application that demonstrates reliable communication between two separate computers over a network using TCP/IP socket programming. The system consists of two independent programs: a server and a client. The server runs on one machine and listens for incoming connections on a specified port, while the client runs on another machine and connects to the server using its IP address.

The core functionality of this project is to establish a stable connection between the client and server and enable data exchange in real time. The client must provide the correct IP address of the server to ensure successful communication. Once connected, both programs can send and receive messages, making it a practical implementation of basic networking concepts.

This project highlights important concepts such as socket creation, binding, listening, connecting, and data transmission. It is designed to work within a local area network (LAN), but it can also be extended for broader network use with proper configuration.

Overall, this project serves as a strong foundation for understanding network programming in C++ and can be further enhanced with features like multi-client handling, file transfer, and secure communication.

## Features

* TCP/IP based communication
* Separate client and server programs
* Works across two different machines on the same network
* Easy IP-based connection from client to server
* Simple and lightweight C++ implementation

## How It Works

1. The **server** starts first and listens on a port.
2. The **client** enters the server’s IP address and port number.
3. The client connects to the server.
4. Both sides communicate successfully over the network.

## Requirements

* C++ compiler (such as g++, MinGW, MSVC, or similar)
* Two PCs connected to the same network
* Server machine IP address
* Basic socket programming support on your system

## Project Structure

```bash
project-folder/
├── server.cpp
├── client.cpp
└── README.md
```

## Setup and Compilation

### On Linux / macOS

```bash
g++ server.cpp -o server
g++ client.cpp -o client
```

### On Windows (MinGW)

```bash
g++ server.cpp -o server.exe
g++ client.cpp -o client.exe
```

## Running the Project

### 1) Start the Server

Run the server program on the server PC:

```bash
./server
```

or on Windows:

```bash
server.exe
```

The server will start listening on a port.

### 2) Get the Server IP Address

Find the IP address of the server PC.

* On Windows: use `ipconfig`
* On Linux/macOS: use `ifconfig` or `ip addr`

Example server IP:

```bash
192.168.1.10
```

### 3) Start the Client

Run the client program on the client PC and enter:

* **Server IP address**
* **Port number**

The client will then connect to the server.

## Example Usage

* **Server IP:** `192.168.1.10`
* **Port:** `8080`

The client connects using:

```cpp
192.168.1.10:8080
```

## Notes

* Make sure both PCs are connected to the same network.
* Ensure the port is open in the firewall if connection fails.
* The server must be running before the client tries to connect.
* The client must use the correct server IP address.

## Troubleshooting

### Client cannot connect

* Check if the server is running
* Verify the IP address is correct
* Confirm the port number matches on both sides
* Disable or configure firewall permissions if needed
* Make sure both systems are on the same LAN

### Connection refused

* Server may not be listening
* Wrong IP or port may be used
* Firewall may be blocking the connection

## Future Improvements

* Add a graphical user interface
* Support multiple clients
* Add file sharing
* Improve error handling
* Add encryption for secure communication

## Author

Developed as a C++ client-server networking project with AI assistance.

## License

This project is for educational purposes.
