#include "game_screen.h"

int main(int arv, char * argc[])
{
	if (!GAME_SCREEN.INIT())
	{
		cout << "GAME_SCREEN: fail at INIT()\n";
		return -1;
	}

	if (!GAME_SCREEN.LOAD_MEDIA())
	{
		cout << "GAME_SCREEN: fail at LOAD_MEDIA()\n";
		return -1;
	}

	GAME_SCREEN.DISPLAY_SCREEN();

	return 0;
}