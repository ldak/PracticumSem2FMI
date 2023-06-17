//
// Created by MILEN_PC on 1.6.2023 г..
//

#include "FormulaCell.h"
#include "../../Utils/HelperFunctions/HelperFunctions.h"

double FormulaCell::getValue() const {
    return expr->getValue();
}

int FormulaCell::getLength() const {
    try{
        return HelperFunctions::findLength(this->getValue());
    }catch (std::exception& e){
        return 5; // strlen of "Error"
    }
}

SharedPtr<BasicCell>FormulaCell::clone() const {

    return new FormulaCell(*this);
}

void FormulaCell::print(std::ostream &os) const {
    try {
        os << this->getValue();
    }catch (std::exception &e){
        os << "Error";
    }
}

FormulaCell::FormulaCell(const SharedPtr<BasicExpr> &expr) {
    this->expr = expr;
}


void FormulaCell::printExpression(std::ostream &os) const {
    os << '=';
    expr->print(os);
}
