
#include "Date.h"
#include <sstream>

Date::Date() {
    Date t = today();
    day = t.day;
    month = t.month;
    year = t.year;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date Date::today() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << day << "/" << month << "/" << year;
    return ss.str();
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}
