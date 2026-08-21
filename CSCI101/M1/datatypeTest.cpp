// compile: g++  datatypeTest.cpp -o datatypeTest.exe
// run: ./datatypeTest.exe

#include <iostream>
using namespace std;

int main()
{
    char ch1, ch2;
    cout << "Enter two characters: ";
    cin >> ch1 >> ch2;
    cout << "The ASCII value of " << ch1 << " is: " << static_cast<int>(ch1) << endl;
    cout << "The ASCII value of " << ch2 << " is: " << static_cast<int>(ch2) << endl;

    bool flag1;
    flag1 = true;
    cout << "The value of flag1 is: " << flag1 << endl;
    cout << boolalpha;
    cout << "The value of flag1 is: " << flag1 << endl;
    return 0;
}