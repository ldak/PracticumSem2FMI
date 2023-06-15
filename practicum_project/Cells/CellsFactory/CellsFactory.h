//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_CELLSFACTORY_H
#define PRACTUCUMSEM2_CELLSFACTORY_H


#include "../BasicCell/BasicCell.h"
#include "../../Utils/MyString/MyString.h"
#include "../../Utils/SharedPtr/SharedPtr.hpp"
#include "../../Utils/MyVector/MyVector.hpp"
#include "../../Expressions/ExprFactory/ExprFactory.h"

class CellsFactory {
private:
    static CellsFactory* instance;
    ExprFactory* exprFactory;
    CellsFactory();
public:
    static CellsFactory* getInstance();

    CellsFactory(const CellsFactory&) = delete;
    CellsFactory& operator=(const CellsFactory&) = delete;

    SharedPtr<BasicCell> createCell(const MyString& content);

    MyVector<WeakPtr<BasicExpr>> getCellExprToFill();

    static void freeInstance();
};


#endif //PRACTUCUMSEM2_CELLSFACTORY_H
