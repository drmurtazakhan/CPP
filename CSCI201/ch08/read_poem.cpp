// File name: read_poem.cpp
// compile: g++ read_poem.cpp -o read_poem.exe
// run: ./read_poem.exe

#include <iostream>
#include <fstream> // Required for file input/output
#include <string>  // Required for the string data type

using namespace std;

int main()
{
    ifstream inFile; // Declare an input file stream variable
    string line;     // String variable to store each line read from the file

    // Open the input file "poem.txt"
    inFile.open("poem.txt");

    // Check if the file opened successfully
    if (inFile.is_open())
    {
        // Loop to read the file line by line until the end is reached
        // getline reads from the stream into the 'line' variable
        while (getline(inFile, line))
        {
            cout << line << endl; // Display the current line
        }

        // Close the input file after reading
        inFile.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}