// HashTableChaining.cpp
#include "HashTableChaining.h"

// Simple hash function
int HashTableChaining::hashFunction(int key) {
    return key % HTSize;
}

// Insert key into hash table
void HashTableChaining::insert(int key) {
    int index = hashFunction(key);

    // Check for duplicate
    for (int item : HT[index]) {
        if (item == key) {
            cout << "Duplicate not allowed: " << key << endl;
            return;
        }
    }

    // Insert at end of linked list
    HT[index].push_back(key);
}

// Search key in hash table
bool HashTableChaining::search(int key) {
    int index = hashFunction(key);

    // Sequential search in linked list
    for (int item : HT[index]) {
        if (item == key)
            return true;
    }
    return false;
}

// Remove key from hash table
void HashTableChaining::remove(int key) {
    int index = hashFunction(key);

    // Find and remove key
    for (auto it = HT[index].begin(); it != HT[index].end(); ++it) {
        if (*it == key) {
            HT[index].erase(it);
            cout << "Deleted: " << key << endl;
            return;
        }
    }

    cout << "Key not found: " << key << endl;
}

// Display hash table
void HashTableChaining::display() {
    cout << "\nHash Table (Chaining):\n";

    for (int i = 0; i < HTSize; i++) {
        cout << "HT[" << i << "] --> ";

        for (int item : HT[i]) {
            cout << item << " --> ";
        }

        cout << "NULL\n";
    }
}