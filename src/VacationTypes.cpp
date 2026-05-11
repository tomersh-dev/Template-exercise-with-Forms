#include "VacationTypes.h"

std::string VacationTypes::getValuesAndNames() {
    return "(1 - Weekend, 2 - Mid-week)";
}

std::string VacationTypes::getName(int value) {
    if (value == 1) return "Weekend";
    if (value == 2) return "Mid-week";
    return "Unknown";
}