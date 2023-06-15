//
// Created by MILEN_PC on 1.6.2023 г..
//

#ifndef PRACTUCUMSEM2_FORMULACELL_H
#define PRACTUCUMSEM2_FORMULACELL_H


#include "../BasicCell/BasicCell.h"
#include "../../Utils/MyVector/MyVector.hpp"
#include "../../Expressions/BasicExpr/BasicExpr.h"
#include <iostream>

class FormulaCell: public BasicCell {
private:
    SharedPtr<BasicExpr> expr;
public:
    FormulaCell() = default;
    FormulaCell(const SharedPtr<BasicExpr> &expr);
    double getValue() const override;
    int getLength() const override;
    void print(std::ostream &os) const override;
    SharedPtr<BasicCell> clone() const override;
    friend std::ostream &operator<<(std::ostream &os, const FormulaCell &cell);
};
std::ostream &operator<<(std::ostream &os, const FormulaCell &cell);

#endif //PRACTUCUMSEM2_FORMULACELL_H
