#include "const.h"

/* Инициализация параметров змейки */
void init_snake(size_t* snake_x, size_t snake_size, DIRECTION direction) {
	// Заполняем массив индексов змейки snake_x
	for (size_t i = 0; i < snake_size; i++) {
		if (direction == LEFT)
			snake_x[i] = i + 1;
		if (direction == RIGHT)
			snake_x[i] = snake_size - i;
	}
}

/* Передвижение змейки */
void move_snake(size_t* snake_x, size_t snake_size, DIRECTION direction) {
	switch (direction)
	{
	case LEFT:
		// Сдвигаем значащие индексы змейки влево 
		for (size_t i = 0; i < snake_size; i++)
			snake_x[i]--;
		break;
	case RIGHT:
		// Сдвигаем значащие индексы змейки вправо
		for (size_t i = 0; i < snake_size; i++)
			snake_x[i]++;
		break;
	default:
		break;
	}
}