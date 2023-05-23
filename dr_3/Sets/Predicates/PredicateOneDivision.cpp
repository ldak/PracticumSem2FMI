//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "PredicateOneDivision.h"

PredicateOneDivision::PredicateOneDivision(const MyVector<int> &elements) {
    this->elements = elements;
}

PredicateOneDivision::PredicateOneDivision(MyVector<int> &&elements) {
    this->elements = std::move(elements);

}

bool PredicateOneDivision::operator()(int element) const{
    int divisionCount = 0;
    for (int i = 0; i < elements.size(); ++i) {
        if (element % elements[i] != 0) {
            continue;
        }
        divisionCount++;
        if(divisionCount == 2){
            return false;
        }
    }
    return divisionCount == 1;
}
