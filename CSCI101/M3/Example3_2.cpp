// Example 3.2: Input with different data types
// Compile: g++ Example3_2.cpp -o Example3_2.exe
// Run: ./Example3_2.exe
#include <iostream>
using namespace std;

int main()
{
    int a;
    double z;
    char ch;

    // Example: input with spaces
    cout << "Enter: 57 A 26.9\n";
    cin >> a >> ch >> z;

    cout << "a = " << a << endl;
    cout << "ch = " << ch << endl;
    cout << "z = " << z << endl;

    // Input without spaces also works
    cout << "\nEnter: 57A26.9\n";
    cin >> a >> ch >> z;

    cout << "a = " << a << ", ch = " << ch
         << ", z = " << z << endl;

    return 0;
}