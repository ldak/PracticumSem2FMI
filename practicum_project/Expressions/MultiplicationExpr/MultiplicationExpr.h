//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_MULTIPLICATIONEXPR_H
#define PRACTUCUMSEM2_MULTIPLICATIONEXPR_H


#include "../BinaryExpr/BinaryExpr.h"

class MultiplicationExpr : public BinaryExpr{
public:
    double getValue() const override;
    int getPriority() const override;
    SharedPtr<BasicExpr> clone() const override;
};


#endif //PRACTUCUMSEM2_MULTIPLICATIONEXPR_H
