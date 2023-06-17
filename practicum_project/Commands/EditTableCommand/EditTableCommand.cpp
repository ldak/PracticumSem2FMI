//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "EditTableCommand.h"

SharedPtr<BasicCommand> EditTableCommand::clone() const {
    return SharedPtr<BasicCommand>(new EditTableCommand(*this));
}

void EditTableCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    int row;
    int col;
    std::cout << "Enter cell row: ";
    std::cin >> row;
    std::cout << "Enter cell col: ";
    std::cin >> col;
    std::cout << "Enter cell value: ";
    MyString value;
    std::cin >> value;
    CellsFactory* factory = CellsFactory::getInstance();
    try{
        SharedPtr<BasicCell> cell = factory->createCell(value);
        table->setCell(row - 1, col - 1, cell);
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
