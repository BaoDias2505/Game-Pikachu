
#include"Round.h"

void swap(char& a, char& b)
{
	char c = a;
	a = b;
	b = c;
}
void vong2(char**& pikachu, int begin, int end)
{
	for (int j = 1; j < COL + 1; j++)
	{
		for (int i = begin + 1; i < end; i++)
		{
			if (pikachu[i - 1][j] == ' ')
			{
				if (pikachu[i][j] != ' ')
				{
					if (i - 1 < begin) continue;
					swap(pikachu[i - 1][j], pikachu[i][j]);
					i -= 2;
				}
			}
		}
	}
}

void vong3(char**& pikachu, int begin, int end)
{
	for (int j = 1; j < COL + 1; j++) {
		for (int i = end; i > begin + 1; i--)
		{
			if (pikachu[i - 1][j] != ' ')
			{
				if (pikachu[i][j] == ' ')
				{
					if (i - 1 < begin) continue;
					if (i > end) continue;
					swap(pikachu[i][j], pikachu[i - 1][j]);
					i += 2;
				}
			}
		}
	}
}

void vong4(char**& pikachu, int begin, int end)
{
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = begin + 1; j < end; j++)
		{
			if (pikachu[i][j - 1] == ' ')
			{
				if (pikachu[i][j] != ' ')
				{
					if (j - 1 < begin) continue;
					swap(pikachu[i][j - 1], pikachu[i][j]);
					j -= 2;
				}
			}
		}
	}
}

void vong5(char**& pikachu, int begin, int end)
{
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = end; j > begin + 1; j--)
		{
			if (pikachu[i][j - 1] != ' ')
			{
				if (pikachu[i][j] == ' ')
				{
					if (j > end) continue;
					if (j - 1 < begin) continue;
					swap(pikachu[i][j], pikachu[i][j - 1]);
					j += 2;
				}
			}
		}
	}
}
