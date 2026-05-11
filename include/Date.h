#pragma once
#include <iostream>

class Date {
public:
    Date() : year(1970), month(1), day(1) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    Date operator-(int years) const;

    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;

    std::istream& read(std::istream& is);
    std::ostream& print(std::ostream& os) const;

private:
    int year;
    int month;
    int day;
};

std::istream& operator>>(std::istream& is, Date& date);
std::ostream& operator<<(std::ostream& os, const Date& date);