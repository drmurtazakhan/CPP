// vector_insert_demo.cpp
#include <iostream>
#include <vector>    // Needed to use the vector container
#include <iterator>  // Needed for advanced iterator functions

using namespace std;

int main() {
    // 1. Create a basic "raw" array of integers.
    // This is a fixed-size list of 4 numbers.
    int scoresArray[] = {70, 80, 90, 100};

    // 2. Initialize the vector container using the array.
    // 'scoresArray' is the start address (index 0).
    // 'scoresArray + 4' is the address 4 spots later (just past the end).
    // This copies the data from the old array into our new dynamic vector.
    vector<int> scoreList(scoresArray, scoresArray + 4);

    // 3. Create an iterator variable.
    // Think of an iterator as a "smart pointer" or a "finger" 
    // that points to items inside the vector.
    vector<int>::iterator it;

    // 4. Print the list before we make any changes.
    cout << "Original Scores: ";
    for (it = scoreList.begin(); it != scoreList.end(); ++it) {
        // We use *it to "dereference" the iterator and see the value inside.
        cout << *it << " ";
    }
    cout << endl;

    // 5. Prepare to insert a new number.
    // First, we point our iterator 'it' to the very start of the list (the 70).
    it = scoreList.begin();

    // 6. Move the "finger" forward.
    // ++it moves the pointer from the first item (70) to the second item (80).
    ++it;

    // 7. Perform the insertion.
    // This says: "At the spot where 'it' is pointing, put the number 85."
    // The vector automatically pushes 80, 90, and 100 one spot to the right.
    // After this operation, the list will look like: 70, 85, 80, 90, 100
    scoreList.insert(it, 85);

    // 8. Print the list again to see the result.
    cout << "Updated Scores:  ";
    for (it = scoreList.begin(); it != scoreList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}