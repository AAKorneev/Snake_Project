#include "const.h"
#include "game.h"
#include "food.h"
#include "field.h"
#include "snake.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

extern DIRECTION direction;

int main() { 
	srand(time(0)); // seed для random

	init_game();	// Инициализация игры (меню + user input)
	init_field();	// Заполнение массива игрового поля
	init_snake();	// Инициализация змейки
	init_food();	// Загушка (пока)
	set_snake();	// Установка змейки в поле
	system("cls");	// Очистка меню перед выводом поля
	print_field();	// Вывод поля на экран

	while (game_on) {
		game_mode();		// Отображение режима игры
		animate_snake();	// Анимация змейки
		set_food();			// Установка еды в поле
		check_game();		// Проверка завершения игры
		print_field();		// Вывод поля на экран
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The End!" << std::endl;
	std::cout << std::endl;
	return 0;
}
