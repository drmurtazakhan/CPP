// list_container.cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    // 1. Create a list with initial values
    list<int> myList = {30, 10, 20};

    // 2. Add elements to both ends
    myList.push_back(40);
    myList.push_front(5);

    cout << "--- Initial List (After Pushes) ---" << endl;
    for (int n : myList) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 3. Sort the list (using the list's member function)
    myList.sort();
    cout << "--- After Sorting ---" << endl;
    for (int n : myList) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 4. Remove the front element
    cout << "Removing from front (pop_front)..." << endl;
    myList.pop_front(); 

    // --- NEW: Display after pop_front ---
    cout << "List after pop_front:" << endl;
    for (int n : myList) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 5. Special remove: finds and deletes all instances of the value 20
    cout << "Removing all instances of 20..." << endl;
    myList.remove(20);

    cout << "Final List contents:" << endl;
    for (int n : myList) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}