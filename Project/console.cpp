#include "console.h"
#include <iostream>

using namespace std;

void PrintMenu(const char menu[][20], int n, int x, int y,int color) {
	TextColor(color);
	for (int i = 0; i < n; i++) {
		gotoXY(x, y + i);
		cout << menu[i];
	}
}
//to mau menu duoc chon
void PaintMenu(int x, int y, int numCur, int numPre, char menu[][20]) {
	--numCur; --numPre;
	gotoXY(x, y + numPre); TextColor(15); cout << menu[numPre];
	gotoXY(x, y + numCur); TextColor(12); cout << menu[numCur];
}
//tra ve so menu duoc chon
int NumMenu(char menu[][20], int nCate, int posStandX, int posStandY) {
	//luu su kien chuot
	StatusMouse sMouse;
	//luu su kien phien
	int CKey;

	//chi so vi tri dang duoc to  mau
	unsigned int numMenuCur = 1;
	unsigned int numMenuPre = nCate;

	//in ra menu va to mau theo chi so
	PrintMenu(menu, nCate, posStandX, posStandY,ColorCode_White);
	PaintMenu(posStandX, posStandY, numMenuCur, numMenuPre, menu);
	int dem = 0;

	//thuc hien chon menu bang phim va chuot
	while (1)
	{
		putKey(CKey);// bat su kien phim
		switch (CKey)
		{
		case key_Up:
		{
			if (numMenuCur == 1) { numMenuCur = nCate; numMenuPre = 1; }
			else { numMenuPre = numMenuCur; --numMenuCur; }
			goto paint;
		}
		case key_Down:
		{
			if (numMenuCur == nCate) { numMenuCur = 1; numMenuPre = nCate; }
			else { numMenuPre = numMenuCur; ++numMenuCur; }
			goto paint;
		}
		case 13: { return numMenuCur; }
			 paint:
		{
			PaintMenu(posStandX, posStandY, numMenuCur, numMenuPre, menu);
			break;
		}
		default:
			break;
		}
	}
}

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}
int inputKey2()
{
    int numkey;
	if (_kbhit())
	{
		putKey(numkey);
		return numkey;
	}
	return key_none;
}
//
//-------------------------Screen-------------------------
//
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
//screen: goto [x,y]
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
HANDLE whand;
HANDLE rhand;

//catch key and mouse
void KeyMouse(StatusMouse &mouse, int &Key) {
	//lay handle man hinh console
	rhand = GetStdHandle(STD_INPUT_HANDLE);
	bool runCath = 1;// thiet lap co che thoat
	Key = 0;
	mouse._kindMouse = 0;
	while (runCath)
	{
		//lay so luong event da xay ra
		DWORD numberEvent = 0;
		GetNumberOfConsoleInputEvents(rhand, &numberEvent);
		if (numberEvent != 0) {//co su kien xay ra
			//tao mang de luu cac event
			INPUT_RECORD *enventBuff = new INPUT_RECORD[numberEvent];
			DWORD rnumberEvent = 0;
			//doc event vao man
			ReadConsoleInput(rhand, enventBuff, numberEvent, &rnumberEvent);
			for (DWORD i = 0; i < rnumberEvent; ++i) {
				if (enventBuff[i].EventType == MOUSE_EVENT) {//kiem tra co phai event mouse
					// lay toa do chuot
					mouse.x = enventBuff[i].Event.MouseEvent.dwMousePosition.X;
					mouse.y = enventBuff[i].Event.MouseEvent.dwMousePosition.Y;
					//kiem tra co phai chuot trai duoc nhan
					if (enventBuff[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
						mouse._kindMouse = 1;
						runCath = 0;
					}
					//kiem tra co phai chuot phai nhan
					else if (enventBuff[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
						mouse._kindMouse = 2;
						runCath = 0;
					}
				}//kiem tra co phai event key
				else if (enventBuff[i].EventType == KEY_EVENT && enventBuff[i].Event.KeyEvent.bKeyDown) {
					if ((Key = enventBuff[i].Event.KeyEvent.uChar.AsciiChar) == 0) {
						Key = enventBuff[i].Event.KeyEvent.wVirtualScanCode+1000;
					}
					runCath = 0;
				}
			}
			delete[] enventBuff;
		}
	}
	Sleep(1);
}
// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void putKey( int &Key) {
	//lay handle man hinh console
	rhand = GetStdHandle(STD_INPUT_HANDLE);
	bool runCath = 1;// thiet lap co che thoat
	Key = -1;
	while (runCath)
	{
		//lay so luong event da xay ra
		DWORD numberEvent = 0;
		GetNumberOfConsoleInputEvents(rhand, &numberEvent);
		if (numberEvent != 0) {//co su kien xay ra
			//tao mang de luu cac event
			INPUT_RECORD *enventBuff = new INPUT_RECORD[numberEvent];
			DWORD rnumberEvent = 0;
			//doc event vao man
			ReadConsoleInput(rhand, enventBuff, numberEvent, &rnumberEvent);
			for (DWORD i = 0; i < rnumberEvent; ++i) {
				if (enventBuff[i].EventType == KEY_EVENT && enventBuff[i].Event.KeyEvent.bKeyDown) {
					if ((Key = enventBuff[i].Event.KeyEvent.uChar.AsciiChar) == 0) {
						Key = enventBuff[i].Event.KeyEvent.wVirtualScanCode+1000;
					}
					runCath = 0;
				}
			}
			delete[] enventBuff;
		}
	}
	Sleep(1);
}
