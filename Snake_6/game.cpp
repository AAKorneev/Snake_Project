#include "const.h"
#include "food.h"
#include "field.h"
#include "snake.h"
#include "winconsole.h"

#include <conio.h>
#include <iostream>


static bool food_flag = false;

void init_game(int* timeout) { 
	*timeout = TIMEOUT_DEFAULT;
}
 
/* Установка змейки в игровое поле field */
void set_snake(char* field, const size_t* snake_x, size_t snake_size) {
	// Устанавливаем змейку в игровое поле field 
	for (size_t i = 0; i < snake_size; i++) {
		if (i == 0)
			field[snake_x[i]] = head_symbol;
		else if (snake_x[i] > 0)
			field[snake_x[i]] = tail_symbol;
	}
}

/* Очистка позиций которые занимала змейка */
void clear_snake(char* field) {
	clear_field(field);
}

size_t generate_food(const size_t* free_x, size_t free_count) {
	/* Генерируем рандомный индекс для массива свободных координат
	   и выдаем значение установки еды в свободных координатах*/
	if (free_count == 1)
		return free_x[0];
	else {
		return free_x[(rand() % (free_count - 1))];
	}
}

/* Установка еды в игровое поле field */
void set_food(char* field, size_t* food_x, bool* game_on) {
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

		// Опрeделяем индекс установки еды в свободных координатах	
		if (free_count > 0) {
			*food_x = generate_food(free_x, free_count);
			food_flag = true;
		}
		else
			*game_on = false;
	}

	if (food_flag)
		field[*food_x] = food_symbol;
}

/* Проверка: встретила ли змейка границу поля field */
void check_snake(size_t* snake_x, size_t snake_size, DIRECTION direction) {
	for (size_t i = 0; i < snake_size; i++)
	{
		if (direction == LEFT && snake_x[i] == 0)
			snake_x[i] = COLUMNS - 2;
		else if (direction == RIGHT && snake_x[i] == COLUMNS - 1)
			snake_x[i] = 1;
	}
}

/* Проверка: съела ли змейка еду */
void check_eating(size_t* snake_x, size_t* snake_size, size_t food_x, DIRECTION direction) {
	// Увеличиваем snake_size в случае поедание еды
	if (snake_x[0] == food_x) {
		food_flag = false;
		(*snake_size)++;
		if (direction == LEFT) {
			snake_x[*snake_size - 1] = snake_x[*snake_size - 2] + 1;
			if (snake_x[*snake_size - 1] == COLUMNS - 1)
				snake_x[*snake_size - 1] = 1;
		}
		else if (direction == RIGHT) {
			snake_x[*snake_size - 1] = snake_x[*snake_size - 2] - 1;
			if (snake_x[*snake_size - 1] == 0)
				snake_x[*snake_size - 1] = COLUMNS - 2;
		}
	}
}

/* Проверка завершения игры */
void check_game(bool* game_on, size_t snake_size) {
	if (snake_size > MAXLEN)
		*game_on = false;
}

/* Обработка нажатия клавиш */
void handle_cmd(bool* game_on) {
	int input_code = _getch();
	if(input_code == ESC)
		*game_on = false;
}

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(char* field, size_t* snake_x, size_t* snake_size, size_t food_x, DIRECTION direction) {
	clear_snake(field);
	check_eating(snake_x, snake_size, food_x, direction);
	set_snake(field, snake_x, *snake_size);
	move_snake(snake_x, *snake_size, direction);
	check_snake(snake_x, *snake_size, direction);
}