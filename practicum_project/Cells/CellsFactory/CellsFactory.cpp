//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "CellsFactory.h"
#include "../IntCell/IntCell.h"
#include "../DoubleCell/DoubleCell.h"
#include "../StringCell/StringCell.h"
#include "../../Expressions/ExprFactory/ExprFactory.h"
#include "../FormulaCell/FormulaCell.h"

CellsFactory* CellsFactory::instance = nullptr;

CellsFactory *CellsFactory::getInstance() {
    if (instance == nullptr){
        instance = new CellsFactory();
    }
    return instance;
}

void CellsFactory::freeInstance() {
    delete instance;
    instance = nullptr;
    ExprFactory::freeInstance();
}

SharedPtr<BasicCell> CellsFactory::createCell(const MyString &content) {
    MyString string = content
            .clearStartWhitespaces()
            .clearEndWhitespaces();
    if (string.isInt())
        return new IntCell(string.toInt());

    if (string.isDouble())
        return new DoubleCell(string.toDouble());

    if (string.isStringLiteral())
        return new StringCell(string.fromStringLiteral());

    if (string[0] == '='){
        try{
            SharedPtr<BasicExpr> expr = exprFactory->createExpr(string);
            return new FormulaCell(expr);
        }catch (std::exception& e){
            MyString error = "Invalid formula expression " + content;
            throw std::invalid_argument(error.c_str());
        }

    }

    MyString error = "Invalid cell content " + content;
    throw std::invalid_argument(error.c_str());
}

CellsFactory::CellsFactory() {
    exprFactory = ExprFactory::getInstance();
}

MyVector<WeakPtr<BasicExpr>> CellsFactory::getCellExprToFill() {
    return this->exprFactory->getCellExprs();
}


