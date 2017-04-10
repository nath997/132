#include<iostream>
#include<conio.h>
#include"console.h"
#include"AVLtree.h"
#include<fstream>

using namespace std;

void drawBox(int x, int y, int height, int width)
{
	for (int i = 1; i <= height; i++)
	{
		if (i == 1 )
		{
			gotoXY(x, y);
			for (int j = 1; j <= width; j++)
			{
				if (j == 1)
					cout << char(201);
				else {
					if (j == width)
						cout << char(187);
					else cout << char(205);
				}
			}
			y++;
		}
		else {
			if (i == height)
			{
				gotoXY(x, y);
				for (int j = 1; j <= width; j++)
				{
					if (j == 1)
						cout << char(200);
					else {
						if (j == width)
							cout << char(188);
						else cout << char(205);
					}
				}
			}
			else{
				gotoXY(x, y);
				cout << char(186);
				gotoXY(x + width - 1, y);
				cout << char(186);
				cout << endl;
				y++;
			}
		}
	}
}


void clearBox(int x, int y, int height, int width)
{
	for (int i = 1; i <= height; i++,y++)
	{
		gotoXY(x, y);
		for (int j = 1; j <= width; j++)
			cout << ' ';
	}
}
int main()
{
	int check, res;
	char array[100];
	P_AVL Root = NULL;
	while (1)
	{
		cout << "Ban muon nhap lieu hay xem du lieu(1 = nhap lieu, 0 = xem, -1 = xoa, -2 = xoa tat ca): ", cin >> check;
		cin.ignore();
		while (check != 1 && check != 0 && check != -1 && check != -2)
		{
			cout << "Nhap sai, nhap lai:", cin >> check;
			cin.ignore();
		}
		if (check == 1)
			newCourse(Root);
		if (check == 0)
		{
			if (Root == NULL)
			{
				cout << "Khong he co du lieu" << endl;
				continue;
			}
			else traverseLNR(Root);
		}
		if (check == -1)
		{
			if (Root == NULL)
			{
				cout << "Khong he co du lieu" << endl;
				continue;
			}
			else {
				cout << "Nhap id can de xoa: ", cin.getline(array, 100);
				res = deleteCourse(Root, array);
				if (res == FALSE)
					cout << "Khong ton tai." << endl;
			}
		}
		if (check = -2)
		{
			clearAllCourses(Root);
		}
	}
	_getch();
}