//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "SaveTableCommand.h"

SharedPtr<BasicCommand> SaveTableCommand::clone() const {
    return new SaveTableCommand(*this);
}

void SaveTableCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    if (!table.exists()){
        std::cout << "You need to open table first!" << std::endl;
        return;
    }
    std::ofstream file(tableFile.c_str(), std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    file << *table;

    file.close();

}
