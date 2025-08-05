#pragma once

/* Заполнение массива игрового поля */ 
void clear_field(char[][COLUMNS]);

/* Инициализация игрового поля */
void init_field(char[][COLUMNS]);

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(const char[][COLUMNS]);