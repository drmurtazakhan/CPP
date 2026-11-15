// compile: g++ mergeSortIntRecursive.cpp -o mergeSortIntRecursive.exe
// run: ./mergeSortIntRecursive.exe

#include <iostream>

using namespace std;

// Function prototypes
void mergeSort(int list[], int length);
void recMergeSort(int list[], int first, int last);
void merge(int list[], int first, int mid, int last);

void mergeSort(int list[], int length) {
    recMergeSort(list, 0, length - 1);
}

void recMergeSort(int list[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        recMergeSort(list, first, mid);      // left half[cite: 2]
        recMergeSort(list, mid + 1, last);   // right half[cite: 2]
        merge(list, first, mid, last);       // merge halves[cite: 2]
    }
}

void merge(int list[], int first, int mid, int last) {
    int *tempList = new int[last + 1];
    int combinedIndex = first, leftIndex = first, rightIndex = mid + 1;

    // Merge elements in order[cite: 3]
    while (leftIndex <= mid && rightIndex <= last) {
        if (list[leftIndex] <= list[rightIndex])
            tempList[combinedIndex++] = list[leftIndex++];
        else
            tempList[combinedIndex++] = list[rightIndex++];
    }

    // Copy remaining elements[cite: 3]
    while (leftIndex <= mid) tempList[combinedIndex++] = list[leftIndex++];
    while (rightIndex <= last) tempList[combinedIndex++] = list[rightIndex++];

    // Copy back to original array[cite: 3]
    for (int i = first; i <= last; i++) list[i] = tempList[i];

    delete[] tempList;
}

int main() {
    int list[] = {35, 28, 18, 45, 62, 48, 30, 38};
    int length = sizeof(list) / sizeof(list[0]);

    cout << "Original array: ";
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    mergeSort(list, length);

    cout << "Sorted array:   ";
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}