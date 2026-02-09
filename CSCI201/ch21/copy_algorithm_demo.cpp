//copy_algorithm_demo.cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for copy
#include <iterator>  // Required for ostream_iterator

using namespace std;

int main() {
    // 1. Initialize a vector with some numbers
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> myList(arr, arr + 5);

    cout << "Output using the copy algorithm:" << endl;

    // 2. The copy function in action
    // myList.begin() -> Start of source
    // myList.end()   -> End of source
    // ostream_iterator<int>(cout, " ") -> Destination (the screen)
    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));

    cout << endl;
    return 0;
}