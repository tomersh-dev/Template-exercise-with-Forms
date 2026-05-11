#pragma once
#include <string>
#include <iostream>

template <typename Traits>
class ValuesToNames {
public:
    ValuesToNames(int val = 0) : value(val) {}

    std::string valuesAndNames() const {
        return Traits::getValuesAndNames();
    }

    int getValue() const { return value; }

    bool operator>=(const ValuesToNames& other) const { return value >= other.value; }
    bool operator<=(const ValuesToNames& other) const { return value <= other.value; }

    std::istream& read(std::istream& is) { return is >> value; }
    std::ostream& print(std::ostream& os) const {
        std::string name = Traits::getName(value);
        if (name != "Unknown") os << name;
        else os << value;
        return os;
    }

private:
    int value;
};

template <typename Traits>
std::istream& operator>>(std::istream& is, ValuesToNames<Traits>& obj) { return obj.read(is); }

template <typename Traits>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<Traits>& obj) { return obj.print(os); }