#include "MailValidator.h"
#include <regex>

bool MailValidator::isValid(const std::string& value) const {
    const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(value, pattern);
}

std::string MailValidator::getErrorMessage() const {
    return "Invalid email address format.";
}