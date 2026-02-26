
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "Date.h"

class Transaction {
    int patronId;
    std::string bookTitle;
    Date date;
public:
    Transaction(int pid, std::string bt);
    std::string toString() const;
};

#endif
