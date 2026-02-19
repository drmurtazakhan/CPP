// state_client.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    std::string abbrev;
    std::cout << "Enter a 2-letter state abbreviation (e.g., NY): ";
    std::cin >> abbrev;

    // 1. Create Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Define Server Address (Localhost)
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. Connect
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed" << std::endl;
        return -1;
    }

    // 4. Send the Abbreviation
    send(sock, abbrev.c_str(), 2, 0);

    // 5. Read the Response
    char buffer[1024] = {0};
    recv(sock, buffer, 1024, 0);

    std::cout << "Full State Name: " << buffer << std::endl;

    // 6. Cleanup
    close(sock);
    return 0;
}