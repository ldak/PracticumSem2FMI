//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_CELLEXPR_H
#define PRACTUCUMSEM2_CELLEXPR_H


#include "../../Cells/BasicCell/BasicCell.h"
#include "../../Utils/WeakPtr/WeakPtr.hpp"
#include "../ValueExpr/ValueExpr.h"
#include "../../Utils/MyString/MyString.h"

class CellExpr: public ValueExpr{
private:
    int row;
    int col;
    WeakPtr<BasicCell> cell;
public:
    int getRow() const;
    int getCol() const;
    void setCell(const WeakPtr<BasicCell>& cell);

    CellExpr(const MyString& expr);
    double getValue() const override;
    SharedPtr<BasicExpr> clone() const override;
};


#endif //PRACTUCUMSEM2_CELLEXPR_H
