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
	// Module Field
	char field[ROWS][COLUMNS] = { 0 };

	// Module Snake
	size_t snake_size = 0;
	size_t snake_x[MAXLEN] = { 0 };
	size_t snake_y[MAXLEN] = { 0 };
	DIRECTION direction = RIGHT;

	// Module Game
	bool game_on = true;
	int timeout = 0;
	bool is_auto = false;				// Режим игры (автоматически или пошагово)

	// Module Food
	size_t food_x = 0;
	size_t food_y = 0;
	

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
			break;
		case 'y':
		case 'Y':
			std::cout << "AUTO mode selected!" << std::endl;
			is_auto = true;
			std::cout << "Set the timeout value: ";
			std::cin >> timeout;
			if (timeout <= 0) {
				std::cout << "Incorrect! Default timeout selected!" << std::endl;
				init_game(&timeout);				// Инициализация игры (таймаут по умолчанию)
			}
			break;
		default:
			std::cout << "Incorrect! Default step-by-step control selected!" << std::endl;
			break;
		}

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
		std::cout << "Set the snake size (max 8): ";
		std::cin >> snake_size;
		if (snake_size <= 0 || snake_size > 8)
			snake_size = 3;
		std::cout << std::endl;
	}
#endif

	init_field(field);										// Заполнение массива игрового поля
	init_snake(snake_x, snake_y, snake_size, direction);	// Инициализация змейки
	init_food();											// Загушка		
	set_snake(field, snake_x, snake_y, snake_size);			// Установка змейки в поле
	system("cls");											// Очистка меню перед выводом поля

	while (game_on) {
		print_field(field);
		std::cout << "Snake_size: " << snake_size << std::endl;
		// Отображение режима игры
		if (is_auto) {
			std::cout << "Timeout: " << timeout << std::endl;
			std::cout << "Press ESC for exit!" << std::endl;
			Sleep(timeout);
			if (_kbhit())
				handle_cmd(&game_on, &direction);
		}
		else {
			std::cout << std::endl;
			std::cout << "Press any key for play game or ESC for exit!" << std::endl;
			handle_cmd(&game_on, &direction);
		}

		set_food(field, &food_x, &food_y);												// Установка еды в поле
		animate_snake(field, snake_x, snake_y, &snake_size, food_x, food_y, direction);	// Анимация змейки
		check_game(field, snake_x, snake_y, &game_on, snake_size);						// Проверка завершения игры
	}

	std::cout << std::endl;
	std::cout << "The End!" << std::endl;

	return 0;

}