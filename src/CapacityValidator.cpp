#include "CapacityValidator.h"

CapacityValidator::CapacityValidator(Field<int>* totalPeople, Field<int>* adults, Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms)
    : fTotalPeople(totalPeople), fAdults(adults), fKids(kids), fPairRooms(pairRooms), fFamilyRooms(familyRooms) {
}

bool CapacityValidator::validate() {
    int total = fTotalPeople->getValue();
    int adults = fAdults->getValue();
    int kids = fKids->getValue();
    int pairs = fPairRooms->getValue();
    int family = fFamilyRooms->getValue();

    if (total != (adults + kids)) {
        errorMsg = "Total people must equal adults + kids.";
        return false;
    }

    int maxCapacity = (pairs * 2) + (family * 5);
    if (total > maxCapacity) {
        errorMsg = "Not enough room capacity for all guests.";
        return false;
    }

    return true;
}

std::string CapacityValidator::getErrorMessage() const {
    return errorMsg;
}