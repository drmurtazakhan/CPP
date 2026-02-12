// vector_vs_map_find2.cpp
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm> 

using namespace std;

int main() {
    int target = 3002;

    // --- VECTOR OF PAIRS ---
    // Storing ID and Name just like the map
    vector<pair<int, string>> v = {
        {1001, "Monitor"}, {2005, "Keyboard"}, 
        {3002, "USB-C Hub"}, {5001, "Mouse"}
    };

    // We use find_if because we only want to compare the .first (the ID)
    auto vIt = find_if(v.begin(), v.end(), [target](const pair<int, string>& p) {
        return p.first == target;
    });

    if (vIt != v.end()) {
        cout << "Vector: Found " << vIt->second << " after checking entries." << endl;
    }

    // --- MAP ---
    map<int, string> m = {
        {1001, "Monitor"}, {2005, "Keyboard"}, 
        {3002, "USB-C Hub"}, {5001, "Mouse"}
    };

    // Map uses its internal tree to skip unnecessary checks
    auto mIt = m.find(target);

    if (mIt != m.end()) {
        cout << "Map: Found " << mIt->second << " instantly via tree search." << endl;
    }

    return 0;
}