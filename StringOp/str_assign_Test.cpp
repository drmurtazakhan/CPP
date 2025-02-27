#include <iostream>
#include <string>
using namespace std;    // std::string

int main()
{
    string str;
    cout << str << endl;

    // Assigning a new string
    str.assign("Atomic Habits");
    cout << str << endl;

    // Assigning (first 4 characters)
    str.assign("Atomic Habits", 4);
    cout << str << endl;

    // Assigning a part of the string (start at index 8, length 4)  
    str.assign("Atomic Habits", 8, 4);
    cout << str << endl;

    return 0;
}