//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "TableParser.h"

std::istream &operator>>(std::istream &in, TableParser &tableParser){
    while(!in.eof()) {
        char buffer[10024];
        in.getline(buffer, 10024);
        std::stringstream ss(buffer);
        Row row;
        ss >> row;
        tableParser.rows.push_back(row);
    }
    tableParser.setFunctionCellRefs();
}

std::ostream &operator<<(std::ostream &out, TableParser &tableParser) {
    for (int i = 0; i < tableParser.rows.size(); ++i) {
        out << tableParser.rows[i] << std::endl;
    }
}

WeakPtr<BasicCell> TableParser::getCell(int i, int j) {
    if (rows.size() <= i || rows[i].size() <= j) {
        return WeakPtr<BasicCell>();
    }
    return WeakPtr<BasicCell>(rows[i][j]);
}

void TableParser::setFunctionCellRefs() {
    CellsFactory* cellsFactory = CellsFactory::getInstance();
    MyVector<WeakPtr<BasicExpr>> cellExprs = cellsFactory->getCellExprToFill();
    for (int i = 0; i < cellExprs.size(); ++i) {
        CellExpr& cellExpr = (CellExpr&)*cellExprs[i];
        cellExpr.setCell(this->getCell(cellExpr.getRow(), cellExpr.getCol()));
    }

}

