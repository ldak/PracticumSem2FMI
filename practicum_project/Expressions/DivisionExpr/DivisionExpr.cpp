//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "DivisionExpr.h"

double DivisionExpr::getValue() const {
    return left->getValue() / right->getValue();
}

int DivisionExpr::getPriority() const {
    return 2;
}

SharedPtr<BasicExpr> DivisionExpr::clone() const {
    return new DivisionExpr(*this);
}
