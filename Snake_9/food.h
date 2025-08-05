#pragma once

struct Food
{
	size_t x;
	size_t y;
};

void init_food(struct Food* food);

void generate_food(const struct Field* field, struct Food* food);