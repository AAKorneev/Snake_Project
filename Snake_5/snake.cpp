#include "const.h"

size_t snake_size = 0;
size_t snake_x[MAXLEN] = { 0 };
DIRECTION direction = LEFT;

/* Инициализация параметров змейки */ 
void init_snake() {
	// Заполняем массив индексов змейки snake_x
	for (size_t i = 0; i < snake_size; i++) {
		if (direction == LEFT)
			snake_x[i] = i + 1;
		if (direction == RIGHT)
			snake_x[i] = snake_size - i;
	}
}

/* Передвижение змейки */
void move_snake() {
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