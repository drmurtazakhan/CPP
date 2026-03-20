// testCounter.cpp
// to compile: g++ CounterImp.cpp testCounter.cpp -o testCounter.exe
// to run: ./testCounter

#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
    // Create an object of the Counter class
    Counter myCounter;

    // 1. Increment the counter 3 times
    myCounter.increment();
    myCounter.increment();
    myCounter.increment();
    cout << "After 3 increments, count is: " << myCounter.getCount() << endl;

    // 2. Decrement the counter 1 time
    myCounter.decrement();
    cout << "After 1 decrement, count is: " << myCounter.getCount() << endl;

    // 3. Reset the counter
    myCounter.reset();
    cout << "After reset, count is: " << myCounter.getCount() << endl;

    return 0;
}