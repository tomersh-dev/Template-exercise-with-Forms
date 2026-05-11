#pragma once
#include "FormValidator.h"
#include <string>

template <typename VacationFieldType, typename HostingFieldType>
class VacationToHostingValidator : public FormValidator {
public:
    VacationToHostingValidator(VacationFieldType* vacField, HostingFieldType* hostField)
        : m_vacationField(vacField), m_hostingField(hostField) {
    }

    bool validate() override {
        if (!m_vacationField->isValid() || !m_hostingField->isValid()) {
            return true;
        }

        if (m_vacationField->getValue().getValue() == 1 && m_hostingField->getValue().getValue() == 1) {
            m_vacationField->invalidate("");
            m_hostingField->invalidate("");
            return false;
        }
        return true;
    }

    std::string getErrorMessage() const override {
        return "Weekend vacation cannot be 'Breakfast' only.";
    }

private:
    VacationFieldType* m_vacationField;
    HostingFieldType* m_hostingField;
};