//
// Created by MILEN_PC on 16.6.2023 г..
//

#ifndef PRACTUCUMSEM2_SAVETABLECOMMAND_H
#define PRACTUCUMSEM2_SAVETABLECOMMAND_H


#include "../BasicComand/BasicCommand.h"
#include <fstream>

class SaveTableCommand : public BasicCommand{
public:
    SharedPtr<BasicCommand> clone() const override;
    void execute(SharedPtr<TableParser> &table, MyString &tableFile) override;
};


#endif //PRACTUCUMSEM2_SAVETABLECOMMAND_H
