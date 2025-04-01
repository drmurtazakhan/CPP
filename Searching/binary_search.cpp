#include <iostream>
using namespace std;

// Function to perform Binary Search (iterative approach)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if key is at mid
        if (arr[mid] == key)
            return mid;
        
        // If key is greater, ignore the left half
        if (arr[mid] < key)
            left = mid + 1;
        // If key is smaller, ignore the right half
        else
            right = mid - 1;
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
    int arr[] = {11, 12, 22, 25, 64}; // Sorted array for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 22;
    
    cout << "Array: ";
    printArray(arr, n);
    
    cout << "Binary Search: Searching " << key << endl;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;
    
    return 0;
}
