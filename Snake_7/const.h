#pragma once

const char head_symbol = 'o'; 
const char tail_symbol = '+';

const char field_symbol = ' ';
const char border_symbol = '#';

const char food_symbol = 'x';

const size_t COLUMNS = 10;
const size_t ROWS = 10;

const size_t MAXLEN = (COLUMNS - 2) * (ROWS - 2);

enum KEYS {
	ESC = 27,
	KEY_W = 'w', KEY_A = 'a',
	KEY_S = 's', KEY_D = 'd',
	LEFT_ARROW = 75, RIGHT_ARROW = 77,
	UP_ARROW = 72, DOWN_ARROW = 80,
	FUNC_BUTTONS = 224
};

enum DIRECTION { LEFT, RIGHT, UP, DOWN };

const int TIMEOUT_DEFAULT = 100;