//basic_assert_check.cpp
#include <iostream>
#include <cassert> 
using namespace std;

int main() {
    int sum = 100;
    int counter;

    cout << "Enter the counter: ";
    cin >> counter;

    // If counter is 0, the program halts here
    assert(counter != 0); 

    int average = sum / counter;
    cout << "The average is: " << average << endl;

    return 0;
}