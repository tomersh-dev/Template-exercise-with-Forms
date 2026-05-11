#pragma once
#include "FormValidator.h"
#include <string>

template <typename VacationFieldType, typename HostingFieldType>
class VacationToHostingValidator : public FormValidator {
public:
    VacationToHostingValidator(VacationFieldType* vacField, HostingFieldType* hostField)
        : vacationField(vacField), hostingField(hostField) {
    }

    bool validate() override {
        if (vacationField->getValue().getValue() == 1 && hostingField->getValue().getValue() == 1) {
            return false;
        }
        return true;
    }

    std::string getErrorMessage() const override {
        return "Weekend vacations must include at least Half Board.";
    }

private:
    VacationFieldType* vacationField;
    HostingFieldType* hostingField;
};