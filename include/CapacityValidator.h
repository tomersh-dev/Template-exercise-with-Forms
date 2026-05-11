#pragma once
#include "FormValidator.h"
#include "Field.h"

class CapacityValidator : public FormValidator {
public:
    CapacityValidator(Field<int>* totalPeople, Field<int>* adults, Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms);

    bool validate() override;
    std::string getErrorMessage() const override;

private:
    Field<int>* fTotalPeople;
    Field<int>* fAdults;
    Field<int>* fKids;
    Field<int>* fPairRooms;
    Field<int>* fFamilyRooms;
    std::string errorMsg;
};