#include "chat.h"
#include <iostream>

// ����� ��� ����� ������������ � ���
void Chat::loginUser() {
    std::string login, password;
    std::cout << "  ������� �����: ";
    std::cin >> login;
    std::cout << "  ������� ������: ";
    std::cin >> password;

    std::cout << "---------------------" << std::endl << std::endl;

    bool userFound = false;
    // ����� ������������ � ��������� ������� � ������� � ������ �������������
    for (const auto& user : userList) {
        if (user.getLogin() == login && user.getPassword() == password) {
            std::cout << "  �� ������� ����� � ���!" << std::endl << std::endl;
            std::cout << "  ������������, " << user.getName() << "." << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;
            userFound = true;

            while (true) {
                std::cout << "  �������� ��������:" << std::endl << std::endl;
                std::cout << "  1. ��������� ���������" << std::endl;
                std::cout << "  2. ��������� ���������" << std::endl;
                std::cout << "  3. ����������� ������������������ �������������" << std::endl;
                std::cout << "  4. ����� �� ����" << std::endl;
                std::cout << "---------------------" << std::endl << std::endl;

                int choice;
                std::cin >> choice;
                std::cout << "---------------------" << std::endl << std::endl;

                if (choice == 1) {
                    sendUserMessage(user);
                }
                else if (choice == 2) {
                    readMessages();
                }
                else if (choice == 3) {
                    viewUsers();
                }
                else if (choice == 4) {
                    break; // ����� �� �����
                }
                else {
                    std::cout << "������������ �����. ���������� �����." << std::endl;
                }
            }
            break;
        }
    }

    if (!userFound) {
        std::cout << "  ������������ � ����� ������� � ������� �� ������." << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << "  �������� �����: " << std::endl << std::endl;
    }
}

void Chat::registerUser() {
    std::string login, password, name;
    std::cout << "  ������� �����: ";
    std::cin >> login;
    std::cout << "  ������� ������: ";
    std::cin >> password;
    std::cout << "  ������� ���: ";
    std::cin >> name;

    std::cout << "---------------------" << std::endl << std::endl;


    bool userExists = false;
    for (const auto& user : userList) {
        if (user.getLogin() == login) {
            std::cout << "  ������������ � ����� ������� ��� ����������." << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;
            std::cout << " �������� �����: " << std::endl << std::endl;
            userExists = true;
            break;
        }
    }

    if (!userExists) {
        userList.emplace_back(login, password, name); // ��������� ������ ������������ � ������
        std::cout << "  ������������ " << name << " ������� ���������������!" << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << " �������� �����: " << std::endl << std::endl;
    }
}

void Chat::sendMessage(const User& sender, const std::string& recipient, const std::string& text) {
    messageList.emplace_back(sender.getName(), recipient, text); // ��������� ����� ��������� � ������
    std::cout << "  ��������� ��� " << recipient << " ����������: " << text << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;
}


void Chat::sendUserMessage(const User& sender) {
    std::string recipient, text;
    if (getUserInput(recipient, text)) {
        auto it = std::find_if(userList.begin(), userList.end(), [&recipient](const User& user) { return user.getName() == recipient; });
        if (it != userList.end()) {
            // ���� ���������� ������, ���������� ���������
            sendMessage(sender, recipient, text);
        }
        else {
            // ���� ���������� �� ������, ������� ��������� �� ������
            std::cout << "  ������������ � ������ " << recipient << " �� ������." << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;
        }
    }
}

bool Chat::getUserInput(std::string& recipient, std::string& text) const {
    // ����������� � ������������ ��� ���������� � ���������
    std::cout << "  ������� ��� ����������: ";
    std::cin >> recipient;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  ������ �����. ���������� ��� ���." << std::endl;
        return false;
    }
    std::cout << "  ������� ���������: ";
    std::cin.ignore(); // ������� ����� �����
    std::getline(std::cin, text);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  ������ �����. ���������� ��� ���." << std::endl;
        return false;
    }
    return true;
}

void Chat::readMessages() {
    std::cout << "��������� � ����:" << std::endl;
    for (const auto& message : messageList) {
        std::cout << "  " << message.getSender() << " -> " << message.getRecipient() << ": " << message.getText() << " ����� �����������: (" << message.getTime() << "): " << std::endl;
    }
    std::cout << "---------------------" << std::endl << std::endl;
}


void Chat::viewUsers() {
    std::cout << "  ������������������ ������������:" << std::endl << std::endl;
    std::cout << " �������� �����: " << std::endl << std::endl;
    int userCount = 0; // ����� ���������� �������������
    for (const auto& user : userList) {
        std::cout << "��� ������������: " << user.getName() << std::endl;
        userCount++; // ����������� ���������� �������������
    }
    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "����� ������������������ �������������: " << userCount << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;
}
