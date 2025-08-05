#include "food.h"
#include "const.h"
#include "field.h"
#include <windows.h>


void init_food(struct Food* food) {
	food->x = 0;
	food->y = 0;
}

void generate_food(const struct Field* field, struct Food* food) {
	food->x = rand() % (field->columns - 2);
	food->y = rand() % (field->rows - 2);
}