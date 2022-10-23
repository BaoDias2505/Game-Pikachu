
//#ifndef __GRAPHICS_H__
//#define __GRAPHICS_H__
//#endif
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

#define CO_THEME 7
#define WIDTH 1400
#define HEIGHT 750

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

struct toado
{
	int x;
	int y;
};
struct ds {
	string name;
	int time;
	int score;
};
void createconsole();
void console();
void background();
void hideCursor();
void setConsoleColor(int background, int text);
void fontsize(int a, int b);
void gotoxy(toado contro);
void simple_square(toado& contro, char** pikachu, int background, int text);
toado chuyendoi(toado contro);

void backgroundend();
string displayClock(int time);
