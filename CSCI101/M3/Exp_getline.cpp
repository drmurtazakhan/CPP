// Example:  Using getline() to read a full line
// Compile: g++ Exp_getline.cpp -o Exp_getline.exe
// Run: ./Exp_getline.exe
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    string sentence;

    // >> skips leading spaces and stops at the first whitespace
    cout << "Enter your name (first and last): ";
    cin >> name;

    cout << "Using >>, name is: " << name << endl;

    // Clear the leftover newline before using getline()
    cin.ignore(100, '\n');

    // getline() reads the entire line including spaces
    cout << "\nEnter a sentence: ";
    getline(cin, sentence);

    cout << "Using getline(), sentence is: " << sentence << endl;

    return 0;
}