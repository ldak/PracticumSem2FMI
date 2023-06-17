//
// Created by MILEN_PC on 17.6.2023 г..
//

#ifndef PRACTUCUMSEM2_EMPTYCELL_H
#define PRACTUCUMSEM2_EMPTYCELL_H


#include "../BasicCell/BasicCell.h"

class EmptyCell : public BasicCell {
    void printExpression(std::ostream &os) const override;
    SharedPtr<BasicCell> clone() const override;
    void print(std::ostream &os) const override;
    double getValue() const override;
    int getLength() const override;
};


#endif //PRACTUCUMSEM2_EMPTYCELL_H
