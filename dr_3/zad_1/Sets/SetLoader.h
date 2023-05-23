//
// Created by MILEN_PC on 23.5.2023 г..
//

#ifndef PRACTUCUMSEM2_SETLOADER_H
#define PRACTUCUMSEM2_SETLOADER_H
#include <fstream>
#include "../Utils/MyString.h"
#include "Set.h"
#include "../Utils/MyVector.hpp"
#include "SetByCriteria.hpp"
#include "Predicates/PredicateExactContains.h"
#include "Predicates/PredicateNoDivision.h"
#include "Predicates/PredicateOneDivision.h"
#include "SetUnion.h"
#include "SetIntersection.h"

namespace SetLoader {
    Set *loadFromFile(const MyString &fileName);
};


#endif //PRACTUCUMSEM2_SETLOADER_H
