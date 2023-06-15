//
// Created by MILEN_PC on 1.6.2023 г..
//

#ifndef PRACTUCUMSEM2_FORMULACELL_H
#define PRACTUCUMSEM2_FORMULACELL_H


#include "../BasicCell/BasicCell.h"
#include "../../../Utils/MyVector/MyVector.hpp"

class FormulaCell: BasicCell {
private:
    MyVector<BasicCell*> cells;
public:
    FormulaCell() = default;
    double getValue() const override;
    int getLength() const override;
    void print(std::ostream &os) const override;
    BasicCell * clone() const override;

};


#endif //PRACTUCUMSEM2_FORMULACELL_H
