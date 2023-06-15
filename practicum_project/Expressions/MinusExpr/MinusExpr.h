//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_MINUSEXPR_H
#define PRACTUCUMSEM2_MINUSEXPR_H


#include "../BinaryExpr/BinaryExpr.h"

class MinusExpr : public BinaryExpr{
public:
    int getPriority() const override;
    double getValue() const override;
    SharedPtr<BasicExpr> clone() const override;
};


#endif //PRACTUCUMSEM2_MINUSEXPR_H
