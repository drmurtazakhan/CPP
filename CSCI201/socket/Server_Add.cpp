// Server_Add.cpp
#include <iostream>
#include <winsock2.h> // Required for Windows networking
#include <ws2tcpip.h>  // Required for modern IP functions

// To compile on Bash Terminal
// Server: g++ Server_Add.cpp -o Server_Add.exe -lws2_32
// Client: g++ Client_Add.cpp -o Client_Add.exe -lws2_32

// To Run
// 1. Start the Server first: ./Server_Add.exe
// 2. Open the new terminal and run the client, you have to input two integers to see the result
// 3. Start the client: ./Client_Add.exe 


// This tells the compiler to link the Winsock library file
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Initialize Winsock (Required for Windows)
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    // 2. Setup Listening Socket
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (servSock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return -1;
    }

    // 3. Bind to Address and Port 8080
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY; // Listen on all network cards
    servAddr.sin_port = htons(8080);

    if (bind(servSock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed" << std::endl;
        closesocket(servSock);
        WSACleanup();
        return -1;
    }

    // 4. Start Listening
    if (listen(servSock, 5) == SOCKET_ERROR) {
        std::cerr << "Listen failed" << std::endl;
        closesocket(servSock);
        WSACleanup();
        return -1;
    }

    std::cout << "Server_Add is running and waiting for numbers on port 8080..." << std::endl;

    while (true) {
        // 5. Accept a connection
        SOCKET clntSock = accept(servSock, nullptr, nullptr);
        if (clntSock == INVALID_SOCKET) continue;

        // 6. Receive the array of 2 integers from the client
        int numbers[2];
        int bytesReceived = recv(clntSock, (char*)numbers, sizeof(numbers), 0);

        if (bytesReceived > 0) {
            // 7. Perform the calculation
            int sum = numbers[0] + numbers[1];
            std::cout << "Received: " << numbers[0] << " and " << numbers[1] << std::endl;
            std::cout << "Sending back Sum: " << sum << std::endl;

            // 8. Send the result back and close this connection
            send(clntSock, (char*)&sum, sizeof(sum), 0);
        }
        closesocket(clntSock);
    }

    // 9. Final Cleanup
    closesocket(servSock);
    WSACleanup();
    return 0;
}