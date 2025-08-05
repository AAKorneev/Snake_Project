#pragma once

struct Field
{
	char** arr;
	size_t rows;
	size_t columns;
};

/* Заполнение массива игрового поля */
void clear_field(struct Field* field);

/* Инициализация игрового поля */
void init_field(struct Field* field, size_t rows, size_t columns);

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(const struct Field* field);

void create_field_array(struct Field* field);

void destroy_field_array(struct Field* field);