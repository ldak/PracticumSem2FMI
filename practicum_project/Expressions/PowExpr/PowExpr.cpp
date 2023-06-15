//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "PowExpr.h"

double PowExpr::getValue() const {
    return pow(left->getValue(), right->getValue());
}

int PowExpr::getPriority() const {
    return 3;
}

SharedPtr<BasicExpr> PowExpr::clone() const {
    return SharedPtr<BasicExpr>(new PowExpr(*this));
}
