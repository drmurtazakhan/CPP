// HashTableChaining.h
#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include <iostream>
#include <list>
using namespace std;

// Hash table size
const int HTSize = 10;

// Hash Table using Chaining (Open Hashing)
class HashTableChaining {
private:
    // Array of linked lists (STL list)
    list<int> HT[HTSize];

    // Hash function
    int hashFunction(int key);

public:
    // Insert key
    void insert(int key);

    // Search key
    bool search(int key);

    // Delete key
    void remove(int key);

    // Display table
    void display();
};

#endif