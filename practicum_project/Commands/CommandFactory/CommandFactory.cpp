//
// Created by MILEN_PC on 16.6.2023 г..
//

#include "CommandFactory.h"
#include "../InvalidCommand/InvalidCommand.h"

CommandFactory* CommandFactory::instance = nullptr;

CommandFactory *CommandFactory::getInstance() {
    if (instance == nullptr){
        instance = new CommandFactory();
    }
    return instance;
}

SharedPtr<BasicCommand> CommandFactory::createCommand() {

    return new InvalidCommand();
}

void CommandFactory::freeInstance() {
    delete instance;
    instance = nullptr;
}
