// Public_Client.cpp
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

// To compile: g++ Public_Client.cpp -o Public_Client.exe -lws2_32
// To Run: ./Public_Client.exe

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 1. Create a TCP Socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. Specify the Public Server Address (Example: 93.184.216.34)
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(80); // Port 80 is for standard Web traffic
    inet_pton(AF_INET, "93.184.216.34", &servAddr.sin_addr);

    // 3. Connect to the External Server
    std::cout << "Connecting to public server..." << std::endl;
    if (connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cout << "Connection failed!" << std::endl;
        WSACleanup();
        return 1;
    }

    // 4. Send a basic HTTP Request (This is how browsers talk)
    std::string request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    send(sock, request.c_str(), (int)request.length(), 0);

    // 5. Receive the data from the Public Server
    char buffer[2048] = {0};
    recv(sock, buffer, 2048, 0);
    
    std::cout << "Response from Server:\n" << "------------------\n";
    std::cout << buffer << std::endl;

    // 6. Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}