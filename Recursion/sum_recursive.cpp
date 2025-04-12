#include <iostream>
using namespace std;

// Recursive function to compute sum from 1 to n
int sum(int n) {
    if (n == 1) {  // Base case
        return 1;
    } else {       // Recursive case
        return n + sum(n - 1);
    }
}

int main() {
    int num = 5;  // Number to compute sum up to
    int result = sum(num);
    cout << "Sum of numbers from 1 to " << num << " is " << result << endl;
    return 0;
}