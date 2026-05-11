#include "VacationDateValidator.h"

VacationDateValidator::VacationDateValidator(const Date& current) : m_currentDate(current) {}

bool VacationDateValidator::isValid(const Date& value) const {
    std::string dateErr = value.getValidationError();
    if (!dateErr.empty()) {
        m_errorMessage = dateErr;
        return false;
    }

    if (value > m_currentDate && value.getYear() == m_currentDate.getYear()) {
        return true;
    }

    m_errorMessage = "Date must be in the future and within the current year.";
    return false;
}

std::string VacationDateValidator::getErrorMessage() const {
    return m_errorMessage;
}