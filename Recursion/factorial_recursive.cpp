#include <iostream>
using namespace std;

// Recursive function to compute factorial
int factorial(int n) {
    if (n == 0) // Base case
        return 1;
    else
        return n * factorial(n - 1); // Recursive call
}

int main() {
    int num = 4;
    int numFactorial = factorial(num);
    cout << "Factorial of " << num << " is " << numFactorial << endl;
    return 0;
}
