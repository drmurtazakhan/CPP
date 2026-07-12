// File name: Exp_8_6.cpp
// compile: g++ Exp_8_6.cpp -o Exp_8_6.exe
// run: ./Exp_8_6.exe

#include <iostream>

using namespace std;

// Initialize array components to 0
void initializeArray(int list[], int listSize)
{
    for (int index = 0; index < listSize; index++)
        list[index] = 0;
}

// Read data into the array
void fillArray(int list[], int listSize)
{
    for (int index = 0; index < listSize; index++)
        cin >> list[index];
}

// Print array elements
void printArray(const int list[], int listSize)
{
    for (int index = 0; index < listSize; index++)
        cout << list[index] << " ";
}

// Return the sum of array elements
int sumArray(const int list[], int listSize)
{
    int sum = 0;
    for (int index = 0; index < listSize; index++)
        sum += list[index];
    return sum;
}

// Return the index of the largest element
int indexLargestElement(const int list[], int listSize)
{
    int maxIndex = 0;
    for (int index = 1; index < listSize; index++)
        if (list[maxIndex] < list[index])
            maxIndex = index;
    return maxIndex;
}

// Function to copy a specific range of elements from one array to another.
// list1: The source array containing the original data.
// src: The starting index in the source array (list1) to begin copying from.
// list2: The target array where the elements will be copied.
// tar: The starting index in the target array (list2) to begin pasting into.
// numElements: The total count of elements to be copied from list1 to list2.
// Note: Ensure list2 has sufficient capacity to accommodate the copied elements.
void copyArray(int list1[], int src, int list2[], int tar, int numElements)
{
    for (int index = src; index < src + numElements; index++)
    {
        list2[tar] = list1[index];
        tar++;
    }
}

int main()
{
    const int SIZE = 5;
    int myList[SIZE];

    // Example usage of functions
    cout << "Enter " << SIZE << " integers: ";
    fillArray(myList, SIZE);

    cout << "Array elements: ";
    printArray(myList, SIZE);
    cout << endl;

    cout << "Sum of elements: " << sumArray(myList, SIZE) << endl;
    cout << "Index of largest element: " << indexLargestElement(myList, SIZE) << endl;

    return 0;
}