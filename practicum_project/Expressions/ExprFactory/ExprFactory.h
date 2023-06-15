//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_EXPRFACTORY_H
#define PRACTUCUMSEM2_EXPRFACTORY_H


#include "../../Utils/SharedPtr/SharedPtr.hpp"
#include "../BasicExpr/BasicExpr.h"
#include "../../Utils/MyString/MyString.h"
#include "../CellExpr/CellExpr.h"
#include "../../Utils/MyVector/MyVector.hpp"

class ExprFactory {
private:
    static ExprFactory* instance;
    MyVector<WeakPtr<BasicExpr>> cellExprs;

    ExprFactory() = default;
    SharedPtr<BasicExpr> createValueExpr(const MyString& expr, int start, int &index);
    SharedPtr<BasicExpr> createOperationExpr(char operation);


public:
    ExprFactory(const ExprFactory&) = delete;
    ExprFactory& operator=(const ExprFactory&) = delete;

    static ExprFactory* getInstance();
    SharedPtr<BasicExpr> createExpr(const MyString& expr);
    static void freeInstance();
    MyVector<WeakPtr<BasicExpr>>& getCellExprs();

};


#endif //PRACTUCUMSEM2_EXPRFACTORY_H
