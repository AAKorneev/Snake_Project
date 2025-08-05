#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"
#include "food.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

#define AUTOMATIC

int main() {
	srand(time(0));						// seed для random

	Game* game = new Game;

	// Module Field
	size_t rows = 0;
	size_t columns = 0;

	// Module Snake
	size_t snake_size = 0;
	DIRECTION direction = LEFT;

	// Module Game
	bool game_on = true;
	int timeout = 0;

	/*	Меню игры:  */
#if 1
	{
		std::cout << "Snake game!" << std::endl;
#ifdef AUTOMATIC
		std::cout << "Set the timeout value (default 200): ";
		std::cin >> timeout;
		if (timeout <= 0) {
			std::cout << "Incorrect! Default timeout selected!" << std::endl;
		}
#endif // AUTOMATIC

		// Выбор размера поля
		std::cout << "Let's set the field size! Max size: 100x100" << std::endl;
		std::cout << "How many ROWS? ";
		std::cin >> rows;
		if (rows <= 0 || rows > 100)
			rows = 10;
		else
			rows = rows + 2; // (+2) - добавить границы полей сверху и снизу

		std::cout << "How many COLUMNS? ";
		std::cin >> columns;
		if (columns <= 0 || columns > 100)
			columns = 10;
		else
			columns = columns + 2; // (+2) - добавить границы полей слева и справа

		// Выбор направления движения
		char user_direction = 0;
		std::cout << "Set the snake movement: LEFT or RIGHT (L/R)? ";
		std::cin >> user_direction;
		switch (user_direction)
		{
		case 'l':
		case 'L':
			direction = LEFT;
			break;
		case 'r':
		case 'R':
			direction = RIGHT;
			break;
		default:
			std::cout << "Incorrect! Default LEFT selected!" << std::endl;
			break;
		}

		// Выбор размера змейки
		std::cout << "Set the snake size (max: " << columns - 2 << "): ";
		std::cin >> snake_size;
		if (snake_size <= 0 || snake_size > columns - 2)
			snake_size = 3;
		std::cout << std::endl;
	}
#endif
	system("cls");										// Очистка меню перед выводом поля

	init_game(game, timeout, game_on, rows, columns, snake_size, direction);
	exec_game(game);

	std::cout << std::endl;
	std::cout << "The End!" << std::endl;

	system("pause");

	destroy_game(game);
	return 0;
}