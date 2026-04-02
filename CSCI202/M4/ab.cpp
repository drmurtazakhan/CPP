#ifndef H_searchSortAlgorithms
#define H_searchSortAlgorithms

// Forward declarations to ensure the compiler knows these exist 
// regardless of the order they are defined in the file.
template <class elemType>
void swapElements(elemType list[], int first, int second);

template <class elemType>
int minLocation(elemType list[], int first, int last);

template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item)
{
    int loc;
    bool found = false;  
    loc = 0;

    while (loc < length && !found)
        if (list[loc] == item) // Fixed: changed searchItem to item
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

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swapElements(list, loc, minIndex); // Fixed: using swapElements
    }
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