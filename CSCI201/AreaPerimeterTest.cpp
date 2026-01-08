#include <iostream>
using namespace std;

// Function Prototype
void areaAndPerimeter(double length, double width);

int main() {
    double l = 5.0;
    double w = 3.0;

    // Call the function
    areaAndPerimeter(l, w);

    return 0;
}

// Function Definition
void areaAndPerimeter(double length, double width) {
    // Calculations
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Printing inside the function as requested    
    cout << "Calculated Area: " << area << endl;
    cout << "Calculated Perimeter: " << perimeter << endl;
}