#pragma once
extern int timeout;
extern bool game_on;
extern bool is_auto;

/*
	Меню игры:
	- Выбор режима игры
	- Выбор направления движения 
	- Выбор размера змейки
*/
void init_game();

/* Установка змейки в игровое поле field */
void set_snake();

/* Установка еды в игровое поле field */
void set_food();

/* Проверка: съела ли змейка еду */
void check_eating();

/* Очистка позиций которые занимала змейка */
void clear_snake();

/* Вызовы функций для создания "эффекта анимации" */
void animate_snake();

/* Проверка завершения игры */
void check_game();

/* Обработка нажатия клавиш */
void handle_cmd();

/* Режим игры: автоматическое или ручное управление */
void game_mode();

