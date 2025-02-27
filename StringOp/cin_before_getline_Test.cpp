#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char t;
    cout << "Enter 'A':  ";
    cin >> t;
    cout << "Enter a line of text:  ";
    //cin.ignore();  // to avoid the '\n' character
    getline(cin, s);

    cout << endl;
    cout << s << endl;
}