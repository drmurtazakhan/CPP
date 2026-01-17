#include <iostream>
#include <string>
using namespace std;

class Color {
    string name;
public:
    Color(string n) : name(n) {}
    string getName() { return name; }
};

class Wall {
private:
    // Simple data types
    int height;
    int width;
    
    // Complex object (Composition)
    Color wallColor; 

public:
    // We add 'w' for width to the parameter list
    Wall(int h, int w, string c) : height(h), width(w), wallColor(c) {
        // The initializer list above handles everything!
    }

    void displayDetails() {
        cout << "Wall Dimensions: " << width << "ft wide x " << height << "ft high." << endl;
        cout << "Wall Color: " << wallColor.getName() << endl;
        cout << "Total Surface Area: " << (width * height) << " sq ft." << endl;
    }
};

int main() {
    // Now we pass three arguments: height, width, and color
    Wall gardenWall(10, 25, "Seashell White");

    gardenWall.displayDetails();

    return 0;
}