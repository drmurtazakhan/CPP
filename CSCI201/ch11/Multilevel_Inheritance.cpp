#include <iostream>
using namespace std;

// Base class
class Shape {
   public:
      void display() {
         cout << "This is a shape." << endl;
      }
};

// First derived class
class Polygon : public Shape {
   public:
      void sides() {
         cout << "A polygon has multiple sides." << endl;
      }
};

// Second derived class
class Triangle : public Polygon {
   public:
      void type() {
         cout << "A triangle comes under a three-sided polygon." << endl;
      }
};

int main() {
   Triangle myTriangle;

   myTriangle.display();  // From Shape
   myTriangle.sides();    // From Polygon
   myTriangle.type();      // From Triangle

   return 0;
}