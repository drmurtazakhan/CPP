#include <iostream>
using namespace std;

int main()
{
    int c = 0;
    while (c < 10)
    {
        cout << c << ' ';
        c = c + 2;
    }
    cout << c << endl;

    return 0;
}