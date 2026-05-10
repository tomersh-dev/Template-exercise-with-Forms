#pragma once
#include <iostream>

class BaseField {
public:
    virtual ~BaseField() = default;
    virtual void fillField() = 0;
    virtual bool validate() = 0;
    virtual bool isValid() const = 0;
    virtual void print(std::ostream& os) const = 0;
};