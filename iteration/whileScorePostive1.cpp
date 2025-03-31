#include <iostream>
using namespace std;

int main()
{
    short score;
    cout << "Please enter a score: ";
    cin >> score;
    while (score < 0)
    {
        cin.clear();
        cout << "please enter postive score: ";
        cin >> score;
    }
    cout << score;
}