// To compile: g++ Image_Server.cpp -o Image_Server.exe -lws2_32
// To Run: ./Image_Server.exe

#include <iostream>
#include <fstream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 1;

    SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(servSock, (struct sockaddr*)&addr, sizeof(addr));
    listen(servSock, 5);

    std::cout << "Server is running. Waiting for client..." << std::endl;

    sockaddr_in clntAddr;
    int clntSize = sizeof(clntAddr);
    SOCKET clntSock = accept(servSock, (struct sockaddr*)&clntAddr, &clntSize);

    // 1. Open file and check if it exists
    std::ifstream file("image.jpg", std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cout << "Error: image.jpg not found in folder!" << std::endl;
        long long failSize = -1; 
        send(clntSock, (char*)&failSize, sizeof(failSize), 0);
    } else {
        // 2. Get file size
        long long fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        // 3. Send size first
        std::cout << "Sending file size: " << fileSize << " bytes" << std::endl;
        send(clntSock, (char*)&fileSize, sizeof(fileSize), 0);

        // 4. Send image data
        char* buffer = new char[fileSize];
        file.read(buffer, fileSize);
        send(clntSock, buffer, (int)fileSize, 0);
        
        std::cout << "Image sent successfully!" << std::endl;
        delete[] buffer;
    }

    closesocket(clntSock);
    closesocket(servSock);
    WSACleanup();
    return 0;
}