#pragma once
#include "Validator.h"
#include <string>

class NameValidator : public Validator<std::string> {
public:
    bool isValid(const std::string& value) const override;
    std::string getErrorMessage() const override;
};