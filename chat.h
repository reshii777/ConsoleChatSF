#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "user.h"
#include "message.h"

// Класс 
class Chat {
public:
    Chat() {
        std::cout << "Chat created" << std::endl;
    }

    ~Chat() {
        std::cout << "Chat destroyed" << std::endl;
    }

    void loginUser(); // метод для входа пользователя в чат
    void registerUser(); // метод для регистрации нового пользователя
    void sendMessage(const User& sender, const std::string& recipient, const std::string& text); // метод для отправки сообщения
    void sendUserMessage(const User& sender);
    void readMessages();
    void viewUsers();

    bool getUserInput(std::string& recipient, std::string& text) const;

private:
    std::vector<User> userList; // список пользователей чата
    std::vector<Message> messageList; // список сообщений чата
};
