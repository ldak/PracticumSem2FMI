//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "MinusExpr.h"

int MinusExpr::getPriority() const {
    return 1;
}

double MinusExpr::getValue() const {
    return left->getValue() - right->getValue();
}

SharedPtr<BasicExpr> MinusExpr::clone() const {
    return new MinusExpr(*this);
}
