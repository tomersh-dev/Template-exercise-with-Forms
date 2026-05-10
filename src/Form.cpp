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

std::ostream& operator<<(std::ostream& os, const Form& form) {
    for (const auto* field : form.fields) {
        field->print(os);
        os << '\n';
    }

    if (!form.formErrors.empty()) {
        os << "\n--- Form Validation Errors ---\n";
        for (const auto& err : form.formErrors) {
            os << "! " << err << '\n';
        }
    }
    return os;
}