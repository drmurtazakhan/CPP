// deque_container.cpp
#include <iostream>
#include <deque>

using namespace std;

int main() {
    // 1. Create a deque with initial values
    deque<int> myDeque = {10, 20, 30};

    // 2. Add elements to BOTH ends
    myDeque.push_back(40);  // Adds 40 to the end
    myDeque.push_front(5);  // Adds 5 to the start

    cout << "--- After Pushes (Initial State) ---" << endl;
    for (int n : myDeque) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 3. Remove from the FRONT
    cout << "Removing from front (pop_front)..." << endl;
    myDeque.pop_front();    // Removes the 5
    
    // Display after pop_front
    for (int n : myDeque) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 4. Remove from the BACK
    cout << "Removing from back (pop_back)..." << endl;
    myDeque.pop_back();     // Removes the 40

    // Display after pop_back
    for (int n : myDeque) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 5. Modify a middle value using an index
    cout << "Changing index 1 to 99..." << endl;
    myDeque[1] = 99; 

    cout << "Final Deque contents:" << endl;
    for (int n : myDeque) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}