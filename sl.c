#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <windows.h>

#define D51HIGHT 10
#define D51FUNNEL 7
#define D51LENGTH 83
#define D51PATTERNS 6

#define D51STR1 TEXT("      ====        ________                ___________ ")
#define D51STR2 TEXT("  _D _|  |_______/        \\__I_I_____===__|_________| ")
#define D51STR3 TEXT("   |(_)---  |   H\\________/ |   |        =|___ ___|   ")
#define D51STR4 TEXT("   /     |  |   H  |  |     |   |         ||_| |_||   ")
#define D51STR5 TEXT("  |      |  |   H  |__--------------------| [___] |   ")
#define D51STR6 TEXT("  | ________|___H__/__|_____/[][]~\\_______|       |   ")
#define D51STR7 TEXT("  |/ |   |-----------I_____I [][] []  D   |=======|__ ")

#define D51WHL11 TEXT("__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ ")
#define D51WHL12 TEXT(" |/-=|___|=    ||    ||    ||    |_____/~\\___/        ")
#define D51WHL13 TEXT("  \\_/      \\O=====O=====O=====O_/      \\_/            ")

#define D51WHL21 TEXT("__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ ")
#define D51WHL22 TEXT(" |/-=|___|=O=====O=====O=====O   |_____/~\\___/        ")
#define D51WHL23 TEXT("  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            ")

#define D51WHL31 TEXT("__/ =| o |=-O=====O=====O=====O \\ ____Y___________|__ ")
#define D51WHL32 TEXT(" |/-=|___|=    ||    ||    ||    |_____/~\\___/        ")
#define D51WHL33 TEXT("  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            ")

#define D51WHL41 TEXT("__/ =| o |=-~O=====O=====O=====O\\ ____Y___________|__ ")
#define D51WHL42 TEXT(" |/-=|___|=    ||    ||    ||    |_____/~\\___/        ")
#define D51WHL43 TEXT("  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            ")

#define D51WHL51 TEXT("__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ ")
#define D51WHL52 TEXT(" |/-=|___|=   O=====O=====O=====O|_____/~\\___/        ")
#define D51WHL53 TEXT("  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/            ")

#define D51WHL61 TEXT("__/ =| o |=-~~\\  /~~\\  /~~\\  /~~\\ ____Y___________|__ ")
#define D51WHL62 TEXT(" |/-=|___|=    ||    ||    ||    |_____/~\\___/        ")
#define D51WHL63 TEXT("  \\_/      \\_O=====O=====O=====O/      \\_/            ")

#define D51DEL TEXT("                                                      ")

#define COAL01 TEXT("                              ")
#define COAL02 TEXT("                              ")
#define COAL03 TEXT("    _________________         ")
#define COAL04 TEXT("   _|                \\_____A  ")
#define COAL05 TEXT(" =|                        |  ")
#define COAL06 TEXT( " -|                        |  ")
#define COAL07 TEXT( "__|________________________|_ ")
#define COAL08 TEXT( "|__________________________|_ ")
#define COAL09 TEXT( "   |_D__D__D_|  |_D__D__D_|   ")
#define COAL10 TEXT("    \\_/   \\_/    \\_/   \\_/    ")

#define COALDEL TEXT("                              ")

#define LOGOHIGHT 6
#define LOGOFUNNEL 4
#define LOGOLENGTH 84
#define LOGOPATTERNS 6

#define LOGO1 TEXT("     ++      +------ ")
#define LOGO2 TEXT("     ||      |+-+ |  ")
#define LOGO3 TEXT("   /---------|| | |  ")
#define LOGO4 TEXT("  + ========  +-+ |  ")

#define LWHL11 TEXT(" _|--O========O~\\-+  ")
#define LWHL12 TEXT("//// \\_/      \\_/    ")

#define LWHL21 TEXT(" _|--/O========O\\-+  ")
#define LWHL22 TEXT("//// \\_/      \\_/    ")

#define LWHL31 TEXT(" _|--/~O========O-+  ")
#define LWHL32 TEXT("//// \\_/      \\_/    ")

#define LWHL41 TEXT(" _|--/~\\------/~\\-+  ")
#define LWHL42 TEXT("//// \\_O========O    ")

