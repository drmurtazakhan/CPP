// main.cpp
// Demonstrates every topic of Chapter 6 (Hashing).
//
// Usage:   hashing            -> runs all demos
//          hashing <number>   -> runs one demo (1-9)
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "HashFunctions.h"
#include "LimitedArrayMap.h"
#include "ChainingHashTable.h"
#include "LinearProbingHashTable.h"
#include "QuadraticProbingHashTable.h"
#include "DoubleHashingHashTable.h"

using namespace std;

// Small helper to print a section heading.
void Heading(const string& text) {
   cout << endl << "==== " << text << " ====" << endl;
}

// ---------------------------------------------------------------------------
// Demo 1 (6.1): limited map that uses the key directly as an array index.
// ---------------------------------------------------------------------------
void DemoLimitedMap() {
   Heading("1. Limited map ADT (keys 0-9)");
   LimitedArrayMap map;
   map.Insert(1, "Red");
   map.Insert(4, "Green");
   map.Insert(7, "Violet");
   map.Insert(2, "Orange");
   cout << "Contains key 7? " << boolalpha << map.Contains(7) << endl;  // true
   cout << "Contains key 9? " << map.Contains(9) << endl;               // false
   map.Remove(2);
   cout << "After Remove(2), contains 2? " << map.Contains(2) << endl;  // false
   cout << "Insert(10) works? " << map.Insert(10, "X") << endl;         // false: out of range
}

// ---------------------------------------------------------------------------
// Demo 2 (6.1): hash functions.
// ---------------------------------------------------------------------------
void DemoHashFunctions() {
   Heading("2. Hash functions");
   cout << "HashString(\"APPLE\") = " << HashString("APPLE") << endl;   // 370
   cout << "HashString(\"TAB\")   = " << HashString("TAB") << endl;     // 215
   cout << "HashString(\"BAT\")   = " << HashString("BAT") << endl;     // 215 (same!)
   cout << "HashInt(3384)        = " << HashInt(3384) << endl;          // 3384
   cout << "HashInt(-76)         = " << HashInt(-76) << endl;           // 2147483572
   cout << "HashInt(INT_MIN)     = " << HashInt(-2147483647 - 1) << endl; // 0
   Employee arnold { "Arnold", 101 };
   cout << "HashEmployee(Arnold) = " << HashEmployee(arnold) << endl;   // 101
}

// ---------------------------------------------------------------------------
// Demo 3 (6.1): bucket indices and a collision (10 buckets, chaining).
// ---------------------------------------------------------------------------
void DemoBucketsAndCollision() {
   Heading("3. Bucket index and collision (chaining, 10 buckets)");
   ChainingHashTable<int, string> playerNums(10);
   playerNums.Insert(86, "Paola");   // 86 % 10 = 6
   playerNums.Insert(23, "Maria");   // 23 % 10 = 3
   playerNums.Insert(42, "Jan");     // 42 % 10 = 2
   playerNums.Insert(16, "Julie");   // 16 % 10 = 6 -> collision with 86
   playerNums.PrintTable(cout);
   cout << "Length: " << playerNums.Length() << endl;                  // 4
   cout << "Contains 23? " << boolalpha << playerNums.Contains(23) << endl;
   cout << "Contains 56? " << playerNums.Contains(56) << endl;
}

// ---------------------------------------------------------------------------
// Airport program (the zyDE of sections 6.2-6.5), reused for each table type.
// ---------------------------------------------------------------------------
void RunAirportProgram(HashTable<string, string>& table) {
   vector<string> keys = { "LAX", "IAH", "IAD", "ORD", "SFO",
                           "DAL", "NRT", "JFK", "YVR", "LHR" };
   vector<string> values = { "Los Angeles", "Houston", "Washington", "Chicago",
                             "San Francisco", "Dallas", "Tokyo", "New York",
                             "Vancouver", "London" };

   // Add all items
   for (int i = 0; i < (int)keys.size(); i++) {
      table.Insert(keys[i], values[i]);
   }

   // Print the items, then the buckets
   cout << "Items:" << endl;
   table.Print(cout, ": ", "\n", "", "\n");
   cout << endl << "Buckets:" << endl;
   table.PrintTable(cout);

   // Remove some items
   cout << endl;
   vector<string> keysToRemove = { "LAX", "ORD" };
   for (const string& keyToRemove : keysToRemove) {
      cout << "Removing \"" << keyToRemove << "\"" << endl;
      table.Remove(keyToRemove);
   }

   // Print again
   cout << endl << "Buckets after removals:" << endl;
   table.PrintTable(cout);
}

