//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "IntCell.h"

void IntCell::print(std::ostream &os) const {
    os << this->value;
}

IntCell::IntCell(int value) {
    this->value = value;
}

int IntCell::getLength() const {
    return HelperFunctions::findLength(this->value);
}

double IntCell::getValue() const {
    return this->value;
}

BasicCell *IntCell::clone() const {
    return new IntCell(*this);
}
