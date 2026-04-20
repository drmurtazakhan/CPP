// Test_Graph_Fig20_6.cpp
// compile: g++ Test_Graph_Fig20_6.cpp -o Test_Graph_Fig20_6.exe
// to run: ./Test_Graph_Fig20_6.exe

#include <iostream>
#include <string>
#include "graphType.h"

using namespace std;

// Suggested file name: main.cpp
int main() {
    graphType myGraph(10);

    // Hardcode the file name here
    myGraph.createGraph("graphFig20-6.txt");

    cout << "Graph representation (Adjacency List):" << endl;
    myGraph.printGraph();

    return 0;
}