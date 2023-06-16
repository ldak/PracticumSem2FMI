//
// Created by MILEN_PC on 24.5.2023 г..
//

#ifndef PRACTUCUMSEM2_ROW_H
#define PRACTUCUMSEM2_ROW_H


#include "../../Utils/MyVector/MyVector.hpp"
#include "../../Utils/SharedPtr/SharedPtr.hpp"
#include "../../Cells/CellsFactory/CellsFactory.h"

class Row {
private:
    MyVector<SharedPtr<BasicCell>> cells;

    void copyFrom(const Row& other);
    void moveFrom(Row& other);
    void free();
public:
    Row() = default;
    explicit Row(const MyVector<SharedPtr<BasicCell>> &cells);
    explicit Row(MyVector<SharedPtr<BasicCell>> &&cells);

    Row(const Row& other);
    Row& operator=(const Row& other);
    Row(Row&& other) noexcept;
    Row& operator=(Row&& row) noexcept;
    ~Row();

    int size() const;
    SharedPtr<BasicCell>& operator[](int index);
    const SharedPtr<BasicCell>& operator[](int index) const;

    friend std::istream &operator>>(std::istream &in, Row &row);
    friend std::ostream &operator<<(std::ostream &os, const Row &row);

    void print(std::ostream &os, MyVector<int> alignments) const;

    void setAlignments(MyVector<int>& vector);
};

std::istream &operator>>(std::istream &in, Row &row);
std::ostream &operator<<(std::ostream &os, const Row &row);

#endif //PRACTUCUMSEM2_ROW_H
