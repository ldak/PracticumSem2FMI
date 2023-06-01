//
// Created by MILEN_PC on 24.5.2023 г..
//

#ifndef PRACTUCUMSEM2_DOUBLECELL_H
#define PRACTUCUMSEM2_DOUBLECELL_H


#include "../BasicCell/BasicCell.h"
#include "../../../Utils/HelperFunctions/HelperFunctions.h"

class DoubleCell: public BasicCell {
private:
    double value;
public:
    DoubleCell(double value);

    double getValue() const override;

    void print(std::ostream &os) const override;

    int getLength() const override;

    BasicCell* clone() const override;
};




#endif //PRACTUCUMSEM2_DOUBLECELL_H
