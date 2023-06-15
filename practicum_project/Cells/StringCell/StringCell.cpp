//
// Created by MILEN_PC on 14.5.2023 г..
//

#include "StringCell.h"

StringCell::StringCell(const MyString &value) {
    this->value = value;
}

StringCell::StringCell(MyString &&value) {
    this->value = std::move(value);
}

void StringCell::print(std::ostream &os) const {
    os << this->value;
}

int StringCell::getLength() const {
    return this->value.length();
}

double StringCell::getValue() const {
    return 0;
}

SharedPtr<BasicCell>StringCell::clone() const {
    return new StringCell(*this);
}
