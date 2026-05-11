#pragma once
#include "Validator.h"
#include <cstdint>
#include <string>

class IdValidator : public Validator<uint32_t> {
public:
    bool isValid(const uint32_t& value) const override;
    std::string getErrorMessage() const override;
};