#define LWHL51 TEXT(" _|--/~\\------/~\\-+  ")
#define LWHL52 TEXT("//// \\O========O/    ")

#define LWHL61 TEXT(" _|--/~\\------/~\\-+  ")
#define LWHL62 TEXT("//// O========O_/    ")

#define LCOAL1 TEXT("____                 ")
#define LCOAL2 TEXT("|   \\@@@@@@@@@@@     ")
#define LCOAL3 TEXT("|    \\@@@@@@@@@@@@@_ ")
#define LCOAL4 TEXT("|                  | ")
#define LCOAL5 TEXT("|__________________| ")
#define LCOAL6 TEXT("   (O)       (O)     ")

#define LCAR1 TEXT("____________________ ")
#define LCAR2 TEXT("|  ___ ___ ___ ___ | ")
#define LCAR3 TEXT("|  |_| |_| |_| |_| | ")
#define LCAR4 TEXT("|__________________| ")
#define LCAR5 TEXT("|__________________| ")
#define LCAR6 TEXT(  "   (O)        (O)    ")

#define DELLN TEXT("                     ")

#define C51HIGHT 11
#define C51FUNNEL 7
#define C51LENGTH 87
#define C51PATTERNS 6

#define C51DEL TEXT("                                                       ")

#define C51STR1 TEXT("        ___                                            ")
#define C51STR2 TEXT("       _|_|_  _     __       __             ___________")
#define C51STR3 TEXT("    D__/   \\_(_)___|  |__H__|  |_____I_Ii_()|_________|")
#define C51STR4 TEXT("     | `---'   |:: `--'  H  `--'         |  |___ ___|  ")
#define C51STR5 TEXT("    +|~~~~~~~~++::~~~~~~~H~~+=====+~~~~~~|~~||_| |_||  ")
#define C51STR6 TEXT( "    ||        | ::       H  +=====+      |  |::  ...|  ")
#define C51STR7 TEXT( "|    | _______|_::-----------------[][]-----|       |  ")

#define C51WH61 TEXT("| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__")
#define C51WH62 TEXT("------'|oOo|==[]=-     ||      ||      |  ||=======_|__")
#define C51WH63 TEXT("/~\\____|___|/~\\_|   O=======O=======O  |__|+-/~\\_|     ")
#define C51WH64 TEXT("\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       ")

#define C51WH51 TEXT("| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__")
#define C51WH52 TEXT("------'|oOo|===[]=-    ||      ||      |  ||=======_|__")
#define C51WH53 TEXT("/~\\____|___|/~\\_|    O=======O=======O |__|+-/~\\_|     ")
#define C51WH54 TEXT("\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       ")

#define C51WH41 TEXT("| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__")
#define C51WH42 TEXT("------'|oOo|===[]=- O=======O=======O  |  ||=======_|__")
#define C51WH43 TEXT("/~\\____|___|/~\\_|      ||      ||      |__|+-/~\\_|     ")
#define C51WH44 TEXT("\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       ")

#define C51WH31 TEXT("| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__")
#define C51WH32 TEXT("------'|oOo|==[]=- O=======O=======O   |  ||=======_|__")
#define C51WH33 TEXT("/~\\____|___|/~\\_|      ||      ||      |__|+-/~\\_|     ")
#define C51WH34 TEXT("\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       ")

#define C51WH21 TEXT("| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__")
#define C51WH22 TEXT("------'|oOo|=[]=- O=======O=======O    |  ||=======_|__")
#define C51WH23 TEXT("/~\\____|___|/~\\_|      ||      ||      |__|+-/~\\_|     ")
#define C51WH24 TEXT("\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       ")

#define C51WH11 TEXT("| /~~ ||   |-----/~~~~\\  /[I_____I][][] --|||_______|__")
#define C51WH12 TEXT("------'|oOo|=[]=-      ||      ||      |  ||=======_|__")
#define C51WH13 TEXT("/~\\____|___|/~\\_|  O=======O=======O   |__|+-/~\\_|     ")
#define C51WH14 TEXT("\\_/         \\_/  \\____/  \\____/  \\____/      \\_/       ")

#define SmokePTNS 16

