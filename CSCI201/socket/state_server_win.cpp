// state_server_win.cpp
#include <iostream>
#include <map>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // 1. Initialize Winsock (Required for Windows)
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Winsock initialization failed" << std::endl;
        return 1;
    }

    // Our State Dictionary
    std::map<std::string, std::string> states = {
        {"AL", "Alabama"}, {"AK", "Alaska"}, {"AZ", "Arizona"}, {"CA", "California"},
        {"FL", "Florida"}, {"NY", "New York"}, {"TX", "Texas"}
    };

    // 2. Setup Socket
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all network cards
    address.sin_port = htons(8080);

    // 3. Bind and Listen
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 5);

    std::cout << "Server is running. Waiting for a connection..." << std::endl;

    while (true) {
        // 4. Accept a connection
        SOCKET new_socket = accept(server_fd, nullptr, nullptr);
        if (new_socket == INVALID_SOCKET) continue;

        // 5. Read the 2-letter abbreviation
        char buffer[3] = {0}; 
        recv(new_socket, buffer, 2, 0);
        std::string abbrev(buffer);

        // 6. Find the name
        std::string response;
        if (states.count(abbrev)) {
            response = states[abbrev];
        } else {
            response = "Error: State not found";
        }

        // 7. Send it back and close this specific connection
        send(new_socket, response.c_str(), (int)response.length(), 0);
        closesocket(new_socket); 
        
        std::cout << "Served request for: " << abbrev << std::endl;
    }

    // 8. Cleanup
    closesocket(server_fd);
    WSACleanup();
    return 0;
}