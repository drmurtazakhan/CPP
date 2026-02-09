//common_stl_functions.cpp
#include <iostream>
#include <vector>   // We'll use vector to demonstrate common functions

using namespace std;

int main() {
    // 1. Constructors: Initializes containers to an empty state 
    vector<int> list1;
    vector<int> list2 = {1, 2, 3}; // Initialized with data

    // 2. size(): Returns the number of elements currently in the container 
    cout << "Size of list2: " << list2.size() << endl;

    // 3. max_size(): Returns the maximum possible number of elements 
    cout << "Maximum possible size: " << list2.max_size() << endl;

    // 4. empty(): Returns true if the container has no elements 
    if (list1.empty()) {
        cout << "list1 is currently empty." << endl;
    }

    // 5. swap(): Exchanges all elements between two containers of the same type 
    cout << "Before swap, list1 size: " << list1.size() << endl;
    list1.swap(list2); 
    cout << "After swap, list1 size: " << list1.size() << " (now contains {1, 2, 3})" << endl;
    cout << "After swap, list2 size: " << list2.size() << " (list2 is currently empty)" << endl;

    // 6. clear(): Deletes every element, leaving it empty 
    list1.clear();
    cout << "After clear, list1 size: " << list1.size() << endl;

    return 0;
}