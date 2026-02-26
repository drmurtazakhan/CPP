
#include "Transaction.h"

Transaction::Transaction(int pid, std::string bt)
    : patronId(pid), bookTitle(bt), date(Date::today()) {}

std::string Transaction::toString() const {
    return "PatronID: " + std::to_string(patronId) +
           " | Book: " + bookTitle +
           " | Date: " + date.toString();
}
