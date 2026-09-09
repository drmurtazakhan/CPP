// compile: g++ DeepCopyAssignmentOverload.cpp -o DeepCopyAssignmentOverload.exe
// run: ./DeepCopyAssignmentOverload.exe

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class ptrMemberVarType
{
public:
    ptrMemberVarType(int valX = 8, int length = 50)
    {
        x = valX;
        lenP = length;
        p = new int[lenP];
        p[0] = 5;
        p[1] = 36;
        p[2] = 24;
        p[3] = 15;
    }

    // Copy Constructor
    ptrMemberVarType(const ptrMemberVarType &otherObject)
    {
        x = otherObject.x;
        lenP = otherObject.lenP;
        p = new int[lenP];
        for (int i = 0; i < lenP; i++)
        {
            p[i] = otherObject.p[i];
        }
    }

    // Overloaded Assignment Operator (Copy-and-Swap)
    ptrMemberVarType &operator=(ptrMemberVarType rightObject)
    {
        swap(x, rightObject.x);
        swap(lenP, rightObject.lenP);
        swap(p, rightObject.p);
        return *this;
    }

    ~ptrMemberVarType()
    {
        delete[] p;
    }

    void copyAndCompare()
    {
        x = 99;
        lenP = 100;
        p[0] = 77;
    }

    void print(string objName) const
    {
        cout << objName << ":" << endl;
        cout << "  x = " << x << ", lenP = " << lenP << endl;
        cout << "  Pointer p points to address: " << p << endl;
        cout << "  First four values in p: " << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    }

private:
    int x;
    int lenP;
    int *p;
};

int main()
{
    ptrMemberVarType objectOne(8, 50);

    // Direct initialization (triggers Copy Constructor directly)
    ptrMemberVarType objectTwo = objectOne;

    // Calling copyAndCompare on objectTwo
    objectTwo.copyAndCompare();

    cout << "--- Verification of Deep Copy ---" << endl;
    objectOne.print("objectOne"); // Unaffected
    cout << endl;
    objectTwo.print("objectTwo"); // Modified independently

    return 0;
}