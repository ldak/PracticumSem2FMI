//
// Created by MILEN_PC on 1.6.2023 г..
//

#include "FormulaCell.h"

double FormulaCell::getValue() const {
    return 0;
}

int FormulaCell::getLength() const {
    return 0;
}

SharedPtr<BasicCell>FormulaCell::clone() const {

    return new FormulaCell(*this);
}

void FormulaCell::print(std::ostream &os) const {


}

FormulaCell::FormulaCell(const SharedPtr<BasicExpr> &expr) {
    this->expr = expr;
}
