#include "Date.h"
#include <iomanip>

Date Date::operator-(int years) const {
    return Date(year - years, month, day);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

bool Date::operator<=(const Date& other) const {
    return !(*this > other);
}

bool Date::operator>(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}

std::istream& Date::read(std::istream& is) {
    char dash1, dash2;
    int y, m, d;
    if (is >> y >> dash1 >> m >> dash2 >> d) {
        if (dash1 == '-' && dash2 == '-' && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
            year = y; month = m; day = d;
        }
        else {
            is.setstate(std::ios::failbit);
        }
    }
    return is;
}

std::ostream& Date::print(std::ostream& os) const {
    os << std::setfill('0') << std::setw(4) << year << "-"
        << std::setfill('0') << std::setw(2) << month << "-"
        << std::setfill('0') << std::setw(2) << day;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) { return date.read(is); }
std::ostream& operator<<(std::ostream& os, const Date& date) { return date.print(os); }