// File name: selection_sort.cpp
// compile: g++ selection_sort.cpp -o selection_sort.exe
// run: ./selection_sort.exe

#include <iostream>

using namespace std;

// Function to sort an integer array using the selection sort algorithm
void selectionSort(int list[], int length)
{
    int index, smallestIndex, location, temp;

    // Outer loop moves the boundary of the sorted/unsorted portion
    for (index = 0; index < length - 1; index++)
    {
        // Step a: Find the index of the smallest element in the unsorted portion
        smallestIndex = index; // Assume the first element is the smallest

        for (location = index + 1; location < length; location++)
            if (list[location] < list[smallestIndex])
                smallestIndex = location; // Update smallestIndex if a smaller element is found

        // Step b: Swap the smallest element with the first element of the unsorted portion
        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;
    }
}

int main()
{
    // Define an unsorted list
    int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};
    int length = 10;

    // Call the selectionSort function
    selectionSort(list, length);

    // Display the sorted list
    cout << "After sorting, the list elements are:" << endl;
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;

    return 0;
}