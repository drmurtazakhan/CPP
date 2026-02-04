// File name: template_larger.cpp
#include <iostream>
#include <string>
using namespace std;

// The Template "Blueprint"
template <class Type>
Type larger(Type first, Type second) {
    if (first >= second) {
        return first;
    } else {
        return second;
    }
}

int main() {
    // --- Integer Section ---
    int i1 = 15;
    int i2 = 25;
    cout << "Larger of " << i1 << " and " << i2 << " is: " 
         << larger(i1, i2) << endl;

    // --- Double Section ---
    // Defined here because we don't need them earlier
    double d1 = 45.67;
    double d2 = 32.12;
    cout << "Larger of " << d1 << " and " << d2 << " is: " 
         << larger(d1, d2) << endl;

    // --- String Section ---
    // Defined at the last possible second
    string s1 = "Apple";
    string s2 = "Orange";
    cout << "Larger of " << s1 << " and " << s2 << " is: " 
         << larger(s1, s2) << endl;

    return 0;
}