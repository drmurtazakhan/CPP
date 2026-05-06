// File: Blockchain.cpp
// Compile: g++ main.cpp Blockchain.cpp -o main
// Run: .\main

#include <iostream>
#include <sstream>
#include <ctime>
#include "Blockchain.h"

using namespace std;

// Constructor
Blockchain::Blockchain() {
    front = rear = nullptr;
}

// Simple hash function (string-based)
string Blockchain::calculateHash(int blockNumber, long nonce, string data, string prevHash) {
    stringstream ss;
    ss << blockNumber << nonce << data << prevHash;

    string input = ss.str();
    int sum = 0;

    for (char c : input)
        sum += (int)c;

    return to_string(sum);
}

// Insert block (enqueue)
void Blockchain::insert(string data) {
    Block* newBlock = new Block;

    newBlock->data = data;
    newBlock->next = nullptr;

    // Block number
    if (rear == nullptr)
        newBlock->blockNumber = 0;
    else
        newBlock->blockNumber = rear->blockNumber + 1;

    // Nonce (timestamp)
    newBlock->nonce = time(0);

    // Previous hash
    if (rear == nullptr)
        newBlock->previousHash = "0";
    else
        newBlock->previousHash = rear->hash;

    // Current hash
    newBlock->hash = calculateHash(
        newBlock->blockNumber,
        newBlock->nonce,
        newBlock->data,
        newBlock->previousHash
    );

    // Queue insert
    if (rear == nullptr)
        front = rear = newBlock;
    else {
        rear->next = newBlock;
        rear = newBlock;
    }
}

// Display blockchain
void Blockchain::display() {
    Block* temp = front;

    cout << "\nBlockchain:\n";

    while (temp != nullptr) {
        cout << "\nBlock #: " << temp->blockNumber << endl;
        cout << "Nonce: " << temp->nonce << endl;
        cout << "Data: " << temp->data << endl;
        cout << "Prev Hash: " << temp->previousHash << endl;
        cout << "Hash: " << temp->hash << endl;

        temp = temp->next;
    }
}

// Validate single block
bool Blockchain::validateBlock(Block* blk) {
    string recalculated = calculateHash(
        blk->blockNumber,
        blk->nonce,
        blk->data,
        blk->previousHash
    );

    return (recalculated == blk->hash);
}

// Validate entire chain
bool Blockchain::validateChain() {
    Block* temp = front;

    while (temp != nullptr) {

        // Validate block hash
        if (!validateBlock(temp)) {
            cout << "Invalid block at #" << temp->blockNumber << endl;
            return false;
        }

        // Validate chain linkage
        if (temp->next != nullptr) {
            if (temp->hash != temp->next->previousHash) {
                cout << "Broken chain at block #" << temp->blockNumber << endl;
                return false;
            }
        }

        temp = temp->next;
    }

    return true;
}

// Hack a block (modify data)
void Blockchain::hackBlock(int blockNumber, string newData) {
    Block* temp = front;

    while (temp != nullptr) {
        if (temp->blockNumber == blockNumber) {
            temp->data = newData;
            cout << "Block #" << blockNumber << " hacked.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Block not found.\n";
}