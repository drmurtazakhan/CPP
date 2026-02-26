
#include "Book.h"

Book::Book(std::string t, std::string a, Genre g)
    : title(t), author(a), genre(g), status(BookStatus::Available) {}

void Book::displayInfo() const {
    std::cout << *this << std::endl;
}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
Genre Book::getGenre() const { return genre; }
BookStatus Book::getStatus() const { return status; }
void Book::setStatus(BookStatus s) { status = s; }

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author;
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << "Title: " << b.title
       << " | Author: " << b.author
       << " | Status: "
       << (b.status == BookStatus::Available ? "Available" : "Checked Out");
    return os;
}
