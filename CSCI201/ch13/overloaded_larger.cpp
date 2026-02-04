// File name: overloaded_larger.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. Version for Integers
int larger(int first, int second) {
    if (first >= second) {
        return first;
    } else {
        return second;
    }
}

// 2. Version for Doubles
double larger(double first, double second) {
    if (first >= second) {
        return first;
    } else {
        return second;
    }
}

// 3. Version for Strings
string larger(string first, string second) {
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
    // Compiler calls the int version
    cout << "Larger of " << i1 << " and " << i2 << " is: " 
         << larger(i1, i2) << endl;

    // --- Double Section ---
    double d1 = 45.67;
    double d2 = 32.12;
    // Compiler calls the double version
    cout << "Larger of " << d1 << " and " << d2 << " is: " 
         << larger(d1, d2) << endl;

    // --- String Section ---
    string s1 = "Apple";
    string s2 = "Orange";
    // Compiler calls the string version
    cout << "Larger of " << s1 << " and " << s2 << " is: " 
         << larger(s1, s2) << endl;

    return 0;
}