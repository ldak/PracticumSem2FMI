//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "CellExpr.h"

double CellExpr::getValue() const {
    if (cell.expired())
        return 0;
    return cell->getValue();
}

SharedPtr<BasicExpr> CellExpr::clone() const {
    return new CellExpr(*this);
}
