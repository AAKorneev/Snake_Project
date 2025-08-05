#pragma once
#include "const.h"

/* Инициализация параметров змейки */
void init_snake(size_t* snake_x, size_t snake_size, DIRECTION direction);

/* Передвижение змейки */
void move_snake(size_t* snake_x, size_t snake_size, DIRECTION direction);