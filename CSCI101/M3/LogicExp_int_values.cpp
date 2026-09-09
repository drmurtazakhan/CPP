// compile: g++ LogicExp_int_values.cpp -o LogicExp_int_values.exe
// run:     ./LogicExp_int_values.exe
#include <iostream>
using namespace std;

int main()
{
    int val1 = -7;
    int val2 = 0;
    int val3 = 7;

    // Condition 1: Negative Non-Zero (-7)
    if (val1)
    {
        cout << val1 << " is non-zero, so it evaluates to TRUE." << endl;
    }
    else
    {
        cout << val1 << " evaluates to FALSE." << endl;
    }

    // Condition 2: Zero (0)
    if (val2)
    {
        cout << val2 << " evaluates to TRUE." << endl;
    }
    else
    {
        cout << val2 << " is zero, so it evaluates to FALSE." << endl;
    }

    // Condition 3: Positive Non-Zero (7)
    if (val3)
    {
        cout << val3 << " is non-zero, so it evaluates to TRUE." << endl;
    }
    else
    {
        cout << val3 << " evaluates to FALSE." << endl;
    }

    return 0;
}