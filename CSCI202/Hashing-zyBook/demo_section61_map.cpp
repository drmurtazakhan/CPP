// demo section 6.1
// compiles: g++ -std=c++17 demo_section61_map.cpp -o demo_section61_map.exe
// run: ./demo_section61_map.exe

#include <iostream>
#include <string>
#include "LimitedArrayMap.h"

using namespace std;

int main() {
   cout << "==== 1. Limited map ADT (keys 0-9) ====" << endl;
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
   return 0;
}