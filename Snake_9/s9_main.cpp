#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"
#include "food.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

int main() {
	srand(time(0));						// seed для random 

	Field* field = new Field;
	Snake* snake = new Snake;
	Food* food = new Food;
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
	bool is_auto = false;				// Режим игры (автоматически или пошагово)

	/*	Меню игры:  */
#if 1
	{
		// Выбор режима игры
		char user_mode = 0;
		std::cout << "Snake game!" << std::endl;
		std::cout << "Do you want to select AUTO mode? YES or NO (y/n)? ";
		std::cin >> user_mode;
		switch (user_mode)
		{
		case 'n':
		case 'N':
			std::cout << "Step-by-step control selected!" << std::endl;
			std::cout << std::endl;
			break;
		case 'y':
		case 'Y':
			std::cout << "AUTO mode selected!" << std::endl;
			is_auto = true;
			std::cout << "Set the timeout value: ";
			std::cin >> timeout;
			if (timeout <= 0) {
				std::cout << "Incorrect! Default timeout selected!" << std::endl;
			}
			break;
		default:
			std::cout << "Incorrect! Default step-by-step control selected!" << std::endl;
			break;
		}

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

	init_game(game, timeout, game_on);
	init_field(field, rows, columns);					// Заполнение массива игрового поля
	init_snake(field, snake, snake_size, direction);	// Инициализация змейки
	init_food(food);									// Инициализация еды	
	set_snake(field, snake);							// Установка змейки в поле
	system("cls");										// Очистка меню перед выводом поля

	while (game->game_on) {
		print_field(field);
		std::cout << "Snake_size: " << snake->size << std::endl;
		// Отображение режима игры
		if (is_auto) {
			std::cout << "Timeout: " << game->timeout << std::endl;
			std::cout << "Press ESC for exit!" << std::endl;
			Sleep(game->timeout);
			if (_kbhit())
				handle_cmd(game, snake);
		}
		else {
			std::cout << std::endl;
			std::cout << "Press any key for play game or ESC for exit!" << std::endl;
			handle_cmd(game, snake);
		}

		set_food(field, food);						// Установка еды в поле
		animate_snake(game, field, snake, food);	// Анимация змейки
		check_game(field, snake, game);				// Проверка завершения игры
	}

	std::cout << std::endl;
	std::cout << "The End!" << std::endl;

	destroy_field_array(field);
	delete food;
	delete snake;
	delete field;
	delete game;
	return 0;

}