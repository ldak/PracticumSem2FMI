//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "LiteralExpr.h"

LiteralExpr::LiteralExpr(double value) {
    this->value = value;

}

double LiteralExpr::getValue() const {
    return this->value;
}

SharedPtr<BasicExpr> LiteralExpr::clone() const {
    return new LiteralExpr(*this);
}
