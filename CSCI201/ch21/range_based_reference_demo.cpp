// range_based_reference_demo.cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. Setup the vector
    vector<int> scores = {10, 20, 30, 40};

    cout << "Original values are:" << endl;
    for (int n : scores) {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // 2. Modify the elements using a reference
    // The '&' allows us to change the actual data in the container
    for (int &s : scores) {
        s = s * 2; 
    }

    // 3. Display the results using your preferred loop format
    cout << "The doubled values are:" << endl;
    for (int n : scores) {
        cout << n << " ";
    }
    
    cout << endl; // Finish with a newline
    return 0;
}