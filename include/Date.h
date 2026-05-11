#pragma once
#include <iostream>
#include <string>

class Date {
public:
    Date() : m_year(0), m_month(0), m_day(0) {}
    Date(int y, int m, int d) : m_year(y), m_month(m), m_day(d) {}

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }

    Date operator-(int years) const;

    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;

    std::string getValidationError() const;

    std::istream& read(std::istream& is);
    std::ostream& print(std::ostream& os) const;

private:
    int m_year;
    int m_month;
    int m_day;
};

std::istream& operator>>(std::istream& is, Date& date);
std::ostream& operator<<(std::ostream& os, const Date& date);