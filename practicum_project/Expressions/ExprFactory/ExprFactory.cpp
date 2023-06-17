//
// Created by MILEN_PC on 15.6.2023 г..
//

#include "ExprFactory.h"
#include "../LiteralExpr/LiteralExpr.h"
#include "../PlusExpr/PlusExpr.h"
#include "../MinusExpr/MinusExpr.h"
#include "../MultiplicationExpr/MultiplicationExpr.h"
#include "../DivisionExpr/DivisionExpr.h"
#include "../PowExpr/PowExpr.h"

ExprFactory* ExprFactory::instance = nullptr;

void ExprFactory::freeInstance() {
    delete instance;
    instance = nullptr;
}

ExprFactory* ExprFactory::getInstance() {
    if (instance == nullptr)
        instance = new ExprFactory();
    return instance;
}

SharedPtr<BasicExpr> ExprFactory::createExpr(const MyString &string) {
    int i = 1;
    while(string[i] == ' ')
        i++;
    SharedPtr<BasicExpr> result = createValueExpr(string, i, i);
    while (i < string.length()) {
        while(string[i] == ' ')
            i++;
        char operation = string[i];
        SharedPtr<BasicExpr> op = createOperationExpr(operation);
        if (result->getPriority() > op->getPriority()){
            op->setLeft(std::move(result));
            result = op;
        }
        else{
            result->setRight(std::move(op));
        }
        i++;
        while(string[i] == ' ')
            i++;
        SharedPtr<BasicExpr> right = createValueExpr(string, i, i);
        result->setRight(std::move(right));
    }

    return result;
}

SharedPtr<BasicExpr> ExprFactory::createValueExpr(const MyString &expr, int start,  int &index) {
    while(expr[index] != ' '
          && expr[index] != '+'
          && expr[index] != '-'
          && expr[index] != '*'
          && expr[index] != '/'
          && expr[index] != '^'
          && index < expr.length())
        index++;

    MyString subString = expr.substr(start, index - start);
    if (subString[0] != 'R') {
        double value = subString.isInt()? subString.toInt() :subString.toDouble();

        return SharedPtr<BasicExpr>(new LiteralExpr(value));
    }
    SharedPtr<BasicExpr> cellExpr = SharedPtr<BasicExpr>(new CellExpr(subString));
    WeakPtr<BasicExpr> weakCellExpr( cellExpr);
    this->cellExprs.push_back(weakCellExpr);

    return cellExpr;
}

SharedPtr<BasicExpr> ExprFactory::createOperationExpr(char operation) {
    switch (operation) {
        case '+':
            return SharedPtr<BasicExpr>(new PlusExpr());
        case '-':
            return SharedPtr<BasicExpr>(new MinusExpr());
        case '*':
            return SharedPtr<BasicExpr>(new MultiplicationExpr());
        case '/':
            return SharedPtr<BasicExpr>(new DivisionExpr());
        case '^':
            return SharedPtr<BasicExpr>(new PowExpr());
        default:
            throw std::invalid_argument("Invalid operation");
    }
}

MyVector<WeakPtr<BasicExpr>> &ExprFactory::getCellExprs() {
    return this->cellExprs;
}
