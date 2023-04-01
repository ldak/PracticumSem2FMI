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

void RightsGroup::changeRight(char right) {
    switch (right) {
        case 'r':
            this->read = !this->read;
            break;
        case 'w':
            this->write = !this->write;
            break;
        case 'x':
            this->execute = !this->execute;
            break;
        default:
            std::cout << "Invalid right!" << std::endl;
            break;
    }

}

void RightsGroup::print() {
    std::cout << (this->read ? "r" : "-");
    std::cout << (this->write ? "w" : "-");
    std::cout << (this->execute ? "x" : "-");
}
