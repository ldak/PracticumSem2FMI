//
// Created by MILEN_PC on 4/19/2023.
//

#ifndef PRACTUCUMSEM2_MESSAGE_H
#define PRACTUCUMSEM2_MESSAGE_H


#include <cstring>
#include "User.h"
#include "iostream"

class Message {
    char* content;
    size_t size;
    User* sender;
    User* receiver;
    void free();
    void copyFrom(const Message& other);
public:
    Message();
    Message(const char* content, User* sender, User* receiver);
//    explicit Message(const char *content);
    Message(const Message& other);
    Message& operator=(const Message& other);
    ~Message();

    const User *getSender();

    const User *getReceiver();

    void print();
};


#endif //PRACTUCUMSEM2_MESSAGE_H
