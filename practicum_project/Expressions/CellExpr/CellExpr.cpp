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

CellExpr::CellExpr(const MyString &expr) {
    int i = 2;
    while(expr[i] != 'C') {
        i++;
    }
    this->row = expr.substr(1, i).toInt();
    this->col = expr.substr(i + 1, expr.length()).toInt();

}

int CellExpr::getRow() const {
    return this->row;
}

int CellExpr::getCol() const {
    return this->col;
}

void CellExpr::setCell(const WeakPtr<BasicCell> &cell) {
    this->cell = cell;
}
