//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "PowExpr.h"

double PowExpr::getValue() const {
    double left = this->left->getValue();
    double right = this->right->getValue();
    return pow(left, right);
}

int PowExpr::getPriority() const {
    return 3;
}

SharedPtr<BasicExpr> PowExpr::clone() const {
    return SharedPtr<BasicExpr>(new PowExpr(*this));
}

void PowExpr::print(std::ostream &os) const {
    this->left->print(os);
    os << " ^ ";
    this->right->print(os);

}
