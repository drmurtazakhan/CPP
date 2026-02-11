// set_associative_container.cpp
#include <iostream>
#include <set>
#include <string>

using namespace std;

// Separate function to print set elements in a simple way
void displaySet(const string& message, const set<int>& s) {
    cout << message << ": ";
    for (int n : s) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    // 1. Initial items (Notice they are out of order here)
    set<int> myNumbers = {40, 10, 30};
    displaySet("Initial set (automatically sorted)", myNumbers);

    // 2. Insert 2 more items
    myNumbers.insert(50);
    myNumbers.insert(20);
    displaySet("After inserting 50 and 20", myNumbers);

    // 3. Attempt to insert a duplicate (will be ignored)
    myNumbers.insert(30);
    displaySet("After trying to insert 30 again", myNumbers);

    // 4. Erase few items by value
    myNumbers.erase(10); // Removes the 10
    myNumbers.erase(40); // Removes the 40
    displaySet("After erasing 10 and 40", myNumbers);

    return 0;
}
