// range_based_reference_demo.cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. Setup the vector
    vector<int> vals = {10, 20, 30, 40};

    cout << "Original values are:" << endl;
    for (int x : vals) {
        cout << x << " ";
    }
    cout << "\n" << endl;
    
    // --- ATTEMPT 1: Doubling by Value ---
    // Here, 'x' is a COPY of the element in the vector.
    // Changing 'x' is like writing on a photocopy; the original remains unchanged.
    for (int x : vals) {
        x = x * 2; // Only the local copy 'x' is doubled
    }

    // Display the results: values will still be 10, 20, 30, 40
    cout << "After Attempt 1 (by value), values are still:" << endl;
    for (int x : vals) {
        cout << x << " ";
    }
    cout << "\n" << endl;

    // --- ATTEMPT 2: Doubling by Reference ---
    // The '&' makes 'x' an alias (a nickname) for the actual element in the vector.
    // Changing 'x' here is like writing directly on the original paper.
    for (int &x : vals) {
        x = x * 2; // The actual data inside 'vals' is doubled
    }

    // 3. Display the results: values will now be 20, 40, 60, 80
    cout << "After Attempt 2 (by reference), the doubled values are:" << endl;
    for (int x : vals) {
        cout << x << " ";
    }
    
    cout << endl; 
    return 0;
}