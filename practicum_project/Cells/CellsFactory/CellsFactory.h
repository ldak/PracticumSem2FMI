//
// Created by MILEN_PC on 15.6.2023 г..
//

#ifndef PRACTUCUMSEM2_CELLSFACTORY_H
#define PRACTUCUMSEM2_CELLSFACTORY_H


#include "../BasicCell/BasicCell.h"
#include "../../Utils/MyString/MyString.h"
#include "../../Utils/SharedPtr/SharedPtr.hpp"
#include "../../Utils/MyVector/MyVector.hpp"

class CellsFactory {
private:
    static CellsFactory* instance;
    MyVector<SharedPtr<BasicCell>> cells;
    CellsFactory() = default;
public:
    static CellsFactory* getInstance();

    SharedPtr<BasicCell> createCell(const MyString& content);

    static void freeInstance();
};


#endif //PRACTUCUMSEM2_CELLSFACTORY_H
