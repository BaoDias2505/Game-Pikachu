#include "Game.h"

int getarrow() {
	int c = -1;
	if (_kbhit()) {
		c = toupper(_getch());
		switch (c) {
		case KEY_UP:
			return 1;
			break;
		case KEY_DOWN:
			return 2;
			break;
		case KEY_LEFT:
			return 3;
			break;
		case KEY_RIGHT:
			return 4;
			break;
		case KEY_ENTER:
			return 5;
			break;
		case KEY_SPACE:
			return 6;
			break;
		case KEY_ESC:
			return 0;
			break;
		case KEY_PAUSE:
			return 7;
			break;
		}
	}
	return -1;
}

bool check(char** pikachu)
{
	bool check = true;

	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			if (pikachu[i][j] == '-')
			{
				check = false;
				return check;
			}
		}
	}
	return check;
}

void board(char**& pikachu, toado contro)
{

	pikachu = new char* [ROW + 2];
	for (int i = 0; i < ROW + 2; i++)
	{
		pikachu[i] = new char[COL + 2];
		for (int j = 0; j < COL + 2; j++)
		{
			pikachu[i][j] = '-';
		}
	}

	for (contro.y = 0; contro.y <= ROW * 4; contro.y += 4)
	{
		for (contro.x = 0; contro.x < COL * 9 - COL; contro.x++)
		{
			gotoxy(contro);
			if (contro.x % 8 == 0) cout << " ";
			else cout << "-";
		}
	}
	for (contro.x = 0; contro.x < COL * 9; contro.x += 8)
	{
		for (contro.y = 0; contro.y < ROW * 5 - ROW; contro.y++)
		{
			gotoxy(contro);
			if (contro.y % 4 == 0) cout << " ";
			else putchar(124);
		}
	}
	int i = 65 + rand() % (90 - 65 + 1);
	srand(time(NULL));
	while (check(pikachu) == 0) {
		toado N = { 1 + rand() % (ROW) , 1 + rand() % (COL) };
		toado M = { 1 + rand() % (ROW) ,1 + rand() % (COL) };

		if ((N.x != M.x || N.y != M.y) && pikachu[N.x][N.y] == '-' && pikachu[M.x][M.y] == '-')
		{
			pikachu[N.x][N.y] = i;
			pikachu[M.x][M.y] = i;
			i++;
			if (i >= 90)
			{
				i = 65;
			}
		}
	}


}

void output(char** pikachu)
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			toado contro = { j * 8 + 4,i * 4 + 2 };
			gotoxy(contro);
			cout << pikachu[i + 1][j + 1];
			fontsize(16, 14);
		}
	}
}

void choose(toado& A, toado& B, toado& now)
{

	now.x = (now.x) / 8 + 1;
	now.y = (now.y) / 4 + 1;


	if (A.x == -1 && A.y == -1)
	{
		A = { now.x, now.y };
	}
	else
	{
		if (B.x == -1 && B.y == -1)
		{
			B = { now.x, now.y };
			if (A.x == B.x && A.y == B.y)
			{
				B = { -1,-1 };
			}
		}
		else
		{
			A = { now.x, now.y };
			B = { -1,-1 };
		}
	}
}

void kiemtra(toado& A, toado& B, char**& pikachu)
{
	if (A.x == -1 || A.y == -1 || B.x == -1 || B.y == -1)
	{
		return;
	}
	else {
		if (pikachu[A.y][A.x] == pikachu[B.y][B.x])
		{
			pikachu[A.y][A.x] = ' ';
			pikachu[B.y][B.x] = ' ';
		}
		else {
			A = { -1,-1 };
			B = { -1,-1 };
		}
	}
	return;
}

bool correct(toado& A, toado& B, char**& pikachu)
{
	if (A.x == -1 || A.y == -1 || B.x == -1 || B.y == -1)
	{
		return false;
	}
	if (Imatching(A, B, pikachu))
	{
		kiemtra(A, B, pikachu);
		return true;
	}
	else {
		if (Lmatching(A, B, pikachu))
		{
			kiemtra(A, B, pikachu);
			return true;
		}
		else
			if (ZUmatching(A, B, pikachu))
			{
				kiemtra(A, B, pikachu);
				return true;
			}
	}

	return false;
}

bool correctHidden(toado A, toado B, char** pikachu)
{
	if (A.x == -1 || A.y == -1 || B.x == -1 || B.y == -1)
	{
		return false;
	}
	if (Imatching(A, B, pikachu))
	{

		return true;
	}
	else
	{
		if (ZUmatching(A, B, pikachu))
		{
			return true;
		}
		else
			if (Lmatching(A, B, pikachu))
			{
				return true;
			}
	}
	return false;
}

