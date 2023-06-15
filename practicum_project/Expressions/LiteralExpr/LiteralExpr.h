//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_LITERALEXPR_H
#define PRACTUCUMSEM2_LITERALEXPR_H


#include "../ValueExpr/ValueExpr.h"

class LiteralExpr : public ValueExpr{

private:
    double value;
public:
    explicit LiteralExpr(double value);

    double getValue() const override;
    SharedPtr<BasicExpr> clone() const override;
    void print(std::ostream &os) const override;
};


#endif //PRACTUCUMSEM2_LITERALEXPR_H
