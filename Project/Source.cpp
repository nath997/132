#include<iostream>
#include<conio.h>
#include"console.h"
#include"AVLtree.h"
#include<fstream>
#include<string.h>
#include"Class.h"
#include<direct.h>

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

struct p
{
	p *P = NULL;
	int t;
};

int main()
{
	// check AVL
	/*int check, res;
	char array[100];
	P_AVL Root = NULL;
	while (1)
	{
		cout << "(1 = nhap lieu, 0 = xem, -1 = xoa, -2 = xoa tat ca, -3 = luu du lieu, -4 = doc du lieu, -5 = kiem tra cay nhi phan, -6 = show balance factor): ", cin >> check;
		cin.ignore();
		while (check != 1 && check != 0 && check != -1 && check != -2 && check != -3 && check != -4 && check != -5 && check != -6)
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
		if (check == -2)
		{
			clearAllCourses(Root);
		}
		if (check == -3)
		{
			if (Root == NULL)
			{
				cout << "Khong he co du lieu" << endl;
				continue;
			}
			else {
				writeToFileAVL(Root);
			}
		}
		if (check == -4)
		{
			if (Root != NULL)
			{
				cout << "Da co du lieu" << endl;
				continue;
			}
			readFileAVL(Root);
		}
		if (check == -5)
		{
			if (checkAVL(Root) == FALSE)
				cout << "Khong phai la cay AVL";
			else cout << "La cay AVL";
		}
		if (check == -6)
		{
			showBalFactor(Root);
		}
	}*/

	// check class
	/*int check;
	ClassList List;
	Class Data;
	char array[15];
	while (1)
	{
		cout << "1 : nhap lieu, 0 : xem du lieu, -1 : ghi vao file , -2 : doc file , -3 : xoa, -10 : thoat  : ";
		cin >> check;
		cin.ignore();
		while (check != 1 && check != 0 && check != -1 && check != -2 && check != -10 && check != -3)
		{
			cout << "Nhap lai: ", cin >> check;
			cin.ignore();
		}
		if (check == 1)
		{
			addList(List);
			continue;
		}
		if (check == 0)
		{
			if (List.nClasses == 0)
			{
				cout << "Khong co du lieu" << endl;
				continue;
			}
			showList(List);
			continue;
		}
		if (check == -1)
		{
			if (List.nClasses == 0)
			{
				cout << "Khong co du lieu" << endl;
				continue;
			}
			else {
				writeToClassFile(List);
				continue;
			}

		}
		if (check == -2)
		{
			readClassFile(List);
			continue;
		}
		if (check == -10)
			break;
		if (check == -3)
		{
			cout << "Nhap phan tu can xoa: ", cin.getline(array, 15), fflush(stdin);
			deleteClass(List, array);
		}
	}*/

_getch();

	
}