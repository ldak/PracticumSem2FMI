//
// Created by MILEN_PC on 3/30/2023.
//

#ifndef PRACTUCUMSEM2_MENU_H
#define PRACTUCUMSEM2_MENU_H
#include "iostream"
#include "MarkdownTableParser.h"

namespace Menu {

    void printMenu();

    void changeColumnName(MarkdownTableParser& parser);

    void addRow(MarkdownTableParser& parser);

    void changeCellByNameAndRow(MarkdownTableParser& parser);

    void changeCellByNameAndValue(MarkdownTableParser& parser);

    void selectByValue(MarkdownTableParser& parser);

    void saveTable(MarkdownTableParser &parser);
}


#endif //PRACTUCUMSEM2_MENU_H
