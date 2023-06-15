//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_BINARYEXPR_H
#define PRACTUCUMSEM2_BINARYEXPR_H


#include "../BasicExpr/BasicExpr.h"

class BinaryExpr : public BasicExpr {
protected:
    SharedPtr<BasicExpr> left;
    SharedPtr<BasicExpr> right;
public:
    void setLeft(SharedPtr<BasicExpr>&& left) override;
    void setRight(SharedPtr<BasicExpr>&& right) override;
};


#endif //PRACTUCUMSEM2_BINARYEXPR_H
