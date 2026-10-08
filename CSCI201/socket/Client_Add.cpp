// Client_Add.cpp

// Define target Windows version (0x0600 = Windows Vista or later).
// MUST be defined before winsock2.h/ws2tcpip.h to expose inet_pton across all MinGW/GCC toolchains.
#define _WIN32_WINNT 0x0600

// How to Compile:
// Server: g++ Server_Add.cpp -o Server_Add.exe -lws2_32
// Client: g++ Client_Add.cpp -o Client_Add.exe -lws2_32

// How to Run:
// 1. Start the Server first: ./Server_Add.exe
// 2. Open a second terminal and run the Client: ./Client_Add.exe
// 3. Enter two integers when prompted to receive the sum from the server.

#include <iostream>
#include <string>
#include <winsock2.h> // Windows replacement for sys/socket.h
#include <ws2tcpip.h> // Windows replacement for arpa/inet.h (provides inet_pton)

// Tell the compiler to link the Windows Socket library
#pragma comment(lib, "ws2_32.lib")

int main()
{
    // 1. Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "Winsock initialization failed" << std::endl;
        return 1;
    }

    // 2. Create TCP Socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET)
    {
        std::cout << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // 3. Configure Server Address Structure
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8080);

    // Convert IP address string to binary format (inet_pton requires _WIN32_WINNT >= 0x0600)
    if (inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr) <= 0)
    {
        std::cout << "Invalid IP address or address conversion failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // 4. Connect to the Server
    if (connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        std::cout << "Connection Failed. Ensure Server_Add.exe is running first." << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // 5. Get two integers from user input
    int vals[2];
    std::cout << "Enter first integer: ";
    std::cin >> vals[0];
    std::cout << "Enter second integer: ";
    std::cin >> vals[1];

    // 6. Send raw integer array to the server
    send(sock, (char *)vals, sizeof(vals), 0);

    // 7. Receive the calculated sum back from the server
    int sum = 0;
    recv(sock, (char *)&sum, sizeof(sum), 0);

    std::cout << "The Server calculated the sum: " << sum << std::endl;

    // 8. Cleanup and Close Socket
    closesocket(sock);
    WSACleanup();
    return 0;
}