#include <iostream>
using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 22;
    
    cout << "Array: ";
    printArray(arr, n);
    
    cout << "Linear Search: Searching " << key << endl;
    
    int result = linearSearch(arr, n, key);
    
    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;
    
    return 0;
}
