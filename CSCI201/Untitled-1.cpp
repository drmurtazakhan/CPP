// Public_Time_Client.cpp snippet

sockaddr_in servAddr;
servAddr.sin_family = AF_INET;
servAddr.sin_port = htons(13); // Port 13 is the "Time" door

// Convert the text IP "129.6.15.28" into binary format for the computer
inet_pton(AF_INET, "129.6.15.28", &servAddr.sin_addr);

