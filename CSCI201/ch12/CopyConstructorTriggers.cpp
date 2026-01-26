#include <iostream>
using namespace std;

class TriggerDemo {
public:
    int val;
    TriggerDemo(int v) : val(v) {}

    // User-defined copy constructor to track when it runs
    TriggerDemo(const TriggerDemo& other) {
        val = other.val;
        cout << "[Copy Constructor Executed]" << endl;
    }
};

// Situation 2: Passed by value as a parameter
void myFunction(TriggerDemo tempObj) {
    cout << "Inside function, value is: " << tempObj.val << endl;
}

// Situation 3: Return value of a function is an object
TriggerDemo createObject(int v) {
    TriggerDemo localObj(v); 
    return localObj; 
}

int main() {
    cout << "--- Slide 2: Situation 1 (Initialization) ---" << endl;
    TriggerDemo objectOne(10);
    TriggerDemo objectTwo = objectOne; // Trigger 1
    cout << "The value in objectOne is: " << objectOne.val << endl;
    cout << "The value in objectTwo is: " << objectTwo.val << endl;

    cout << "\n--- Slide 2: Situation 2 (Passing by Value) ---" << endl;
    myFunction(objectOne); // Trigger 2

    cout << "\n--- Slide 2: Situation 3 (Returning by Value) ---" << endl;
    TriggerDemo objectThree = createObject(99);
    cout << "The value in objectThree is: " << objectThree.val << endl;

    return 0;
}