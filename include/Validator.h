#pragma once
#include <string>

template <typename T>
class Validator {
public:
    virtual ~Validator() = default;
    virtual bool isValid(const T& value) const = 0;
    virtual std::string getErrorMessage() const = 0;
};