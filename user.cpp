#include "user.h"

User::User(const std::string& login, const std::string& password, const std::string& name)
    : login_(login), password_(password), name_(name) {}

const std::string& User::getLogin() const {
    return login_;
}

const std::string& User::getPassword() const {
    return password_;
}

const std::string& User::getName() const {
    return name_;
}

void User::addSentMessage(const Message& message) {
    sentMessages.push_back(message);
}

void User::addReceivedMessage(const Message& message) {
    receivedMessages.push_back(message);
}

const std::vector<Message>& User::getSentMessages() const {
    return sentMessages;
}

const std::vector<Message>& User::getReceivedMessages()const {
    return receivedMessages;
}