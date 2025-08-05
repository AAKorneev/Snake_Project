#include "const.h"
#include "winconsole.h"
#include "field.h"
#include <iostream>

/* Заполнение массива игрового поля */ 
void clear_field(char** field, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++)
		{
			if (i == 0 || i == rows - 1)
				field[i][j] = border_symbol;
			else if (j == 0 || j == columns - 1)
				field[i][j] = border_symbol;
			else
				field[i][j] = field_symbol;
		}
	}
}

void init_field(char** field, size_t rows, size_t columns) {
	clear_field(field, rows, columns);
}

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(char** field, size_t rows, size_t columns) {
	setCursorPosition(0, 0);
	for (size_t i = 0; i < rows; i++) { 
		for (size_t j = 0; j < columns; j++)
		{
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

char** create_field_array(size_t rows, size_t columns) {
	char** field = new char* [rows];

	for (size_t i = 0; i < rows; i++)
		field[i] = new char[columns];

	return field;
}

void destroy_field_array(char** field, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; i++)
		delete[] field[i];
	delete[] field;
	field = 0;
}