#include "const.h"
#include "winconsole.h"
#include "field.h"
#include <iostream>

/* Заполнение массива игрового поля */ 
void clear_field(char field[][COLUMNS]) {
	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLUMNS; j++)
		{
			if (i == 0 || i == ROWS - 1)
				field[i][j] = border_symbol;
			else if (j == 0 || j == COLUMNS - 1)
				field[i][j] = border_symbol;
			else
				field[i][j] = field_symbol;
		}
	}
}

void init_field(char field[][COLUMNS]) {
	clear_field(field);
}

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(const char field[][COLUMNS]) {
	setCursorPosition(0, 0);
	for (size_t i = 0; i < ROWS; i++) { 
		for (size_t j = 0; j < COLUMNS; j++)
		{
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}