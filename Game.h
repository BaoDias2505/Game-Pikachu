#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#endif



#include <fstream>
#include <iostream>
#include <conio.h>
#include "Round.h"
#include "Matching.h"

#define KEY_UP 87
#define KEY_DOWN 83
#define KEY_LEFT 65
#define KEY_RIGHT 68
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_SPACE 32
#define KEY_PAUSE 80


using namespace std;


int getarrow();

bool check(char** pikachu);

void board(char**& pikachu, toado contro);

void output(char** pikachu);

void choose(toado& A, toado& B, toado& now);

void kiemtra(toado& A, toado& B, char**& pikachu);

bool correct(toado& A, toado& B, char**& pikachu);

bool correctHidden(toado A, toado B, char** pikachu);

void copy(char** pikachu, char*& random);

bool help(char** pikachu, toado& C, toado& D);

void Return(char** pikachu);

void Random(char**& pikachu, char* random);

bool endgame(char** pikachu);

void gameset(char**& pikachu, int round);

int gameClock();
bool checkplayer(ds& player, ds infor[], int n);

void sapxep(ds infor[], int n);

bool leaderboard(ds& player);

bool game(int round, int& diem, int& timeCount);
bool xuli(int n, int& diem, int& time);
ds cutLine(string line);

void xuly(int& n, ds& player);
void challenge();

int input();


void menu();

int lenh();



void swap(ds& a, ds& b);
