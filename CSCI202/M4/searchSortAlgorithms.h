#ifndef H_searchSortAlgorithms
#define H_searchSortAlgorithms

#include <iostream>

using namespace std;

// --- FORWARD DECLARATIONS ---
// These ensure all functions are visible to each other
template <class elemType>
void swapElements(elemType list[], int first, int second);

template <class elemType>
int minLocation(elemType list[], int first, int last);

template <class elemType>
int partition(elemType list[], int first, int last);

template <class elemType>
void recQuickSort(elemType list[], int first, int last);

template <class elemType>
void recMergeSort(elemType list[], int first, int last);

template <class elemType>
void merge(elemType list[], int first, int mid, int last);

template <class elemType>
void heapify(elemType list[], int low, int high);

template <class elemType>
void buildHeap(elemType list[], int length);

// --- SEARCHING ALGORITHMS ---

template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item)
{
    int loc;
    bool found = false;  
    loc = 0;

    while (loc < length && !found)
        if (list[loc] == item) // FIXED: Changed searchItem to item
            found = true;
        else
            loc++;
     
     if (found)
        return loc;
    else
        return -1;
}

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else 
        return -1;
}

// --- SORTING ALGORITHMS ---

template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (list[index] > list[index + 1])
                swapElements(list, index, index + 1);
        }
    }
}

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swapElements(list, loc, minIndex);
    }
}

template <class elemType>
void insertionSort(elemType list[], int length)
{
    int firstOutOfOrder, location;
    elemType temp;

    for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
}

template <class elemType>
void quickSort(elemType list[], int length)
{
    recQuickSort(list, 0, length - 1);
}

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation);
        recQuickSort(list, pivotLocation + 1, last);
    }
}

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;
    int index, smallIndex;

    swapElements(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
    {
        if (list[index] < pivot)
        {
            smallIndex++;
            swapElements(list, smallIndex, index);
        }
    }

    swapElements(list, first, smallIndex);

    return smallIndex;
}

template <class elemType>
void mergeSort(elemType list[], int length)
{
    recMergeSort(list, 0, length - 1);
}

template <class elemType>
void recMergeSort(elemType list[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        recMergeSort(list, first, mid);
        recMergeSort(list, mid + 1, last);
        merge(list, first, mid, last);
    }
}

template <class elemType>
void merge(elemType list[], int first, int mid, int last)
{
    elemType *tempList; 
    int combinedIndex = first;
    int leftIndex = first;
    int rightIndex = mid + 1;

    tempList = new elemType[last + 1];

    while (leftIndex <= mid && rightIndex <= last)
    {
        if (list[leftIndex] <= list[rightIndex])
            tempList[combinedIndex++] = list[leftIndex++];
        else
            tempList[combinedIndex++] = list[rightIndex++];
    }

    while (leftIndex <= mid)
        tempList[combinedIndex++] = list[leftIndex++];

    while (rightIndex <= last)
        tempList[combinedIndex++] = list[rightIndex++];

    for (int i = first; i <= last; i++)
        list[i] = tempList[i];

    delete [] tempList;
}

template <class elemType>
void heapSort(elemType list[], int length)
{
    buildHeap(list, length);

    for (int lastOutOfOrder = length - 1; lastOutOfOrder >= 0; lastOutOfOrder--)
    {
        swapElements(list, 0, lastOutOfOrder);
        heapify(list, 0, lastOutOfOrder - 1);
    }
}

// --- UTILITY FUNCTIONS ---

template <class elemType>
void buildHeap(elemType list[], int length)
{
    for (int index = length / 2 - 1; index >= 0; index--)
        heapify(list, index, length - 1);
}

template <class elemType>
void heapify(elemType list[], int low, int high)
{
    int largeIndex;
    elemType temp = list[low];  

    largeIndex = 2 * low + 1; 

    while (largeIndex <= high)
    {
        if (largeIndex < high)
            if (list[largeIndex] < list[largeIndex + 1])
                largeIndex = largeIndex + 1; 

        if (temp > list[largeIndex])
            break;
        else
        {
            list[low] = list[largeIndex]; 
            low = largeIndex;    
            largeIndex = 2 * low + 1;
        }
    }

    list[low] = temp; 
}

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
}

template <class elemType>
void swapElements(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

#endif