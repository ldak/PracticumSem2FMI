//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "ValueExpr.h"

void ValueExpr::setLeft(SharedPtr<BasicExpr> &&left) {
    throw std::runtime_error("ValueExpr has no left child");
}

void ValueExpr::setRight(SharedPtr<BasicExpr> &&right) {
    throw std::runtime_error("ValueExpr has no right child");
}

int ValueExpr::getPriority() const {
    return 4;
}
