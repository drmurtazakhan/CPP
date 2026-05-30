// Example2_17.cpp
// compile: g++ Example2_17.cpp -o Example2_17.exe
// run:     ./Example2_17.exe
// This program illustrates how input statements work.
  
#include <iostream>

using namespace std;

int main()  
{
    int feet;
    int inches;

    cout << "Enter two integers separated by one or more spaces: ";
    cin >> feet >> inches;
    cout << endl;

    cout << "Feet = " << feet << endl;
    cout << "Inches = " << inches << endl;
    
    return 0;
}
