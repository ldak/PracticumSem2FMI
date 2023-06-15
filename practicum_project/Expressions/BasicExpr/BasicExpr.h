//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_BASICEXPR_H
#define PRACTUCUMSEM2_BASICEXPR_H


#include "../../Utils/SharedPtr/SharedPtr.hpp"

class BasicExpr {

public:
    virtual int getPriority() const = 0;
    virtual double getValue() const = 0;
    virtual void setLeft(SharedPtr<BasicExpr>&& left) = 0;
    virtual void setRight(SharedPtr<BasicExpr>&& right) = 0;
    virtual ~BasicExpr() = default;
    virtual SharedPtr<BasicExpr> clone() const = 0;
};


#endif //PRACTUCUMSEM2_BASICEXPR_H
