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
    std::vector<BaseField*> m_fields;
    std::vector<FormValidator*> m_formValidators;
    std::vector<std::string> m_formErrors;
};

std::ostream& operator<<(std::ostream& os, const Form& form);