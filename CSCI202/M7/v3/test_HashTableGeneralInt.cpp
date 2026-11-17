// test_HashTableGeneralInt.cpp
// Compilation:
// g++ HashTableGeneralInt.cpp test_HashTableGeneralInt.cpp -o test_HashTableGeneralInt.exe
// .\test_HashTableGeneralInt.exe

#include "HashTableGeneralInt.h"

int main() {
    // With HTSize = 8, keys 8, 16, 24, 32, 40 all hash to homeIndex = 0 (key % 8 == 0).
    // This lets us clearly observe how different (c1, c2) values resolve collisions!

    // =========================================================================
    // TEST 1: Linear Probing (c1 = 1, c2 = 0)
    // Formula: (H + i) % 8  -->  Probe path from 0: 0, 1, 2, 3, 4...
    // =========================================================================
    cout << "=== TEST 1: LINEAR PROBING (c1 = 1, c2 = 0) ===";
    cout << endl;

    initializeHTGeneralInt(1.0, 0.0);

    insertGeneralInt(8);   // Lands at index 0
    insertGeneralInt(16);  // Collides at 0 -> lands at index 1
    insertGeneralInt(24);  // Collides at 0, 1 -> lands at index 2
    insertGeneralInt(32);  // Collides at 0, 1, 2 -> lands at index 3
    insertGeneralInt(16);  // Duplicate test

    displayGeneralInt();
    cout << "Search 8: " << (searchGeneralInt(8) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (searchGeneralInt(99) ? "Found" : "Not Found") << endl;


    // =========================================================================
    // TEST 2: Pure Quadratic Probing (c1 = 0, c2 = 1)
    // Formula: (H + i^2) % 8  -->  Probe path from 0: 0, 1, 4, 1, 0...
    // Notice: On a power-of-2 table (size 8), (0, 1) only reaches slots 0, 1, 4!
    // =========================================================================
    cout << "\n=== TEST 2: PURE QUADRATIC PROBING (c1 = 0, c2 = 1) ===";
    cout << endl;

    initializeHTGeneralInt(0.0, 1.0);

    insertGeneralInt(8);   // step 0 -> index 0
    insertGeneralInt(16);  // step 1 -> index 1
    insertGeneralInt(24);  // step 2 -> index 4
    insertGeneralInt(32);  // Repeats 1, 0, 1, 4... cannot reach remaining slots!

    displayGeneralInt();
    cout << "Search 16: " << (searchGeneralInt(16) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (searchGeneralInt(99) ? "Found" : "Not Found") << endl;



    // =========================================================================
    // TEST 3: Optimal Triangular Quadratic Probing (c1 = 0.5, c2 = 0.5)
    // Formula: (H + 0.5*i + 0.5*i^2) % 8  -->  Probe path from 0: 0, 1, 3, 6, 2, 7, 5, 4
    // Notice: Visits ALL 8 slots without repeating!
    // =========================================================================
    cout << "\n=== TEST 3: OPTIMAL QUADRATIC PROBING (c1 = 0.5, c2 = 0.5) ===";
    initializeHTGeneralInt(0.5, 0.5);

    insertGeneralInt(8);   // step 0 -> index 0
    insertGeneralInt(16);  // step 1 -> index 1
    insertGeneralInt(24);  // step 2 -> index 3
    insertGeneralInt(32);  // step 3 -> index 6
    insertGeneralInt(40);  // step 4 -> index 2

    displayGeneralInt();
    cout << "Search 24: " << (searchGeneralInt(24) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (searchGeneralInt(99) ? "Found" : "Not Found") << endl;

    // =========================================================================
    // TEST 4: zyBook Example Quadratic Probing (c1 = 1, c2 = 1)
    // Formula: (H + i + i^2) % 8  -->  Probe path from 0: 0, 2, 6, 4, 4, 6, 2, 0
    // Notice: Because i + i^2 = i(i + 1) is ALWAYS even, starting at H = 0
    //         only ever visits EVEN slots (0, 2, 4, 6) and misses all ODD slots!
    // =========================================================================
    cout << "\n=== TEST 4: QUADRATIC PROBING (c1 = 1, c2 = 1) ===";
    cout << endl;
    
    initializeHTGeneralInt(1.0, 1.0);

    insertGeneralInt(8);   // step 0 -> (0 + 0 + 0) % 8 = index 0
    insertGeneralInt(16);  // step 1 -> (0 + 1 + 1) % 8 = index 2
    insertGeneralInt(24);  // step 2 -> (0 + 2 + 4) % 8 = index 6
    insertGeneralInt(32);  // step 3 -> (0 + 3 + 9) % 8 = index 4
    insertGeneralInt(40);  // Steps 4..7 repeat 4, 6, 2, 0 -> fails even though 4 odd slots are empty!

    displayGeneralInt();
    cout << "Search 32: " << (searchGeneralInt(32) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (searchGeneralInt(40) ? "Found" : "Not Found") << endl;

    return 0;
}