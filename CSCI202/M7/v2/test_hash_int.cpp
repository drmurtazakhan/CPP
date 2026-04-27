// g++ test_hash_int.cpp -o test_int.exe
// .\test_int.exe
#include "HashTable.h"

int main() {
    HashTable<int> ht;

    ht.insert(11);
    ht.insert(22);
    ht.insert(31);
    ht.insert(41);
    ht.insert(11); // duplicate

    ht.display();

    cout << "\nSearch 22: " << (ht.search(22) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    return 0;
}