void copy(char** pikachu, char*& random)
{
	int h = 0;
	for (int i = 1; i < (ROW + 1); i++)
	{
		for (int j = 1; j < (COL + 1); j++)
		{
			random[h] = pikachu[i][j];
			h++;
		}
	}
}

bool help(char** pikachu, toado& C, toado& D)
{
	for (int i = 1; i < (ROW + 1); i++)
	{
		for (int j = 1; j < (COL + 1); j++)
		{
			for (int m = 1; m < (ROW + 1); m++)
			{
				for (int n = 1; n < (COL + 1); n++)
				{
					if (pikachu[i][j] != ' ' && pikachu[i][j] != '-')
					{
						if (pikachu[i][j] == pikachu[m][n] && (i != m || j != n))
						{
							C = { -1,-1 };
							D = { -1,-1 };
							if (correctHidden({ j,i }, { n,m }, pikachu) == true)
							{
								C = { j,i };
								D = { n,m };
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

void Return(char** pikachu)
{
	for (int i = 1; i < (ROW + 1); i++)
	{
		for (int j = 1; j < (COL + 1); j++)
		{
			pikachu[i][j] = '/';
		}
	}
}

void Random(char**& pikachu, char* random)
{
	for (int i = 0; i < ROW * COL; )
	{
		int a = 1 + rand() % (ROW);
		int b = 1 + rand() % (COL);
		if (pikachu[a][b] == '/')
		{
			pikachu[a][b] = random[i];
			i++;
		}
	}
}

bool endgame(char** pikachu)
{
	for (int i = 1; i < (ROW + 1); i++)
	{
		for (int j = 1; j < (COL + 1); j++)
		{
			if (pikachu[i][j] != ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void gameset(char**& pikachu, int round)
{
	if (round == 1) {
		vong2(pikachu, 1, ROW + 1);
	}
	if (round == 2)
	{
		vong3(pikachu, 0, ROW);
	}
	if (round == 3)
	{
		vong4(pikachu, 1, COL + 1);
	}
	if (round == 4)
	{
		vong5(pikachu, 0, COL);
	}
	if (round == 5)
	{
		if (ROW % 2 == 0)
		{
			vong2(pikachu, 1, ((ROW + 1) / 2) + 1);
			vong3(pikachu, ((ROW + 1) / 2), ROW);
		}
		else
		{
			vong2(pikachu, 1, ((ROW + 1) / 2));
			vong3(pikachu, ((ROW + 1) / 2) - 1, ROW);
		}
	}
	if (round == 6)
	{
		if (ROW % 2 == 0)
		{
			vong3(pikachu, 0, (ROW / 2));
			vong2(pikachu, (ROW / 2) + 1, ROW + 1);
		}
		else
		{
			vong3(pikachu, 0, ((ROW) / 2));
			vong2(pikachu, ((ROW) / 2) - 1, ROW);
		}
	}
	if (round == 7)
	{
		if (COL % 2 == 0)
		{
			vong4(pikachu, 1, ((COL + 1) / 2) + 1);
			vong5(pikachu, ((COL + 1) / 2), COL);
		}
		else
		{
			vong4(pikachu, 1, ((COL + 1) / 2));
			vong5(pikachu, ((COL + 1) / 2) - 1, COL);
		}
	}
	if (round == 8)
	{
		if (COL % 2 == 0)
		{
			vong5(pikachu, 0, (COL / 2));
			vong4(pikachu, (COL / 2) + 1, COL + 1);
		}
		else
		{
			vong5(pikachu, 0, ((COL) / 2));
			vong4(pikachu, ((COL) / 2) - 1, COL);
		}
	}
}

int gameClock()
{
	time_t timeBegin = time(NULL);
	while (!_kbhit())
	{
		system("cls");
		int thoigianchenhlech = (int)difftime(time(NULL), timeBegin);
		thoigianchenhlech += 266;

		int hour = thoigianchenhlech / 3600;
		int minute = (thoigianchenhlech - hour * 3600) / 60;
		int second = (thoigianchenhlech - hour * 3600 - minute * 60) % 60;

		cout << setw(2) << setfill('0') << hour;
		cout << " : ";
		cout << setw(2) << setfill('0') << minute;
		cout << " : ";
		cout << setw(2) << setfill('0') << second;

		Sleep(100);
	}
	return 0;
}


bool checkplayer(ds& player, ds infor[], int n)
{
	if (player.score < infor[n - 1].score)
	{
		return false;
	}
	else if (player.score == infor[n - 1].score)
	{
		if (player.time <= infor[n - 1].time)
		{
			return false;
		}
		else
		{
			swap(player, infor[n - 1]);
			return true;
		}
	}
	else
	{
		swap(player, infor[n - 1]);
		return true;
	}
}

void sapxep(ds infor[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (infor[i].score < infor[j].score)
			{
				swap(infor[i], infor[j]);
			}
			else if (infor[i].score == infor[j].score)
			{
				if (infor[i].time > infor[j].time)
				{
					swap(infor[i], infor[j]);
				}
			}
		}
	}
}

bool leaderboard(ds& player)
{
	int n = 6;
	ds infor[6];
	string line;
	ifstream in;
	in.open("input.txt");
	if (!in)
	{
		cout << "Cannot open file...";
		return false;
	}
	int i = 0;
	while (!in.eof())
	{
		getline(in, line);
		if (line != "")
		{
			infor[i] = cutLine(line);
			i++;
		}
	}
	in.close();
	ofstream out;
	out.open("input.txt");
	if (!out)
	{
		cout << "Cannot open file...";
		return false;
	}
	if (checkplayer(player, infor, n))
	{
		sapxep(infor, n);
	}
	for (int i = 0; i < 6; i++)
	{
		out << infor[i].name << ";" << infor[i].score << ";" << infor[i].time << endl;
	}
	out.close();

	cout << "\n------------Leader Board-------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << setw(15) << infor[i].name << setw(15) << infor[i].score << setw(15) << infor[i].time << endl;
	}
	return true;
}

bool game(int round, int& diem, int& timeCount)
{
	int goiy = 10;
	char** pikachu;
	char* random = new char[ROW * COL];
	toado A = { -1,-1 };
	toado B = { -1,-1 };
	toado HintA = { -1,-1 };
	toado HintB = { -1,-1 };
	toado HintC = { -1,-1 };
	toado HintD = { -1,-1 };
	time_t timeBegin = time(NULL);
	int timeGo;
	toado contro = { 4,2 };
	toado controLucTruoc = contro;
	toado controDaChon = { 0,0 };
	toado controBiXoa = contro;
	bool smallpause = false;
	int timetemp = 0;
	system("cls");
	board(pikachu, contro);
	int startPrint = 40 + COL * 3 + ROW;
	output(pikachu);
	gotoxy(contro);
	bool kt = false;
	while (1) {
		gotoxy(contro);
		simple_square(contro, pikachu, BRIGHT_WHITE, BLACK);

		if (kt) {
			simple_square(controLucTruoc, pikachu, BLACK, BRIGHT_WHITE);
			kt = false;
		}
		if (controDaChon.x != 0 && controDaChon.y != 0 && pikachu[controDaChon.y / 4 + 1][controDaChon.x / 8 + 1] != ' ') {
			simple_square(controDaChon, pikachu, LIGHT_BLUE, BLACK);
		}

		/*	if((contro.x == controBiXoa.x && contro.y == controBiXoa.y) || (pikachu[contro.y / 4 + 1][contro.x / 8 + 1] != ' '))
				simple_square(contro, pikachu, BLACK, BRIGHT_WHITE);*/
		Sleep(100);
		int t = getarrow();
		if (smallpause == true)
		{
			gotoxy(toado{ startPrint,2 });
			cout << "-------------------------------------------------------" << endl;
			gotoxy(toado{ startPrint + 20,3 });
			cout << "GAMEPAUSE" << endl;
			timetemp += timeGo;
			timeBegin = time(NULL);
			if (t != 7) t = -1;
			timeGo = 0;
		}

		if (smallpause == false)
		{
			timeGo = (int)difftime(time(NULL), timeBegin);
			gotoxy(toado{ startPrint,2 });
			cout << "                                                            " << endl;
			gotoxy(toado{ startPrint + 20,3 });
			cout << "             " << endl;
		}
		switch (t) {
		case 1:
			controLucTruoc = contro;
			contro.y -= 4;
			if (contro.y < 2) {
				contro.y = 2;
				break;
			}
			kt = true;
			break;
		case 2:
			controLucTruoc = contro;

			contro.y += 4;

			if (contro.y < 2)
				contro.y = 2;
			if (contro.y > 4 * ROW - 2) {
				contro.y = 4 * ROW - 2;
				break;
			}
			kt = true;
			break;
		case 3:
			controLucTruoc = contro;

			contro.x -= 8;
			if (contro.x < 4) {
				contro.x = 4;
				break;
			}
			kt = true;
			break;
		case 4:
			controLucTruoc = contro;

			contro.x += 8;
			if (contro.x < 4)
				contro.x = 4;
			if (contro.x > 8 * COL - 4) {
				contro.x = 8 * COL - 4;
				break;
			}
			kt = true;
			break;
		case 5:
			if (controDaChon.x != 0 && controDaChon.y != 0)
				simple_square(controDaChon, pikachu, BLACK, BRIGHT_WHITE);
			toado now = chuyendoi(contro);
			controDaChon = contro;

			choose(A, B, now);
			if (correct(A, B, pikachu) == true) {

				controBiXoa = B;
				diem += 10;
				A = { -1,-1 };
				B = { -1,-1 };
			}

			gameset(pikachu, round);

			output(pikachu);
			break;
		case 6:
			if (goiy > 0) {
				help(pikachu, HintA, HintB);
				goiy--;
			}
			gotoxy(toado{ startPrint,12 });
			cout << "-------------------------------------------------------" << endl;
			gotoxy(toado{ startPrint,13 });
			cout << "A hint: " << HintA.y << "," << HintA.x << "  " << endl;
			gotoxy(toado{ startPrint,14 });
			cout << "B hint : " << HintB.y << "," << HintB.x << "   " << endl;
			break;
		case 7:

			smallpause = !smallpause;
			fontsize(16, 14);
			break;
		case 0:
			system("cls");
			background();
			exit(0);
			break;
		}
		if (help(pikachu, HintC, HintD) == false) {
			copy(pikachu, random);
			Return(pikachu);
			Random(pikachu, random);
			gameset(pikachu, round);

			output(pikachu);
		}
		gotoxy(toado{ startPrint,5 });
		cout << "-------------------------------------------------" << endl;
		gotoxy(toado{ startPrint,6 });
		cout << "|Your points: " << diem << endl;
		gotoxy(toado{ startPrint,7 });
		cout << "|A: " << A.y << "," << A.x << "  ";
		gotoxy(toado{ startPrint + 20,7 });
		cout << "B: " << B.y << "," << B.x << "   " << endl;
		gotoxy(toado{ startPrint,8 });
		cout << "|Round: " << round << endl;
		gotoxy(toado{ startPrint,9 });
		cout << "|Goi y: " << setw(2) << setfill('0') << goiy << endl;
		gotoxy(toado{ startPrint,10 });
		cout << "|" << displayClock(timeGo + timetemp) << endl;

		gotoxy(contro);
		if (endgame(pikachu)) {
			system("cls");
			break;
		}
	}
	timeCount += timeGo + timetemp;
	gotoxy(toado{ 0,0 });
	cout << "YOU WIN !!!!" << endl;
	cout << "Your points: " << diem << endl;
	cout << "X to exit, Enter to continue" << endl;
	cout << "total Time: " << displayClock(timeCount) << endl;
	background();

	if (int(toupper(_getch())) == int('X') || ((round + 1) == 9)) {
		return true;
	}
	else {
		game(round + 1, diem, timeCount);
	}
}


bool xuli(int n, int& diem, int& time)
{
	system("cls");
	switch (n) {
	case 0:
		return 0;
	case 1:
		ROW = 4;
		COL = 4;
		break;
	case 2:
		ROW = 6;
		COL = 6;

		break;
	case 3:
		ROW = 8;
		COL = 8;

		break;
	}
	return game(0, diem, time);
}
ds cutLine(string line)
{
	ds result;
	string name;
	int time;
	int score;

	int end1 = line.find(';');
	name = line.substr(0, end1);

	int start2 = line.find(';') + 1;
	int end2 = line.find_last_of(';');
	score = stoi(line.substr(start2, end2));

	int start3 = line.find_last_of(';') + 1;
	int end3 = line.length();
	time = stoi(line.substr(start3, end3));

	result.name = name;
	result.time = time;
	result.score = score;
	return result;
}

void xuly(int& n, ds& player)
{
	switch (n)
	{
	case 1:
	{
		system("cls");
		do
		{
			fflush(stdin);
			cin.ignore();
			cin.clear();
			gotoxy({ 85,18 });
			cout << "Nhap ten nguoi choi: ";
			getline(cin, player.name);
			challenge();
			n = input();
			if (xuli(n, player.score, player.time) == true) break;
		} while (n != 0);
		cout << "Your result: ";
		cout << player.name << " " << player.score << " " << displayClock(player.time);
		system("cls");

		break;
	}
	case 2:
	{
		system("cls");
		fflush(stdin);
		cin.ignore();
		cin.clear();

		gotoxy({ 60,0 });
		cout << "------------------- HOW TO PLAY PIKACHU Game -------------------" << endl;
		gotoxy({ 5,5 });
		cout << "_ To move, user use 4 key W, A, S, D." << endl;
		gotoxy({ 5,7 });
		cout << "_ Use key ENTER to select. Your task is to be the one to select 2 tiles with the same characters to connect them together to make them disappear from the screen. The condition for \n successful connection is to follow the I U Land Z lines. " << endl;
		gotoxy({ 5,10 });
		cout << "_ Pikachu game includes 3 modes: easy, medium and hard. In each mode, the player will play including 9 rounds." << endl;
		gotoxy({ 5,12 });
		cout << "_ In round 0, the position of the cells will be kept constant." << endl;
		gotoxy({ 5,14 });
		cout << "_ Next to round 1, the elements in the cell will move upwards after the 2 selected cells disappear." << endl;
		gotoxy({ 5,16 });
		cout << "_ Round 2, the elements in the cell will move down after the 2 selected cells disappear." << endl;
		gotoxy({ 5,18 });
		cout << "_ When it comes to round 3, the elements in the cell will shift to the left after the 2 selected cells disappear." << endl;
		gotoxy({ 5,20 });
		cout << "_ Similar but in round 4, the elements in the cell will be shifted to the right." << endl;
		gotoxy({ 5,22 });
		cout << "_ By round 5, the top half of the table will pile upand the bottom half of the table will fold down when the 2 selected cells disappear." << endl;
		gotoxy({ 5,24 });
		cout << "_ Passing round 5, the top half of the board will be moved downand the bottom half of the table will be moved up when the 2 selected cells disappear." << endl;
		gotoxy({ 5,26 });
		cout << "_ In round 7, the right half of the table will be pushed to the right, the left half will be moved to the left when the 2 selected cells disappear." << endl;
		gotoxy({ 5,28 });
		cout << "_ Finally, round 8, the right half of the board will move to the leftand the left half will move to the right. " << endl;
		system("pause");

		break;
	}
	case 3:
	{
		system("cls");
		leaderboard(player);
		system("pause");
		break;
	}
	case 4:
	{
		system("cls");
		fflush(stdin);
		cin.ignore();
		cin.clear();

		gotoxy({ 75,0 });
		cout << "------------------- ABOUT -------------------" << endl;
		gotoxy({ 90,5 });
		cout << "_ Instructor_ " << endl;
		gotoxy({ 86,6 });
		cout << "~ Mr. BUI HUY THONG ~ " << endl;
		gotoxy({ 91,8 });
		cout << "_ Producer_ " << endl;
		gotoxy({ 80,9 });
		cout << "~ NGUYEN MAU GIA BAO ~ " << endl;
		gotoxy({ 105,9 });
		cout << " 21127583 " << endl;
		gotoxy({ 80,11 });
		cout << "~ PHAN LY BAO HANH ~ " << endl;
		gotoxy({ 105,11 });
		cout << " 21127039 " << endl;
		system("pause");

		break;
	}
	case 5:
	{
		cout << " EXIT GAME " << endl;
		n = -1;
		break;
	}
	}
}


int input()
{
	int n;
	do
	{
		gotoxy({ 70,20 });
		cout << "Add your choice: " << endl;
		gotoxy({ 87,20 });
		cin >> n;

	} while (n > 3 || n < 0);

	return n;
}


void challenge()
{
	system("cls");
	gotoxy({ 70,10 });
	cout << "------------------- CHOOSE YOUR CHALLENGE -------------------" << endl;
	gotoxy({ 88,12 });
	cout << " 0. RETURN " << endl;
	gotoxy({ 88,14 });
	cout << " 1. EASY " << endl;
	gotoxy({ 88,16 });
	cout << " 2. MEDIUM " << endl;
	gotoxy({ 88,18 });
	cout << " 3. HARD " << endl;
}

void menu()
{
	system("cls");
	gotoxy({ 70,10 });
	cout << "------------------- PIKACHU Game -------------------" << endl;
	gotoxy({ 88,12 });
	cout << " 1. PLAY GAME " << endl;
	gotoxy({ 88,14 });
	cout << " 2. HOW TO PLAY " << endl;
	gotoxy({ 88,16 });
	cout << " 3. LEADER BOARD " << endl;
	gotoxy({ 88,18 });
	cout << " 4. ABOUT " << endl;
	gotoxy({ 88,20 });
	cout << " 5. EXIT GAME " << endl;
}

int lenh()
{
	int n;
	do
	{
		gotoxy({ 70,22 });
		cout << "Add your choice: " << endl;
		gotoxy({ 87,22 });
		cin >> n;
	} while (n > 5 || n < 1);

	return n;
}



void swap(ds& a, ds& b)
{
	ds temp = a;
	a = b;
	b = temp;
}
