// copy_between_lists.cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for copy
#include <iterator>  // Required for ostream_iterator
#include <string>

using namespace std;

// 1. Separate function to print the container using the copy algorithm
void printList(const string& label, const vector<int>& v) {
    cout << label << ": ";
    // Using copy + ostream_iterator to display elements one by one
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    // 2. Source list with data
    vector<int> source = {5, 10, 15, 20, 25};

    // 3. Destination list (Must be initialized with a size of 5)
    // This creates 5 spots filled with 0s
    vector<int> destination(5);

    printList("Source before copy", source);
    printList("Destination before copy", destination);
    cout << "-----------------------------------" << endl;

    // 4. Using the copy algorithm to move data from source to destination
    // Parameters: (Source Start, Source End, Destination Start)
    copy(source.begin(), source.end(), destination.begin());

    // 5. Print both to see the results
    printList("Source after copy", source);
    printList("Destination after copy", destination);

    return 0;
}