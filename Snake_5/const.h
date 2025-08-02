#pragma once

const char head_symbol = 'o';
const char tail_symbol = '~';

const char field_symbol = ' ';
const char border_symbol = '#';
const size_t COLUMNS = 15;
const size_t MAXLEN = COLUMNS - 2;

const char food_symbol = '+'; 

enum KEYS {
	ESC = 27,
	KEY_W = 'w', KEY_A = 'a',
	KEY_S = 's', KEY_D = 'd',
	LEFT_ARROW = 75, RIGHT_ARROW = 77,
	UP_ARROW = 72, DOWN_ARROW = 80,
	FUNC_BUTTONS = 224
};

enum DIRECTION { LEFT, RIGHT };
