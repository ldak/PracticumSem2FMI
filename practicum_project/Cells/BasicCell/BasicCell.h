//
// Created by MILEN_PC on 14.5.2023 г..
//

#ifndef PRACTUCUMSEM2_BASICCELL_H
#define PRACTUCUMSEM2_BASICCELL_H
#include <iostream>
#include "../../Utils/SharedPtr/SharedPtr.hpp"

class BasicCell {
public:
    virtual void print( std::ostream& os) const = 0;
    virtual double getValue() const = 0;
    virtual int getLength() const = 0;
    virtual ~BasicCell() = default;
    virtual SharedPtr<BasicCell> clone() const = 0;
    virtual void printExpression(std::ostream& os) const = 0;
};


#endif //PRACTUCUMSEM2_BASICCELL_H
