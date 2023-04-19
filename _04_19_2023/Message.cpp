//
// Created by MILEN_PC on 4/19/2023.
//

#include "Message.h"

void Message::free() {
    delete[] this->content;
}

void Message::copyFrom(const Message &other) {
    this->size = other.size;
    this->content = new char[size + 1];
    strcpy(this->content, other.content);
}
//
//Message::Message(const char *content) {
//    this->size = strlen(content);
//    this->content = new char[size + 1];
//    strcpy(this->content, content);
//}

Message::Message(const Message &other) {
    this->copyFrom(other);
}

Message &Message::operator=(const Message &other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Message::~Message() {
    this->free();
}

Message::Message() {
    this->size = 0;
    this->content = new char[size + 1];
    this->content[0] = '\0';
}

Message::Message(const char *content, User *sender, User *receiver) {
    this->size = strlen(content);
    this->content = new char[size + 1];
    strcpy(this->content, content);
    this->sender = sender;
    this->receiver = receiver;
}

const User *Message::getSender() {
    return this->sender;
}

const User *Message::getReceiver() {
    return this->receiver;
}

void Message::print() {
    std::cout << this->content << std::endl;

}

