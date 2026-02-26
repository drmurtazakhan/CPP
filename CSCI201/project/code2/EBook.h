
#ifndef EBOOK_H
#define EBOOK_H
#include "Book.h"

class EBook : public Book {
    double fileSizeMB;
public:
    EBook(std::string t, std::string a, Genre g, double size);
    void displayInfo() const override;
    std::string getType() const override;
    double getSize() const;
};

#endif
