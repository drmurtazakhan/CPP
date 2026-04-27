// g++ test_hash_string.cpp -o test_string.exe
// .\test_string.exe
#include "HashTable.h"
#include <string>

int main() {
    HashTable<string> ht;

    ht.insert("Ali");
    ht.insert("Sara");
    ht.insert("Ahmed");
    ht.insert("Zara");
    ht.insert("Ali"); // duplicate

    ht.display();

    cout << "\nSearch Sara: " << (ht.search("Sara") ? "Found" : "Not Found") << endl;
    cout << "Search John: " << (ht.search("John") ? "Found" : "Not Found") << endl;

    return 0;
}