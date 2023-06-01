//
// Created by MILEN_PC on 14.5.2023 г..
//

#ifndef PRACTUCUMSEM2_BASICCELL_H
#define PRACTUCUMSEM2_BASICCELL_H
#include <iostream>

class BasicCell {
public:
    virtual void print( std::ostream& os) const = 0;
    virtual double getValue() const = 0;
    virtual int getLength() const = 0;
    virtual ~BasicCell() = default;
    virtual BasicCell* clone() const = 0;
};


#endif //PRACTUCUMSEM2_BASICCELL_H
