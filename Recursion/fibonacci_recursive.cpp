#include <iostream>
using namespace std;

// Recursive function to compute nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)        // Base case 1
        return 0;
    else if (n == 1)   // Base case 2
        return 1;
    else               // Recursive case
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 6; // nth Fibonacci number
    int n_fibonacci = fibonacci(n);
    cout << n << "th term of Fibonacci sequence is " << n_fibonacci << endl;
    return 0;
} 