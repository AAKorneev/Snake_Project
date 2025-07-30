#include <iostream>
#include <conio.h>

enum KEYS {
	ESC = 27,
	KEY_W = 'w', KEY_A = 'a',
	KEY_S = 's', KEY_D = 'd',
	LEFT_ARROW = 75, RIGHT_ARROW = 77,
	UP_ARROW = 72, DOWN_ARROW = 80,
	FUNC_BUTTONS = 224
};

int main() {
	// Задание 1 
#if 1
	{
		char input = 0;
		bool is_quit = false;
		while (!is_quit) {
			std::cin >> input;
			switch (input)
			{
			case 'w':
				std::cout << '^' << std::endl;
				break;
			case 'a':
				std::cout << '<' << std::endl;
				break;
			case 's':
				std::cout << 'v' << std::endl;
				break;
			case 'd':
				std::cout << '>' << std::endl;
				break;
			case '0':
				is_quit = true;
				std::cout << "Quit!\n";
				break;
			default:
				std::cout << "Error input!" << std::endl;
				break;
			}
		}
	}
#endif

	//Задание 2
#if 1
	{
		bool is_quit = false;
		while (!is_quit) {
			int input = _getch();
			switch (input)
			{
			case KEY_W:
				std::cout << '^' << std::endl;
				break;
			case KEY_A:
				std::cout << '<' << std::endl;
				break;
			case KEY_S:
				std::cout << 'v' << std::endl;
				break;
			case KEY_D:
				std::cout << '>' << std::endl;
				break;
			case ESC:
				is_quit = true;
				std::cout << "Quit!\n";
				break;
			default:
				std::cout << "Error input!" << std::endl;
				break;
			}
		}
	}
#endif
	//Задание 3
#if 1 
	{
		bool is_quit = false;
		while (!is_quit) {
			int input = _getch();
			if (input == FUNC_BUTTONS) {
				input = _getch();
				switch (input)
				{
				case UP_ARROW:
					std::cout << '^' << std::endl;
					break;
				case LEFT_ARROW:
					std::cout << '<' << std::endl;
					break;
				case DOWN_ARROW:
					std::cout << 'v' << std::endl;
					break;
				case RIGHT_ARROW:
					std::cout << '>' << std::endl;
					break;
				default:
					std::cout << "Error input!" << std::endl;
					break;
				}
			}
			else if (input == ESC) {
				is_quit = true;
				std::cout << "Quit!\n";
				break;
			}
			else
				std::cout << "Error input!" << std::endl;
		}
	}
#endif
	return 0;
}