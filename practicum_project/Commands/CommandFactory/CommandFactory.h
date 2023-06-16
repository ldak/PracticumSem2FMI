//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_COMMANDFACTORY_H
#define PRACTUCUMSEM2_COMMANDFACTORY_H


#include "../../Utils/SharedPtr/SharedPtr.hpp"
#include "../BasicComand/BasicCommand.h"

class CommandFactory {
private:
    static CommandFactory* instance;
    CommandFactory() = default;
public:
    CommandFactory(const CommandFactory&) = delete;
    CommandFactory& operator=(const CommandFactory&) = delete;

    static CommandFactory* getInstance();
    SharedPtr<BasicCommand> createCommand();
    static void freeInstance();

};


#endif //PRACTUCUMSEM2_COMMANDFACTORY_H
