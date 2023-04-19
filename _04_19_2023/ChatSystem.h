//
// Created by MILEN_PC on 4/19/2023.
//

#ifndef PRACTUCUMSEM2_CHATSYSTEM_H
#define PRACTUCUMSEM2_CHATSYSTEM_H


#include "User.h"
#include "Message.h"

class ChatSystem {
private:
    User users[100];
    size_t usersCount = 0;
    Message *messages;
    size_t messagesCount;
    size_t messagesCapacity;
    void free();
    void copyFrom(const ChatSystem& other);
    void resize();
public:
    ChatSystem();
    ChatSystem(const ChatSystem& other);
    ChatSystem& operator=(const ChatSystem& other);
    ~ChatSystem();

    void addUser(const User& user);
    void sendMessage(User& sender, User& receiver, const char* message);
    void printMessages(const User& sender, const User& receiver) const;

};


#endif //PRACTUCUMSEM2_CHATSYSTEM_H
