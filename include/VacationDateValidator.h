#pragma once
#include "Validator.h"
#include "Date.h"

class VacationDateValidator : public Validator<Date> {
public:
    VacationDateValidator(const Date& current);
    bool isValid(const Date& value) const override;
    std::string getErrorMessage() const override;

private:
    Date currentDate;
};