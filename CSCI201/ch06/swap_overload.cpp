#include <iostream>
#include <string>

using namespace std;

// 1. Version for Integers
void mySwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Version for Strings (Overloaded)
// Notice it has the exact same name, but different parameter types!
void mySwap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

int main() {
    // Testing Integers
    int num1 = 10, num2 = 20;
    cout << "Before Int Swap: " << num1 << ", " << num2 << endl;
    mySwap(num1, num2); // Calls the int version
    cout << "After Int Swap:  " << num1 << ", " << num2 << endl;

    cout << "--------------------------" << endl;

    // Testing Strings
    string str1 = "John", str2 = "Brown";
    cout << "Before String Swap: " << str1 << ", " << str2 << endl;
    mySwap(str1, str2); // Calls the string version
    cout << "After String Swap:  " << str1 << ", " << str2 << endl;

    return 0;
}