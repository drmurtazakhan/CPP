#include <iostream>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int count = 0;
    int num = 2;
    std::cout << "First 10 prime numbers: ";
    while (count < 10) {
        if (isPrime(num)) {
            std::cout << num << " ";
            count++;
        }
        num++;
    }
    std::cout << std::endl;
    return 0;
}