#ifndef _countof
#define _countof(_Array) (sizeof(_Array) / sizeof((_Array)[0]))
#endif

#ifndef _tstoi
#ifdef _UNICODE
#define _tstoi wstoi
#else
#define _tstoi atoi
#endif
#endif

#ifndef _ttolower
#ifdef _UNICODE
#define _ttolower towlower
#else
#define _ttolower tolower
#endif
#endif

#ifdef _MSC_VER
COORD SetCurrentConsoleFontSize() {
	CONSOLE_FONT_INFO ConsoleFontInfo;
	COORD dwSize;
	RECT Rect;
	GetClientRect(GetConsoleWindow(), &Rect);
	GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &ConsoleFontInfo);
	dwSize.X = round((double)(Rect.right - Rect.left) / ConsoleFontInfo.dwFontSize.X);
	dwSize.Y = round((double)(Rect.bottom - Rect.top) / ConsoleFontInfo.dwFontSize.Y);
	return dwSize;
}
#else
#define _tcsncpy_s(_Dst, _SizeInBytes, _Src, _MaxCount) _tcsncpy(_Dst, _Src, _MaxCount)
#if __STDC_VERSION__ < 199901L
#define _tprintf_s(_Format, _Dest) _tprintf(_Format, _Dest)
double round(double _X) {
	return _X > 0 ? floor(_X + 0.5) : -floor(_X + 0.5);
}
#else
#define _tprintf_s(_Format, ...) _tprintf(_Format, __VA_ARGS__)
#endif
HWND GetConsoleWindow() {
	TCHAR lpWindowName[MAX_PATH];
	GetConsoleTitle(lpWindowName, _countof(lpWindowName));
	return FindWindow(TEXT("ConsoleWindowClass"), lpWindowName);
}
COORD SetCurrentConsoleFontSize() {
	COORD dwSize;
	RECT Rect;
	GetClientRect(GetConsoleWindow(), &Rect);
	dwSize.X = round((double)(Rect.right - Rect.left) / 8);
	dwSize.Y = round((double)(Rect.bottom - Rect.top) / 18);
	return dwSize;
}
#endif

typedef struct _OPTION {
	BOOL ACCIDENT, LOGO, FLY, C51;
	int SPEED;
} OPTION;

int mvaddstr(const int y, const int x, LPCTSTR str, const SHORT COLS) {
	COORD dwCusorPosition;
	LPTSTR _Dest;
	_Dest = (LPTSTR)malloc(sizeof(TCHAR) * (COLS + 1));
	memset(_Dest, TEXT('\0'), COLS + 1);
	if (x > 0) {
		if (x < COLS && y >= 0) {
			_tcsncpy_s(_Dest, COLS + 1, str, COLS - x);
		}
		else {
			free(_Dest);
			return EXIT_FAILURE;
		}
		dwCusorPosition.X = x;
	}
	else {
		if (_tcslen(str) < -x || y < 0) {
			free(_Dest);
			return EXIT_FAILURE;
		}
		else {
			_tcsncpy_s(_Dest, COLS + 1, str - x, COLS);
		}
		dwCusorPosition.X = 0;
	}
	dwCusorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCusorPosition);
	_tprintf_s(TEXT("%s"), _Dest);
	free(_Dest);
	return EXIT_SUCCESS;
}

void add_man(const int y, const int x, const SHORT COLS) {
	LPCTSTR man[2][2] = { { TEXT(""), TEXT("(O)") }, { TEXT("Help!"), TEXT("\\O/") } };
	UINT i;
	for (i = 0; i < 2; ++i) {
		mvaddstr(y + i, x, man[(LOGOLENGTH + x) / 12 % 2][i], COLS);
	}
	return;
}

