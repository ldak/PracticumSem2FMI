//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "PredicateExactContains.h"

bool PredicateExactContains::operator()(int element) const {
    for (int i = 0; i < this->elements.size(); ++i) {
        if (element == this->elements[i])
            return true;
    }
    return false;
}

PredicateExactContains::PredicateExactContains(const MyVector<int> &elements) {
    this->elements = elements;
}

PredicateExactContains::PredicateExactContains(MyVector<int> &&elements) {
    this->elements = std::move(elements);

}