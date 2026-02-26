
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

enum class Genre { Fiction, NonFiction, Mystery, Science, Biography };
enum class BookStatus { Available, CheckedOut };

class Book {
protected:
    std::string title;
    std::string author;
    Genre genre;
    BookStatus status;

public:
    Book(std::string t, std::string a, Genre g);
    virtual ~Book() = default;

    virtual void displayInfo() const;
    virtual std::string getType() const = 0;

    std::string getTitle() const;
    std::string getAuthor() const;
    Genre getGenre() const;
    BookStatus getStatus() const;
    void setStatus(BookStatus s);

    bool operator==(const Book& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Book& b);
};

#endif
