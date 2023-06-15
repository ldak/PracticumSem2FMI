//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_DIVISIONEXPR_H
#define PRACTUCUMSEM2_DIVISIONEXPR_H


#include "../BinaryExpr/BinaryExpr.h"

class DivisionExpr : public BinaryExpr{

public:
    double getValue() const override;
    int getPriority() const override;
    SharedPtr<BasicExpr> clone() const override;
    void print(std::ostream &os) const override;
};


#endif //PRACTUCUMSEM2_DIVISIONEXPR_H
