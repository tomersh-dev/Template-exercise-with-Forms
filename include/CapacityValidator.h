#pragma once
#include "FormValidator.h"
#include "Field.h"
#include <vector>
#include <string>

class CapacityValidator : public FormValidator {
public:
    CapacityValidator(Field<int>* totalPeople, Field<int>* adults, Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms);

    bool validate() override;
    std::string getErrorMessage() const override;

private:
    Field<int>* m_fTotalPeople;
    Field<int>* m_fAdults;
    Field<int>* m_fKids;
    Field<int>* m_fPairRooms;
    Field<int>* m_fFamilyRooms;
    std::vector<std::string> m_errorMsgs;
};