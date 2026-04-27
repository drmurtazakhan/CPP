#ifndef HASHTABLEINT_H
#define HASHTABLEINT_H

#include <iostream>
using namespace std;

const int HTSize = 10;
const int emptyKey = -1;

struct ItemInt {
    int key;
};

extern ItemInt HTInt[HTSize];

int hashFunction(int key);
void initializeHTInt();
void insertInt(int key);
bool searchInt(int key);
void displayInt();

#endif