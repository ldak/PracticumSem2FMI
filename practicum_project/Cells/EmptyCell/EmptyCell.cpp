//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "EmptyCell.h"

void EmptyCell::printExpression(std::ostream &os) const {

}

SharedPtr<BasicCell> EmptyCell::clone() const {
    return new EmptyCell(*this);
}

void EmptyCell::print(std::ostream &os) const {

}

double EmptyCell::getValue() const {
    return 0;
}

int EmptyCell::getLength() const {
    return 0;
}
