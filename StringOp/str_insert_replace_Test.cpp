#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello World!";
    cout << str << endl;

    // Inserting a string at index 6
    str.insert(6, "Beautiful ");
    cout << str << endl;

    // Replace 9 characters starting at index 6 with "Amazing"
    str.replace(6, 9, "Amazing");
    cout << str << endl;

    return 0;
}