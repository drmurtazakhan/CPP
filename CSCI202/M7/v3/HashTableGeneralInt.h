// HashTableGeneralInt.h
#ifndef HASHTABLEGENERALINT_H
#define HASHTABLEGENERALINT_H

#include <iostream>
using namespace std;

// Power-of-2 table size (8 = 2^3) so that c1 = 0.5, c2 = 0.5
// is guaranteed to visit every single slot in the table.
const int HTSize = 8;
const int emptyKey = -1;

struct ItemGeneralInt {
    int key;
};

// Global hash table array and probing constants
extern ItemGeneralInt HTGeneralInt[HTSize];
extern double c1;
extern double c2;

// Function prototypes
int hashFunction(int key);
int computeProbeIndex(int homeIndex, int step);
void initializeHTGeneralInt(double newC1, double newC2);
void insertGeneralInt(int key);
bool searchGeneralInt(int key);
void displayGeneralInt();

#endif