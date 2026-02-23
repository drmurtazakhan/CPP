// Client_Add.cpp
#include <iostream>
#include <string>
#include <winsock2.h> // Windows replacement for sys/socket.h
#include <ws2tcpip.h>  // Windows replacement for arpa/inet.h

// To compile on Bash Terminal
// Server: g++ Server_Add.cpp -o Server_Add.exe -lws2_32
// Client: g++ Client_Add.cpp -o Client_Add.exe -lws2_32

// To Run
// 1. Start the Server first: ./Server_Add.exe
// 2. Open the new terminal and run the client, you have to input two integers to see the result
// 3. Start the client: ./Client_Add.exe

// Link the Windows Socket library
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Winsock initialization failed" << std::endl;
        return 1;
    }

    // 2. Create Socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cout << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    // 3. Connect to the Server
    if (connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cout << "Connection Failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // 4. Get two integers from the user
    int vals[2];
    std::cout << "Enter first integer: ";
    std::cin >> vals[0];
    std::cout << "Enter second integer: ";
    std::cin >> vals[1];

    // 5. Send raw data and receive the sum
    send(sock, (char*)vals, sizeof(vals), 0);

    int sum = 0;
    recv(sock, (char*)&sum, sizeof(sum), 0);

    std::cout << "The Server calculated the sum: " << sum << std::endl;

    // 6. Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}

