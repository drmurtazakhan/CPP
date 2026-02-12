// vector_vs_map_find.cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // Required for find() on vectors

using namespace std;

int main()
{
    int target = 3002;

    // --- VECTOR SEARCH ---
    vector<int> v = {1001, 2005, 3002, 4001};
    // We have to use the external find algorithm
    auto vIt = find(v.begin(), v.end(), target);

    if (vIt != v.end())
    {
        cout << "Vector found " << target << " by looking at everything." << endl;
    }

    // --- MAP SEARCH ---
    map<int, string> m = {
        {1001, "Monitor"},
        {2005, "Keyboard"},
        {3002, "USB-C Hub"},
        {5001, "Mouse"}};
    // Map has its own 'smart' find built right in
    auto mIt = m.find(target);

    if (mIt != m.end())
    {
        cout << "Map found " << mIt->first << " (" << mIt->second << ") instantly." << endl;
    }

    return 0;
}