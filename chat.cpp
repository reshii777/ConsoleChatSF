#include "chat.h"
#include <iostream>

// Метод для входа пользователя в чат
void Chat::loginUser() {
    std::string login, password;
    std::cout << "  Введите логин: ";
    std::cin >> login;
    std::cout << "  Введите пароль: ";
    std::cin >> password;

    std::cout << "---------------------" << std::endl << std::endl;

    bool userFound = false;
    // Поиск пользователя с указанным логином и паролем в списке пользователей
    for (const auto& user : userList) {
        if (user.getLogin() == login && user.getPassword() == password) {
            std::cout << "  Вы успешно вошли в чат!" << std::endl << std::endl;
            std::cout << "  Здравствуйте, " << user.getName() << "." << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;
            userFound = true;

            while (true) {
                std::cout << "  Выберите действие:" << std::endl << std::endl;
                std::cout << "  1. Отправить сообщение" << std::endl;
                std::cout << "  2. Прочитать сообщения" << std::endl;
                std::cout << "  3. Просмотреть зарегистрированных пользователей" << std::endl;
                std::cout << "  4. Выйти из чата" << std::endl;
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
                    break; // выход из цикла
                }
                else {
                    std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                }
            }
            break;
        }
    }

    if (!userFound) {
        std::cout << "  Пользователь с таким логином и паролем не найден." << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << "  Выберите пункт: " << std::endl << std::endl;
    }
}

void Chat::registerUser() {
    std::string login, password, name;
    std::cout << "  Введите логин: ";
    std::cin >> login;
    std::cout << "  Введите пароль: ";
    std::cin >> password;
    std::cout << "  Введите имя: ";
    std::cin >> name;

    std::cout << "---------------------" << std::endl << std::endl;


    bool userExists = false;
    for (const auto& user : userList) {
        if (user.getLogin() == login) {
            std::cout << "  Пользователь с таким логином уже существует." << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;
            std::cout << " Выберите пункт: " << std::endl << std::endl;
            userExists = true;
            break;
        }
    }

    if (!userExists) {
        userList.emplace_back(login, password, name); // добавляем нового пользователя в список
        std::cout << "  Пользователь " << name << " успешно зарегистрирован!" << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << " Выберите пункт: " << std::endl << std::endl;
    }
}

void Chat::sendMessage(const User& sender, const std::string& recipient, const std::string& text) {
    messageList.emplace_back(sender.getName(), recipient, text); // добавляем новое сообщение в список
    std::cout << "  Сообщение для " << recipient << " отправлено: " << text << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;
}


void Chat::sendUserMessage(const User& sender) {
    std::string recipient, text;
    if (getUserInput(recipient, text)) {
        auto it = std::find_if(userList.begin(), userList.end(), [&recipient](const User& user) { return user.getName() == recipient; });
        if (it != userList.end()) {
            // Если получатель найден, отправляем сообщение
            sendMessage(sender, recipient, text);
        }
        else {
            // Если получатель не найден, выводим сообщение об ошибке
            std::cout << "  Пользователь с именем " << recipient << " не найден." << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;
        }
    }
}

bool Chat::getUserInput(std::string& recipient, std::string& text) const {
    // Запрашиваем у пользователя имя получателя и сообщение
    std::cout << "  Введите имя получателя: ";
    std::cin >> recipient;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Ошибка ввода. Попробуйте еще раз." << std::endl;
        return false;
    }
    std::cout << "  Введите сообщение: ";
    std::cin.ignore(); // очищаем буфер ввода
    std::getline(std::cin, text);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Ошибка ввода. Попробуйте еще раз." << std::endl;
        return false;
    }
    return true;
}

void Chat::readMessages() {
    std::cout << "Сообщения в чате:" << std::endl;
    for (const auto& message : messageList) {
        std::cout << "  " << message.getSender() << " -> " << message.getRecipient() << ": " << message.getText() << " Время отправления: (" << message.getTime() << "): " << std::endl;
    }
    std::cout << "---------------------" << std::endl << std::endl;
}


void Chat::viewUsers() {
    std::cout << "  Зарегистрированные пользователи:" << std::endl << std::endl;
    std::cout << " Выберите пункт: " << std::endl << std::endl;
    int userCount = 0; // общее количество пользователей
    for (const auto& user : userList) {
        std::cout << "Имя пользователя: " << user.getName() << std::endl;
        userCount++; // увеличиваем количество пользователей
    }
    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Всего зарегистрированных пользователей: " << userCount << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;
}
