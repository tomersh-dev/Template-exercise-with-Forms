#include "Form.h"

void Form::addField(BaseField* field) {
    fields.push_back(field);
}

void Form::addValidator(FormValidator* validator) {
    formValidators.push_back(validator);
}

void Form::fillForm() {
    for (auto* field : fields) {
        if (!field->isValid()) {
            field->fillField();
        }
    }
}

bool Form::validateForm() {
    bool allValid = true;
    formErrors.clear();

    for (auto* field : fields) {
        if (!field->validate()) {
            allValid = false;
        }
    }

    if (!allValid) {
        return false;
    }

    for (auto* formValidator : formValidators) {
        if (!formValidator->validate()) {
            formErrors.push_back(formValidator->getErrorMessage());
            allValid = false;
        }
    }

    return allValid;
}

void Form::print(std::ostream& os) const {
    for (const auto* field : fields) {
        field->print(os);
        os << '\n';
    }

    if (!formErrors.empty()) {
        os << "\n--- Form Validation Errors ---\n";
        for (const auto& err : formErrors) {
            os << "! " << err << '\n';
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    form.print(os);
    return os;
}