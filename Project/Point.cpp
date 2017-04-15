#include<iostream>
#include<string.h>
#include"Point.h"

using namespace std;

P_Point newPointNode()
{
	P_Point Ptr = new PointNode();
	return Ptr;
}
P_Point newPoint(Point &Temp)
{
	P_Point Ptr = new PointNode();
	Ptr->Data = Temp;
	Ptr->Next = NULL;
	return Ptr;
}

void insertFirst(P_Point &First, Point &Temp)
{
	P_Point Ptr = newPoint(Temp);
	Ptr->Next = First;
	First = Ptr;
}

int insertAfter(P_Point Ptr, Point &Temp)
{
	if (Ptr == NULL)
		return FALSE;
	P_Point PtrTemp = newPoint(Temp);
	PtrTemp->Next = Ptr->Next;
	Ptr->Next = PtrTemp;
	return TRUE;
}

int deleteAfter(P_Point Ptr)
{
	if (Ptr == NULL || Ptr->Next == NULL)
		return FALSE;
	P_Point PtrTemp = Ptr->Next;
	Ptr->Next = PtrTemp->Next;
	delete PtrTemp;
	return TRUE;
}

int deleteFirst(P_Point &First)
{
	if (First == NULL)
		return FALSE;
	P_Point PtrTemp = First;
	First = PtrTemp->Next;
	delete PtrTemp;
	return TRUE;
}

void insertLast(P_Point &First, P_Point &Last, Point &Temp)
{
	P_Point PtrTemp = newPoint(Temp);
	if (Last == NULL && First == NULL)
	{
		First = PtrTemp;
		Last = PtrTemp;
		return;
	}
	Last->Next = PtrTemp;
	Last = Last->Next;
}

int deleteLast(P_Point &First, P_Point &Last)
{
	if (First == NULL)
		return FALSE;
	if (First == Last)
	{
		deleteFirst(First);
		Last = NULL;
		return TRUE;
	}
	P_Point PtrTemp = First;
	while (PtrTemp->Next != Last)
		PtrTemp = PtrTemp->Next;
	deleteAfter(PtrTemp);
	Last = PtrTemp;
	return TRUE;
}