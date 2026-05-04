#include <iostream>
#include <winsock2.h>
#include <thread>

using namespace std;

void receiveData(SOCKET clientSocket)
{
    char buffer[1024];

    while (true)
    {
        int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytes <= 0)
        {
            cout << "\nClient disconnected.\n";
            break;
        }

        cout << "\nClient: " << string(buffer, bytes) << endl;
    }
}
//server side
//socket bind listen accept recv send close

//client
// scket conect send rcieve 
void sendData(SOCKET clientSocket)
{
    string msg;

    while (true)
    {
        getline(cin, msg);

        if (msg == "exit") break;

        send(clientSocket, msg.c_str(), msg.length(), 0);
    }
}

int main()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "WSAStartup failed\n";
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == INVALID_SOCKET)
    {
        cout << "Socket failed\n";
        return 1;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5000);

    if (bind(serverSocket, (sockaddr*)&server, sizeof(server)) < 0)
    {
        cout << "Bind failed: " << WSAGetLastError() << endl;
        return 1;
    }

    if (listen(serverSocket, 1) < 0)
    {
        cout << "Listen failed\n";
        return 1;
    }

    cout << "Waiting for client...\n";

    SOCKET clientSocket = accept(serverSocket, NULL, NULL);

    if (clientSocket < 0)
    {
        cout << "Accept failed\n";
        return 1;
    }

    cout << "Client connected!\n";

    thread t1(receiveData, clientSocket);
    thread t2(sendData, clientSocket);

    t1.join();
    t2.join();

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}