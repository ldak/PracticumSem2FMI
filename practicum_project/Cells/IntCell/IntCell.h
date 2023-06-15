//
// Created by MILEN_PC on 24.5.2023 г..
//

#ifndef PRACTUCUMSEM2_INTCELL_H
#define PRACTUCUMSEM2_INTCELL_H


#include "../BasicCell/BasicCell.h"
#include "../../Utils/HelperFunctions/HelperFunctions.h"

class IntCell: public BasicCell{
private:
    int value;
public:
    explicit IntCell(int value);
    int getLength() const override;
    void print(std::ostream &os) const override;
    double getValue() const override;
    SharedPtr<BasicCell> clone() const override;
};


#endif //PRACTUCUMSEM2_INTCELL_H
