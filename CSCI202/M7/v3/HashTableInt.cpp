#include "HashTableInt.h"

ItemInt HTInt[HTSize];

// Simple hash
int hashFunction(int key) {
    return key % HTSize;
}

// Initialize
void initializeHTInt() {
    for (int i = 0; i < HTSize; i++)
        HTInt[i].key = emptyKey;
}

// Insert
void insertInt(int key) {
    int hIndex = hashFunction(key);
    int start = hIndex;

    while (HTInt[hIndex].key != emptyKey) {
        if (HTInt[hIndex].key == key) {
            cout << "Duplicate not allowed: " << key << endl;
            return;
        }

        hIndex = (hIndex + 1) % HTSize;

        if (hIndex == start) {
            cout << "Table full\n";
            return;
        }
    }

    HTInt[hIndex].key = key;
}

// Search
bool searchInt(int key) {
    int hIndex = hashFunction(key);
    int start = hIndex;

    while (HTInt[hIndex].key != emptyKey) {
        if (HTInt[hIndex].key == key)
            return true;

        hIndex = (hIndex + 1) % HTSize;

        if (hIndex == start)
            break;
    }
    return false;
}

// Display
void displayInt() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < HTSize; i++) {
        cout << "HT[" << i << "] = ";
        if (HTInt[i].key == emptyKey)
            cout << "EMPTY";
        else
            cout << HTInt[i].key;
        cout << endl;
    }
}