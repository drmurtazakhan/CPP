#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <functional>   // for std::hash
using namespace std;

const int HTSize = 10;

// Generic Item
template <typename T>
struct Item {
    T key;
    bool isEmpty;
};

// Generic Hash Table (Linear Probing)
template <typename T>
class HashTable {
private:
    Item<T> HT[HTSize];

    int hashFunction(T key) {
        return std::hash<T>{}(key) % HTSize;
    }

public:
    // Constructor
    HashTable() {
        for (int i = 0; i < HTSize; i++)
            HT[i].isEmpty = true;
    }

    // Insert
    void insert(T key) {
        int hIndex = hashFunction(key);
        int start = hIndex;

        while (!HT[hIndex].isEmpty) {
            if (HT[hIndex].key == key) {
                cout << "Duplicate not allowed: " << key << endl;
                return;
            }

            hIndex = (hIndex + 1) % HTSize;

            if (hIndex == start) {
                cout << "Hash table full. Cannot insert " << key << endl;
                return;
            }
        }

        HT[hIndex].key = key;
        HT[hIndex].isEmpty = false;
    }

    // Search
    bool search(T key) {
        int hIndex = hashFunction(key);
        int start = hIndex;

        while (!HT[hIndex].isEmpty) {
            if (HT[hIndex].key == key)
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
};

#endif