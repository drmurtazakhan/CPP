// HashTableString.cpp
#include "HashTableString.h"

Item HT[HTSize];

// Your given hash function
int hashFunction(char *insertKey, int keyLength)
{
    int sum = 0;

    for (int j = 0; j < keyLength; j++)
        sum = sum + static_cast<int>(insertKey[j]);

    return (sum % HTSize);
}

// Initialize
void initializeHT() {
    for (int i = 0; i < HTSize; i++) {
        HT[i].isEmpty = true;
        HT[i].key[0] = '\0';
    }
}

// Insert (linear probing)
void insert(char *key) {
    int hIndex = hashFunction(key, strlen(key));
    int start = hIndex;

    while (!HT[hIndex].isEmpty) {
        if (strcmp(HT[hIndex].key, key) == 0) {
            cout << "Duplicate not allowed: " << key << endl;
            return;
        }

        hIndex = (hIndex + 1) % HTSize;

        if (hIndex == start) {
            cout << "Table full\n";
            return;
        }
    }

    strcpy(HT[hIndex].key, key);
    HT[hIndex].isEmpty = false;
}

// Search
bool search(char *key) {
    int hIndex = hashFunction(key, strlen(key));
    int start = hIndex;

    while (!HT[hIndex].isEmpty) {
        if (strcmp(HT[hIndex].key, key) == 0)
            return true;

        hIndex = (hIndex + 1) % HTSize;

        if (hIndex == start)
            break;
    }
    return false;
}

// Display
void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < HTSize; i++) {
        cout << "HT[" << i << "] = ";
        if (HT[i].isEmpty)
            cout << "EMPTY";
        else
            cout << HT[i].key;
        cout << endl;
    }
}