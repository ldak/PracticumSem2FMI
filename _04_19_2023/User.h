//
// Created by MILEN_PC on 4/19/2023.
//

#ifndef PRACTUCUMSEM2_USER_H
#define PRACTUCUMSEM2_USER_H


#include "cstring"

class User {
    char *username;
    char *password;
    char *email;
    void free();
    void copyFrom(User const &other);
public:
    User();
    User(User const &other);
    User &operator=(const User &other);
    ~User();
};


#endif //PRACTUCUMSEM2_USER_H
