//
// Created by MILEN_PC on 3/22/2023.
//

#pragma once

#include <iostream>
#include "ConfigConst.h"
#include <fstream>

inline int strLength(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

inline int strCompare(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

inline void strcpyWithoutSpaces(char *dest, const char *src) {
    int size = strLength(src);
    int start = 0;
    while(src[start] == ' ')
        start++;

    int end = size - 1;
    while(src[end] == ' ')
        end--;
    int i = 0;

    while (start + i <= end) {
        dest[i] = src[start + i];
        i++;
    }
    dest[i] = '\0';
}

inline void alignString(const char *str, int size, Alignment align) {
    int strSize = strLength(str);
    int spaces = size - strSize;
    int leftSpaces = 0;
    int rightSpaces = 0;

    if (align == Alignment::LEFT) {
        leftSpaces = 1;
        rightSpaces = spaces - 1;
    } else if (align == Alignment::RIGHT) {
        leftSpaces = spaces - 1;
        rightSpaces = 1;
    } else if (align == Alignment::CENTER) {
        leftSpaces = spaces / 2;
        rightSpaces = spaces - leftSpaces;
    }

    for (int i = 0; i < leftSpaces; ++i) {
        std::cout << " ";
    }

    std::cout << str;

    for (int i = 0; i < rightSpaces; ++i) {
        std::cout << " ";
    }
}

inline void alignString(const char *str, int size, Alignment align, std::ofstream &ofs) {
    if (!ofs.is_open())
        return;
    int strSize = strLength(str);
    int spaces = size - strSize;
    int leftSpaces = 0;
    int rightSpaces = 0;

    if (align == Alignment::LEFT) {
        leftSpaces = 1;
        rightSpaces = spaces - 1;
    } else if (align == Alignment::RIGHT) {
        leftSpaces = spaces;
        rightSpaces = 1;
    } else if (align == Alignment::CENTER) {
        leftSpaces = spaces / 2;
        rightSpaces = spaces - leftSpaces;
    }

    for (int i = 0; i < leftSpaces; ++i) {
        ofs << " ";
    }

    ofs << str;

    for (int i = 0; i < rightSpaces; ++i) {
        ofs << " ";
    }
}
