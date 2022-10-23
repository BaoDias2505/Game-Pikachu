#include "Graphics.h"

void createconsole()
{
	HWND console = GetConsoleWindow();
	RECT r;
	HANDLE hconsole;

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, CO_THEME);
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, WIDTH, HEIGHT, TRUE);
}

void console()
{
	HWND console = GetConsoleWindow();
	LONG style = GetWindowLong(console, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(console, GWL_STYLE, style);
}

void background()
{
	cout << "                                        .\n";
	cout << "                         |              |\n";
	cout << "                         |             ,|\n";
	cout << "                ,_       |\\            F'   ,.-\"\"`.\n";
	cout << "               /  `-._   |`           // ,-\"_,..  |\n";
	cout << "              |   ___ `. | \\ ,\"\"\"`-. /.-' ,'    ' |_....._\n";
	cout << "              |  /   `-.`.  L......|j j_.'      ` |       `._\n";
	cout << "              | |      _,'| |______|' | '-._     ||  ,.-.    `.\n";
	cout << "               L|    ,'   | |      | j      `-.  || '    `.    \\\n";
	cout << "___            | \\_,'     | |`\"----| |         `.||       |\\    \\\n";
	cout << " \"\"=+...__     `,'   ,.-.   |....._|   _....     Y \\      j_),..+=--\n";
	cout << "     `\"-._\"._  .   ,' |  `   \\    /  ,' |   \\     \\ j,..-\"_..+-\"  L\n";
	cout << "          `-._-+. j   !   \\   `--'  .   !    \\  ,.-\" _..<._  |    |\n";
	cout << "              |-. |   |    L        |   !     |  .-/'      `.|-.,-|\n";
	cout << "              |__ '   '    |        '   |    /    /|   `, -. |   j\n";
	cout << "        _..--'\"__  `-.___,'          `.___,.'  __/_|_  /   / '   |\n";
	cout << "   _.-_..---\"\"_.-\\                            .,...__\"\"--./L/_   |\n";
	cout << " -'\"\"'     ,\"\"  ,-`-.    .___.,...___,    _,.+\"      \"\"\"\"`-+-==++-\n";
	cout << "          / /  `.   )\"-.._`v \\|    V/  /-'    \\._,._.'\"-. /    /\n";
	cout << "          ` `.  )---.     `\"\"\\\\__  / .'        /    \\    Y\"._.'\n";
	cout << "           `\"'`\"     `-.     /|._\"\"_/         |  ,..   _ |  |\n";
	cout << "                        `\"\"\"' |  \"'           `. `-'  (_|,-.'\n";
	cout << "                               \\               |`       .`-\n";
	cout << "                                `.           . j`._    /\n";
	cout << "                                 |`.._     _.'|    `\"\"/\n";
	cout << "                                 |    /\"\"'\"   |  .\". j\n";
	cout << "                                .`.__j         \\ `.' |\n";
	cout << "                                j    |          `._.'\n";
	cout << "                               /     |\n";
	cout << "                              /,  ,  \\\n";
	cout << "                              \\|  |   L\n";
	cout << "                               `..|_..' \n";

}
void hideCursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO info = { 1, 0 };
	SetConsoleCursorInfo(out, &info);
}

void setConsoleColor(int background, int text)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(out, background * 16 + text);
}
void fontsize(int a, int b)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

void gotoxy(toado contro) {
	COORD coord;
	coord.X = contro.x;
	coord.Y = contro.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void simple_square(toado& contro, char** pikachu, int background, int text) {
	setConsoleColor(background, text);
	toado tmp;
	for (int i = contro.x - 3; i <= contro.x + 3; ++i) {
		for (int j = contro.y - 1; j <= contro.y + 1; ++j) {
			tmp.x = i;
			tmp.y = j;
			gotoxy(tmp);
			if (i == contro.x && j == contro.y) {
				putchar(pikachu[contro.y / 4 + 1][contro.x / 8 + 1]);
			}
			else putchar(' ');
		}
	}
	gotoxy(contro);
	setConsoleColor(BLACK, BRIGHT_WHITE);
}

toado chuyendoi(toado contro) {
	toado result = contro;
	result.x = contro.x;
	result.y = contro.y;
	return result;
}

void backgroundend()
{
	cout << "                                             ,-.\n";
	cout << "                                          _.|  '\n";
	cout << "                                        .'  | /\n";
	cout << "                                      ,'    |'\n";
	cout << "                                     /      /\n";
	cout << "                       _..----\"\"---.'      /\n";
	cout << " _.....---------...,-\"\"                  ,'\n";
	cout << " `-._  \\                                /\n";
	cout << "     `-.+_            __           ,--. .\n";
	cout << "          `-.._     .:  ).        (`--\"| \\\n";
	cout << "               7    | `\" |         `...'  \\\n";
	cout << "               |     `--'     '+\"        ,\". ,\"\"-\n";
	cout << "               |   _...        .____     | |/    '\n";
	cout << "          _.   |  .    `.  '--\"   /      `./     j\n";
	cout << "         \\' `-.|  '     |   `.   /        /     /\n";
	cout << "         '     `-. `---\"      `-\"        /     /\n";
	cout << "          \\       `.                  _,'     /\n";
	cout << "           \\        `                        .\n";
	cout << "            \\                                j\n";
	cout << "             \\                              /\n";
	cout << "              `.                           .\n";
	cout << "                +                          \\\n";
	cout << "                |                           L\n";
	cout << "                |                           |\n";
	cout << "                |  _ /,                     |\n";
	cout << "                | | L)'..                   |\n";
	cout << "                | .    | `                  |\n";
	cout << "                '  \\'   L                   '\n";
	cout << "                 \\  \\   |                  j\n";
	cout << "                  `. `__'                 /\n";
	cout << "                _,.--.---........__      /\n";
	cout << "               ---.,'---`         |   -j\"\n";
	cout << "                .-'  '....__      L    |\n";
	cout << "              \"\"--..    _,-'       \\ l||\n";
	cout << "                  ,-'  .....------. `||'\n";
	cout << "               _,'                /\n";
	cout << "             ,'                  /\n";
	cout << "            '---------+-        /\n";
	cout << "                     /         /\n";
	cout << "                   .'         /\n";
	cout << "                 .'          /\n";
	cout << "               ,'           /\n";
	cout << "             _'....----\"\"\"\"\" \n";
}
string displayClock(int time)
{
	stringstream buffer;
	int hour = time / 3600;
	int minute = (time - hour * 3600) / 60;
	int second = (time - hour * 3600 - minute * 60) % 60;

	buffer << setw(2) << setfill('0') << hour;
	buffer << " : ";
	buffer << setw(2) << setfill('0') << minute;
	buffer << " : ";
	buffer << setw(2) << setfill('0') << second;

	return buffer.str();
}
