//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "CloseTableCommand.h"

void CloseTableCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    if (!table.exists()){
        std::cout << "You need to open table first!" << std::endl;
        return;
    }
    table = nullptr;
    tableFile = "";
}

SharedPtr<BasicCommand> CloseTableCommand::clone() const {
    return new CloseTableCommand(*this);
}
