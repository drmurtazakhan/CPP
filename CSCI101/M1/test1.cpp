#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    if (num % 2 == 0)
    {
        cout << num << " is even." << endl;
        cout << "Square root of " << num << " is: " << sqrt(num) << endl;
    }

    return 0;
}