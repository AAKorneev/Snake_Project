#pragma once
#include "const.h"

/* Инициализация параметров змейки */ 
void init_snake(size_t* snake_x, size_t* snake_y, size_t snake_size, DIRECTION direction);

/* Передвижение змейки */
void move_snake(size_t* snake_x, size_t* snake_y, size_t snake_size, DIRECTION direction);

static void shift_head(size_t* snake_x, size_t* snake_y, DIRECTION direction);
static void shift_tail(size_t* snake_x, size_t* snake_y, size_t snake_size, size_t head_x, size_t head_y);