#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

int timeout = 100;
bool game_on = true;
bool is_auto = false;
int input_code = 0; 

static bool food_flag = false;

/*
	Меню игры:
	- Выбор режима игры
	- Выбор направления движения
	- Выбор размера змейки
*/
void init_game() {
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
		if (timeout <= 0)
			timeout = 100;
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
	std::cout << "Set the snake size: ";
	std::cin >> snake_size;
	if (snake_size <= 0)
		snake_size = 1;
	std::cout << std::endl;
}

/* Установка змейки в игровое поле field */
void set_snake() {
	// Устанавливаем змейку в игровое поле field 
	for (size_t i = 0; i < snake_size; i++) {
		if (i == 0)
			field[snake_x[i]] = head_symbol;
		else if (snake_x[i] > 0)
			field[snake_x[i]] = tail_symbol;
	}
}

/* Установка еды в игровое поле field */
void set_food() {
	// массив свободных координат
	size_t free_x[MAXLEN] = { 0 };
	size_t rand_idx = 0; // рандомный индекс в массиве свободных координат
	size_t free_count = 0; // счетчик свободных координат

	if (!food_flag) {
		// Заполняем массив свободных координат
		free_count = 0;
		for (size_t i = 0; i <= COLUMNS - 2; i++) {
			if (field[i] == field_symbol) {
				free_x[free_count] = i;
				free_count++;
			}
		}
		// Опрeделяем рандомный индекс в интервале от 0 до free_count - 1		
		if (free_count > 0) {
			if (free_count == 1)
				food_x = free_x[0];
			else {
				rand_idx = rand() % (free_count - 1);
				food_x = free_x[rand_idx];
			}
			food_flag = true;
		}
		else
			game_on = false;
	}

	if (food_flag)
		field[food_x] = food_symbol;
}

/* Проверка: съела ли змейка еду */
void check_eating() {
	// Увеличиваем snake_size в случае поедание еды
	if (snake_x[0] == food_x) {
		food_flag = false;
		snake_size++;
		if (direction == LEFT) {
			snake_x[snake_size - 1] = snake_x[snake_size - 2] + 1;
			if (snake_x[snake_size - 1] == COLUMNS - 1)
				snake_x[snake_size - 1] = 1;
		}
		if (direction == RIGHT) {
			snake_x[snake_size - 1] = snake_x[snake_size - 2] - 1;
			if (snake_x[snake_size - 1] == 0)
				snake_x[snake_size - 1] = COLUMNS - 2;
		}
	}
}

/* Очистка позиций которые занимала змейка */
void clear_snake() {
	clear_field();	
}

/* Проверка: встретила ли змейка границу поля field */
void check_snake() {
	for (size_t i = 0; i < snake_size; i++)
	{
		if (direction == LEFT && snake_x[i] == 0)
			snake_x[i] = COLUMNS - 2;
		else if (direction == RIGHT && snake_x[i] == COLUMNS - 1)
			snake_x[i] = 1;
	}
}

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake() {
	clear_snake();
	set_snake();
	check_eating();
	move_snake();
	check_snake();
}

/* Проверка завершения игры */
void check_game() {
	if (input_code == ESC)
		game_on = false;
}

/* Обработка нажатия клавиш */
void handle_cmd() {
	input_code = _getch();
}

/* Режим игры: автоматическое или ручное управление */
void game_mode() {
	// Отображение режима игры
	if (is_auto) {
		std::cout << "Timeout: " << timeout << std::endl;
		std::cout << "Press ESC for exit!" << std::endl;
		Sleep(timeout);
		if (_kbhit())
			handle_cmd();
	}
	else {
		std::cout << std::endl;
		std::cout << "Press any key for play game or ESC for exit!" << std::endl;
		handle_cmd();
	}
}

