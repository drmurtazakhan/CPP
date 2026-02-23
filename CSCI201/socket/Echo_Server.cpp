// Echo_Server.cpp
#include <iostream>
#include <winsock2.h> // Windows replacement for sys/socket.h
#include <ws2tcpip.h>  // Windows replacement for arpa/inet.h

// To compile on Bash Terminal
// Server: g++ Echo_Server.cpp -o Echo_Server.exe -lws2_32
// Client: g++ Echo_Client.cpp -o Echo_Client.exe -lws2_32

// To Run
// 1. Start the Server first: ./Echo_Server.exe
// 2. Open a new terminal to run the client
// 3. Start the client: ./Echo_Client.exe 

// Link the Windows Socket library
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Initialize Winsock (Required for Windows)
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    // 2. Create the listening socket
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (servSock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return -1;
    }

    // 3. Setup the Server Address structure for port 8080
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY; 
    servAddr.sin_port = htons(8080);

    // 4. Bind the socket
    if (bind(servSock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed" << std::endl;
        closesocket(servSock);
        WSACleanup();
        return -1;
    }

    // 5. Listen for incoming connections
    if (listen(servSock, 5) == SOCKET_ERROR) {
        std::cerr << "Listen failed" << std::endl;
        closesocket(servSock);
        WSACleanup();
        return -1;
    }

    std::cout << "Echo_Server is running on port 8080..." << std::endl;

    while (true) {
        // 6. Accept a client connection
        SOCKET clntSock = accept(servSock, nullptr, nullptr);
        if (clntSock == INVALID_SOCKET) continue;

        // 7. Receive the message string
        char buffer[1024] = {0};
        int bytesReceived = recv(clntSock, buffer, sizeof(buffer), 0);

        if (bytesReceived > 0) {
            std::cout << "Received: " << buffer << " - Echoing back..." << std::endl;

            // 8. Echo the message back to the client
            send(clntSock, buffer, bytesReceived, 0);
        }

        // 9. Close this client connection
        closesocket(clntSock);
    }

    // 10. Cleanup
    closesocket(servSock);
    WSACleanup();
    return 0;
}