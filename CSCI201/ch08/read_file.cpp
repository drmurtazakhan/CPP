// File name: read_file.cpp
// compile: g++ read_file.cpp -o read_file.exe
// run: ./read_file.exe

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