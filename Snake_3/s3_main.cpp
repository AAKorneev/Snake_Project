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

#define AUTO
//#define DEBUG 

int main() {
	const char head_symbol = 'o';
	const char tail_symbol = '~';
	size_t snake_size = 5;
	int input_code = 0;

	const char field_symbol = ' ';
	const char border_symbol = '#';
	const size_t COLUMNS = 10;
	const size_t MAXLEN = COLUMNS - 2;

	char field[COLUMNS] = { 0 };
	size_t snake_x[MAXLEN] = { 0 };

	//DIRECTION direction = LEFT;
	DIRECTION direction = RIGHT;
	bool game_on = true;
	int timeout = 200;

	// Заполняем массив индексов змейки snake_x
	for (size_t i = 0; i < snake_size; i++) {
		if(direction == LEFT)
			snake_x[i] = i + 1;
		if (direction == RIGHT)
			snake_x[i] = snake_size - i;
	}

	while (game_on) {
		system("cls");

		// Заполняем массив игрового поля field
		for (size_t i = 0; i < COLUMNS; i++) {
			if (i == 0 || i == COLUMNS - 1)
				field[i] = border_symbol;
			else
				field[i] = field_symbol;
		}

		// Устанавливаем змейку в игровое поле field 
		for (size_t i = 0; i < snake_size; i++) {
			if(i == 0)
				field[snake_x[i]] = head_symbol;
			else if(snake_x[i] > 0)
				field[snake_x[i]] = tail_symbol;
		}
#ifdef DEBUG
		std::cout << "DEBUG: snake_x { ";
		for (size_t i = 0; i < MAXLEN; i++) {
			std::cout << snake_x[i];
		}
		std::cout << " }\n";
#endif
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

		std::cout << "##########" << std::endl;
		for (size_t i = 0; i < COLUMNS; i++) {
			std::cout << field[i];
		}
		std::cout << std::endl;
		std::cout << "##########" << std::endl;
		std::cout << std::endl;

#ifdef AUTO
		std::cout << "Press ESC for exit!";
		Sleep(timeout);
		if (_kbhit())
			input_code = _getch();
#else
		std::cout << "Press any key for play game or ESC for exit!";
		input_code = _getch();
#endif
		if (input_code == ESC)
			game_on = false;
	}
	return 0;
}