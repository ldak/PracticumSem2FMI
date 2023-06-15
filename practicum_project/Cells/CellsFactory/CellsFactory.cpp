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

    if (string[0] != '=')
        return new StringCell(string);
    ExprFactory* exprFactory = ExprFactory::getInstance();
    SharedPtr<BasicExpr> expr = exprFactory->createExpr(string);

    return new FormulaCell(expr);


    return nullptr;
}

