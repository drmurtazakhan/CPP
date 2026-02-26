
#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H
#include "Book.h"

class PrintedBook : public Book {
    int pages;
public:
    PrintedBook(std::string t, std::string a, Genre g, int p);
    void displayInfo() const override;
    std::string getType() const override;
    int getPages() const;
};

#endif
