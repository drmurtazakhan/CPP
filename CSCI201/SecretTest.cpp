#include <iostream>
using namespace std;

// 1. Function Prototype
int secret(int x);

int main()
{

    int x = 4;
    int result = secret(x);

    cout << " x = " << x << endl;
    cout << " result = " << result << endl;

    return 0;
}

// 3. Function Definition
int secret(int x)
{
    if (x > 5)
        return 2 * x;
    //return x;
}