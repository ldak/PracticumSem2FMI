//
// Created by MILEN_PC on 4/1/2023.
//

#include "RightsManager.h"

RightsManager::RightsManager(const char *rights) {
    this->user = RightsGroup(rights[0] != '-', rights[1] != '-', rights[2] != '-');
    this->owner = RightsGroup(rights[3] != '-', rights[4] != '-', rights[5] != '-');
    this->other = RightsGroup(rights[6] != '-', rights[7] != '-', rights[8] != '-');

}

bool RightsManager::canWrite(char role) {
    if (role == 'u')
        return this->user.canWrite();

    if (role == 'g')
        return this->owner.canWrite();

    return this->other.canWrite();
}

bool RightsManager::canRead(char role) {
    if (role == 'u')
        return this->user.canRead();

    if (role == 'g')
        return this->owner.canRead();

    return this->other.canRead();
}

bool RightsManager::canExecute(char role) {
    if (role == 'u')
        return this->user.canExecute();

    if (role == 'g')
        return this->owner.canExecute();

    return this->other.canExecute();
}

void RightsManager::changeRight(char role, char right) {
    if (role == 'u'){
        this->user.changeRight(right);
        return;
    }

    if (role == 'g'){
        this->owner.changeRight(right);
        return;
    }

    this->other.changeRight(right);
}

void RightsManager::print() {
    this->user.print();
    this->owner.print();
    this->other.print();
    std::cout << std::endl;
}
