//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_EXPRFACTORY_H
#define PRACTUCUMSEM2_EXPRFACTORY_H


#include "../../Utils/SharedPtr/SharedPtr.hpp"
#include "../BasicExpr/BasicExpr.h"
#include "../../Utils/MyString/MyString.h"
#include "../CellExpr/CellExpr.h"

class ExprFactory {
private:
    static ExprFactory* instance;
    ExprFactory() = default;
    SharedPtr<BasicExpr> createValueExpr(const MyString& expr, int &index);
    SharedPtr<BasicExpr> createOperationExpr(char operation);


public:
    static ExprFactory* getInstance();
    SharedPtr<BasicExpr> createExpr(const MyString& expr);
    static void freeInstance();

};


#endif //PRACTUCUMSEM2_EXPRFACTORY_H
