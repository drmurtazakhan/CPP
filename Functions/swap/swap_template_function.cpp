#include <iostream>
#include <string>

using namespace std;

// Template swap function
template <typename SwapT>
void mySwap(SwapT &a, SwapT &b)
{
    SwapT c = a;
    a = b;
    b = c;
}

int main() {
    // Test swap for integers
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    mySwap<int>(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl << endl;

    // Test swap for strings
    string s1 = "Hello", s2 = "World";
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    mySwap<string>(s1, s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl;

    return 0;
}
