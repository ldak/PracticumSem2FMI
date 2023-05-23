//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_PREDICATEONEDIVISION_H
#define PRACTUCUMSEM2_PREDICATEONEDIVISION_H


#include "../../Utils/MyVector.hpp"

class PredicateOneDivision {
private:
    MyVector<int> elements;
public:
    explicit PredicateOneDivision(const MyVector<int>& elements);
    explicit PredicateOneDivision(MyVector<int>&& elements);


    bool operator()(int element) const;

};


#endif //PRACTUCUMSEM2_PREDICATEONEDIVISION_H
