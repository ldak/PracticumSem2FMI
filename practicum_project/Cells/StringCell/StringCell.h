//
// Created by MILEN_PC on 14.5.2023 г..
//

#ifndef PRACTUCUMSEM2_STRINGCELL_H
#define PRACTUCUMSEM2_STRINGCELL_H


#include "../BasicCell/BasicCell.h"
#include "../../Utils/MyString/MyString.h"

class StringCell : public BasicCell {
private:
    MyString value;
public:
    explicit StringCell(const MyString &value);
    explicit StringCell(MyString &&value);

    void print(std::ostream &os) const override;
    int getLength() const override;
    double getValue() const override;
    SharedPtr<BasicCell> clone() const override;
};


#endif //PRACTUCUMSEM2_STRINGCELL_H
