//
// Created by MILEN_PC on 3/22/2023.
//
#include <iostream>
#include "MarkdownTableParser.h"
#include <fstream>


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

}

void addRow(MarkdownTableParser& parser) {
    char* rowValue = new char[300];
    std::cout << "Enter row: ";
    std::cin.ignore();
    std::cin.getline(rowValue, 320);
    std::stringstream ss(rowValue);
    Row row{};
    int i = 0;
    while(!ss.eof()){
        char* value = new char[20];
        ss >> value;
        row.setValue( value, i++);
    }
    parser.addRow(row);
    std::cout << "Row added!" << std::endl;

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
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    }while(option != '9');
}

void loadTable(MarkdownTableParser& parser) {
    std::ifstream ifs("table.md");

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