#include <iostream>

void swap(double & a, double & b) {
    double c{a}; // Temporary variable to hold value of 'a'
    a = b;
    b = c;
}

int main() {
    double a = 2.5, b = 7.5;

    // Output values before swap
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swap(a, b); // Function call to swap the values

    // Output values after swap
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
