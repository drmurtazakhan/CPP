// merge_sort_test.cpp
// How to compile: g++ merge_sort_test.cpp -o merge_sort_test.exe
// How to run: ./merge_sort_test.exe
#include <iostream>
using namespace std;

// ------------------- Merge Function -------------------
template <class elemType>
void merge(elemType list[], int first, int mid, int last)
{
    elemType *tempList = new elemType[last + 1];
    int combinedIndex = first; // Tracks where to put the next element in tempList
    int leftIndex = first;     // Starts at the beginning of the left subarray
    int rightIndex = mid + 1;  // Starts at the beginning of the right subarray

    // Merge two halves in sorted order
    while (leftIndex <= mid && rightIndex <= last)
    {
        if (list[leftIndex] <= list[rightIndex])
            tempList[combinedIndex++] = list[leftIndex++];
        else
            tempList[combinedIndex++] = list[rightIndex++];
    }

    // Copy remaining elements from left half
    while (leftIndex <= mid)
        tempList[combinedIndex++] = list[leftIndex++];

    // Copy remaining elements from right half
    while (rightIndex <= last)
        tempList[combinedIndex++] = list[rightIndex++];

    // Copy back to original array
    for (int i = first; i <= last; i++)
        list[i] = tempList[i];

    delete[] tempList;
}

// ------------------- Recursive Merge Sort -------------------
template <class elemType>
void recMergeSort(elemType list[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;

        cout << "Splitting: first = " << first << ", mid = " << mid << endl;
        recMergeSort(list, first, mid);    // Sort left half
        
        cout << "Splitting: mid + 1 = " << (mid + 1) << ", last = " << last << endl;
        recMergeSort(list, mid + 1, last); // Sort right half
        
        //cout << "Merging: first=" << first << ", mid=" << mid << ", last=" << last << endl;
        merge(list, first, mid, last); // Merge halves
    }
}

// ------------------- Merge Sort Function -------------------
template <class elemType>
void mergeSort(elemType list[], int length)
{
    recMergeSort(list, 0, length - 1);
}

// ------------------- Main Function -------------------
int main()
{
    int myList[] = {35, 28, 18, 45, 62, 48, 30, 38};
    int n = sizeof(myList) / sizeof(myList[0]);

    cout << "Original list: ";
    for (int i = 0; i < n; i++)
        cout << myList[i] << " ";
    cout << endl;

    mergeSort(myList, n);

    cout << "Sorted list:   ";
    for (int i = 0; i < n; i++)
        cout << myList[i] << " ";
    cout << endl;

    return 0;
}