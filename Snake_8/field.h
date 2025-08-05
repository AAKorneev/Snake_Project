#pragma once

/* Заполнение массива игрового поля */ 
void clear_field(char** field, size_t rows, size_t columns);

/* Инициализация игрового поля */
void init_field(char** field, size_t rows, size_t columns);

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field(char** field, size_t rows, size_t columns);

char** create_field_array(size_t rows, size_t columns);

void destroy_field_array(char** field, size_t rows, size_t columns);