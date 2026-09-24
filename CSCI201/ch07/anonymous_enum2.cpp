// compile: g++ anonymous_enum2.cpp -o anonymous_enum2.exe
// run: ./anonymous_enum2.exe

#include <iostream>
using namespace std;

int main()
{
    enum
    {
        BASKETBALL,
        FOOTBALL,
        BASEBALL,
        HOCKEY
    } mySport;

    mySport = FOOTBALL;

    cout << "mySport = " << mySport << endl;

    return 0;
}