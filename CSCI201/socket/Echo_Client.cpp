// Echo_Client.cpp
#include <iostream>
#include <string>
#include <winsock2.h> 
#include <ws2tcpip.h>  

// To compile on Bash Terminal
// Server: g++ Echo_Server.cpp -o Echo_Server.exe -lws2_32
// Client: g++ Echo_Client.cpp -o Echo_Client.exe -lws2_32

// To Run
// 1. Start the Server first: ./Echo_Server.exe
// 2. Open a new terminal and run the client
// 3. Start the client: ./Echo_Client.exe 

// Link the Windows Socket library
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Winsock initialization failed" << std::endl;
        return 1;
    }

    // 2. Create the client socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cout << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // 3. Define Server Address (Localhost)
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    // 4. Connect to the Server
    if (connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cout << "Connection Failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // 5. User Input
    std::string message;
    std::cout << "Enter a message to echo: ";
    std::getline(std::cin, message);

    // 6. Send message
    send(sock, message.c_str(), (int)message.length(), 0);

    // 7. Receive Echo
    char buffer[1024] = {0};
    int bytesReceived = recv(sock, buffer, 1024, 0);

    if (bytesReceived > 0) {
        std::cout << "Server Echoed: " << buffer << std::endl;
    }

    // 8. Final Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}