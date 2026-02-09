// range_vs_traditional_demo.cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // --- 1. ARRAY EXAMPLE ---
    int numbers[] = {1, 2, 3, 4, 5};
    int n = sizeof(numbers) / sizeof(numbers[0]); // Calculating size for the old way

    cout << "--- Array: Old Way (Index-based) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    
    cout << "\n--- Array: New Way (Range-based) ---" << endl;
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << "\n" << endl;


    // --- 2. VECTOR EXAMPLE ---
    vector<int> scores = {90, 85, 77, 92};

    cout << "--- Vector: Old Way (Index-based) ---" << endl;
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i] << " ";
    }

    cout << "\n--- Vector: New Way (Range-based) ---" << endl;
    for (int s : scores) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}