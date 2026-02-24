// To compile: g++ Image_Client.cpp -o Image_Client.exe -lws2_32
// To Run: ./Image_Client.exe

#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 1;

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    if (connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cout << "Connection failed!" << std::endl;
        return 1;
    }

    // 1. Receive the file size
    long long fileSize = 0;
    recv(sock, (char*)&fileSize, sizeof(fileSize), 0);

    // 2. Safety Check to prevent std::bad_alloc
    if (fileSize <= 0 || fileSize > 100000000) { // Limit to 100MB
        std::cout << "Error: Invalid file size received: " << fileSize << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Receiving image of size: " << fileSize << " bytes..." << std::endl;

    // 3. Allocate memory and receive data in chunks
    char* buffer = new char[fileSize];
    int totalReceived = 0;
    while (totalReceived < fileSize) {
        int bytes = recv(sock, buffer + totalReceived, (int)fileSize - totalReceived, 0);
        if (bytes <= 0) break;
        totalReceived += bytes;
    }

    // 4. Save to file
    std::ofstream outFile("received_image.jpg", std::ios::binary);
    outFile.write(buffer, fileSize);
    outFile.close();

    std::cout << "Success! Image saved as 'received_image.jpg'" << std::endl;

    delete[] buffer;
    closesocket(sock);
    WSACleanup();
    return 0;
}