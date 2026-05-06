// File: Blockchain.h
// Compile: g++ main.cpp Blockchain.cpp -o main
// Run: .\main

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"

class Blockchain {
private:
    Block* front;
    Block* rear;

    string calculateHash(int blockNumber, long nonce, string data, string prevHash);

public:
    Blockchain();

    void insert(string data);
    void display();
    bool validateBlock(Block* blk);
    bool validateChain();
    void hackBlock(int blockNumber, string newData);
};

#endif