// sequence_container_demo.cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// This separate function can print any vector of integers
void printList(const string& label, const vector<int>& v) {
    cout << label << ": ";
    // We use a range-based for loop for simplicity
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // 1. Initialization (Range Constructor)
    int arr[] = {10, 20, 30};
    vector<int> myList(arr, arr + 3);
    printList("Original List", myList);

    // 2. push_back(elem): Adds element to the end
    myList.push_back(40);
    printList("After push_back(40)", myList);

    // 3. front() and back(): Accessing ends
    cout << "First element (front): " << myList.front() << endl;
    cout << "Last element (back): " << myList.back() << endl;

    // 4. insert(pos, elem): Adding 15 at index 1
    // We move an iterator to the second position
    vector<int>::iterator it = myList.begin();
    ++it; 
    myList.insert(it, 15);
    printList("After inserting 15 at index 1", myList);

    // 5. pop_back(): Removes the very last element (40)
    myList.pop_back();
    printList("After pop_back()", myList);

    // 6. erase(pos): Removes the element at index 2 (20)
    it = myList.begin();
    it += 2; // Move to the third element
    myList.erase(it);
    printList("After erasing element at index 2", myList);

    // 7. resize(num): Changing size to 6
    // New spots are filled with 0 by default
    myList.resize(6);
    printList("After resize(6)", myList);

    // 8. clear(): Wiping the container clean
    myList.clear();
    cout << "After clear(), size is: " << myList.size() << endl;

    return 0;
}