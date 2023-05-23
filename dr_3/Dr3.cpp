#include <fstream>
#include "Utils/MyString.h"
#include "Sets/Set.h"
#include "Utils/MyVector.hpp"
#include "Sets/SetByCriteria.hpp"
#include "Sets/Predicates/PredicateExactContains.h"
#include "Sets/Predicates/PredicateNoDivision.h"
#include "Sets/Predicates/PredicateOneDivision.h"
#include "Sets/SetUnion.h"
#include "Sets/SetIntersection.h"

MyVector<int> getNumbersFromFile(std::ifstream &ifstream, unsigned short n) {
    int *elements = new int[n];
    ifstream.read((char *) elements, sizeof(int) * n);
    MyVector<int> elementsVector(elements, n);
    return elementsVector;
}

Set *loadFirstType(std::ifstream &ifstream, unsigned short n) {
    MyVector<int> elementsVector = getNumbersFromFile(ifstream, n);
    PredicateExactContains predicate(elementsVector);
    SetByCriteria<PredicateExactContains> *set = new SetByCriteria<PredicateExactContains>(predicate);
    return set;

}

Set *loadSecondType(std::ifstream &ifstream, unsigned short n) {
    MyVector<int> elementsVector = getNumbersFromFile(ifstream, n);
    PredicateNoDivision predicate(elementsVector);
    SetByCriteria<PredicateNoDivision> *set = new SetByCriteria<PredicateNoDivision>(predicate);
    return set;
}

Set *loadThirdType(std::ifstream &ifstream, unsigned short n) {
    MyVector<int> elementsVector = getNumbersFromFile(ifstream, n);
    PredicateOneDivision predicate(elementsVector);
    SetByCriteria<PredicateOneDivision> *set = new SetByCriteria<PredicateOneDivision>(predicate);
    return set;
}

Set* loadFromFile(const MyString& fileName);

Set *loadFourthType(std::ifstream& ifstream, unsigned short n) {
    MyVector<Set*> sets;
    for (int i = 0; i < n; ++i) {
        MyString fileName;
        ifstream >> fileName;
        std::cout << fileName << std::endl;
        sets.push_back(loadFromFile(fileName));
    }
    SetUnion* set = new SetUnion(sets);

    return set;
}

Set *loadFifthType(std::ifstream& ifstream, unsigned short n) {
    MyVector<Set*> sets;
    for (int i = 0; i < n; ++i) {
        MyString fileName;
        fileName.loadBinary(ifstream);
        std::cout << fileName << std::endl;
        Set* set = loadFromFile(fileName);
        sets.push_back(set);
    }
    SetIntersection* set = new SetIntersection(std::move(sets));

    return set;
}

Set *loadFromFile(const MyString &fileName) {
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


int main() {
    Set * set = loadFromFile("set.dat");
    for (int i = 0; i < 10; ++i) {
        if (set->contains(i)) {
            std::cout << i << " ";
        }
    }

    return 0;
}