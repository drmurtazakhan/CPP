// ExternGlobalVariable.cpp
// compile: g++ ExternGlobalVariable.cpp -o ExternGlobalVariable.exe
// run:     ./ExternGlobalVariable.exe
#include <iostream>
using namespace std;

void showLateGlobal()
{
    // 1. Tell compiler global 'a' exists below (No local 'a' declared here!)
    extern int a;

    // 2. Accesses global 'a' declared at the bottom of the file
    cout << "The Global 'a' (declared later) is: " << a << endl;
}

// 3. GLOBAL VARIABLE (Declared AFTER the function definition)
int a = 100;

int main()
{
    showLateGlobal();
    return 0;
}