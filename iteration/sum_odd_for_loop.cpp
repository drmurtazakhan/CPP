#include <iostream>

int main() {
    int sum = 0;
    int i = 1;
    for (int count = 1; count <= 10; count++) {
        sum += i;
        i += 2;
    }
    std::cout << "Sum of the first 10 odd numbers: " << sum << std::endl;
    return 0;
}
