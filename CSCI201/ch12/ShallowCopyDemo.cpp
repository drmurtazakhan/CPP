#include <iostream>
using namespace std;

class Shallow {
public:
    int* data;

    Shallow(int d) {
        data = new int(d); // Allocate memory on the heap
    }

    // No copy constructor defined - Compiler provides a "Shallow" one automatically
    
    ~Shallow() {
        // We won't delete data here to avoid a crash during the demo,
        // but normally this is where a memory leak or crash happens!
    }
};

int main() {
    Shallow objectOne(100);
    
    // Slide 1 Example: Initializing objectThree using objectOne
    Shallow objectThree(objectOne); 

    cout << "--- Slide 1: Shallow Copy (Default) ---" << endl;
    cout << "Value in objectOne: " << *(objectOne.data) << " at address: " << objectOne.data << endl;
    cout << "Value in objectThree: " << *(objectThree.data) << " at address: " << objectThree.data << endl;
    
    cout << "\nNOTICE: Both addresses are the SAME. This is a Shallow Copy!" << endl;
    
    return 0;
}