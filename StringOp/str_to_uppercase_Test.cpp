#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter a string: ";
    getline(cin, str1);
    str2 = str1;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    cout << str1 << endl;

    transform(str2.begin()+1, str2.end(), str2.begin(), ::toupper);
    cout << str2 << endl;
    
    return 0;
}