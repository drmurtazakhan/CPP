// Associativity_Precaution.cpp
// compile: g++ Associativity_Precaution.cpp -o Associativity_Precaution.exe
// run:     ./Associativity_Precaution.exe
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << endl;
    if (0 <= num <= 10)
        cout << num << " is within 0 and 10." << endl;
    else
        cout << num << " is not within 0 and 10." << endl;
    return 0;
}