//
// Created by MILEN_PC on 14.5.2023 г..
//

#ifndef PRACTUCUMSEM2_BASICCELL_H
#define PRACTUCUMSEM2_BASICCELL_H


class BasicCell {
public:
    virtual void print() const;
    virtual double getValue() const;
    virtual ~BasicCell() = default;
};


#endif //PRACTUCUMSEM2_BASICCELL_H
