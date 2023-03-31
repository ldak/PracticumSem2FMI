//
// Created by MILEN_PC on 4/1/2023.
//

#include "RightsGroup.h"

RightsGroup::RightsGroup(bool read, bool write, bool execute) {
    this->read = read;
    this->write = write;
    this->execute = execute;
}

bool RightsGroup::canWrite() const {
    return this->write;
}

bool RightsGroup::canRead() const {
    return this->read;
}

bool RightsGroup::canExecute() const {
    return this->execute;
}
