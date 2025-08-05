#pragma once
#include "const.h"

struct Game
{
	int timeout;
	bool game_on;
	struct  Snake* snake;
	struct Food* food;
	struct Field* field;
};

void init_game(struct Game* game, int timeout, bool game_on, size_t rows, size_t columns, size_t snake_size, DIRECTION dir);

/* Установка змейки в игровое поле field */
void set_snake(struct Game* game);

/* Очистка позиций которые занимала змейка */
void clear_snake(struct Game* game);

/* Установка еды в игровое поле field */
void set_food(struct Game* game);

/* Проверка: съела ли змейка еду */
void check_eating(struct Game* game);

/* Проверка: встретила ли змейка границу поля field */
void check_snake(struct Game* game);

/* Проверка завершения игры */
void check_game(struct Game* game);

/* Обработка нажатия клавиш */
void handle_cmd(struct Game* game);

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(struct Game* game);

/* Выполнение шага игры */
void next_step(struct Game* game);

/* Запуск и выполнение процесса игры */
void exec_game(struct Game* game);

/* Очистка памяти */
void destroy_game(struct Game* game);
