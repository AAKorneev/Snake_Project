#pragma once
#include "const.h"

struct Game
{
	int timeout;
	bool game_on;
};

void init_game(struct Game* game, int timeout, bool game_on);

/* Установка змейки в игровое поле field */ 
void set_snake(struct Field* field, struct Snake* snake);

/* Очистка позиций которые занимала змейка */
void clear_snake(struct Field* field, struct Snake* snake);

/* Установка еды в игровое поле field */
void set_food(struct Field* field, struct Food* food);

/* Проверка: съела ли змейка еду */
void check_eating(struct Snake* snake, const struct Food* food);

/* Проверка: встретила ли змейка границу поля field */
void check_snake(const struct Field* field, struct Snake* snake);

/* Проверка завершения игры */
void check_game(const struct Field* field, const struct Snake* snake, struct Game* game);

/* Обработка нажатия клавиш */
void handle_cmd(struct Game* game, struct Snake* snake);

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(struct Game* game, struct Field* field, struct Snake* snake, struct Food* food);
