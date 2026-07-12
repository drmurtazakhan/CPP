// File name: test_fileio.cpp
// compile: g++ test_fileio.cpp -o test_fileio.exe
// run: ./test_fileio.exe

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // Needed for setting decimal precision

using namespace std;

int main()
{
    // Hardcoded file names as constants
    const string INPUT_FILE = "scores.txt";
    const string OUTPUT_FILE = "scoresOut.txt";

    ifstream infile;
    ofstream outfile;

    // --- 1. OPEN HARDCODED INPUT FILE ---
    infile.open(INPUT_FILE);

    // IF YOU SEE THIS ERROR: Make sure "scores.txt" is placed in the exact
    // same folder where your IDE executes the compiled program!
    if (!infile)
    {
        cout << "=========================================" << endl;
        cout << "ERROR: Could not open '" << INPUT_FILE << "'!" << endl;
        cout << "Please make sure the file exists in this directory." << endl;
        cout << "=========================================" << endl;
        cout << "\nPress Enter to exit...";
        cin.get(); // Keeps the window open so you can read this error
        return 1;
    }

    // --- 2. OPEN HARDCODED OUTPUT FILE ---
    outfile.open(OUTPUT_FILE);

    if (!outfile)
    {
        cout << "Error: Could not create/open " << OUTPUT_FILE << endl;
        infile.close();
        cout << "\nPress Enter to exit...";
        cin.get();
        return 1;
    }

    // Setup both console (cout) and file (outfile) formatting to show 2 decimal places
    cout << fixed << setprecision(2);
    outfile << fixed << setprecision(2);

    // --- 3. PROCESS SCORES, COMPUTE AVERAGES, & DISPLAY/WRITE ---
    double score1, score2, score3;
    int studentCount = 1;

    cout << "Processing data from " << INPUT_FILE << "...\n"
         << endl;
    cout << "--- CONSOLE DISPLAY START ---" << endl;

    // Read 3 scores at a time from the file until the end is reached
    while (infile >> score1 >> score2 >> score3)
    {
        // Calculate the average
        double average = (score1 + score2 + score3) / 3.0;

        // 1. This explicitly prints the results onto your monitor screen
        cout << "Student " << studentCount << " Scores: "
             << (int)score1 << " " << (int)score2 << " " << (int)score3
             << " | Average: " << average << "\n";

        // 2. This writes the exact same data to the output text file
        outfile << "Student " << studentCount << " Scores: "
                << (int)score1 << " " << (int)score2 << " " << (int)score3
                << " | Average: " << average << "\n";

        studentCount++;
    }

    cout << "--- CONSOLE DISPLAY END ---\n"
         << endl;
    cout << "Success! Results have also been automatically saved to " << OUTPUT_FILE << endl;

    // Clean up file streams
    infile.close();
    outfile.close();

    // --- 4. FORCE WINDOW TO STAY OPEN ---
    cout << "\nPress Enter to close this window...";
    cin.clear();  // Clear any error flags
    cin.ignore(); // Discard any leftover characters in the input buffer
    cin.get();    // Freeze the program and wait for you to hit Enter

    return 0;
}