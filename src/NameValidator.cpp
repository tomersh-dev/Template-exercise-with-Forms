#include "NameValidator.h"
#include <cctype>

bool NameValidator::isValid(const std::string& value) const {
    if (value.length() < 3) return false;
    for (char c : value) {
        if (std::isdigit(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

std::string NameValidator::getErrorMessage() const {
    return "Name cannot contain digits and must be at least 3 characters long.";
}