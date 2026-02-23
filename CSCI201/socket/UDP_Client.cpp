// UDP_Client.cpp
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

// To compile on Bash Terminal
// Server: g++ UDP_Server.cpp -o UDP_Server.exe -lws2_32
// Client: g++ UDP_Client.cpp -o UDP_Client_App.exe -lws2_32

// Link the library
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Start Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return 1;
    }

    // 2. Create UDP Socket
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == INVALID_SOCKET) {
        WSACleanup();
        return 1;
    }

    // 3. Setup Server Address
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    // 4. Send Message
    std::string msg = "hello world";
    sendto(sock, msg.c_str(), (int)msg.length(), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
    std::cout << "Message sent to server..." << std::endl;

    // 5. Receive Response
    char buffer[1024] = {0};
    int addrLen = sizeof(servAddr);
    int bytes = recvfrom(sock, buffer, 1024, 0, (struct sockaddr*)&servAddr, &addrLen);

    if (bytes > 0) {
        std::cout << "Server returned: " << buffer << std::endl;
    }

    // 6. Close and Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}