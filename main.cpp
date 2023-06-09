// Для реализации чата с таким функционалом можно создать следующие классы и файлы :

// main.cpp : основной файл, в котором создается объект чата и запускается его метод run();
// chat.h и chat.cpp: класс чата, который содержит список пользователей и список сообщений;
// user.h и user.cpp: класс пользователя, содержащий данные пользователя(логин, пароль, имя);
// message.h и message.cpp: класс сообщения, содержащий текст сообщения, отправителя и получателя.

#include <iostream>
#include "chat.h"
#include <windows.h>

//using namespace std;

int main() {
	// русская локализация
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru_Ru");

	Chat chat;

	// Заголовок
	std::cout << " Проект SkillFactory." << std::endl;
	std::cout << " Приветствую тебя, Джедай." << std::endl;
	std::cout << " Да пребудет с тобой сила." << std::endl;
	std::cout << " version 1.0\n " << std::endl;
	
	// Бесконечный цикл, в котором запрашиваются команды от пользователя
	while (true) {
		// Выводим список команд и запрашиваем у пользователя выбор команды
		std::cout	<< "   1: [Вход существующего пользователя] \n"
					<< "   2: [Регистрация нового пользователя] \n"
					<< "   0: [Закрыть]\n" << std::endl;

		std::cout << "---------------------" << std::endl << std::endl;
		std::cout << " Выберите пункт: ";

		int choice;
		std::cin >> choice;
		std::cout << "---------------------\n" << std::endl;

		// Обрабатываем выбор пользователя
		switch (choice){
		case 1: {
			chat.loginUser();
			break;
		}

		case 2: {
			// Регистрируем пользователя
			chat.registerUser();
			break;
		}

		case 0:
			std::cout << "\n   Завершение работы...  " << '\n';
			std::cout << "--------------" << std::endl << std::endl;
			//break;
			return 0;

		default:
			std::cout << "\n [ Неверный выбор. Попробуйте снова. ]" << std::endl;
			std::cout << "--------------------------------------------------" << std::endl << std::endl;
			break;
		}
	}

	// Запрашиваем у пользователя имя получателя и текст сообщения
	std::string recipient, message;
	std::cout << "Введите имя получателя: ";
	std::cin >> recipient;
	std::cout << "Введите текст сообщения: ";
	std::cin >> message;

	// Отправляем сообщение пользователю
	std::cout << "Сообщение для " << recipient << " отправлено: " << message << std::endl

	return 0;
}
