// UDP_Server.cpp
#include <iostream>
#include <string>
#include <algorithm> // For std::transform
#include <winsock2.h>
#include <ws2tcpip.h>

// To compile: g++ UDP_Server.cpp -o UDP_Server.exe -lws2_32
// To Run: ./UDP_Server.exe

#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Initialize Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. Create a UDP Socket (SOCK_DGRAM)
    // Note: We use SOCK_DGRAM instead of SOCK_STREAM for UDP
    SOCKET servSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // 3. Setup Server Address (Port 8080)
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(8080);

    // 4. Bind the socket to the port
    bind(servSock, (struct sockaddr*)&servAddr, sizeof(servAddr));

    std::cout << "UDP Upper Case Server is running on port 8080..." << std::endl;

    char buffer[1024];
    sockaddr_in clntAddr; // To store who sent the data
    int clntAddrLen = sizeof(clntAddr);

    while (true) {
        // 5. Receive data from a client
        // recvfrom() is used in UDP to get data AND the sender's address
        int bytesReceived = recvfrom(servSock, buffer, 1024, 0, (struct sockaddr*)&clntAddr, &clntAddrLen);
        
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::string message(buffer);
            std::cout << "Received: " << message << std::endl;

            // 6. Convert the message to Upper Case
            std::transform(message.begin(), message.end(), message.begin(), ::toupper);

            // 7. Send the upper case message back to the client
            // sendto() uses the clntAddr we captured in recvfrom()
            sendto(servSock, message.c_str(), (int)message.length(), 0, (struct sockaddr*)&clntAddr, clntAddrLen);
            std::cout << "Sent back: " << message << std::endl;
        }
    }

    // 8. Cleanup
    closesocket(servSock);
    WSACleanup();
    return 0;
}