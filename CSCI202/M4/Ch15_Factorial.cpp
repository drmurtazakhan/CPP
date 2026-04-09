//Chapter 15: Factorial
// compile with: g++   Ch15_Factorial.cpp -o Ch15_Factorial.exe
// run with: ./Ch15_Factorial.exe
#include <iostream> 

using namespace std;
 
int  fact(int num);

int main()
{ 
    cout << "Factorial of 3 = " << fact(3) << endl;
    cout << "Factorial of 10 = " << fact(10) << endl;

    return 0;
}

int fact(int num) 
{
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}
