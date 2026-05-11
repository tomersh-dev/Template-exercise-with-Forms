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
    std::string dateStr;
    if (!(is >> dateStr)) return is;

    m_year = 0; m_month = 0; m_day = 0;

    size_t dash1 = dateStr.find('-');
    if (dash1 != std::string::npos) {
        size_t dash2 = dateStr.find('-', dash1 + 1);
        if (dash2 != std::string::npos) {
            try {
                m_year = std::stoi(dateStr.substr(0, dash1));
                m_month = std::stoi(dateStr.substr(dash1 + 1, dash2 - dash1 - 1));
                m_day = std::stoi(dateStr.substr(dash2 + 1));
            }
            catch (...) {
                // Ignore conversion errors and leave elements 0 to trigger validation errors later
            }
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