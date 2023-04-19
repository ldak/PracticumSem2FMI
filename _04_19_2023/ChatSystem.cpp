//
// Created by MILEN_PC on 4/19/2023.
//

#include "ChatSystem.h"

ChatSystem::ChatSystem() {
    this->messages = new Message[2];
    this->messagesCount = 0;
    this->messagesCapacity = 2;
}

void ChatSystem::free() {
    delete[] this->messages;
}

void ChatSystem::copyFrom(const ChatSystem& other) {
    this->messages = new Message[this->messagesCapacity];
    for (int i = 0; i < this->messagesCount; ++i) {
        this->messages[i] = other.messages[i];
    }
}

ChatSystem::ChatSystem(const ChatSystem &other) {
    this->copyFrom(other);

}

ChatSystem &ChatSystem::operator=(const ChatSystem &other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

ChatSystem::~ChatSystem() {
    this->free();
}

void ChatSystem::addUser(const User &user) {
    this->users[this->usersCount++] = user;
}

void ChatSystem::sendMessage(User &sender, User &receiver, const char *message) {
    if (this->messagesCount == this->messagesCapacity) {
        this->resize();
    }

    this->messages[this->messagesCount++] = Message(message, &sender, &receiver);
}

void ChatSystem::resize() {
    this->messagesCapacity *= 2;
    Message *newMessages = new Message[this->messagesCapacity];
    for (int i = 0; i < this->messagesCount; ++i) {
        newMessages[i] = this->messages[i];
    }

    this->free();
    this->messages = newMessages;
}

void ChatSystem::printMessages(const User &sender, const User &receiver) const {
    for (int i = 0; i < this->messagesCount; ++i) {
        if (this->messages[i].getSender() == &sender && this->messages[i].getReceiver() == &receiver) {
            this->messages[i].print();
        }
    }

}


