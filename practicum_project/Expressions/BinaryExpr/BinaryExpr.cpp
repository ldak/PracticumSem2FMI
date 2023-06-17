//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "BinaryExpr.h"


void BinaryExpr::setLeft(SharedPtr<BasicExpr>&& left) {
    this->left = std::move(left);
}

void BinaryExpr::setRight(SharedPtr<BasicExpr> &&right) {
    if (!this->right.exists()){
        this->right = std::move(right);
        return;
    }
    if (this->right->getPriority() >= right->getPriority()){
        right->setLeft(std::move(this->right));
        this->right = right;
        return;
    }
    this->right->setRight(std::move(right));
}
