//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_SETBYCRITERIA_HPP
#define PRACTUCUMSEM2_SETBYCRITERIA_HPP
#include "Set.h"

template <typename T>
class SetByCriteria : public Set {
private:
    T predicate;
public:
    explicit SetByCriteria(T predicate) : predicate(predicate) {}

    bool contains(int element) const override {
        return predicate(element);
    }
};

#endif //PRACTUCUMSEM2_SETBYCRITERIA_HPP
