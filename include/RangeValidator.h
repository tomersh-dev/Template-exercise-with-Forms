#pragma once
#include "Validator.h"
#include <string>

template <typename T>
class RangeValidator : public Validator<T> {
public:
    RangeValidator(const T& min, const T& max, const std::string& err)
        : minValue(min), maxValue(max), errorMessage(err) {
    }

    bool isValid(const T& value) const override {
        return (value >= minValue && value <= maxValue);
    }

    std::string getErrorMessage() const override {
        return errorMessage;
    }

private:
    T minValue;
    T maxValue;
    std::string errorMessage;
};