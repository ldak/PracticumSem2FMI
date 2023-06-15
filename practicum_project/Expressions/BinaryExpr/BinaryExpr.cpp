//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "BinaryExpr.h"


void BinaryExpr::setLeft(SharedPtr<BasicExpr>&& left) {
    this->left = std::move(left);
}

void BinaryExpr::setRight(SharedPtr<BasicExpr> &&right) {
    this->right = std::move(right);
}
