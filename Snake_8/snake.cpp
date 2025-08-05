#include "snake.h"

/* Инициализация параметров змейки */
void init_snake(size_t rows, size_t columns, size_t* snake_x, size_t* snake_y, size_t snake_size, DIRECTION direction) {
	// Заполняем массив индексов змейки snake_x
	for (size_t i = 0; i < snake_size; i++) {
		if (direction == LEFT)
			snake_x[i] = (columns - 2) - snake_size + 1 + i; // установка с хвоста
		if (direction == RIGHT)
			snake_x[i] = snake_size - i; // установка с хвоста
	}

	for (size_t i = 0; i < snake_size; i++)
		snake_y[i] = rows / 2; // установка в центре поля 
}

/* Передвижение змейки */
void move_snake(size_t* snake_x, size_t* snake_y, size_t snake_size, DIRECTION direction) {
	size_t head_x = snake_x[0];
	size_t head_y = snake_y[0];
	shift_head(snake_x, snake_y, direction);
	shift_tail(snake_x, snake_y, snake_size, head_x, head_y);
}

/* Сдвиг головы */
static void shift_head(size_t* snake_x, size_t* snake_y, DIRECTION direction) {
	switch (direction)
	{
	case LEFT:
		snake_x[0]--;
		break;
	case RIGHT:
		snake_x[0]++;
		break;
	case UP:
		snake_y[0]--;
		break;
	case DOWN:
		snake_y[0]++;
	default:
		break;
	}
}

/* Сдвиг хвоста */
static void shift_tail(size_t* snake_x, size_t* snake_y, size_t snake_size, size_t head_x, size_t head_y) {
	for (size_t i = snake_size - 1; i > 1; i--)
	{
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	snake_x[1] = head_x;
	snake_y[1] = head_y;
}