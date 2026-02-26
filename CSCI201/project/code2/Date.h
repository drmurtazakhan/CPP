
#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>

class Date {
    int day, month, year;

public:
    Date();
    Date(int d, int m, int y);

    static Date today();
    std::string toString() const;

    bool operator<(const Date& other) const;
};

#endif
