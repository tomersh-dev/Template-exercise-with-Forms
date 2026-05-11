#include "CapacityValidator.h"

CapacityValidator::CapacityValidator(Field<int>* totalPeople, Field<int>* adults, Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms)
    : m_fTotalPeople(totalPeople), m_fAdults(adults), m_fKids(kids), m_fPairRooms(pairRooms), m_fFamilyRooms(familyRooms) {
}

bool CapacityValidator::validate() {
    m_errorMsgs.clear();

    int total = m_fTotalPeople->getValue();
    int adults = m_fAdults->getValue();
    int kids = m_fKids->getValue();
    int pairs = m_fPairRooms->getValue();
    int family = m_fFamilyRooms->getValue();

    bool valid = true;

    if (total != (adults + kids)) {
        m_errorMsgs.push_back("The total number of people does not match the sum of adults and children.");
        valid = false;
    }

    int totalRooms = pairs + family;
    if (totalRooms == 0) {
        m_errorMsgs.push_back("You must book at least one room.");
        valid = false;
    }
    else if (totalRooms > total) {
        m_errorMsgs.push_back("You cannot book more rooms than the total number of people.");
        valid = false;
    }

    int maxCapacity = (pairs * 2) + (family * 5);
    if (maxCapacity < total) {
        m_errorMsgs.push_back("Not enough beds for the requested number of people.");
        valid = false;
    }

    return valid;
}

std::string CapacityValidator::getErrorMessage() const {
    std::string result;
    for (size_t i = 0; i < m_errorMsgs.size(); ++i) {
        result += m_errorMsgs[i];
        if (i < m_errorMsgs.size() - 1) {
            result += "\n";
        }
    }
    return result;
}