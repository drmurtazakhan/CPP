// Assert_AgeCheck.cpp
// compile: g++ Assert_AgeCheck.cpp -o Assert_AgeCheck.exe
// run:     ./Assert_AgeCheck.exe
#include <iostream>
#include <cassert> // Required for assert()

using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    // Age must not be negative
    assert(age >= 0 && "Age cannot be negative");

    cout << "Your age is " << age << " years." << endl;

    return 0;
}