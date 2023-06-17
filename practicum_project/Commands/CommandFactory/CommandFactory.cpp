//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "CommandFactory.h"
#include "../InvalidCommand/InvalidCommand.h"
#include "../OpenTableCommand/OpenTableCommand.h"
#include "../CloseTableCommand/CloseTableCommand.h"
#include "../SaveTableCommand/SaveTableCommand.h"
#include "../SaveTableAsCommand/SaveTableAsCommand.h"
#include "../PrintTableCommand/PrintTableCommand.h"
#include "../EditTableCommand/EditTableCommand.h"
#include "../ExitCommand/ExitCommand.h"

CommandFactory *CommandFactory::instance = nullptr;

CommandFactory *CommandFactory::getInstance() {
    if (instance == nullptr) {
        instance = new CommandFactory();
    }
    return instance;
}

SharedPtr<BasicCommand> CommandFactory::createCommand() {
    std::cout << "Enter command (1-7): ";
    char command;
    std::cin >> command;
    std::cin.ignore();
    switch (command) {
        case '1':
            return new OpenTableCommand();
        case '2':
            return new CloseTableCommand();
        case '3':
            return new SaveTableCommand();
        case '4':
            return new SaveTableAsCommand();
        case '5':
            return new PrintTableCommand();
        case '6':
            return new EditTableCommand();
        case '7':
            return new ExitCommand();
        default:
            return new InvalidCommand();
    }
}

void CommandFactory::freeInstance() {
    delete instance;
    instance = nullptr;
}
