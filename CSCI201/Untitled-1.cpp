Step 1: Waiting for the Answer

// UDP_Client.cpp snippet
char buffer[1024] = {0};
int addrLen = sizeof(servAddr);

// The client now waits to catch the "Upper Case" packet
recvfrom(sock, buffer, 1024, 0, (struct sockaddr*)&servAddr, &addrLen);
std::cout << "Server returned: " << buffer << std::endl;