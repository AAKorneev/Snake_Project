#include "const.h"
#include "winconsole.h"
#include <iostream>

/* Заполнение массива игрового поля */
void clear_field(char* field) {
	for (size_t i = 0; i < COLUMNS; i++) {
		if (i == 0 || i == COLUMNS - 1)
			field[i] = border_symbol;
		else
			field[i] = field_symbol; 
	}
}

void init_field(char* field) {
	clear_field(field);
}

/* Вывод границ поля field */
static void print_border() {
	for (size_t i = 0; i < COLUMNS; i++) { std::cout << "#"; }
	std::cout << std::endl;
}

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(const char* field) {
	setCursorPosition(0, 0);
	print_border();
	for (size_t i = 0; i < COLUMNS; i++) { std::cout << field[i]; }
	std::cout << std::endl;
	print_border();
}