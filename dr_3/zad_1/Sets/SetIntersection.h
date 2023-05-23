//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_SETINTERSECTION_H
#define PRACTUCUMSEM2_SETINTERSECTION_H


#include "../Utils/MyVector.hpp"
#include "Set.h"

class SetIntersection : public Set{
private:
    MyVector<Set*> sets;
public:
    explicit SetIntersection(const MyVector<Set*>& sets);
    explicit SetIntersection(MyVector<Set*>&& sets);
    bool contains(int element) const override;
    ~SetIntersection() override;

};


#endif //PRACTUCUMSEM2_SETINTERSECTION_H
