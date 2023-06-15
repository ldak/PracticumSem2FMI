//
// Created by MILEN_PC on 1.6.2023 г..
//

#include "FormulaCell.h"
#include "../../Utils/HelperFunctions/HelperFunctions.h"

double FormulaCell::getValue() const {
    return expr->getValue();
}

int FormulaCell::getLength() const {
    return HelperFunctions::findLength(this->getValue());
}

SharedPtr<BasicCell>FormulaCell::clone() const {

    return new FormulaCell(*this);
}

void FormulaCell::print(std::ostream &os) const {
    expr->print(os);
//    os << this->getValue();
}

FormulaCell::FormulaCell(const SharedPtr<BasicExpr> &expr) {
    this->expr = expr;
}

std::ostream &operator<<(std::ostream &os, const FormulaCell &cell) {
    os << '=';
    cell.print(os);
    return os;
}
