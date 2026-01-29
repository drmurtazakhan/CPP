#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));
    bool b1;
    for (int i = 0; i < 10; i++)
    {
        b1 = rand() %2;
        cout << "Random boolean value: " << b1 << endl;
    }
    return 0;
}
 
 