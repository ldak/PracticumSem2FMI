//
// Created by MILEN_PC on 17.6.2023 г..
//

#ifndef PRACTUCUMSEM2_SAVETABLEASCOMMAND_H
#define PRACTUCUMSEM2_SAVETABLEASCOMMAND_H


#include "../BasicComand/BasicCommand.h"

class SaveTableAsCommand : public BasicCommand{
public:
    void execute(SharedPtr<TableParser> &table, MyString &tableFile) override;
    SharedPtr<BasicCommand> clone() const override;
};


#endif //PRACTUCUMSEM2_SAVETABLEASCOMMAND_H
