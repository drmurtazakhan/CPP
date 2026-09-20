// compile: g++ list_type_methods.cpp -o list_type_methods.exe
// run: ./list_type_methods.exe

#include <iostream>
using namespace std;

class listType
{
private:
    int list[4]; // A simple array inside our class

public:
    listType()
    {
        // Initialize with some default values
        for (int i = 0; i < 4; i++)
            list[i] = 0;
    }

    // Method to insert/update elements by index
    void setAt(int index, int value)
    {
        if (index < 0 || index >= 4)
        {
            cerr << "Index out of bounds!" << endl;
            return;
        }
        list[index] = value;
    }

    // Method to retrieve elements by index
    int getAt(int index) const
    {
        if (index < 0 || index >= 4)
        {
            cerr << "Index out of bounds!" << endl;
            return list[0]; // Return first element as a safety
        }
        return list[index];
    }
};

int main()
{
    listType myData;

    // Writing to the object using setAt()
    myData.setAt(0, 10);
    myData.setAt(1, 20);
    myData.setAt(2, 30);
    myData.setAt(3, 40);

    cout << "Values in myData object:" << endl;
    for (int i = 0; i < 4; i++)
    {
        // Reading from the object using getAt()
        cout << "Index " << i << ": " << myData.getAt(i) << endl;
    }

    return 0;
}