#include <iostream>
#include <conio.h>
#include "Game.h"
int main()
{
	hideCursor();
	int n;
	ds player;
	createconsole();
	console();
	system("cls");

	player.time = 0;
	player.score = 0;
	do
	{
		menu();
		n = lenh();
		xuly(n, player);
	} while (n != -1);

	system("cls");
	backgroundend();

	return 0;
}
