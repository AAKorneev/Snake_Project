#include <iostream>
#include <windows.h>
#include <conio.h>
#include "const.h"
#include "game.h"
#include "field.h"
#include "snake.h"
#include "food.h"
 
int main() {
	srand(time(0));						// seed для random
	size_t snake_size_m = 1;			// Текущий размер змейки. По умолчанию 1
	size_t snake_x_m[MAXLEN] = { 0 };	// Массив координат змейки по горизонтали (Х)
	char field_m[COLUMNS] = { 0 };		// Массив игрового поля
	size_t food_x_m = 0;				// Координата еды по горизонтали (Х)
	bool game_on_m = true;				// Признак продолжения игры
	DIRECTION direction_m = LEFT;		// Направление движения змейки

	bool is_auto = false;				// Режим игры (автоматически или пошагово)
	int timeout = 0;

	init_game(&timeout);				// Инициализация игры

	/*	Меню игры:
		- Выбор режима игры
		- Выбор направления движения
		- Выбор размера змейки */
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
			direction_m = LEFT;
			break;
		case 'r':
		case 'R':
			direction_m = RIGHT;
			break;
		default:
			std::cout << "Incorrect! Default LEFT selected!" << std::endl;
			break;
		}

		// Выбор размера змейки
		std::cout << "Set the snake size: ";
		std::cin >> snake_size_m;
		if (snake_size_m <= 0)
			snake_size_m = 1;
		std::cout << std::endl;
	}

	init_field(field_m);								// Заполнение массива игрового поля
	init_snake(snake_x_m, snake_size_m, direction_m);	// Инициализация змейки
	init_food();										// Загушка (пока)
	set_snake(field_m, snake_x_m, snake_size_m);		// Установка змейки в поле
	system("cls");										// Очистка меню перед выводом поля
	print_field(field_m);								// Вывод поля на экран

	while (game_on_m) {
		// Отображение режима игры
		if (is_auto) {
			std::cout << "Timeout: " << timeout << std::endl;
			std::cout << "Press ESC for exit!" << std::endl;
			Sleep(timeout);
			if (_kbhit())
				handle_cmd(&game_on_m);
		}
		else {
			std::cout << std::endl;
			std::cout << "Press any key for play game or ESC for exit!" << std::endl;
			handle_cmd(&game_on_m);
		}

		animate_snake(field_m, snake_x_m, &snake_size_m, food_x_m, direction_m);	// Анимация змейки
		set_food(field_m, &food_x_m, &game_on_m);									// Установка еды в поле
		check_game(&game_on_m, snake_size_m);										// Проверка завершения игры
		print_field(field_m);														// Вывод поля на экран
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The End!" << std::endl;
	std::cout << std::endl;

	return 0;
}