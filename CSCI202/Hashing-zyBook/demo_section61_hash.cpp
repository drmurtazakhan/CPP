// demo section61 hash 
// compiles: g++ -std=c++17 demo_section61_hash.cpp -o demo_section61_hash.exe
// run: ./demo_section61_hash.exe

#include <iostream>
#include <string>
#include "HashFunctions.h"

using namespace std;

int main() {
   cout << "==== 2. Hash functions ====" << endl;
   cout << "HashString(\"APPLE\") = " << HashString("APPLE") << endl;   // 370
   cout << "HashString(\"TAB\")   = " << HashString("TAB") << endl;     // 215
   cout << "HashString(\"BAT\")   = " << HashString("BAT") << endl;     // 215
   cout << "HashInt(3384)        = " << HashInt(3384) << endl;          // 3384
   cout << "HashInt(-76)         = " << HashInt(-76) << endl;           // 2147483572
   cout << "HashInt(INT_MIN)     = " << HashInt(-2147483648) << endl; // 0
   Employee arnold { "Arnold", 101 };
   cout << "HashEmployee(Arnold) = " << HashEmployee(arnold) << endl;   // 101
   return 0;
}