//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_POWEXPR_H
#define PRACTUCUMSEM2_POWEXPR_H


#include "../BinaryExpr/BinaryExpr.h"
#include <cmath>

class PowExpr : public BinaryExpr {
public:
    double getValue() const override;
    int getPriority() const override;
    SharedPtr<BasicExpr> clone() const override;
    void print(std::ostream &os) const override;

};


#endif //PRACTUCUMSEM2_POWEXPR_H
