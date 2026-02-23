// state_client_win.cpp

// Compile on Bash
// g++ state_client_win.cpp -o state_client_win.exe -lws2_32

// First start the server first by typing: ./state_server_win.exe
// Then, in another terminal, run the client by typing: ./state_client_win.exe

#include <iostream>
#include <string>
#include <winsock2.h> // The Windows replacement for sys/socket.h
#include <ws2tcpip.h>  // The Windows replacement for arpa/inet.h

// This tells the compiler to include the networking library file
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Windows specific: Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Winsock initialization failed" << std::endl;
        return 1;
    }

    std::string abbrev;
    std::cout << "Enter a 2-letter state abbreviation (e.g., NY): ";
    std::cin >> abbrev;

    // 2. Create Socket (using INVALID_SOCKET for Windows safety)
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cout << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. Connect
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed" << std::endl;
        closesocket(sock); // Windows uses closesocket() instead of close()
        WSACleanup();
        return 1;
    }

    // 4. Send and Receive
    send(sock, abbrev.c_str(), 2, 0);
    char buffer[1024] = {0};
    recv(sock, buffer, 1024, 0);

    std::cout << "Full State Name: " << buffer << std::endl;

    // 5. Cleanup
    closesocket(sock);
    WSACleanup(); // Clean up Winsock
    return 0;
}