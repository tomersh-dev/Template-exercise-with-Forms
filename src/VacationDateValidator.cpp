#include "VacationDateValidator.h"

VacationDateValidator::VacationDateValidator(const Date& current) : currentDate(current) {}

bool VacationDateValidator::isValid(const Date& value) const {
    return (value > currentDate) && (value.getYear() == currentDate.getYear());
}

std::string VacationDateValidator::getErrorMessage() const {
    return "Vacation date must be strictly in the future and within the current calendar year.";
}