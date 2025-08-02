#include "const.h"
#include "winconsole.h"
#include <windows.h>
#include <iostream>

char field[COLUMNS] = { 0 };

/* Заполнение массива игрового поля */ 
void clear_field() {
	for (size_t i = 0; i < COLUMNS; i++) {
		if (i == 0 || i == COLUMNS - 1)
			field[i] = border_symbol;
		else
			field[i] = field_symbol;
	}
}

void init_field() {
	clear_field();
}

/* Вывод границ поля field */
void print_border() {
	for (size_t i = 0; i < COLUMNS; i++) { std::cout << "#"; }
	std::cout << std::endl;
}

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field() {
	setCursorPosition(0, 0);
	print_border();
	for (size_t i = 0; i < COLUMNS; i++) { std::cout << field[i]; }
	std::cout << std::endl;
	print_border();
}

