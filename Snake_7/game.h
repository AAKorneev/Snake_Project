#pragma once
#include "const.h"

void init_game(int* timeout);

/* Установка змейки в игровое поле field */ 
void set_snake(char field[][COLUMNS], const size_t* snake_x, const size_t* snake_y, size_t snake_size);

/* Очистка позиций которые занимала змейка */
void clear_snake(char field[][COLUMNS], const size_t* snake_x, const size_t* snake_y, size_t snake_size);

/* Установка еды в игровое поле field */
void set_food(char field[][COLUMNS], size_t* food_x, size_t* food_y);

/* Проверка: съела ли змейка еду */
void check_eating(size_t* snake_x, size_t* snake_y, size_t* snake_size, size_t food_x, size_t food_y);

/* Проверка: встретила ли змейка границу поля field */
void check_snake(char field[][COLUMNS], size_t* snake_x, size_t* snake_y, DIRECTION direction);

/* Проверка завершения игры */
void check_game(char field[][COLUMNS], size_t* snake_x, size_t* snake_y, bool* game_on, size_t snake_size);

/* Обработка нажатия клавиш */
void handle_cmd(bool* game_on, DIRECTION* direction);

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(char field[][COLUMNS], size_t* snake_x, size_t* snake_y, size_t* snake_size, 
											size_t food_x, size_t food_y, DIRECTION direction);
