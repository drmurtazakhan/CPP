
#include "Patron.h"
#include <algorithm>

Patron::Patron(std::string n, int i) : name(n), id(i) {}

int Patron::getId() const { return id; }
std::string Patron::getName() const { return name; }

void Patron::borrow(Book* b) { borrowed.push_back(b); }

void Patron::returnBook(Book* b) {
    borrowed.erase(std::remove(borrowed.begin(), borrowed.end(), b), borrowed.end());
}

void Patron::display() const {
    std::cout << *this << std::endl;
}

bool Patron::operator==(const Patron& other) const {
    return id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Patron& p) {
    os << "ID: " << p.id << " | Name: " << p.name;
    return os;
}
