#include "Date.h"
#include <iomanip>

Date Date::operator-(int years) const {
    return Date(m_year - years, m_month, m_day);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

bool Date::operator<=(const Date& other) const {
    return !(*this > other);
}

bool Date::operator>(const Date& other) const {
    if (m_year != other.m_year) return m_year > other.m_year;
    if (m_month != other.m_month) return m_month > other.m_month;
    return m_day > other.m_day;
}

bool Date::operator<(const Date& other) const {
    if (m_year != other.m_year) return m_year < other.m_year;
    if (m_month != other.m_month) return m_month < other.m_month;
    return m_day < other.m_day;
}

bool Date::operator==(const Date& other) const {
    return m_year == other.m_year && m_month == other.m_month && m_day == other.m_day;
}

std::string Date::getValidationError() const {
    if (m_year < 1) return "Date cannot be empty.";
    if (m_month < 1 || m_month > 12) return "Month must be between 1 and 12.";
    if (m_day < 1 || m_day > 31) return "Day must be between 1 and 31.";
    return "";
}

std::istream& Date::read(std::istream& is) {
    int y = 0, m = 0, d = 0;
    char dash1 = 0, dash2 = 0;

    if (is >> y >> dash1 >> m >> dash2 >> d) {
        if (dash1 == '-' && dash2 == '-') {
            m_year = y;
            m_month = m;
            m_day = d;
        }
        else {
            is.setstate(std::ios::failbit);
        }
    }
    return is;
}

std::ostream& Date::print(std::ostream& os) const {
    os << std::setfill('0') << std::setw(4) << m_year << "-"
        << std::setfill('0') << std::setw(2) << m_month << "-"
        << std::setfill('0') << std::setw(2) << m_day;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) { return date.read(is); }
std::ostream& operator<<(std::ostream& os, const Date& date) { return date.print(os); }