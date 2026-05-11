#include "IdValidator.h"

bool IdValidator::isValid(const uint32_t& value) const {
    std::string idStr = std::to_string(value);
    if (idStr.length() > 9) return false;
    idStr = std::string(9 - idStr.length(), '0') + idStr;

    int sum = 0;
    for (size_t i = 0; i < 9; ++i) {
        int digit = idStr[i] - '0';
        int mult = digit * ((i % 2 == 0) ? 1 : 2);
        sum += (mult > 9) ? (mult - 9) : mult;
    }
    return (sum % 10 == 0);
}

std::string IdValidator::getErrorMessage() const {
    return "Wrong control digit.";
}