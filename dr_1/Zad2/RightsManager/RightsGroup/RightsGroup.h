//
// Created by MILEN_PC on 4/1/2023.
//

#ifndef PRACTUCUMSEM2_RIGHTSGROUP_H
#define PRACTUCUMSEM2_RIGHTSGROUP_H
#include <iostream>

class RightsGroup {
private:
    bool read;
    bool write;
    bool execute;
public:
    RightsGroup() = default;
    RightsGroup(bool read, bool write, bool execute);

    bool canWrite() const;
    bool canRead() const;
    bool canExecute() const;

    void changeRight(char right);

    void print();
};


#endif //PRACTUCUMSEM2_RIGHTSGROUP_H
