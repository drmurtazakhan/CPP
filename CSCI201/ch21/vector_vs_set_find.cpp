// vector_vs_set_find.cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // Required for find() on vectors

using namespace std;

int main() {
    int target = 3002;

    // --- VECTOR SEARCH ---
    // A simple list of product codes
    vector<int> v = {1001, 2005, 3002, 4001};
    
    // We use the external algorithm 'find'
    auto vIt = find(v.begin(), v.end(), target);

    if (vIt != v.end()) {
        cout << "Vector: Found " << *vIt << " by checking elements in order." << endl;
    }

    // --- SET SEARCH ---
    // An associative collection of product codes
    set<int> s = {1001, 2005, 3002, 4001};
    
    // Set has its own 'smart' find member function
    auto sIt = s.find(target);

    if (sIt != s.end()) {
        cout << "Set: Found " << *sIt << " instantly using its internal tree." << endl;
    }

    return 0;
}