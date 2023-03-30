//
// Created by MILEN_PC on 3/22/2023.
//
#include <iostream>
#include "MarkdownTableParser.h"
#include <fstream>


void saveTable(MarkdownTableParser &parser);

void printMenu(){
    std::cout << "Choose option:" << std::endl;
    std::cout << "1. Print table" << std::endl;
    std::cout << "2. Change column name" << std::endl;
    std::cout << "3. Add row" << std::endl;
    std::cout << "4. Change cell by <row number> and <column name>" << std::endl;
    std::cout << "5. Edit cell" << std::endl;
    std::cout << "6. Print table" << std::endl;

    std::cout << "7. Save table" << std::endl;
    std::cout << "8. Load table" << std::endl;
    std::cout << "9. Exit" << std::endl;
}

void changeColumnName(MarkdownTableParser& parser) {
    char* oldName = new char[20];
    char* newName = new char[20];
    std::cout << "Enter old name: ";
    std::cin >> oldName;
//    std::cout << oldName;
    std::cout << "Enter new name: ";
    std::cin >> newName;
    parser.changeColumnName(oldName, newName);

    delete[] oldName;
    delete[] newName;
}

void addRow(MarkdownTableParser& parser) {
    char* rowValue = new char[300];
    std::cout << "Enter row: ";
    std::cin.ignore();
    std::cin.getline(rowValue, 320);
    parser.addRow(rowValue);
    std::cout << "Row added!" << std::endl;
    delete[] rowValue;
}

void programLoop(MarkdownTableParser& parser){
    char option;
    do {
        printMenu();
        std::cin >> option;
        switch (option) {
            case '1':
                parser.printTable();
                break;
            case '2':
                changeColumnName(parser);
                break;
            case '3':
                addRow(parser);
                break;
            case '7':
                saveTable(parser);
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    }while(option != '9');
}

void saveTable(MarkdownTableParser &parser) {
    std::cout << "Enter file name:" << std::endl;
    char* fileName = new char[2000];
    std::cin >> fileName;
    std::ofstream ofs(fileName);
    delete[] fileName;

    parser.writeToFile(ofs);
    ofs.close();
    std::cout << "Table saved!" << std::endl;
}

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

int main(){
    MarkdownTableParser parser;
    loadTable(parser);
    programLoop(parser);

}