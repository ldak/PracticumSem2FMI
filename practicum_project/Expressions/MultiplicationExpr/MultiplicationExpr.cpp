//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "MultiplicationExpr.h"

double MultiplicationExpr::getValue() const {
    return left->getValue() * right->getValue();
}

int MultiplicationExpr::getPriority() const {
    return 2;
}

SharedPtr<BasicExpr> MultiplicationExpr::clone() const {
    return SharedPtr<BasicExpr>(new MultiplicationExpr(*this));
}
