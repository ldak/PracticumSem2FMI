//
// Created by MILEN_PC on 3/22/2023.
//
#include <iostream>
#include "MarkdownTableParser.h"
#include <fstream>
#include "Menu.h"


void loadTable(MarkdownTableParser& parser) {
    std::cout << "Enter table file name:" << std::endl;
    char* fileName = new char[2000];
    std::cin >> fileName;
    std::ifstream ifs(fileName);
    delete[] fileName;

    parser.readFromFile(ifs);
    std::cout << "table --------------" << std::endl;
    parser.printTable();
    ifs.close();
}

void programLoop(MarkdownTableParser& parser){
    char option;
    do {
        Menu::printMenu();
//        std::cin.ignore();
        std::cin >> option;
        switch (option) {
            case '1':
                parser.printTable();
                break;
            case '2':
                Menu::changeColumnName(parser);
                break;
            case '3':
                Menu::addRow(parser);
                break;
            case '4':
                Menu::changeCellByNameAndRow(parser);
                break;
            case '5':
                Menu::changeCellByNameAndValue(parser);
                break;
            case '6':
                Menu::selectByValue(parser);
                break;
            case '7':
                Menu::saveTable(parser);
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    }while(option != '9');
}

int main(){
    MarkdownTableParser parser;
    loadTable(parser);
    programLoop(parser);

}