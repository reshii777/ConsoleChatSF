#pragma once

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>


// Класс сообщение
class Message {
public:

    // Конструктор класса, принимающий текст сообщения, отправителя и получателя
    Message(const std::string& text, const std::string& sender, const std::string& recipient);

    // Деструктор класса
    ~Message() {
    
    }

    // Геттеры для получения текста, отправителя и получателя сообщения
    const std::string& getText() const;
    const std::string& getSender() const;
    const std::string& getRecipient() const;

    std::string getTime() const;

private:
    std::string text_;       // Текст сообщения
    std::string sender_;     // Отправитель
    std::string recipient_;  // Получатель
    time_t timestamp; // новый член-данные
};
