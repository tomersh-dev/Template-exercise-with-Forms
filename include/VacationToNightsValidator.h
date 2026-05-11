#pragma once
#include "FormValidator.h"
#include <string>

template <typename VacationFieldType, typename NightsFieldType>
class VacationToNightsValidator : public FormValidator {
public:
    VacationToNightsValidator(VacationFieldType* vacField, NightsFieldType* nightsField)
        : m_vacationField(vacField), m_numNightsField(nightsField) {
    }

    bool validate() override {
        int vacType = m_vacationField->getValue().getValue();
        int nights = m_numNightsField->getValue();

        if (vacType == 1 && nights < 3) {
            m_errorMessage = "A Weekend vacation requires a minimum of 3 nights.";
            m_vacationField->invalidate("");
            m_numNightsField->invalidate("");
            return false;
        }

        if (vacType == 2 && nights > 5) {
            m_errorMessage = "A Mid-week vacation can be up to 5 nights. For more, please select Weekend.";
            m_vacationField->invalidate("");
            m_numNightsField->invalidate("");
            return false;
        }

        return true;
    }

    std::string getErrorMessage() const override {
        return m_errorMessage;
    }

private:
    VacationFieldType* m_vacationField;
    NightsFieldType* m_numNightsField;
    std::string m_errorMessage;
};