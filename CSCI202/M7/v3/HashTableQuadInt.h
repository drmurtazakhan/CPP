// HashTableQuadInt.h
#ifndef HASHTABLEQUADINT_H
#define HASHTABLEQUADINT_H

#include <iostream>
using namespace std;

const int HTSize = 10;
const int emptyKey = -1;

struct ItemQuadInt {
    int key;
};

extern ItemQuadInt HTQuadInt[HTSize];

int hashFunction(int key);
void initializeHTQuadInt();
void insertQuadInt(int key);
bool searchQuadInt(int key);
void displayQuadInt();

#endif