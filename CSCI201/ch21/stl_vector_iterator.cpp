#include <iostream>
#include <vector> // Required for vector containers [cite: 739]

using namespace std;

int main() {
    // 1. Create a vector of integers 
    vector<int> myNumbers;

    // 2. Add elements to the back 
    myNumbers.push_back(10);
    myNumbers.push_back(20);
    myNumbers.push_back(30);

    // 3. Declare an iterator 
    vector<int>::iterator it;

    // 4. Use a loop with the iterator to print numbers 
    cout << "My Numbers: ";
    for (it = myNumbers.begin(); it != myNumbers.end(); ++it) {
        cout << *it << " "; // *it "dereferences" to get the value 
    }

    return 0;
}