#include "RangeValidator.h"

RangeValidator<Date>::RangeValidator(const Date& min, const Date& max, const std::string& err)
    : m_minValue(min), m_maxValue(max), m_defaultErrorMessage(err) {
}

bool RangeValidator<Date>::isValid(const Date& value) const {
    std::string dateErr = value.getValidationError();

    if (!dateErr.empty()) {
        m_currentErrorMessage = dateErr;
        return false;
    }

    if (value >= m_minValue && value <= m_maxValue) {
        return true;
    }

    m_currentErrorMessage = m_defaultErrorMessage;
    return false;
}

std::string RangeValidator<Date>::getErrorMessage() const {
    return m_currentErrorMessage;
}