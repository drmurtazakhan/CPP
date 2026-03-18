// selection_sort_main.cpp
// to compile: g++ selection_sort_main.cpp -o selection_sort_main.exe
// to run: ./selection_sort_main.exe
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

// Standard Selection Sort Implementation
void selectionSort(int a[], int n) {
    // Outer loop: k marks the boundary of the sorted portion 
    for (int k = 0; k < n - 1; ++k) {
        int mi = k; // Assume the first unsorted element is the minimum 

        // Inner loop: find the smallest value in the remaining unsorted part 
        for (int i = k + 1; i < n; ++i) {
            // Fundamental instruction: Comparison [cite: 18, 84]
            if (a[i] < a[mi]) {
                mi = i; // Update index of minimum 
            }
        }

        // Swap the found minimum to its correct position outside the inner loop 
        if (mi != k) {
            int temp = a[k];
            a[k] = a[mi];
            a[mi] = temp;
        }
    }
}

int main() {
    const int n = 500;
    int a[n];

    // Seed for random number generation
    srand(time(0));

    // Generate random array of size 500
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000; // Random numbers between 0-999
    }

    std::cout << "Starting Selection Sort for n = " << n << "..." << std::endl;

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Perform sorting
    selectionSort(a, n);

    // Stop measuring time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // Print sorted array
    std::cout << "Sorted Array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
        if ((i + 1) % 15 == 0) std::cout << std::endl; // New line every 15 elements
    }

    std::cout << "\n\nSorting Time: " << duration.count() << " seconds" << std::endl;

    return 0;
}