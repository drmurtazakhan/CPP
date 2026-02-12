// multimap_domo.cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    multimap<int, string> jobAppls = {
        {101, "Alice"}, {101, "Bob"}, {101, "Charlie"}, {202, "David"}
    };

    int searchID = 101;
    auto result = jobAppls.equal_range(searchID);

    // --- THE TRICK: Creating Nicknames ---
    // We create 'start' and 'finish' as aliases for the confusing names
    auto& start  = result.first;
    auto& finish = result.second;

    cout << "Applicants for Job " << searchID << ":" << endl;

    // Now the loop looks very clean!
    for (auto it = start; it != finish; ++it) {
        // 'it' points to a pair {ID, Name}
        // it->first is the ID, it->second is the Name
        string name = it->second; 
        cout << "- " << name << endl;
    }

    return 0;
}