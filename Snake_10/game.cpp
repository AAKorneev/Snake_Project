#include "game.h"
#include "const.h"
#include "food.h"
#include "field.h"
#include "snake.h"
#include "winconsole.h"

#include <conio.h>
#include <iostream>
#include <windows.h>

#define AUTOMATIC

static bool food_flag = false;

void init_game(struct Game* game, int timeout, bool game_on, size_t rows, size_t columns, size_t snake_size, DIRECTION dir) {
	game->field = new Field;
	game->food = new Food;
	game->snake = new Snake;

	game->timeout = timeout;
	game->game_on = game_on;
	init_field(game->field, rows, columns);
	init_snake(game->field, game->snake, snake_size, dir);
	init_food(game->food);
	set_snake(game);
}

/* Установка змейки в игровое поле field */
void set_snake(struct Game* game) {
	for (size_t i = 0; i < game->snake->size; i++)
	{
		if (i == 0)
			game->field->arr[game->snake->y[i]][game->snake->x[i]] = head_symbol;
		else
			game->field->arr[game->snake->y[i]][game->snake->x[i]] = tail_symbol;
	}
}

/* Очистка позиций которые занимала змейка */
void clear_snake(struct Game* game) {
	for (size_t i = 0; i < game->snake->size; i++)
		game->field->arr[game->snake->y[i]][game->snake->x[i]] = field_symbol;
}

/* Установка еды в игровое поле field */
void set_food(struct Game* game) {
	if (!food_flag) {
		generate_food(game->field, game->food);
		if (game->field->arr[game->food->y][game->food->x] == field_symbol) {
			game->field->arr[game->food->y][game->food->x] = food_symbol;
			food_flag = true;
		}
	}
}

/* Проверка: съела ли змейка еду */ 
void check_eating(struct Game* game) {
	// Увеличиваем snake_size в случае поедание еды
	if (game->snake->x[0] == game->food->x && game->snake->y[0] == game->food->y) {
		game->snake->x[game->snake->size] = game->snake->x[game->snake->size - 1];
		game->snake->y[game->snake->size] = game->snake->y[game->snake->size - 1];
		game->snake->size++;
		food_flag = false;
	}
}

/* Проверка: встретила ли змейка границу поля field */
void check_snake(struct Game* game) {
	if (game->snake->x[0] == 0)
		game->snake->x[0] = game->field->columns - 2;
	else if (game->snake->x[0] == game->field->columns - 1)
		game->snake->x[0] = 1;
	else if (game->snake->y[0] == 0)
		game->snake->y[0] = game->field->rows - 2;
	else if (game->snake->y[0] == game->field->rows - 1)
		game->snake->y[0] = 1;
}

/* Проверка завершения игры */
void check_game(struct Game* game){
	if (game->snake->size >= MAXLEN)
		game->game_on = false;
	if(game->field->arr[game->snake->y[0]][game->snake->x[0]] == tail_symbol)
		game->game_on = false;
}

/* Обработка нажатия клавиш */
void handle_cmd(struct Game* game) {
	DIRECTION opp = game->snake->direction;
	int input_code = _getch();
	if(input_code == ESC)
		game->game_on = false;
	else if (input_code == FUNC_BUTTONS) {
		input_code = _getch();
		switch (input_code)
		{
		case UP_ARROW:
			if(opp != DOWN)
				game->snake->direction = UP;
			break;
		case LEFT_ARROW:
			if(opp != RIGHT)
				game->snake->direction = LEFT;
			break;
		case DOWN_ARROW:
			if(opp != UP)
				game->snake->direction = DOWN;
			break;
		case RIGHT_ARROW:
			if(opp != LEFT)
				game->snake->direction = RIGHT;
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
				game->snake->direction = UP;
			break;
		case KEY_A:
			if (opp != RIGHT)
				game->snake->direction = LEFT;
			break;
		case KEY_S:
			if (opp != UP)
				game->snake->direction = DOWN;
			break;
		case KEY_D:
			if (opp != LEFT)
				game->snake->direction = RIGHT;
			break;
		default:
			break;
		}
	}
}

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(struct Game* game) {
	clear_snake(game);
	check_eating(game);
	move_snake(game->snake);
	check_snake(game);
	set_snake(game);
}

/* Выполнение шага игры */
void next_step(struct Game* game) {
	set_food(game);						
	animate_snake(game);	
	check_game(game);
}

/* Запуск и выполнение процесса игры */
void exec_game(struct Game* game) {
	while (game->game_on) {
		print_field(game->field);
		std::cout << "Snake_size: " << game->snake->size << std::endl;
		// Отображение режима игры
#ifdef AUTOMATIC
		std::cout << "Timeout: " << game->timeout << std::endl;
		std::cout << "Press ESC for exit!" << std::endl;
		Sleep(game->timeout);
		if (_kbhit())
			handle_cmd(game);
#else
		std::cout << std::endl;
		std::cout << "Press any key for play game or ESC for exit!" << std::endl;
		handle_cmd(game);
#endif // AUTOMATIC

		next_step(game);
	}
}

/* Очистка памяти */
void destroy_game(struct Game* game) {
	destroy_field_array(game->field);
	delete game->field;
	delete game->snake;
	delete game->food;
	delete game;
}