void add_smoke(const int y, const int x, const COORD magnification, const SHORT COLS) {
	static struct smokes {
		int y, x;
		UINT ptrn, kind;
	} S[1000];
	static int sum = 0;
	LPCTSTR Smoke[2][SmokePTNS] =
	{
		{ TEXT("(   )"), TEXT("(    )"), TEXT("(    )"), TEXT("(   )"), TEXT("(  )"), TEXT("(  )"), TEXT("( )"), TEXT("( )"), TEXT("()"), TEXT("()"), TEXT("O"), TEXT("O"), TEXT("O"), TEXT("O"), TEXT("O"), TEXT(" ") },
		{ TEXT("(@@@)"), TEXT("(@@@@)"), TEXT("(@@@@)"), TEXT("(@@@)"), TEXT("(@@)"), TEXT("(@@)"), TEXT("(@)"), TEXT("(@)"), TEXT("@@"), TEXT("@@"), TEXT("@"), TEXT("@"), TEXT("@"), TEXT("@"), TEXT("@"), TEXT(" ") }
	};
	LPCTSTR Eraser[SmokePTNS] = { TEXT("     "), TEXT("      "), TEXT("      "), TEXT("     "), TEXT("    "), TEXT("    "), TEXT("   "), TEXT("   "), TEXT("  "), TEXT("  "), TEXT(" "), TEXT(" "), TEXT(" "), TEXT(" "), TEXT(" "), TEXT(" ") };
	const UINT dy[SmokePTNS] = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	const UINT dx[SmokePTNS] = { -2, -1, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3 };
	if (sum > 0) {
		S[sum - 1].y *= magnification.Y;
		S[sum - 1].x *= magnification.X;
		if (sum > 1) {
			UINT i;
			for (i = 0; i < sum - 1 && i < SmokePTNS; ++i) {
				S[sum - i - 2].y = S[sum - i - 1].y - dy[i];
				S[sum - i - 2].x = S[sum - i - 1].x + dx[i] + 4;
			}
		}
	}
	if (x % 4 == 0) {
		UINT i;
		for (i = 0; i < sum; ++i) {
			mvaddstr(S[i].y, S[i].x, Eraser[S[i].ptrn], COLS);
			S[i].y -= dy[S[i].ptrn];
			S[i].x += dx[S[i].ptrn];
			S[i].ptrn += (S[i].ptrn < SmokePTNS - 1) ? 1 : 0;
			mvaddstr(S[i].y, S[i].x, Smoke[S[i].kind][S[i].ptrn], COLS);
		}
		mvaddstr(y, x, Smoke[sum % 2][0], COLS);
		S[sum].y = y;
		S[sum].x = x;
		S[sum].ptrn = 0;
		S[sum++].kind = sum % 2;
	}
	else {
		if (x > 0){
			UINT i;
			for (i = 0; i < sum; ++i) {
				mvaddstr(S[i].y, S[i].x + x % 4 - 4, Eraser[S[i].ptrn], COLS);
				mvaddstr(S[i].y, S[i].x + x % 4 - 4, Smoke[S[i].kind][S[i].ptrn], COLS);
			}
		}
		else {
			UINT i;
			for (i = 0; i < sum; ++i) {
				mvaddstr(S[i].y, S[i].x + x % 4, Eraser[S[i].ptrn], COLS);
				mvaddstr(S[i].y, S[i].x + x % 4, Smoke[S[i].kind][S[i].ptrn], COLS);
			}
		}
	}
	return;
}

