#pragma once
// danh sach lien ket quan ly diem cua sinh vien

#include"AVLtree.h"

#define TRUE 1
#define FALSE 0
#define CONTINUE -1

struct Point
{
	char courseId[20];
	int times; // so lan kiem tra, 0 neu chua kiem tra lan nao, 2 lan la toi da
	int point;
};

struct PointNode
{
	Point Data;
	PointNode *Next;
};

typedef PointNode* P_Point;

P_Point newPointNode();
P_Point newPoint(Point &Temp);


void insertFirst(P_Point &First, Point &Temp);
int insertAfter(P_Point Ptr, Point &Temp);
void insertLast(P_Point &First, P_Point &Last, Point &Temp);
int deleteAfter(P_Point Ptr);
int deleteFirst(P_Point &First);
int deleteLast(P_Point &First, P_Point &Last);