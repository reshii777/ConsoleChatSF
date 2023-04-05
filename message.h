#pragma once

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>


// ����� ���������
class Message {
public:

    // ����������� ������, ����������� ����� ���������, ����������� � ����������
    Message(const std::string& text, const std::string& sender, const std::string& recipient);

    // ���������� ������
    ~Message() {
    
    }

    // ������� ��� ��������� ������, ����������� � ���������� ���������
    const std::string& getText() const;
    const std::string& getSender() const;
    const std::string& getRecipient() const;

    std::string getTime() const;

private:
    std::string text_;       // ����� ���������
    std::string sender_;     // �����������
    std::string recipient_;  // ����������
    time_t timestamp; // ����� ����-������
};
