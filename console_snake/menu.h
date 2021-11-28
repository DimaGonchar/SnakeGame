#pragma once

#include <iostream>

#include "game.h"

namespace snakeGame {
	class Menu {
	public:
		Menu();
		void start();
	private:
		const void setGameSpeed(const char& speedValue);
		common::Speed getGameSpeed();
		void setColor(const char& colorValue);
		void hideCursor();
		void showCursor();
		void extend();
		void colorSelection();
		void speedSelection();
	private:
		common::Speed m_speed;
		std::unique_ptr<Game> m_game;
		HANDLE m_consoleColor;
		HANDLE m_cursorHandle;
		CONSOLE_CURSOR_INFO m_structCursorInfo;
	};
}