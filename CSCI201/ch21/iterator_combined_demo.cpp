//iterator_combined_demo.cpp
#include <iostream>
#include <vector>
#include <iterator> 

using namespace std;

int main() {
    // 1. Create a vector with sample data
    vector<int> scores = {70, 80, 90, 100};

    // 2. Print all values currently in the list
    // This helps us see the full "map" of our container
    cout << "Full List: ";
    for (int s : scores) {
        cout << s << " ";
    }
    cout << endl << "-----------------------" << endl;

    // 3. Initialize the iterator to the start
    // 'it' points to the first element (index 0)
    vector<int>::iterator it = scores.begin();

    // 4. Print status BEFORE moving
    // it - scores.begin() will result in 0
    cout << "--- Initial Status ---" << endl;
    cout << "Starting Index: " << (it - scores.begin()) << endl; 
    cout << "Starting Value: " << *it << endl << endl;

    // 5. Move the iterator forward by 2 positions
    // We are jumping over 70 and 80 to land on 90
    it = it + 2;

    // 6. Calculate the "index" and get the "value"
    // index is the distance from the start; value is the data at that spot
    int index = it - scores.begin(); 
    int value = *it;

    // 7. Display the results after moving
    cout << "--- Status After Moving (it = it + 2) ---" << endl;
    cout << "Current Index: " << index << endl; 
    cout << "Value at Index: " << value << endl;

    // 8. Move the iterator forward one more step
    // This demonstrates the prefix increment operator
    ++it;
    index = it - scores.begin(); 
    cout << "\n--- After moving forward (++it) ---" << endl;
    cout << "New Index: " << index << endl;
    cout << "New Value: " << *it << endl;

    return 0;
}