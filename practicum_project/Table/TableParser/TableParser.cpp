//
// Created by MILEN_PC on 24.5.2023 г..
//

#include "TableParser.h"

std::istream &operator>>(std::istream &in, TableParser &tableParser){
    while(!in.eof()) {
        char buffer[10024]{'\0'};
        in.getline(buffer, 10024);
        std::stringstream ss(buffer);
        Row row;
        ss >> row;
        tableParser.rows.push_back(row);
    }
    tableParser.setFunctionCellRefs();
    tableParser.setAlignments();
    return in;
}

std::ostream &operator<<(std::ostream &out, TableParser &tableParser) {
    for (int i = 0; i < tableParser.rows.size() - 1; ++i) {
        out << tableParser.rows[i] << std::endl;
    }
    out << tableParser.rows[tableParser.rows.size() - 1];
    return out;
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
        if (cellExprs[i].expired())
            continue;
        CellExpr* cellExpr = static_cast<CellExpr*>(cellExprs[i].get());
        cellExpr->setCell(this->getCell(cellExpr->getRow() - 1, cellExpr->getCol() - 1));
    }

}

void TableParser::setAlignments() {
    this->alignments.clear();
    for (int i = 0; i < rows.size(); ++i) {
        rows[i].setAlignments(this->alignments);
    }
}

void TableParser::print(std::ostream &os) const {
    for (int i = 0; i < this->rows.size(); ++i) {
        this->rows[i].print(os, this->alignments);
        os << std::endl;
    }
}

void TableParser::setCell(int i, int j, const SharedPtr<BasicCell>& cell) {
    if (this->rows.size() <= i || this->rows[i].size() <= j) {
        throw std::out_of_range("Invalid row or column");
    }
    this->rows[i][j] = cell;
    this->setFunctionCellRefs();
    this->setAlignments();
}

