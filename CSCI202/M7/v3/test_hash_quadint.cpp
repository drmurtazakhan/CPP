// test_hash_quadint.cpp
// g++ HashTableQuadInt.cpp test_hash_quadint.cpp -o test_hash_quadint.exe
// .\test_hash_quadint.exe

#include "HashTableQuadInt.h"

int main() {
    initializeHTQuadInt();

    // All hash to t = 1 (11 % 10 = 1, 21 % 10 = 1, etc.)
    insertQuadInt(11); // i = 0 -> (1 + 0) % 10 = index 1
    insertQuadInt(21); // i = 1 -> (1 + 1) % 10 = index 2
    insertQuadInt(31); // i = 2 -> (1 + 4) % 10 = index 5
    insertQuadInt(41); // i = 3 -> (1 + 9) % 10 = index 0

    insertQuadInt(21); // Duplicate test

    displayQuadInt();

    cout << "\nSearch 31: " << (searchQuadInt(31) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (searchQuadInt(99) ? "Found" : "Not Found") << endl;

    return 0;
}