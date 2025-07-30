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

int main() {
	//Задание 1
	const char head_symbol = '@';
	const char tail_symbol = 'o';
	size_t snake_size = 0;
	int input_code = 0;

	//Задание 2
#if 1
	{
		int count = 0;
		bool is_quit = false;
		while (!is_quit) {
			system("cls");
			std::cout << "Enter \"d\" or \"->\" for move right, and \"ESC\" for quit" << std::endl;

			for (int i = 0; i < count; i++)
				std::cout << " ";
			std::cout << head_symbol;

			input_code = _getch();
			switch (input_code)
			{
			case KEY_D:
				count++;
				break;
			case ESC:
				is_quit = true;
				std::cout << "\nQuit!\n";
				break;
			case FUNC_BUTTONS:
				input_code = _getch();
				if (input_code == RIGHT_ARROW)
					count++;
				break;
			default:
				break;
			}
		}
	}
#endif


	//Задание 3
#if 1
	{
		bool is_correct = false;
		std::cout << "Please, enter snake size: ";
		while (!is_correct) {
			std::cin >> snake_size;
			if (snake_size > 0)
				is_correct = true;
			else
				std::cout << "Incorrect, try again: ";
		}

		int count = 0;
		bool is_quit = false;
		while (!is_quit) {
			system("cls");
			std::cout << "Snake size: " << snake_size << std::endl;
			std::cout << "Enter \"d\" or \"->\" for move right, and \"ESC\" for quit" << std::endl;

			for (int i = 0; i < count; i++)
				std::cout << " ";

			for (int i = 0; i < snake_size - 1; i++)
				std::cout << tail_symbol;
			std::cout << head_symbol;

			input_code = _getch();
			switch (input_code)
			{
			case KEY_D:
				count++;
				break;
			case ESC:
				is_quit = true;
				std::cout << "\nQuit!\n";
				break;
			case FUNC_BUTTONS:
				input_code = _getch();
				if (input_code == RIGHT_ARROW)
					count++;
				break;
			default:
				break;
			}
		}
	}
#endif
	return 0;
}