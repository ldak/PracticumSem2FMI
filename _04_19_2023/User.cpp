//
// Created by MILEN_PC on 4/19/2023.
//

#include "User.h"

void User::free() {
    delete[] this->username;
    delete[] this->password;
    delete[] this->email;
}

void User::copyFrom(const User &other) {
    this->username = new char[strlen(other.username) + 1];
    strcpy(this->username, other.username);

    this->password = new char[strlen(other.password) + 1];
    strcpy(this->password, other.password);

    this->email = new char[strlen(other.email) + 1];
    strcpy(this->email, other.email);
}

User::User() {
    this->username = new char[1];
    this->username[0] = '\0';
    this->password = new char[1];
    this->password[0] = '\0';
    this->email = new char[1];
    this->email[0] = '\0';
}

User::User(const User &other) {
    this->copyFrom(other);

}

User &User::operator=(const User &other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

User::~User() {
    this->free();
}
