#include <iostream>

int main() {
    int sum = 0;
    int i = 1;
    int count = 1;
    do {
        sum += i;
        i += 2;
        count++;
    } while (count <= 10);
    std::cout << "Sum of the first 10 odd numbers: " << sum << std::endl;
    return 0;
}
