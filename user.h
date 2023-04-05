#pragma once

#include <iostream>
#include <vector>
#include "message.h"

// ����� ������������
class User {
public:
    // ����������� ������
    User(const std::string& login, const std::string& password, const std::string& name);

    // ���������� ������
    ~User() {
    
    }

    // ������ ��������� ������ ������������
    const std::string& getLogin() const;
    const std::string& getPassword() const;
    const std::string& getName() const;

    void addSentMessage(const Message& message);
    void addReceivedMessage(const Message& message);
    const std::vector<Message>& getSentMessages() const;
    const std::vector<Message>& getReceivedMessages() const;

private:
    std::string login_;     // ����� ������������
    std::string password_;  // ������ ������������
    std::string name_;      // ��� ������������
    std::vector<Message> sentMessages;      //
    std::vector<Message> receivedMessages;  //
};