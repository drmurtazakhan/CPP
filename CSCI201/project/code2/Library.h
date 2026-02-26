
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
#include "PrintedBook.h"
#include "EBook.h"
#include "Patron.h"
#include "Transaction.h"

class Library {
    std::vector<std::unique_ptr<Book>> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;

public:
    void loadBooks();
    void loadPatrons();
    void saveTransactions();

    void addBook(std::unique_ptr<Book> b);
    void addPatron(const Patron& p);

    void displayBooks() const;
    void displayPatrons() const;

    void searchByAuthor(const std::string& author) const;
    void searchByGenre(Genre g) const;

    void checkout(int patronId, const std::string& title);
    void returnBook(int patronId, const std::string& title);
};

#endif
