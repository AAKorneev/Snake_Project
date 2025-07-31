#include <iostream>
#include <conio.h>
#include <windows.h>

enum KEYS {
	ESC = 27,
	KEY_W = 'w', KEY_A = 'a', 
	KEY_S = 's', KEY_D = 'd',
	LEFT_ARROW = 75, RIGHT_ARROW = 77,
	UP_ARROW = 72, DOWN_ARROW = 80,
	FUNC_BUTTONS = 224
};

enum DIRECTION { LEFT, RIGHT };

int main() {
	const char head_symbol = 'o';
	const char tail_symbol = '~';
	size_t snake_size = 1;
	int input_code = 0;

	const char field_symbol = ' ';
	const char border_symbol = '#';
	const size_t COLUMNS = 15;
	const size_t MAXLEN = COLUMNS - 2;

	char field[COLUMNS] = { 0 };
	size_t snake_x[MAXLEN] = { 0 };

	DIRECTION direction = LEFT;
	bool is_auto = false;
	bool game_on = true;
	int timeout = 100;

	const char food_symbol = '+';
	bool food_flag = false;
	size_t food_x = 0;

	// массив свободных координат
	size_t free_x[MAXLEN] = { 0 };
	size_t rand_idx = 0; // рандомный индекс в массиве свободных координат
	size_t free_count = 0; // счетчик свободных координат

	/* Меню игры */
#if 1
	{
		// Выбор режима игры
		char user_mode = 0;
		std::cout << "Snake game!" << std::endl;
		std::cout << "Do you want to select AUTO mode? YES or NO (y/n)?" << std::endl;
		std::cin >> user_mode;
		switch (user_mode)
		{
		case 'n':
		case 'N':
			std::cout << "step-by-step control selected!" << std::endl;
			break;
		case 'y':
		case 'Y':
			std::cout << "AUTO mode selected!" << std::endl;
			is_auto = true;
			std::cout << "Set the timeout value: ";
			std::cin >> timeout;
			if (timeout <= 0)
				timeout = 100;
			break;
		default:
			std::cout << "Incorrect! Default step-by-step control selected!" << std::endl;
			break;
		}

		// Выбор направления движения
		char user_direction = 0;
		std::cout << "Set the snake movement: LEFT or RIGHT? L/R" << std::endl;
		std::cin >> user_direction;
		switch (user_direction)
		{
		case 'l':
		case 'L':
			direction = LEFT;
			break;
		case 'r':
		case 'R':
			direction = RIGHT;
			break;
		default:
			std::cout << "Incorrect! Default LEFT selected!" << std::endl;
			break;
		}

		// Выбор размера змейки
		std::cout << "Set the snake size: ";
		std::cin >> snake_size;
		if (snake_size <= 0)
			snake_size = 1;
		std::cout << std::endl;
	}
#endif

	// Заполняем массив индексов змейки snake_x
	for (size_t i = 0; i < snake_size; i++) {
		if (direction == LEFT)
			snake_x[i] = i + 1;
		if (direction == RIGHT)
			snake_x[i] = snake_size - i;
	}

	srand(time(0));
	/* Цикл игры */
	while (game_on) {
		system("cls");

		// Заполняем массив игрового поля field
		for (size_t i = 0; i < COLUMNS; i++) {
			if (i == 0 || i == COLUMNS - 1)
				field[i] = border_symbol;
			else
				field[i] = field_symbol;
		}

		// Увеличиваем snake_size в случае поедание еды
		if (snake_x[0] == food_x) {
			food_flag = false;
			snake_size++;
			if (direction == LEFT) {
				snake_x[snake_size - 1] = snake_x[snake_size - 2] + 1;
				if (snake_x[snake_size - 1] == COLUMNS - 1)
					snake_x[snake_size - 1] = 1;
			}
			if (direction == RIGHT) {
				snake_x[snake_size - 1] = snake_x[snake_size - 2] - 1;
				if (snake_x[snake_size - 1] == 0)
					snake_x[snake_size - 1] = COLUMNS - 2;
			}
		}

		// Устанавливаем змейку в игровое поле field 
		for (size_t i = 0; i < snake_size; i++) {
			if (i == 0)
				field[snake_x[i]] = head_symbol;
			else if (snake_x[i] > 0)
				field[snake_x[i]] = tail_symbol;
		}

		/* Устанавливаем еду на поле */
		// нужно обнулить массив!!!!!!!
		if (!food_flag) {
			// Заполняем массив свободных координат
			free_count = 0;
			for (size_t i = 0; i <= COLUMNS - 2; i++) {
				if (field[i] == field_symbol) {
					free_x[free_count] = i;
					free_count++;
				}
			}
			// Опрeделяем рандомный индекс в интервале от 0 до free_count - 1		
			if (free_count > 0) {
				if (free_count == 1)
					food_x = free_x[0];
				else {
					rand_idx = rand() % (free_count - 1);
					food_x = free_x[rand_idx];
				}
				food_flag = true;
			}
			else
				game_on = false;
		}

		if (food_flag)
			field[food_x] = food_symbol;


		size_t temp = 0;
		switch (direction)
		{
		case LEFT:
			// Сдвигаем значащие индексы змейки влево
			for (size_t i = 0; i < snake_size; i++)
			{
				snake_x[i]--;
				if (snake_x[i] == 0)
					snake_x[i] = COLUMNS - 2;
			}
			break;
		case RIGHT:
			// Сдвигаем значащие индексы змейки вправо
			for (size_t i = 0; i < snake_size; i++)
			{
				snake_x[i]++;
				if (snake_x[i] == COLUMNS - 1)
					snake_x[i] = 1;
			}
			break;
		default:
			break;
		}

		// Вывод игрового поля
		std::cout << "Snake size: " << snake_size << std::endl;
		std::cout << std::endl;

		for (size_t i = 0; i < COLUMNS; i++) { std::cout << "#"; }
		std::cout << std::endl;

		for (size_t i = 0; i < COLUMNS; i++) { std::cout << field[i]; }
		std::cout << std::endl;

		for (size_t i = 0; i < COLUMNS; i++) { std::cout << "#"; }
		std::cout << std::endl;

		// Отображение режима игры
		if (is_auto) {
			std::cout << "Timeout: " << timeout << std::endl;
			std::cout << "Press ESC for exit!" << std::endl;
			Sleep(timeout);
			if (_kbhit())
				input_code = _getch();
		}
		else {
			std::cout << "Press any key for play game or ESC for exit!" << std::endl;
			input_code = _getch();
		}

		if (input_code == ESC)
			game_on = false;
	}

	std::cout << "The End!" << std::endl;
	return 0;
}