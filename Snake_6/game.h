#pragma once
#include "const.h"

void init_game(int* timeout);

/* Установка змейки в игровое поле field */
void set_snake(char* field, const size_t* snake_x, size_t snake_size);

/* Очистка позиций которые занимала змейка */
void clear_snake(char* field);

size_t generate_food(const size_t* free_x, size_t free_count);

/* Установка еды в игровое поле field */
void set_food(char* field, size_t* food_x, bool* game_on);

/* Проверка: съела ли змейка еду */
void check_eating(size_t* snake_x, size_t* snake_size, size_t food_x, DIRECTION direction);

/* Проверка: встретила ли змейка границу поля field */
void check_snake(size_t* snake_x, size_t snake_size, DIRECTION direction);

/* Проверка завершения игры */ 
void check_game(bool* game_on, size_t snake_size);

/* Обработка нажатия клавиш */
void handle_cmd(bool* game_on);

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake(char* field, size_t* snake_x, size_t* snake_size, size_t food_x, DIRECTION direction);