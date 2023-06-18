//
// Created by MILEN_PC on 17.6.2023 г..
//

#include "ExitCommand.h"
#include "../CommandFactory/CommandFactory.h"

SharedPtr<BasicCommand> ExitCommand::clone() const {
    return SharedPtr<BasicCommand>(new ExitCommand(*this));
}

void ExitCommand::execute(SharedPtr<TableParser> &table, MyString &tableFile) {
    std::cout << "Exiting the program..." << std::endl;
    CommandFactory::freeInstance();
    table = nullptr;
    exit(0);
}
