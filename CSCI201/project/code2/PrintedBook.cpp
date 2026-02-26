
#include "PrintedBook.h"
#include <iostream>

PrintedBook::PrintedBook(std::string t, std::string a, Genre g, int p)
    : Book(t,a,g), pages(p) {}

void PrintedBook::displayInfo() const {
    Book::displayInfo();
    std::cout << " | Type: Printed | Pages: " << pages << "\n";
}

std::string PrintedBook::getType() const { return "Printed"; }
int PrintedBook::getPages() const { return pages; }
