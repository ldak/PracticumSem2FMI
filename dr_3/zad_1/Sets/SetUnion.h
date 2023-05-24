//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_SETUNION_H
#define PRACTUCUMSEM2_SETUNION_H


#include "../Utils/MyVector.hpp"
#include "Set.h"

class SetUnion :public Set{
private:
    MyVector<Set*> sets;
public:
    SetUnion(const MyVector<Set*> &sets);
    SetUnion(MyVector<Set*> &&other);

    bool contains(int element) const override;
    ~SetUnion() override;
    Set * clone() const override


};


#endif //PRACTUCUMSEM2_SETUNION_H
