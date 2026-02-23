// Public_Time_Client.cpp
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

// To compile: g++ Public_Time_Client.cpp -o Public_Time_Client.exe -lws2_32
// Run: ./Public_Time_Client.exe

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Using a NIST Time Server IP: 129.6.15.28 
    // Port 13 is the "Daytime" service which sends time as text.
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(13); 
    inet_pton(AF_INET, "129.6.15.28", &servAddr.sin_addr);

    std::cout << "Connecting to NIST Time Server (129.6.15.28)..." << std::endl;

    if (connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cout << "Connection Failed! Error: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // This server automatically sends the time upon connection.
    // We just need to receive it!
    char buffer[1024] = {0};
    int bytes = recv(sock, buffer, 1024, 0);

    if (bytes > 0) {
        std::cout << "Current Time from Server: " << buffer << std::endl;
    } else {
        std::cout << "Connected, but received no data." << std::endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}