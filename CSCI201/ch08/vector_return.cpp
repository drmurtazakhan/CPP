// compile: g++ vector_return.cpp -o vector_return.exe
// run: ./vector_return.exe

#include <iostream>
#include <vector>

using namespace std;

vector<int> createVector(int size)
{
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        vec[i] = (i + 1) * 10;
    }
    return vec;
}

int main()
{
    vector<int> myVec = createVector(5);
    for (int val : myVec)
    {
        cout << val << " ";
    }
    return 0;
}