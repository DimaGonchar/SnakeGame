#include "menu.h"

snakeGame::Menu::Menu() :
	m_consoleColor{ GetStdHandle(STD_OUTPUT_HANDLE) },
	m_cursorHandle{ GetStdHandle(STD_OUTPUT_HANDLE) }
{
}

void snakeGame::Menu::start() {

	std::cout << "\t\t\t****************************" << std::endl;
	std::cout << "\t\t\t*welcome to the snake game!*" << std::endl;
	std::cout << "\t\t\t****************************" << std::endl << std::endl;
	extend();
	while (true) {
		std::cout << "\t\t\t\tMemu:" << std::endl;
		colorSelection();
		speedSelection();
		hideCursor();
		m_game = std::make_unique<Game>(getGameSpeed());
		m_game->start();
		showCursor();
		m_game.reset();
	}
}

const void snakeGame::Menu::setGameSpeed(const char& speed)
{
	switch (speed)
	{
	case '1': m_speed = common::Speed::LOW; break;
	case '2': m_speed = common::Speed::MIDDLE; break;
	case '3': m_speed = common::Speed::HIGH; break;
	default:break;
	}
}

snakeGame::common::Speed snakeGame::Menu::getGameSpeed()
{
	return m_speed;
}

void snakeGame::Menu::setColor(const char& colorValue) {
	switch (colorValue)
	{
	case '1': SetConsoleTextAttribute(m_consoleColor, common::Color::BLUE); break;
	case '2': SetConsoleTextAttribute(m_consoleColor, common::Color::RED); break;
	case '3': SetConsoleTextAttribute(m_consoleColor, common::Color::YELLOW); break;
	default: break;
	}
}

void snakeGame::Menu::hideCursor() {
	GetConsoleCursorInfo(m_cursorHandle, &m_structCursorInfo);
	m_structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(m_cursorHandle, &m_structCursorInfo);
}

void snakeGame::Menu::showCursor()
{
	GetConsoleCursorInfo(m_cursorHandle, &m_structCursorInfo);
	m_structCursorInfo.bVisible = true;
	SetConsoleCursorInfo(m_cursorHandle, &m_structCursorInfo);
}

void snakeGame::Menu::extend() {
	std::cout << std::endl;
	std::cout << "enter any letter and press ENTER: ";
	std::cin.get();
	system("cls");
}

void snakeGame::Menu::colorSelection() {
	std::cout << " select color: 1 - BLUE, 2 - RED, 3 - YELLOW, other - leave current : ";
	char color;
	while (true) {
		std::cin >> color;
		if (color < 49 || color > 51)
		{
			std::cout << "there is no such option, repeat: " << std::endl;
			std::cin.clear();
		}
		else {
			setColor(color);
			return;
		}
	}
}

void snakeGame::Menu::speedSelection() {
	char speed;
	while (true) {
		std::cout << " select speed: 1 - LOW, 2 - MIDDLE, 3 - HIGH:";
		std::cin >> speed;
		if (speed < 49 || speed > 51)
		{
			std::cout << "there is no such option, repeat: " << std::endl;
			std::cin.clear();
		}
		else
		{
			setGameSpeed(speed);
			system("cls");
			return;
		}
	}
}

