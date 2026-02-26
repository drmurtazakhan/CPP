
#include "Library.h"
#include <sstream>

void Library::loadBooks() {
    std::ifstream file("books.txt");
    if (!file) throw std::runtime_error("books.txt missing");

    std::string line;
    while (getline(file,line)) {
        std::stringstream ss(line);
        std::string genreStr,title,author,type,extra;
        getline(ss,genreStr,',');
        getline(ss,title,',');
        getline(ss,author,',');
        getline(ss,type,',');
        getline(ss,extra,',');

        Genre g = Genre::Fiction;
        if (genreStr=="Science") g=Genre::Science;
        else if (genreStr=="Mystery") g=Genre::Mystery;
        else if (genreStr=="Biography") g=Genre::Biography;
        else if (genreStr=="NonFiction") g=Genre::NonFiction;

        if (type=="Printed")
            books.push_back(std::make_unique<PrintedBook>(title,author,g,std::stoi(extra)));
        else
            books.push_back(std::make_unique<EBook>(title,author,g,std::stod(extra)));
    }
}

void Library::loadPatrons() {
    std::ifstream file("patrons.txt");
    if (!file) throw std::runtime_error("patrons.txt missing");

    std::string line;
    while (getline(file,line)) {
        std::stringstream ss(line);
        std::string id,name;
        getline(ss,id,',');
        getline(ss,name,',');
        patrons.emplace_back(name,std::stoi(id));
    }
}

void Library::saveTransactions() {
    std::ofstream file("transactions.txt");
    for (auto& t : transactions)
        file << t.toString() << "\n";
}

void Library::addBook(std::unique_ptr<Book> b) {
    books.push_back(std::move(b));
}

void Library::addPatron(const Patron& p) {
    patrons.push_back(p);
}

void Library::displayBooks() const {
    for (const auto& b : books)
        b->displayInfo();
}

void Library::displayPatrons() const {
    for (const auto& p : patrons)
        p.display();
}

void Library::searchByAuthor(const std::string& author) const {
    for (const auto& b : books)
        if (b->getAuthor()==author)
            b->displayInfo();
}

void Library::searchByGenre(Genre g) const {
    for (const auto& b : books)
        if (b->getGenre()==g)
            b->displayInfo();
}

void Library::checkout(int patronId, const std::string& title) {
    for (auto& p : patrons)
        if (p.getId()==patronId)
            for (auto& b : books)
                if (b->getTitle()==title && b->getStatus()==BookStatus::Available) {
                    b->setStatus(BookStatus::CheckedOut);
                    p.borrow(b.get());
                    transactions.emplace_back(patronId,title);
                    return;
                }
    throw std::runtime_error("Checkout failed.");
}

void Library::returnBook(int patronId, const std::string& title) {
    for (auto& p : patrons)
        if (p.getId()==patronId)
            for (auto& b : books)
                if (b->getTitle()==title) {
                    b->setStatus(BookStatus::Available);
                    p.returnBook(b.get());
                    return;
                }
    throw std::runtime_error("Return failed.");
}