int add_sl(const int x, const COORD dwSize, const OPTION op, const COORD magnification) {
	LPCTSTR sl[LOGOPATTERNS][LOGOHIGHT + 1] =
	{
		{ LOGO1, LOGO2, LOGO3, LOGO4, LWHL11, LWHL12, DELLN },
		{ LOGO1, LOGO2, LOGO3, LOGO4, LWHL21, LWHL22, DELLN },
		{ LOGO1, LOGO2, LOGO3, LOGO4, LWHL31, LWHL32, DELLN },
		{ LOGO1, LOGO2, LOGO3, LOGO4, LWHL41, LWHL42, DELLN },
		{ LOGO1, LOGO2, LOGO3, LOGO4, LWHL51, LWHL52, DELLN },
		{ LOGO1, LOGO2, LOGO3, LOGO4, LWHL61, LWHL62, DELLN }
	};
	LPCTSTR coal[LOGOHIGHT + 1] = { LCOAL1, LCOAL2, LCOAL3, LCOAL4, LCOAL5, LCOAL6, DELLN };
	LPCTSTR car[LOGOHIGHT + 1] = { LCAR1, LCAR2, LCAR3, LCAR4, LCAR5, LCAR6, DELLN };
	UINT i, y, py1 = 0, py2 = 0, py3 = 0;
	if (x < -LOGOLENGTH) {
		return EXIT_FAILURE;
	}
	y = dwSize.Y / 2 - 3;
	if (op.FLY == 1) {
		y = (x / 6) + dwSize.Y - (dwSize.X / 6) - LOGOHIGHT;
		py1 = 2;
		py2 = 4;
		py3 = 6;
	}
	for (i = 0; i <= LOGOHIGHT; ++i) {
		mvaddstr(y + i, x, sl[(LOGOLENGTH + x) / 3 % LOGOPATTERNS][i], dwSize.X);
		mvaddstr(y + i + py1, x + 21, coal[i], dwSize.X);
		mvaddstr(y + i + py2, x + 42, car[i], dwSize.X);
		mvaddstr(y + i + py3, x + 63, car[i], dwSize.X);
	}
	if (op.ACCIDENT == 1) {
		add_man(y + 1, x + 14, dwSize.X);
		add_man(y + 1 + py2, x + 45, dwSize.X);
		add_man(y + 1 + py2, x + 53, dwSize.X);
		add_man(y + 1 + py3, x + 66, dwSize.X);
		add_man(y + 1 + py3, x + 74, dwSize.X);
	}
	add_smoke(y - 1, x + LOGOFUNNEL, magnification, dwSize.X);
	return EXIT_SUCCESS;
}

int add_D51(const int x, const COORD dwSize, const OPTION op, const COORD magnification) {
	LPCTSTR d51[D51PATTERNS][D51HIGHT + 1] =
	{
		{ D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7, D51WHL11, D51WHL12, D51WHL13, D51DEL },
		{ D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7, D51WHL21, D51WHL22, D51WHL23, D51DEL },
		{ D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7, D51WHL31, D51WHL32, D51WHL33, D51DEL },
		{ D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7, D51WHL41, D51WHL42, D51WHL43, D51DEL },
		{ D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7, D51WHL51, D51WHL52, D51WHL53, D51DEL },
		{ D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7, D51WHL61, D51WHL62, D51WHL63, D51DEL }
	};
	LPCTSTR coal[D51HIGHT + 1] = { COAL01, COAL02, COAL03, COAL04, COAL05, COAL06, COAL07, COAL08, COAL09, COAL10, COALDEL };
	UINT y, i, dy = 0;
	if (x < -D51LENGTH) {
		return EXIT_FAILURE;
	}
	y = dwSize.Y / 2 - 5;
	if (op.FLY == 1) {
		y = (x / 7) + dwSize.Y - (dwSize.X / 7) - D51HIGHT;
		dy = 1;
	}
	for (i = 0; i <= D51HIGHT; ++i) {
		mvaddstr(y + i, x, d51[(D51LENGTH + x) % D51PATTERNS][i], dwSize.X);
		mvaddstr(y + i + dy, x + 53, coal[i], dwSize.X);
	}
	if (op.ACCIDENT == 1) {
		add_man(y + 2, x + 43, dwSize.X);
		add_man(y + 2, x + 47, dwSize.X);
	}
	add_smoke(y - 1, x + D51FUNNEL, magnification, dwSize.X);
	return EXIT_SUCCESS;
}

