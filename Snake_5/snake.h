#pragma once

extern size_t snake_size;
extern size_t snake_x[];
extern DIRECTION direction;

/* Инициализация параметров змейки */
void init_snake();
 
/* Передвижение змейки */
void move_snake();
