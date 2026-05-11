#pragma once
#include "Validator.h"
#include "Date.h"
#include <string>

template <typename T>
class RangeValidator : public Validator<T> {
public:
    RangeValidator(const T& min, const T& max, const std::string& err)
        : m_minValue(min), m_maxValue(max), m_errorMessage(err) {
    }

    bool isValid(const T& value) const override {
        return (value >= m_minValue && value <= m_maxValue);
    }

    std::string getErrorMessage() const override {
        return m_errorMessage;
    }

private:
    T m_minValue;
    T m_maxValue;
    std::string m_errorMessage;
};

template <>
class RangeValidator<Date> : public Validator<Date> {
public:
    RangeValidator(const Date& min, const Date& max, const std::string& err);

    bool isValid(const Date& value) const override;
    std::string getErrorMessage() const override;

private:
    Date m_minValue;
    Date m_maxValue;
    std::string m_defaultErrorMessage;
    mutable std::string m_currentErrorMessage;
};