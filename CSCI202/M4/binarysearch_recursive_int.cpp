// binarysearch_recursive_int.cpp
// How to compile: g++ binarysearch_recursive_int.cpp -o binarysearch_recursive_int.exe
// How to run: ./binarysearch_recursive_int.exe
#include <iostream>
using namespace std;

// ------------------- Recursive Binary Search for int -------------------
int recBinarySearch(const int list[], int first, int last, int item) {
    // Base case: subarray is empty
    if (first > last){
        cout << "Searching: first = " << first <<  ", last = " << last << endl;
        return -1;
    }
        

    int mid = (first + last) / 2;

    cout << "Searching: first = " << first << ", mid = " << mid << ", last = " << last << endl;

    if (list[mid] == item)          // Found the item
        return mid;
    else if (list[mid] > item)      // Search left half
        return recBinarySearch(list, first, mid - 1, item);
    else                            // Search right half
        return recBinarySearch(list, mid + 1, last, item);
}

// Wrapper function for convenience
int binarySearch(const int list[], int length, int item) {
    return recBinarySearch(list, 0, length - 1, item);
}

// ------------------- Main Function -------------------
int main() {
    int myList[] = {4, 8, 19, 25, 34, 39, 45, 48, 66, 75, 89, 95};
    int n = sizeof(myList) / sizeof(myList[0]);
    int searchItem = 4;

    cout << "List: ";
    for (int i = 0; i < n; i++)
        cout << myList[i] << " ";
    cout << endl;

    cout << "Searching for: " << searchItem << endl;

    int index = binarySearch(myList, n, searchItem);

    if (index != -1)
        cout << "Item found at index: " << index << endl;
    else
        cout << "Item not found!" << endl;

    return 0;
}