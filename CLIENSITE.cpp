#include <iostream>
#include <winsock2.h>
#include <thread>

using namespace std;

void receiveData(SOCKET sock)
{
    char buffer[1024];

    while (true)
    {
        int bytes = recv(sock, buffer, sizeof(buffer), 0);

        if (bytes <= 0)
        {
            cout << "\nServer disconnected.\n";
            break;
        }

        cout << "\nServer: " << string(buffer, bytes) << endl;
    }
}

void sendData(SOCKET sock)
{
    string msg;

    while (true)
    {
        getline(cin, msg);

        if (msg == "exit") break;

        send(sock, msg.c_str(), msg.length(), 0);
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

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET)
    {
        cout << "Socket failed\n";
        return 1;
    }

    sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(5000);

    // ? SAME PC (most important for you right now)
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // ?? If using different PC, replace above with:
    // server.sin_addr.s_addr = inet_addr("YOUR_SERVER_IP");

    if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0)
    {
        cout << "Connection failed: " << WSAGetLastError() << endl;
        return 1;
    }

    cout << "Connected to server!\n";

    thread t1(receiveData, sock);
    thread t2(sendData, sock);

    t1.join();
    t2.join();

    closesocket(sock);
    WSACleanup();

    return 0;
}