void DemoChaining() {
   Heading("4. Chaining (6.2)");
   ChainingHashTable<string, string> table;
   RunAirportProgram(table);
}
void DemoLinearProbing() {
   Heading("5. Linear probing (6.3)");
   LinearProbingHashTable<string, string> table;
   RunAirportProgram(table);
}
void DemoQuadraticProbing() {
   Heading("6. Quadratic probing (6.4)");
   QuadraticProbingHashTable<string, string> table;   // c1 = 1, c2 = 1
   RunAirportProgram(table);
}
void DemoDoubleHashing() {
   Heading("7. Double hashing (6.5)");
   DoubleHashingHashTable<string, string> table;
   RunAirportProgram(table);
}

// ---------------------------------------------------------------------------
// Demo 8: the textbook's worked probing examples with integer keys.
// ---------------------------------------------------------------------------
void DemoProbingExamples() {
   Heading("8. Textbook probing examples");

   cout << "-- Linear probing, 7 buckets: insert 77, 88, 49 --" << endl;
   LinearProbingHashTable<int, string> linear(7);
   linear.Insert(77, "Item 1");   // bucket 0
   linear.Insert(88, "Item 2");   // bucket 4
   linear.Insert(49, "Item 3");   // 49 % 7 = 0 occupied -> bucket 1
   linear.PrintTable(cout);
   cout << "Contains 49? " << boolalpha << linear.Contains(49) << endl;  // true
   cout << "Contains 21? " << linear.Contains(21) << endl;               // false

   cout << endl << "-- Linear probing: empty-after-removal keeps the search going --" << endl;
   linear.Remove(77);            // bucket 0 becomes empty-after-removal
   cout << "After Remove(77), contains 49? " << linear.Contains(49) << endl; // still true
   linear.PrintTable(cout);

   cout << endl << "-- Quadratic probing (c1 = 1, c2 = 1), 10 buckets: 55, 66, 25 --" << endl;
   QuadraticProbingHashTable<int, string> quad(10, 1, 1);
   quad.Insert(55, "a");         // bucket 5
   quad.Insert(66, "b");         // bucket 6
   quad.Insert(25, "c");         // 5 taken -> i=1: (25+1+1)%10 = 7
   quad.PrintTable(cout);

   cout << endl << "-- Double hashing, 11 buckets, H2 = 7 - key % 7 --" << endl;
   DoubleHashingHashTable<int, string> dbl(11, 7);
   int firstKeys[] = { 95, 65, 60, 85, 72 };
   for (int k : firstKeys) dbl.Insert(k, "x");   // no collisions
   dbl.Insert(84, "Cell phone");   // 7 taken -> i=1 -> bucket 3
   dbl.Insert(8, "Cellophane");    // 8, 3 taken -> i=2 -> bucket 9
   dbl.PrintTable(cout);
}

// ---------------------------------------------------------------------------
// Demo 9 (6.6): resizing a hash table to the next prime >= 2 * N buckets.
// ---------------------------------------------------------------------------
void DemoResize() {
   Heading("9. Hash table resizing (6.6)");
   LinearProbingHashTable<int, string> table(5);
   for (int k : { 10, 21, 32, 43 }) table.Insert(k, "v" + to_string(k));
   cout << "Before: " << table.Capacity() << " buckets, "
        << table.Length() << " items" << endl;
   table.PrintTable(cout);

   table.Grow();   // 5 buckets -> next prime >= 10 = 11 buckets
   cout << endl << "After Grow(): " << table.Capacity() << " buckets, "
        << table.Length() << " items" << endl;
   table.PrintTable(cout);
}

int main(int argc, char* argv[]) {
   int choice = (argc > 1) ? atoi(argv[1]) : 0;   // 0 = run everything
   if (choice == 0 || choice == 1) DemoLimitedMap();
   if (choice == 0 || choice == 2) DemoHashFunctions();
   if (choice == 0 || choice == 3) DemoBucketsAndCollision();
   if (choice == 0 || choice == 4) DemoChaining();
   if (choice == 0 || choice == 5) DemoLinearProbing();
   if (choice == 0 || choice == 6) DemoQuadraticProbing();
   if (choice == 0 || choice == 7) DemoDoubleHashing();
   if (choice == 0 || choice == 8) DemoProbingExamples();
   if (choice == 0 || choice == 9) DemoResize();
   return 0;
}
