//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "EditTableCommand.h"

SharedPtr<BasicCommand> EditTableCommand::clone() const {
    return SharedPtr<BasicCommand>(new EditTableCommand(*this));
}

void EditTableCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    if (!table.exists()){
        std::cout << "You need to open table first!" << std::endl;
        return;
    }
    int row;
    int col;
    std::cout << "Enter cell row: ";
    std::cin >> row;
    std::cout << "Enter cell col: ";
    std::cin >> col;
    std::cout << "Enter cell value: ";
    std::cin.ignore();
    char buffer[1024]{'\0'};
    std::cin.getline(buffer, 1024);
    CellsFactory* factory = CellsFactory::getInstance();
    try{
        SharedPtr<BasicCell> cell = factory->createCell(buffer);
        table->setCell(row - 1, col - 1, cell);
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
