// File name: classIllusFriend_demo.cpp
#include <iostream>
using namespace std;

class classIllusFriend {
    // Granting permission to the outside function 'two'
    friend void two(classIllusFriend &cObj); 

public:
    classIllusFriend(int a = 0, int b = 0) : x(a), y(b) {}

    void print() const {
        cout << "Current values: x = " << x << ", y = " << y << endl;
    }

private:
    int x;
    int y;
};

// The friend function definition
// Note: I added '&' (pass by reference) so the changes stay permanent!
void two(classIllusFriend &cObj) {
    cObj.x = cObj.x * 2; // Changing x
    cObj.y = cObj.y * 2; // Changing y
    
    cout << "...Friend function 'two' has modified the data..." << endl;
}

int main() {
    // 1. Create the object
    classIllusFriend myObject(5, 7);

    // 2. Print initial values
    cout << "Before calling two:" << endl;
    myObject.print();

    // 3. Call the friend function
    two(myObject);

    // 4. Print values again to see the change
    cout << "After calling two:" << endl;
    myObject.print();

    return 0;
}