// multimap_phonebook.cpp
// compile with: g++ multimap_phonebook.cpp -o multimap_phonebook.exe
// run with: ./multimap_phonebook.exe
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Key: Name (string), Value: Phone Number (string)
    multimap<string, string> phoneBook;

    // Adding multiple numbers for the same person (the key)
    phoneBook.insert({"John", "555-0101"});
    phoneBook.insert({"John", "555-0102"});
    phoneBook.insert({"John", "555-9999"});
    phoneBook.insert({"Alice", "555-1234"});

    // To find ALL of John's numbers, we use the "start" and "finish" markers
    auto range = phoneBook.equal_range("John");
    auto& start = range.first;
    auto& finish = range.second;

    cout << "John's Phone Numbers:" << endl;
    for (auto it = start; it != finish; ++it) {
        cout << " - " << it->second << endl;
    }

    return 0;
}