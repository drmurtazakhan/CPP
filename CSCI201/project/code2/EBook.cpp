
#include "EBook.h"
#include <iostream>

EBook::EBook(std::string t, std::string a, Genre g, double size)
    : Book(t,a,g), fileSizeMB(size) {}

void EBook::displayInfo() const {
    Book::displayInfo();
    std::cout << " | Type: EBook | Size: " << fileSizeMB << " MB\n";
}

std::string EBook::getType() const { return "EBook"; }
double EBook::getSize() const { return fileSizeMB; }
