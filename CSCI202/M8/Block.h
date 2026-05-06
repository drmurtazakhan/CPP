// File: Block.h
// Compile: g++ main.cpp Blockchain.cpp -o main
// Run: .\main

#ifndef BLOCK_H
#define BLOCK_H

#include <string>
using namespace std;

struct Block {
    int blockNumber;
    long nonce;
    string data;
    string previousHash;
    string hash;

    Block* next;
};

#endif