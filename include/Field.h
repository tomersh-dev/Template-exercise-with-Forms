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
    explicit Field(const std::string& q) : m_question(q), m_valid(false) {}

    void addValidator(Validator<T>* validator) {
        m_validators.push_back(validator);
    }

    void fillField() override {
        if (m_valid) return;

        std::cout << m_question << '\n';
        while (!(std::cin >> m_value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input format. Please try again:\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool validate() override {
        for (auto* validator : m_validators) {
            if (!validator->isValid(m_value)) {
                m_currentError = validator->getErrorMessage();
                m_valid = false;
                return false;
            }
        }
        m_currentError = "";
        m_valid = true;
        return true;
    }

    bool isValid() const override {
        return m_valid;
    }

    void print(std::ostream& os) const override {
        os << m_question << " = " << m_value;
        if (!m_valid && !m_currentError.empty()) {
            os << "\nError: " << m_currentError;
        }
    }

    T getValue() const {
        return m_value;
    }

    void invalidate(const std::string& errorMsg) {
        m_valid = false;
        m_currentError = errorMsg;
    }

private:
    std::string m_question;
    T m_value;
    bool m_valid;
    std::string m_currentError;
    std::vector<Validator<T>*> m_validators;
};