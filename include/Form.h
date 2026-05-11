#pragma once
#include "BaseField.h"
#include "FormValidator.h"
#include <vector>
#include <iostream>
#include <string>

class Form {
public:
    Form() = default;
    ~Form() = default;

    void addField(BaseField* field);
    void addValidator(FormValidator* validator);

    void fillForm();
    bool validateForm();

    void print(std::ostream& os) const;

private:
    std::vector<BaseField*> fields;
    std::vector<FormValidator*> formValidators;
    std::vector<std::string> formErrors;
};

std::ostream& operator<<(std::ostream& os, const Form& form);