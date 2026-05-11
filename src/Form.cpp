#include "Form.h"

void Form::addField(BaseField* field) {
    m_fields.push_back(field);
}

void Form::addValidator(FormValidator* validator) {
    m_formValidators.push_back(validator);
}

void Form::fillForm() {
    for (auto* field : m_fields) {
        if (!field->isValid()) {
            field->fillField();
        }
    }
}

bool Form::validateForm() {
    bool allValid = true;
    m_formErrors.clear();

    for (auto* field : m_fields) {
        if (!field->validate()) {
            allValid = false;
        }
    }

    if (!allValid) {
        return false;
    }

    for (auto* formValidator : m_formValidators) {
        if (!formValidator->validate()) {
            m_formErrors.push_back(formValidator->getErrorMessage());
            allValid = false;
        }
    }

    return allValid;
}

void Form::print(std::ostream& os) const {
    if (!m_formErrors.empty()) {
        for (const auto& err : m_formErrors) {
            os << err << '\n';
        }
    }

    os << "--------------------------------------------------------------------------------\n";
    for (const auto* field : m_fields) {
        field->print(os);
        os << '\n';
        os << "--------------------------------------------------------------------------------\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    form.print(os);
    return os;
}