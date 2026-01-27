#include <iostream>
using namespace std;

class Deep {
public:
    int* data;

    // Standard Constructor
    Deep(int d) {
        data = new int(d);
    }

    // Slide 3 Solution: Overriding the Copy Constructor for a DEEP COPY
    Deep(const Deep& otherObject) {
        // 1. Allocate NEW memory
        data = new int; 
        // 2. Copy the VALUE from the old memory to the new memory
        *data = *(otherObject.data); 
        cout << "Deep Copy Constructor executed successfully!" << endl;
    }

    // Include Destructor to clean up memory
    ~Deep() {
        delete data;
        cout << "Destructor cleaning up memory..." << endl;
    }

    // (Assignment operator overloading would be the next step in a full class)
};

int main() {
    Deep objectOne(50);
    Deep objectTwo(objectOne); // Uses our Deep Copy Constructor

    cout << "\n--- Slide 3: Deep Copy (Safe) ---" << endl;
    cout << "objectOne data address: " << objectOne.data << " Value: " << *(objectOne.data) << endl;
    cout << "objectTwo data address: " << objectTwo.data << " Value: " << *(objectTwo.data) << endl;

    cout << "\nNOTICE: The addresses are DIFFERENT. Each has its own 'room'!" << endl;

    return 0;
}