// demo section61 hash string
// compiles: g++ -std=c++17 demo_section61_hash_string.cpp -o demo_section61_hash_string.exe
// run: ./demo_section61_hash_string.exe

#include <iostream>
#include <string>
#include "HashFunctions.h"

using namespace std;

int main() {
   cout << "==== 2. Hash functions ====" << endl;
   cout << "HashString(\"APPLE\") = " << HashString("APPLE") << endl;   // 370[cite: 11]
   cout << "HashString(\"TAB\")   = " << HashString("TAB") << endl;     // 215[cite: 11]
   cout << "HashString(\"BAT\")   = " << HashString("BAT") << endl;     // 215 (same!)[cite: 11]
   cout << "HashInt(3384)        = " << HashInt(3384) << endl;          // 3384[cite: 11]
   cout << "HashInt(-76)         = " << HashInt(-76) << endl;           // 2147483572[cite: 11]
   cout << "HashInt(INT_MIN)     = " << HashInt(-2147483647 - 1) << endl; // 0[cite: 11]
   Employee arnold { "Arnold", 101 };
   cout << "HashEmployee(Arnold) = " << HashEmployee(arnold) << endl;   // 101[cite: 11]
   return 0;
}