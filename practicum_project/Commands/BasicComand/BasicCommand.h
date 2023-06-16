//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_BASICCOMMAND_H
#define PRACTUCUMSEM2_BASICCOMMAND_H


#include "../../Table/TableParser/TableParser.h"

class BasicCommand {
public:
    virtual void execute(SharedPtr<TableParser>& table, MyString& tableFile) = 0;
    virtual ~BasicCommand() = default;
    virtual SharedPtr<BasicCommand> clone() const = 0;
};


#endif //PRACTUCUMSEM2_BASICCOMMAND_H
