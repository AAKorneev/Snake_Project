#include "food.h"
#include "const.h"
#include <windows.h>


void init_food() {}

void generate_food(size_t rows, size_t columns, size_t* food_x, size_t* food_y) {
	*food_x = rand() % (columns - 2);
	*food_y = rand() % (rows - 2);
}