// test_hash_chaining.cpp
// g++ HashTableChaining.cpp test_hash_chaining.cpp -o test_hash_chaining.exe
// .\test_hash_chaining.exe

#include "HashTableChaining.h"

int main() {
    HashTableChaining ht;

    // Insert elements (some will collide)
    ht.insert(11);   // index 1
    ht.insert(21);   // index 1 (collision)
    ht.insert(31);   // index 1 (collision)

    ht.insert(12);   // index 2
    ht.insert(22);   // index 2 (collision)

    ht.insert(5);    // index 5

    // Display table
    ht.display();

    // Search
    cout << "\nSearch 21: " << (ht.search(21) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    // Delete
    ht.remove(21);
    ht.remove(99);

    // Display after deletion
    ht.display();

    return 0;
}