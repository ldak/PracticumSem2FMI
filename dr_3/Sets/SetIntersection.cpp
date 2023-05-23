//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "SetIntersection.h"

SetIntersection::SetIntersection(const MyVector<Set*> &sets) {
    this->sets = sets;
}

SetIntersection::SetIntersection(MyVector<Set *> &&sets) {
    this->sets = std::move(sets);

}

bool SetIntersection::contains(int element) const {
    for (int i = 0; i < this->sets.size(); ++i) {
        if (!this->sets[i]->contains(element)) {
            return false;
        }
    }

    return true;
}
