#include <iostream>
#include <vector> // Required for vector containers [cite: 739]

using namespace std;

int main() {
    // 1. Create a vector of integers [cite: 742]
    vector<int> myNumbers;

    // 2. Add elements to the back [cite: 822]
    myNumbers.push_back(10);
    myNumbers.push_back(20);
    myNumbers.push_back(30);

    // 3. Declare an iterator [cite: 839]
    vector<int>::iterator it;

    // 4. Use a loop with the iterator to print numbers [cite: 870, 871]
    cout << "My Numbers: ";
    for (it = myNumbers.begin(); it != myNumbers.end(); ++it) {
        cout << *it << " "; // *it "dereferences" to get the value [cite: 851]
    }

    return 0;
}