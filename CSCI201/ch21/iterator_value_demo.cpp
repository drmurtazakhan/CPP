//iterator_value_demo.cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myList = {55, 66, 77};

    // 'it' now holds the position of the first element (55)
    vector<int>::iterator it = myList.begin();

    // To see the "value" at that position, we use *
    cout << "The iterator is pointing to: " << *it << endl; 

    // If we move it forward...
    ++it;
    cout << "Now the iterator is pointing to: " << *it << endl;

    return 0;
}