int add_C51(const int x, const COORD dwSize, const OPTION op, const COORD magnification) {
	LPTSTR c51[C51PATTERNS][C51HIGHT + 1] =
	{
		{ C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7, C51WH11, C51WH12, C51WH13, C51WH14, C51DEL },
		{ C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7, C51WH21, C51WH22, C51WH23, C51WH24, C51DEL },
		{ C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7, C51WH31, C51WH32, C51WH33, C51WH34, C51DEL },
		{ C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7, C51WH41, C51WH42, C51WH43, C51WH44, C51DEL },
		{ C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7, C51WH51, C51WH52, C51WH53, C51WH54, C51DEL },
		{ C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7, C51WH61, C51WH62, C51WH63, C51WH64, C51DEL }
	};
	LPTSTR coal[C51HIGHT + 1] = { COALDEL, COAL01, COAL02, COAL03, COAL04, COAL05, COAL06, COAL07, COAL08, COAL09, COAL10, COALDEL };
	UINT y, i, dy = 0;
	if (x < -C51LENGTH) {
		return EXIT_FAILURE;
	}
	y = dwSize.Y / 2 - 5;
	if (op.FLY == 1) {
		y = (x / 7) + dwSize.Y - (dwSize.X / 7) - C51HIGHT;
		dy = 1;
	}
	for (i = 0; i <= C51HIGHT; ++i) {
		mvaddstr(y + i, x, c51[(C51LENGTH + x) % C51PATTERNS][i], dwSize.X);
		mvaddstr(y + i + dy, x + 55, coal[i], dwSize.X);
	}
	if (op.ACCIDENT == 1) {
		add_man(y + 3, x + 45, dwSize.X);
		add_man(y + 3, x + 49, dwSize.X);
	}
	add_smoke(y - 1, x + C51FUNNEL, magnification, dwSize.X);
	return EXIT_SUCCESS;
}

int _tctoi(const TCHAR _C) {
	TCHAR _Str[2] = TEXT("");
	_Str[0] = _C;
	return _tstoi(_Str);
}

BOOL curs_set(const BOOL bVisible){
	CONSOLE_CURSOR_INFO ConsoleCursorinfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursorinfo);
	ConsoleCursorinfo.bVisible = bVisible;
	return SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursorinfo);
}

OPTION option(LPCTSTR str) {
	OPTION op = { FALSE, FALSE, FALSE, FALSE, 20 };
	while (*str != TEXT('\0')) {
		switch (_ttolower(*str++)) {
		case TEXT('a'):
			op.ACCIDENT = TRUE;
			break;
		case TEXT('f'):
			op.FLY = TRUE;
			break;
		case TEXT('l'):
			op.LOGO = TRUE;
			break;
		case TEXT('c'):
			op.C51 = TRUE;
			break;
		case TEXT('s'):
			op.SPEED = *str != TEXT('\0') ? isdigit(*str) != 0 ? _tctoi(*str++) * 10 : 20 : 20;
			break;
		default:
			break;
		}
	}
	return op;
}

int _tmain(const int argc, LPCTSTR argv[]) {
	int x;
	UINT i;
	COORD dwSize = SetCurrentConsoleFontSize();
	OPTION op = { FALSE, FALSE, FALSE, FALSE, 20 };
	for (i = 1; i < argc; ++i) {
		if (*argv[i] == TEXT('-')) {
			op = option(argv[i] + 1);
		}
	}
	signal(SIGINT, SIG_IGN);
	curs_set(FALSE);
	for (x = dwSize.X - 1; x >= -C51LENGTH; --x) {
		COORD lastSize, magnification;
		lastSize.X = dwSize.X;
		lastSize.Y = dwSize.Y;
		if (op.LOGO == TRUE) {
			dwSize = SetCurrentConsoleFontSize();
			magnification.X = lastSize.X == 0 ? 0 : dwSize.X / lastSize.X;
			magnification.Y = lastSize.Y == 0 ? 0 : dwSize.Y / lastSize.Y;
			if (add_sl(x, dwSize, op, magnification) == EXIT_FAILURE) {
				break;
			}
		}
		else if (op.C51 == TRUE) {
			dwSize = SetCurrentConsoleFontSize();
			magnification.X = lastSize.X == 0 ? 0 : dwSize.X / lastSize.X;
			magnification.Y = lastSize.Y == 0 ? 0 : dwSize.Y / lastSize.Y;
			if (add_C51(x, dwSize, op, magnification) == EXIT_FAILURE) {
				break;
			}
		}
		else {
			dwSize = SetCurrentConsoleFontSize();
			magnification.X = lastSize.X == 0 ? 0 : dwSize.X / lastSize.X;
			magnification.Y = lastSize.Y == 0 ? 0 : dwSize.Y / lastSize.Y;
			if (add_D51(x, dwSize, op, magnification) == EXIT_FAILURE) {
				break;
			}
		}
		Sleep(op.SPEED);
		_tsystem(TEXT("cls"));
	}
	signal(SIGINT, SIG_DFL);
	curs_set(TRUE);
	return EXIT_SUCCESS;
}