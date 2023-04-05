#include "message.h"

// Реализация конструктора класса Message
Message::Message(const std::string& text, const std::string& sender, const std::string& recipient)
    : text_(text), sender_(sender), recipient_(recipient)
{
    timestamp = std::time(nullptr);
}

// Реализация геттеров для класса Message
const std::string& Message::getText() const {
    return text_;
}

const std::string& Message::getSender() const {
    return sender_;
}

const std::string& Message::getRecipient() const {
    return recipient_;
}

std::string Message::getTime() const {
    std::stringstream ss;
    std::tm timeinfo = {};
    localtime_s(&timeinfo, &timestamp);
    ss << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
