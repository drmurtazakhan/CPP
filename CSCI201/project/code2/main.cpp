
#include <iostream>
#include "Library.h"

void menu() {
    std::cout << "\n===== LIBRARY MENU =====\n";
    std::cout << "1. View Books\n";
    std::cout << "2. View Patrons\n";
    std::cout << "3. Checkout Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Search by Author\n";
    std::cout << "6. Exit\n";
}

int main() {
    Library lib;

    try {
        lib.loadBooks();
        lib.loadPatrons();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    int choice;
    do {
        menu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice==1) lib.displayBooks();
        else if (choice==2) lib.displayPatrons();
        else if (choice==3) {
            int id; std::string title;
            std::cout<<"Patron ID: "; std::cin>>id; std::cin.ignore();
            std::cout<<"Title: "; getline(std::cin,title);
            try { lib.checkout(id,title); }
            catch(std::exception& e){ std::cout<<e.what()<<std::endl; }
        }
        else if (choice==4) {
            int id; std::string title;
            std::cout<<"Patron ID: "; std::cin>>id; std::cin.ignore();
            std::cout<<"Title: "; getline(std::cin,title);
            try { lib.returnBook(id,title); }
            catch(std::exception& e){ std::cout<<e.what()<<std::endl; }
        }
        else if (choice==5) {
            std::string author;
            std::cout<<"Author: "; getline(std::cin,author);
            lib.searchByAuthor(author);
        }

    } while (choice!=6);

    lib.saveTransactions();
    return 0;
}
