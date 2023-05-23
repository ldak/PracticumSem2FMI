//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "SetLoader.h"

static MyVector<int> getNumbersFromFile(std::ifstream &ifstream, unsigned short n) {
    int *elements = new int[n];
    ifstream.read((char *) elements, sizeof(int) * n);
    MyVector<int> elementsVector(elements, n);
    delete[] elements;
    return elementsVector;
}

static Set *loadFirstType(std::ifstream &ifstream, unsigned short n) {
    MyVector<int> elementsVector = getNumbersFromFile(ifstream, n);
    PredicateExactContains predicate(elementsVector);
    SetByCriteria<PredicateExactContains> *set = new SetByCriteria<PredicateExactContains>(predicate);
    return set;

}

static Set *loadSecondType(std::ifstream &ifstream, unsigned short n) {
    MyVector<int> elementsVector = getNumbersFromFile(ifstream, n);
    PredicateNoDivision predicate(elementsVector);
    SetByCriteria<PredicateNoDivision> *set = new SetByCriteria<PredicateNoDivision>(predicate);
    return set;
}

static Set *loadThirdType(std::ifstream &ifstream, unsigned short n) {
    MyVector<int> elementsVector = getNumbersFromFile(ifstream, n);
    PredicateOneDivision predicate(elementsVector);
    SetByCriteria<PredicateOneDivision> *set = new SetByCriteria<PredicateOneDivision>(predicate);
    return set;
}

static Set *loadFourthType(std::ifstream& ifstream, unsigned short n) {
    MyVector<Set*> sets;
    for (int i = 0; i < n; ++i) {
        MyString fileName;
        fileName.loadBinary(ifstream);
        sets.push_back(SetLoader::loadFromFile(fileName));
    }
    SetUnion* set = new SetUnion(std::move(sets));

    return set;
}

static Set *loadFifthType(std::ifstream& ifstream, unsigned short n) {
    MyVector<Set*> sets;
    for (int i = 0; i < n; ++i) {
        MyString fileName;
        fileName.loadBinary(ifstream);
        Set* set = SetLoader::loadFromFile(fileName);
        sets.push_back(set);
    }
    SetIntersection* set = new SetIntersection(std::move(sets));

    return set;
}

Set *SetLoader::loadFromFile(const MyString &fileName) {
    std::ifstream file(fileName.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open())
        return nullptr;

    unsigned short n, t;
    file.read((char *) &n, sizeof(n));
    file.read((char *) &t, sizeof(t));
    Set *set = nullptr;
    switch (t) {
        case 0:
            set = loadFirstType(file, n);
            break;
        case 1:
            set = loadSecondType(file, n);
            break;
        case 2:
            set = loadThirdType(file, n);
            break;
        case 3:
            set = loadFourthType(file, n);
            break;
        case 4:
            set = loadFifthType(file, n);
            break;
        default:
            set = nullptr;
    }
    file.close();
    return set;
}