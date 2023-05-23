//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "PredicateNoDivision.h"

PredicateNoDivision::PredicateNoDivision(const MyVector<int>& elements) {
    this->elements = elements;

}

bool PredicateNoDivision::operator()(int element) const{
    for (int i = 0; i < elements.size(); ++i) {
        if (element % elements[i] == 0) {
            return false;
        }
    }
    return true;
}

PredicateNoDivision::PredicateNoDivision(MyVector<int> &&elements) {
    this->elements = std::move(elements);

}
