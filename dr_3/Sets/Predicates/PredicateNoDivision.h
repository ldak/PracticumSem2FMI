//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_PREDICATENODIVISION_H
#define PRACTUCUMSEM2_PREDICATENODIVISION_H


#include "../../Utils/MyVector.hpp"

class PredicateNoDivision {
private:
    MyVector<int> elements;
public:
    explicit PredicateNoDivision(const MyVector<int> &elements);
    explicit PredicateNoDivision(MyVector<int> &&elements);

    bool operator()(int element) const;

};


#endif //PRACTUCUMSEM2_PREDICATENODIVISION_H
