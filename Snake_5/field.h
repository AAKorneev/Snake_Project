#pragma once

extern char field[];

/* Заполнение массива игрового поля */
void clear_field();
 
void init_field();

/* Вывод границ поля field */
void print_border();

/*	- Очистка экрана
	- Вывод границ и массив игрового поля */
void print_field();