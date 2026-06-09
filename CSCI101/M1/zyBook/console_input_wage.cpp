// console_input_wage.cpp
// Compile: g++ console_input_wage.cpp -o console_input_wage.exe
// Run: ./console_input_wage.exe
#include <iostream>
using namespace std;

int main()
{
    int wage;

    cout << "Enter hourly wage: ";
    cin >> wage;

    cout << "Annual salary: ";
    cout << wage * 40 * 52 << endl;

    return 0;
}
