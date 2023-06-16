//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "DoubleCell.h"

DoubleCell::DoubleCell(double value) {
    this->value = value;
}

double DoubleCell::getValue() const {
    return this->value;
}

int DoubleCell::getLength() const {
    return HelperFunctions::findLength(this->value);
}

SharedPtr<BasicCell>DoubleCell::clone() const {
    return new DoubleCell(*this);
}

void DoubleCell::print(std::ostream &os) const {
    os << this->value;

}

void DoubleCell::printExpression(std::ostream &os) const {
    os << this->value;
}
