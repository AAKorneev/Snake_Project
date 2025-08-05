#include "snake.h"
#include "field.h"

/* Инициализация параметров змейки */ 
void init_snake(const struct Field* field, struct Snake* snake, size_t snake_size, DIRECTION direction) {
	snake->size = snake_size;
	snake->direction = direction;

	// Заполняем массив индексов змейки snake_x
	for (size_t i = 0; i < snake_size; i++) {
		if (direction == LEFT)
			snake->x[i] = (field->columns - 2) - snake_size + 1 + i; // установка с хвоста
		if (direction == RIGHT)
			snake->x[i] = snake->size - i; // установка с хвоста
	}

	for (size_t i = 0; i < snake_size; i++)
		snake->y[i] = field->rows / 2; // установка в центре поля
}

/* Передвижение змейки */
void move_snake(struct Snake* snake) {
	size_t head_x = snake->x[0];
	size_t head_y = snake->y[0];
	shift_head(snake);
	shift_tail(snake, head_x, head_y);
}

/* Сдвиг головы */
static void shift_head(struct Snake* snake) {
	switch (snake->direction)
	{
	case LEFT:
		snake->x[0]--;
		break;
	case RIGHT:
		snake->x[0]++;
		break;
	case UP:
		snake->y[0]--;
		break;
	case DOWN:
		snake->y[0]++;
	default:
		break;
	}
}

/* Сдвиг хвоста */
static void shift_tail(struct Snake* snake, size_t head_x, size_t head_y) {
	for (size_t i = snake->size - 1; i > 1; i--)
	{
		snake->x[i] = snake->x[i - 1];
		snake->y[i] = snake->y[i - 1];
	}
	snake->x[1] = head_x;
	snake->y[1] = head_y;
}