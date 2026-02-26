
#ifndef PATRON_H
#define PATRON_H
#include <vector>
#include <iostream>
#include "Book.h"

class Patron {
    std::string name;
    int id;
    std::vector<Book*> borrowed;
public:
    Patron(std::string n="", int i=0);
    int getId() const;
    std::string getName() const;

    void borrow(Book* b);
    void returnBook(Book* b);
    void display() const;

    bool operator==(const Patron& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Patron& p);
};

#endif
