#include <iostream>
using namespace std;

int main()
{
    int c = 1;
    do
    {
        cout << c << ' ';
        c = c + 2;
    }
    while (c < 10);

    cout << c << endl;

    return 0;
}