//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "SetUnion.h"

SetUnion::SetUnion(const MyVector<Set *> &sets) {
    this->sets = sets;

}

SetUnion::SetUnion(MyVector<Set *> &&other) {
    this->sets = std::move(other);

}

bool SetUnion::contains(int element) const {
    for (int i = 0; i < sets.size() ; ++i) {
        if (sets[i]->contains(element)){
            return true;
        }
    }
    return false;
}

SetUnion::~SetUnion() {
    for (int i = 0; i < sets.size(); ++i) {
        delete sets[i];
    }
}

Set *SetUnion::clone() const {
    return new SetUnion(*this);
}
