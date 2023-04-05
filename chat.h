#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "user.h"
#include "message.h"

// ����� 
class Chat {
public:
    Chat() {
        std::cout << "Chat created" << std::endl;
    }

    ~Chat() {
        std::cout << "Chat destroyed" << std::endl;
    }

    void loginUser(); // ����� ��� ����� ������������ � ���
    void registerUser(); // ����� ��� ����������� ������ ������������
    void sendMessage(const User& sender, const std::string& recipient, const std::string& text); // ����� ��� �������� ���������
    void sendUserMessage(const User& sender);
    void readMessages();
    void viewUsers();

    bool getUserInput(std::string& recipient, std::string& text) const;

private:
    std::vector<User> userList; // ������ ������������� ����
    std::vector<Message> messageList; // ������ ��������� ����
};
