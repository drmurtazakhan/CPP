// iterator_slide_demo.cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. Setup the list
    vector<int> scores = {70, 80, 90, 100};

    // 2. Create the iterator pointing to the start
    vector<int>::iterator it = scores.begin();

    // 3. Move forward 2 spots (to index 2)
    it = it + 2;

    // 4. Extract the two different types of information
    int index = it - scores.begin(); // The "Where" (Position)
    int value = *it;                // The "What" (Data)

    cout << "Iterator is at index: " << index << endl;
    cout << "The value stored there is: " << value << endl;

    return 0;
}