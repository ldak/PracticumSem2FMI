//
// Created by MILEN_PC on 3/30/2023.
//

#include "Menu.h"

namespace Menu{

    void printMenu(){
        std::cout << "Choose option:" << std::endl;
        std::cout << "1. Print table" << std::endl;
        std::cout << "2. Change column name" << std::endl;
        std::cout << "3. Add row" << std::endl;
        std::cout << "4. Change cell by <row number> and <column name>" << std::endl;


        std::cout << "7. Save table" << std::endl;
        std::cout << "9. Exit" << std::endl;
    }

    void changeColumnName(MarkdownTableParser& parser) {
        char* oldName = new char[20];
        char* newName = new char[20];
        std::cout << "Enter old name: ";
        std::cin >> oldName;
        std::cout << "Enter new name: ";
        std::cin >> newName;
        bool status = parser.changeColumnName(oldName, newName);
        std::cout << (status? "Column name changed!" : "Column not found") << std::endl;
        delete[] oldName;
        delete[] newName;
    }

    void addRow(MarkdownTableParser& parser) {
        char* rowValue = new char[300];
        std::cout << "Enter row in format: <value1> | <value2> | ... | <valueN>" << std::endl;
        std::cin.ignore();
        std::cin.getline(rowValue, 320);
        bool status = parser.addRow(rowValue);
        std::cout << (status? "Row added!": "Couldn't add the row") << std::endl;
        delete[] rowValue;
    }

    void changeCellByNameAndRow(MarkdownTableParser& parser) {
        char* columnName = new char[20];
        char* newValue = new char[20];
        int rowNumber;
        std::cout << "Enter column name: ";
        std::cin >> columnName;
        std::cout << "Enter row number: ";
        std::cin >> rowNumber;
        std::cout << "Enter new value: ";
        std::cin >> newValue;
        bool status = parser.changeCellByNameAndRow(columnName, rowNumber, newValue);
        std::cout << (status? "Cell changed!" : "Cell not found") << std::endl;
        delete[] columnName;
        delete[] newValue;
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

}
