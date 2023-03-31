//
// Created by MILEN_PC on 3/22/2023.
//

#pragma once

#include <iostream>
#include "ConfigConst.h"
#include <fstream>

namespace string_helper{
    int strLength(const char *str);

    int strCompare(const char *str1, const char *str2);

    void strcpyWithoutSpaces(char *dest, const char *src);

    void alignString(const char *str, int size, Alignment align);

    void alignString(const char *str, int size, Alignment align, std::ofstream &ofs);
}

