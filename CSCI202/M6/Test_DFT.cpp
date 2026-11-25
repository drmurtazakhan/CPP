// Test_DFT.cpp
// compile: g++ Test_DFT.cpp -o Test_DFT.exe
// to run: ./Test_DFT.exe
#include <iostream>
#include <string>
#include "graphType.h"

using namespace std;


int main() {
    // 1. Initialize graph with capacity for 10 vertices
    graphType myGraph(10);

    // 2. Load the graph using the hardcoded file name
    myGraph.createGraph("graphFig20-6.txt");

    // 3. Print the Adjacency List to show the graph structure
    cout << "--- Graph Adjacency List ---" << endl;
    myGraph.printGraph();

    // 4. Demonstrate Depth First Traversal (DFT)
    // DFT visits nodes by going as deep as possible along each branch
    cout << "--- Depth First Traversal ---" << endl;
    myGraph.depthFirstTraversal();
    cout << endl << endl;

    // 5. Demonstrate DFT of a specific vertex (e.g., vertex 0)
    cout << "--- Depth First Traversal (Starting from Vertex 0) ---" << endl;
    myGraph.dftAtVertex(0);
    cout << endl;

    return 0;
}