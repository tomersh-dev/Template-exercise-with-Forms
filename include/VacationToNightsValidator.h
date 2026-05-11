#pragma once
#include "FormValidator.h"
#include <string>

template <typename VacationFieldType, typename NightsFieldType>
class VacationToNightsValidator : public FormValidator {
public:
    VacationToNightsValidator(VacationFieldType* vacField, NightsFieldType* nightsField)
        : vacationField(vacField), numNightsField(nightsField) {
    }

    bool validate() override {
        if (vacationField->getValue().getValue() == 1 && numNightsField->getValue() > 3) {
            return false;
        }
        return true;
    }

    std::string getErrorMessage() const override {
        return "Weekend vacations cannot be longer than 3 nights.";
    }

private:
    VacationFieldType* vacationField;
    NightsFieldType* numNightsField;
};