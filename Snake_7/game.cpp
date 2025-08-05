#include "game.h"
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
void set_snake(char field[][COLUMNS], const size_t* snake_x, const size_t* snake_y, size_t snake_size) {
	for (size_t i = 0; i < snake_size; i++)
	{
		if (i == 0)
			field[snake_y[i]][snake_x[i]] = head_symbol;
		else
			field[snake_y[i]][snake_x[i]] = tail_symbol;
	}
}

/* Очистка позиций которые занимала змейка */
void clear_snake(char field[][COLUMNS], const size_t* snake_x, const size_t* snake_y, size_t snake_size) {
	for (size_t i = 0; i < snake_size; i++)
		field[snake_y[i]][snake_x[i]] = field_symbol;
}

/* Установка еды в игровое поле field */
void set_food(char field[][COLUMNS], size_t* food_x, size_t* food_y) {
	if (!food_flag) {
		generate_food(food_x, food_y);
		if (field[*food_y][*food_x] == field_symbol) {
			field[*food_y][*food_x] = food_symbol;
			food_flag = true;
		}
	}
}

/* Проверка: съела ли змейка еду */
void check_eating(size_t* snake_x, size_t* snake_y, size_t* snake_size, size_t food_x, size_t food_y) {
	// Увеличиваем snake_size в случае поедание еды
	if (snake_x[0] == food_x && snake_y[0] == food_y) {
		snake_x[*snake_size] = snake_x[*snake_size - 1];
		snake_y[*snake_size] = snake_y[*snake_size - 1];
		(*snake_size)++;
		food_flag = false;
	}
}

/* Проверка: встретила ли змейка границу поля field */
void check_snake(char field[][COLUMNS], size_t* snake_x, size_t* snake_y, DIRECTION direction) {
	if (snake_x[0] == 0)
		snake_x[0] = COLUMNS - 2;
	else if (snake_x[0] == COLUMNS - 1)
		snake_x[0] = 1;
	else if (snake_y[0] == 0)
		snake_y[0] = ROWS - 2;
	else if (snake_y[0] == ROWS - 1)
		snake_y[0] = 1;
}

/* Проверка завершения игры */
void check_game(char field[][COLUMNS], size_t* snake_x, size_t* snake_y, bool* game_on, size_t snake_size) {
	if (snake_size >= MAXLEN)
		*game_on = false;
	if(field[snake_y[0]][snake_x[0]] == tail_symbol)
		*game_on = false;
}

/* Обработка нажатия клавиш */
void handle_cmd(bool* game_on, DIRECTION* direction) {
	DIRECTION opp = *direction;
	int input_code = _getch();
	if(input_code == ESC)
		*game_on = false;
	else if (input_code == FUNC_BUTTONS) {
		input_code = _getch();
		switch (input_code)
		{
		case UP_ARROW:
			if(opp != DOWN)
				*direction = UP;
			break;
		case LEFT_ARROW:
			if(opp != RIGHT)
				*direction = LEFT;
			break;
		case DOWN_ARROW:
			if(opp != UP)
				*direction = DOWN;
			break;
		case RIGHT_ARROW:
			if(opp != LEFT)
				*direction = RIGHT;
			break;
		default:
			break;
		}
	}
	else {
		switch (input_code)
		{
		case KEY_W:
			if (opp != DOWN)
				*direction = UP;
			break;
		case KEY_A:
			if (opp != RIGHT)
				*direction = LEFT;
			break;
		case KEY_S:
			if (opp != UP)
				*direction = DOWN;
			break;
		case KEY_D:
			if (opp != LEFT)
				*direction = RIGHT;
			break;
		default:
			break;
		}
	}
}

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(char field[][COLUMNS], size_t* snake_x, size_t* snake_y, size_t* snake_size, 
											size_t food_x, size_t food_y, DIRECTION direction) {
	clear_snake(field, snake_x, snake_y, *snake_size);
	check_eating(snake_x, snake_y, snake_size, food_x, food_y);
	move_snake(snake_x, snake_y, *snake_size, direction);
	check_snake(field, snake_x, snake_y, direction);
	set_snake(field, snake_x, snake_y, *snake_size);
}