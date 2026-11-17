// HashTableQuadInt.cpp
#include "HashTableQuadInt.h"

ItemQuadInt HTQuadInt[HTSize];

// Simple hash
int hashFunction(int key) {
    return key % HTSize;
}

// Initialize
void initializeHTQuadInt() {
    for (int i = 0; i < HTSize; i++)
        HTQuadInt[i].key = emptyKey;
}

// Insert (Quadratic Probing)
void insertQuadInt(int key) {
    int t = hashFunction(key);
    int i = 0;
    int hIndex = t;

    while (HTQuadInt[hIndex].key != emptyKey) {
        if (HTQuadInt[hIndex].key == key) {
            cout << "Duplicate not allowed: " << key << endl;
            return;
        }

        i++;
        if (i == HTSize) {
            cout << "Table full or no available slot for: " << key << endl;
            return;
        }

        hIndex = (t + i * i) % HTSize;
    }

    HTQuadInt[hIndex].key = key;
}

// Search (Quadratic Probing)
bool searchQuadInt(int key) {
    int t = hashFunction(key);
    int i = 0;
    int hIndex = t;

    while (HTQuadInt[hIndex].key != emptyKey) {
        if (HTQuadInt[hIndex].key == key)
            return true;

        i++;
        if (i == HTSize)
            break;

        hIndex = (t + i * i) % HTSize;
    }
    return false;
}

// Display
void displayQuadInt() {
    cout << "\nHash Table (Quadratic Probing):\n";
    for (int i = 0; i < HTSize; i++) {
        cout << "HT[" << i << "] = ";
        if (HTQuadInt[i].key == emptyKey)
            cout << "EMPTY";
        else
            cout << HTQuadInt[i].key;
        cout << endl;
    }
}