#include "HostingTypes.h"

std::string HostingTypes::getValuesAndNames() {
    return "(1 - Breakfast, 2 - Half board, 3 - Full board)";
}

std::string HostingTypes::getName(int value) {
    if (value == 1) return "Breakfast";
    if (value == 2) return "Half board";
    if (value == 3) return "Full board";
    return "Unknown";
}