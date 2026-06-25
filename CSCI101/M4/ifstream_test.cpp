/*
 * File name: ifstream_test.cpp
 * Compile: g++ ifstream_test.cpp -o ifstream_test.exe
 * Run: ./ifstream_test.exe
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;
    int s1, s2, s3;
    double avg;
    int count = 0;

    inFile.open("scores.txt");

    if (!inFile)
    {
        cout << "Error: Could not open scores.txt" << endl;
        return 1;
    }

    // 1. Prime the loop
    inFile >> s1 >> s2 >> s3;

    // 2. Use a loop that validates the stream state
    // 'while (inFile)' checks if the last read operation was successful.
    while (inFile)
    {
        count++;
        avg = (s1 + s2 + s3) / 3.0;
        cout << "Student " << count << " Avg: " << avg << endl;

        // 3. Attempt the next read
        inFile >> s1 >> s2 >> s3;
    }

    inFile.close();
    cout << "Total students processed: " << count << endl;
    return 0;
}