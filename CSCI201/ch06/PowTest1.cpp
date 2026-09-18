// compile: g++ PowTest1.cpp -o PowTest1.exe
// run: ./PowTest1.exe
#include <iostream>
#include <cmath>

int main()
{
    double z = pow(3.0, 2.0);
    std::cout << "  z is " << z << std::endl;

    int z2 = pow(3, 2);
    std::cout << "  z2 is " << z2 << std::endl;
    return 0;
}