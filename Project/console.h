// basic console functions, collected by Nguyen Trung Thanh
// abcxyz tcIT

#ifndef _console_header
#define _console_header


#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_PageUp  1073
#define key_PageDw  1081
#define key_none	-1
#define key_Esc     27

struct  StatusMouse
{
	int _kindMouse = 0, x = 0, y = 0;
};

//--------------------------------------------------------

#include <windows.h>
#include <stdio.h>
#include <conio.h>
//--------------------------------------------------------
void PrintMenu(const char menu[][20], int n, int x, int y, int color);
void PaintMenu(int x, int y, int numCur, int numPre, char menu[][20]);
int NumMenu(char menu[][20], int nCate, int posStandX, int posStandY);
int inputKey();
int inputKey2();
//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY (int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor (int color);
//end----------------------Screen----------------------end
//catch key anh mouse
// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility);
void KeyMouse(StatusMouse &mouse, int &Key);
void putKey(int &key);
#endif
