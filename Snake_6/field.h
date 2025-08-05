#pragma once

/* Заполнение массива игрового поля */
void clear_field(char* field);

void init_field(char* field);

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(const char* field); 