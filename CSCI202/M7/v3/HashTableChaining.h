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
    list<int> HT[HTSize]; // Array of linked lists (STL list)

    int hashFunction(int key); // Hash function

public:
    
    void insert(int key);
    bool search(int key);
    void remove(int key);
    void display();
};

#endif