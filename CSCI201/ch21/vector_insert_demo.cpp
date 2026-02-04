#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int scoresArray[] = {70, 80, 90, 100};

    // Initialize vector using array data
    vector<int> scoreList(scoresArray, scoresArray + 4);

    vector<int>::iterator it;

    // Print the list before the update
    cout << "Original Scores: ";
    for (it = scoreList.begin(); it != scoreList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Point to the beginning and move to the second position
    it = scoreList.begin();
    ++it;

    // Insert the new value
    scoreList.insert(it, 85);

    // Print the list after the update
    cout << "Updated Scores:  ";
    for (it = scoreList.begin(); it != scoreList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}