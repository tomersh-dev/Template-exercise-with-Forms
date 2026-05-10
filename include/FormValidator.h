#pragma once
#include <string>

class FormValidator {
public:
    virtual ~FormValidator() = default;
    virtual bool validate() = 0;
    virtual std::string getErrorMessage() const = 0;
};