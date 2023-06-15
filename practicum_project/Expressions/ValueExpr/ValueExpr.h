//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_VALUEEXPR_H
#define PRACTUCUMSEM2_VALUEEXPR_H


#include "../BasicExpr/BasicExpr.h"

class ValueExpr : public BasicExpr{

public:
    void setLeft(SharedPtr<BasicExpr> &&left) override;
    void setRight(SharedPtr<BasicExpr> &&right) override;
    int getPriority() const override;
};


#endif //PRACTUCUMSEM2_VALUEEXPR_H
