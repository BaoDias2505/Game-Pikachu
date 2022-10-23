#include "Matching.h"

bool Imatching(toado A, toado B, char** pikachu)
{
	int maxx = (A.x > B.x) ? A.x : B.x;
	int minx = (A.x > B.x) ? B.x : A.x;

	int maxy = (A.y > B.y) ? A.y : B.y;
	int miny = (A.y > B.y) ? B.y : A.y;
	if (A.y == B.y) {
		for (int i = minx + 1; i < maxx; i++)
		{
			if (pikachu[A.y][i] != ' ' && pikachu[A.y][i] != '-')
			{
				return false;
			}
		}
		return true;
	}
	if (A.x == B.x)
	{
		for (int i = miny + 1; i < maxy; i++)
		{
			if (pikachu[i][A.x] != ' ' && pikachu[i][A.x] != '-')
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool ZUmatching(toado A, toado B, char** pikachu)
{
	for (int i = 0; i <= COL + 1; i++)
	{
		if ((pikachu[A.y][i] == '-' && pikachu[B.y][i] == '-') || (pikachu[A.y][i] == ' ' && pikachu[B.y][i] == ' '))
		{
			if (Imatching({ i,A.y }, { i,B.y }, pikachu))
			{
				if ((Imatching({ i,A.y }, A, pikachu)) && (Imatching(B, { i,B.y }, pikachu)))
				{
					return true;
				}
			}
		}
	}
	for (int i = 0; i <= ROW + 1; i++)
	{
		if ((pikachu[i][A.x] == '-' && pikachu[i][B.x] == '-') || (pikachu[i][A.x] == ' ' && pikachu[i][B.x] == ' '))
		{
			if (Imatching({ A.x,i }, { B.x,i }, pikachu))
			{
				if ((Imatching({ A.x,i }, A, pikachu)) && (Imatching(B, { B.x,i }, pikachu)))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Lmatching(toado A, toado B, char** pikachu)
{
	if (pikachu[A.y][B.x] == ' ' || pikachu[A.y][B.x] == '-')
		if ((Imatching(A, { B.x,A.y }, pikachu)) && (Imatching({ B.x,A.y }, B, pikachu)))
		{
			return true;
		}
	if (pikachu[B.y][A.x] == ' ' || pikachu[B.y][A.x] == '-')
		if ((Imatching(A, { A.x,B.y }, pikachu)) && (Imatching({ A.x,B.y }, B, pikachu)))
		{
			return true;
		}
	return false;
}
