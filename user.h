#pragma once

#include <iostream>
#include <vector>
#include "message.h"

// Класс пользователь
class User {
public:
    // Конструктор класса
    User(const std::string& login, const std::string& password, const std::string& name);

    // Деструктор класса
    ~User() {
    
    }

    // Методы получения данных пользователя
    const std::string& getLogin() const;
    const std::string& getPassword() const;
    const std::string& getName() const;

    void addSentMessage(const Message& message);
    void addReceivedMessage(const Message& message);
    const std::vector<Message>& getSentMessages() const;
    const std::vector<Message>& getReceivedMessages() const;

private:
    std::string login_;     // Логин пользователя
    std::string password_;  // Пароль пользователя
    std::string name_;      // Имя пользователя
    std::vector<Message> sentMessages;      //
    std::vector<Message> receivedMessages;  //
};