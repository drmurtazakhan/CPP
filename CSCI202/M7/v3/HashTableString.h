// HashTableString.h
#ifndef HASHTABLESTRING_H
#define HASHTABLESTRING_H

#include <iostream>
#include <cstring>
using namespace std;

const int HTSize = 10;
const char emptyKey[] = "";

struct Item {
    char key[50];
    bool isEmpty;
};

extern Item HT[HTSize];

int hashFunction(char *insertKey, int keyLength);
void initializeHT();
void insert(char *key);
bool search(char *key);
void display();

#endif