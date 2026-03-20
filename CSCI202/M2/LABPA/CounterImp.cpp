#include <iostream>
#include "Counter.h"

using namespace std;

// Adds 1 to the current count
void Counter::increment() {
    count++;
}

// Subtracts 1 only if count is greater than 0
void Counter::decrement() {
    if (count > 0) {
        count--;
    } else {
        cout << "Error: Count is already 0. Cannot decrement further." << endl;
    }
}

// Resets the count variable to 0
void Counter::reset() {
    count = 0;
}

// Returns the value of count to the caller
int Counter::getCount() const {
    return count;
}