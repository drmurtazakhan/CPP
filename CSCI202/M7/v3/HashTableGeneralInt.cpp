// HashTableGeneralInt.cpp
#include "HashTableGeneralInt.h"

ItemGeneralInt HTGeneralInt[HTSize];
double c1 = 1.0;
double c2 = 0.0;

// Step 1: Compute the home bucket index using modulo arithmetic
int hashFunction(int key) {
    return key % HTSize;
}

// Step 2: Compute the next probe index using the general formula:
//         (H + c1 * i + c2 * i^2) mod HTSize
int computeProbeIndex(int homeIndex, int step) {
    double rawOffset = (c1 * step) + (c2 * step * step);

    // Add 0.5 before casting to int so values like 5.999999 round cleanly to 6
    int offset = static_cast<int>(rawOffset + 0.5);

    int probeIndex = (homeIndex + offset) % HTSize;
    return probeIndex;
}

// Initialize the table to empty and lock in the probing constants (c1, c2)
// so that insert() and search() always use the exact same probe sequence.
void initializeHTGeneralInt(double newC1, double newC2) {
    c1 = newC1;
    c2 = newC2;

    for (int i = 0; i < HTSize; i++) {
        HTGeneralInt[i].key = emptyKey;
    }
}

// Insert a key using the configured (c1, c2) probing sequence
void insertGeneralInt(int key) {
    int homeIndex = hashFunction(key);
    int step = 0;
    int hIndex = computeProbeIndex(homeIndex, step);

    // Keep probing while the current slot is occupied
    while (HTGeneralInt[hIndex].key != emptyKey) {
        // Check if the key is already in the table
        if (HTGeneralInt[hIndex].key == key) {
            cout << "Duplicate not allowed: " << key << endl;
            return;
        }

        // Move to the next step in the probe sequence
        step++;

        // Stop after HTSize attempts to prevent an infinite loop
        if (step == HTSize) {
            cout << "Table full or no reachable slot for: " << key << endl;
            return;
        }

        hIndex = computeProbeIndex(homeIndex, step);
    }

    // Found an empty slot; store the key
    HTGeneralInt[hIndex].key = key;
}

// Search for a key using the exact same (c1, c2) probing sequence
bool searchGeneralInt(int key) {
    int homeIndex = hashFunction(key);
    int step = 0;
    int hIndex = computeProbeIndex(homeIndex, step);

    // Keep probing until we hit an empty slot
    while (HTGeneralInt[hIndex].key != emptyKey) {
        if (HTGeneralInt[hIndex].key == key) {
            return true;
        }

        step++;

        if (step == HTSize) {
            break;
        }

        hIndex = computeProbeIndex(homeIndex, step);
    }

    return false;
}

// Display all slots in the hash table
void displayGeneralInt() {
    cout << "\nHash Table (c1 = " << c1 << ", c2 = " << c2 << "):\n";
    for (int i = 0; i < HTSize; i++) {
        cout << "HT[" << i << "] = ";
        if (HTGeneralInt[i].key == emptyKey) {
            cout << "EMPTY";
        } else {
            cout << HTGeneralInt[i].key;
        }
        cout << endl;
    }
}