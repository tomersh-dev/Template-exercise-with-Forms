#pragma once
#include <string>
#include <iostream>

template <typename Traits>
class ValuesToNames {
public:
    ValuesToNames(int val = 0) : m_value(val) {}

    std::string valuesAndNames() const {
        return Traits::getValuesAndNames();
    }

    int getValue() const { return m_value; }

    bool operator>=(const ValuesToNames& other) const { return m_value >= other.m_value; }
    bool operator<=(const ValuesToNames& other) const { return m_value <= other.m_value; }

    std::istream& read(std::istream& is) { return is >> m_value; }
    std::ostream& print(std::ostream& os) const {
        std::string name = Traits::getName(m_value);
        if (name != "Unknown") os << name;
        else os << m_value;
        return os;
    }

private:
    int m_value;
};

template <typename Traits>
std::istream& operator>>(std::istream& is, ValuesToNames<Traits>& obj) { return obj.read(is); }

template <typename Traits>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<Traits>& obj) { return obj.print(os); }