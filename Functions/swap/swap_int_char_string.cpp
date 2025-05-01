#include <iostream>
#include <string>

using namespace std;

// Swap function for characters
void mySwap(char &a, char &b) {
    char c = a;
    a = b;
    b = c;
}

// Swap function for integers
void mySwap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}


// Swap function for strings
void mySwap(string &a, string &b) {
    string c = a;
    a = b;
    b = c;
}

int main() {
    // Test integer swap
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    mySwap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl << endl;

    // Test character swap
    char c1 = 'A', c2 = 'B';
    cout << "Before swap: c1 = " << c1 << ", c2 = " << c2 << endl;
    mySwap(c1, c2);
    cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << endl << endl;

    // Test string swap
    string s1 = "Harper", s2 = "College";
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    mySwap(s1, s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl;

    return 0;
}
