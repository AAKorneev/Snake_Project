#pragma once
#include "const.h"

struct Snake 
{
	size_t size;
	size_t x[MAXLEN];
	size_t y[MAXLEN];
	DIRECTION direction;
};

/* Инициализация параметров змейки */
void init_snake(const struct Field* field, struct Snake* snake, size_t snake_size, DIRECTION direction);

/* Передвижение змейки */
void move_snake(struct Snake* snake);

static void shift_head(struct Snake* snake);
static void shift_tail(struct Snake* snake, size_t head_x, size_t head_y);