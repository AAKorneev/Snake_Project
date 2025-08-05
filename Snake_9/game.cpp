#include "game.h"
#include "const.h"
#include "food.h"
#include "field.h"
#include "snake.h"
#include "winconsole.h"

#include <conio.h>
#include <iostream>


static bool food_flag = false;

void init_game(struct Game* game, int timeout, bool game_on) {
	game->timeout = timeout;
	game->game_on = game_on;
}

/* Установка змейки в игровое поле field */ 
void set_snake(struct Field* field, struct Snake* snake) {
	for (size_t i = 0; i < snake->size; i++)
	{
		if (i == 0)
			field->arr[snake->y[i]][snake->x[i]] = head_symbol;
		else
			field->arr[snake->y[i]][snake->x[i]] = tail_symbol;
	}
}

/* Очистка позиций которые занимала змейка */
void clear_snake(struct Field* field, struct Snake* snake) {
	for (size_t i = 0; i < snake->size; i++)
		field->arr[snake->y[i]][snake->x[i]] = field_symbol;
}

/* Установка еды в игровое поле field */
void set_food(struct Field* field, struct Food* food) {
	if (!food_flag) {
		generate_food(field, food);
		if (field->arr[food->y][food->x] == field_symbol) {
			field->arr[food->y][food->x] = food_symbol;
			food_flag = true;
		}
	}
}

/* Проверка: съела ли змейка еду */ 
void check_eating(struct Snake* snake, const struct Food* food) {
	// Увеличиваем snake_size в случае поедание еды
	if (snake->x[0] == food->x && snake->y[0] == food->y) {
		snake->x[snake->size] = snake->x[snake->size - 1];
		snake->y[snake->size] = snake->y[snake->size - 1];
		snake->size++;
		food_flag = false;
	}
}

/* Проверка: встретила ли змейка границу поля field */
void check_snake(const struct Field* field, struct Snake* snake) {
	if (snake->x[0] == 0)
		snake->x[0] = field->columns - 2;
	else if (snake->x[0] == field->columns - 1)
		snake->x[0] = 1;
	else if (snake->y[0] == 0)
		snake->y[0] = field->rows - 2;
	else if (snake->y[0] == field->rows - 1)
		snake->y[0] = 1;
}

/* Проверка завершения игры */
void check_game(const struct Field* field, const struct Snake* snake, struct Game* game){
	if (snake->size >= MAXLEN)
		game->game_on = false;
	if(field->arr[snake->y[0]][snake->x[0]] == tail_symbol)
		game->game_on = false;
}

/* Обработка нажатия клавиш */
void handle_cmd(struct Game* game, struct Snake* snake) {
	DIRECTION opp = snake->direction;
	int input_code = _getch();
	if(input_code == ESC)
		game->game_on = false;
	else if (input_code == FUNC_BUTTONS) {
		input_code = _getch();
		switch (input_code)
		{
		case UP_ARROW:
			if(opp != DOWN)
				snake->direction = UP;
			break;
		case LEFT_ARROW:
			if(opp != RIGHT)
				snake->direction = LEFT;
			break;
		case DOWN_ARROW:
			if(opp != UP)
				snake->direction = DOWN;
			break;
		case RIGHT_ARROW:
			if(opp != LEFT)
				snake->direction = RIGHT;
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
				snake->direction = UP;
			break;
		case KEY_A:
			if (opp != RIGHT)
				snake->direction = LEFT;
			break;
		case KEY_S:
			if (opp != UP)
				snake->direction = DOWN;
			break;
		case KEY_D:
			if (opp != LEFT)
				snake->direction = RIGHT;
			break;
		default:
			break;
		}
	}
}

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(struct Game* game, struct Field* field, struct Snake* snake, struct Food* food) {
	clear_snake(field, snake);
	check_eating(snake, food);
	move_snake(snake);
	check_snake(field, snake);
	set_snake(field, snake);
}