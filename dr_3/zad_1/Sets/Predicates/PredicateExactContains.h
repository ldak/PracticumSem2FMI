//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_PREDICATEEXACTCONTAINS_H
#define PRACTUCUMSEM2_PREDICATEEXACTCONTAINS_H


#include "../../Utils/MyVector.hpp"

class PredicateExactContains {
private:
    MyVector<int> elements;
public:
    explicit PredicateExactContains(const MyVector<int>& elements);
    explicit PredicateExactContains(MyVector<int>&& elements);

    bool operator()(int element) const;
};




#endif //PRACTUCUMSEM2_PREDICATEEXACTCONTAINS_H
