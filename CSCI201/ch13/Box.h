// File name: Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>

template <class T>
class Box {
private:
    T data;
public:
    Box(T d) : data(d) {} // Definition inside class is easy!
    
    void show() { 
        std::cout << "Data: " << data << std::endl; 
    }
};
#endif