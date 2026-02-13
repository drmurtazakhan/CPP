//basic_if_check.cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 100;
    int counter;

    cout << "Enter the counter: ";
    cin >> counter;

    if (counter != 0) {
        int average = sum / counter;
        cout << "The average is: " << average << endl;
    } else {
        cout << "Error: Cannot divide by zero." << endl;
    }

    return 0;
}