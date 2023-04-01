//
// Created by MILEN_PC on 4/1/2023.
//

#ifndef PRACTUCUMSEM2_RIGHTSMANAGER_H
#define PRACTUCUMSEM2_RIGHTSMANAGER_H


#include "../RightsGroup/RightsGroup.h"

class RightsManager {
private:
    RightsGroup user{};
    RightsGroup owner{};
    RightsGroup other{};
public:
    RightsManager() = default;
    explicit RightsManager(const char* rights);

    bool canWrite(char role);
    bool canRead(char role);
    bool canExecute(char role);

    void changeRight(char role, char right);

    void print();
};


#endif //PRACTUCUMSEM2_RIGHTSMANAGER_H
