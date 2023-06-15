//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "PlusExpr.h"

int PlusExpr::getPriority() const {
    return 1;
}

double PlusExpr::getValue() const {
    return left->getValue() + right->getValue();
}

SharedPtr<BasicExpr> PlusExpr::clone() const {
    return SharedPtr<BasicExpr>(new PlusExpr(*this));
}

void PlusExpr::print(std::ostream &os) const {
    left->print(os);
    os << "+";
    right->print(os);

}
