//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_TABLEPARSERMENU_H
#define PRACTUCUMSEM2_TABLEPARSERMENU_H


#include "../Table/TableParser/TableParser.h"

class TableParserMenu {
private:
    SharedPtr<TableParser> table;
    MyString fileName;

    static void printMenu() ;
public:
    void programLoop();

};


#endif //PRACTUCUMSEM2_TABLEPARSERMENU_H
