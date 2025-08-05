#include "const.h"
#include "winconsole.h"
#include "field.h"
#include <iostream>

/* Заполнение массива игрового поля */
void clear_field(struct Field* field) {
	for (size_t i = 0; i < field->rows; i++) {
		for (size_t j = 0; j < field->columns; j++)
		{
			if (i == 0 || i == field->rows - 1)
				field->arr[i][j] = border_symbol;
			else if (j == 0 || j == field->columns - 1)
				field->arr[i][j] = border_symbol;
			else
				field->arr[i][j] = field_symbol;
		}
	}
}

void init_field(struct Field* field, size_t rows, size_t columns) {
	field->rows = rows;
	field->columns = columns;
	create_field_array(field);
	clear_field(field);
}

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(const struct Field* field) {
	setCursorPosition(0, 0);
	for (size_t i = 0; i < field->rows; i++) { 
		for (size_t j = 0; j < field->columns; j++)
		{
			std::cout << field->arr[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void create_field_array(struct Field* field) {
	field->arr = new char* [field->rows];

	for (size_t i = 0; i < field->rows; i++)
		field->arr[i] = new char[field->columns];
}

void destroy_field_array(struct Field* field) {
	for (size_t i = 0; i < field->rows; i++)
		delete[] field->arr[i];
	delete[] field->arr;
	field->arr = 0;
}