#pragma once
#include "BaseField.h"
#include "Validator.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>

template <typename T>
class Field : public BaseField {
public:
    explicit Field(const std::string& q) : question(q), valid(false) {}//!!!!!!!!!!!!!!!!

    void addValidator(Validator<T>* validator) {
        validators.push_back(validator);
    }

    void fillField() override {
        if (valid) return;

        std::cout << question << '\n';
        while (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input format. Please try again:\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool validate() override {
        for (auto* validator : validators) {
            if (!validator->isValid(value)) {
                currentError = validator->getErrorMessage();
                valid = false;
                return false;
            }
        }
        currentError = "";
        valid = true;
        return true;
    }

    bool isValid() const override {
        return valid;
    }

    void print(std::ostream& os) const override {
        os << question << " = " << value;
        if (!valid && !currentError.empty()) {
            os << "  ---> Error: " << currentError;
        }
    }

    T getValue() const {
        return value;
    }

    void invalidate(const std::string& errorMsg) {
        valid = false;
        currentError = errorMsg;
    }

private:
    std::string question;
    T value;
    bool valid;
    std::string currentError;
    std::vector<Validator<T>*> validators;

};