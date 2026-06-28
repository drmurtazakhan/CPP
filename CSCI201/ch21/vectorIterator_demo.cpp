// vectorIterator_demo.cpp
// compile with: c
// run with: ./vectorIterator_demo.exe
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Create a vector with sample data
    vector<int> scores = {70, 80, 90, 100};

    // Create the iterator pointing to the start
    vector<int>::iterator it = scores.begin();

    // using a for loop
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << std::endl;

    // Loop until the iterator reaches the end
    while (it != scores.end())
    {
        std::cout << *it << " "; // Access the element using *
        it++;                    // Move to the next element
    }

    return 0;
}