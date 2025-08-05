#include <Windows.h>

//------------------------------------------------------------------------------
// Установка курсуора и его скрытие - замена system("cls") 
//------------------------------------------------------------------------------
void setCursorPosition(int x, int y)
{
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static bool init = false;
	if (!init) {				// скрываем курсор
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hConsole, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hConsole, &structCursorInfo);
		init = true;
	}
	COORD position = { x, y }; // устанавливаем в нужную позицию
	SetConsoleCursorPosition(hConsole, position);
}
//------------------------------------------------------------------------------
