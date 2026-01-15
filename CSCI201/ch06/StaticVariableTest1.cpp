#include <iostream>
using namespace std;

void countDemo() {
    int normalVar = 0;        // Normal variable
    static int staticVar = 0; // Static variable

    normalVar++;
    staticVar++;

    cout << "Normal: " << normalVar << " | Static: " << staticVar << endl;
}

int main() {
    countDemo(); // Call 1
    countDemo(); // Call 2
    countDemo(); // Call 3
    return 0;
}