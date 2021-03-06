#include<iostream>
#include<string.h>
#include"Student.h"
#include<fstream>

using namespace std;

P_Student newStudentNode()
{
	P_Student Ptr = new StudentNode();
	return Ptr;
}

P_Student newStudent(Student &Temp)
{
	P_Student Ptr = new StudentNode();
	Ptr->Data = Temp;
	Ptr->Next = NULL;
	return Ptr;
}

P_Student searchId(P_Student First, char id[])
{
	while (First != NULL)
	{
		if (_stricmp(First->Data.id, id) == 0)
			return First;
		else First = First->Next;
	}
	return NULL;
}

void insertFirst(P_Student &First, Student &Temp)
{
	P_Student Ptr = newStudent(Temp);
	Ptr->Next = First;
	First = Ptr;
}

int insertAfter(P_Student Ptr, Student &Temp)
{
	if (Ptr == NULL)
		return FALSE;
	P_Student PtrTemp = newStudent(Temp);
	PtrTemp->Next = Ptr->Next;
	Ptr->Next = PtrTemp;
	return TRUE;
}

int deleteAfter(P_Student Ptr)
{
	if (Ptr == NULL || Ptr->Next == NULL)
		return FALSE;
	P_Student PtrTemp = Ptr->Next;
	Ptr->Next = PtrTemp->Next;
	delete PtrTemp;
	return TRUE;
}

int deleteFirst(P_Student &First)
{
	if (First == NULL)
		return FALSE;
	P_Student PtrTemp = First;
	First = PtrTemp->Next;
	delete PtrTemp;
	return TRUE;
}

void insertLast(P_Student &First, P_Student &Last, Student &Temp)
{
	P_Student PtrTemp = newStudent(Temp);
	if (Last == NULL && First == NULL)
	{
		First = PtrTemp;
		Last = PtrTemp;
		return;
	}
	Last->Next = PtrTemp;
	Last = Last->Next;
}

int deleteLast(P_Student &First, P_Student &Last)
{
	if (First == NULL)
		return FALSE;
	if (First == Last)
	{
		deleteFirst(First);
		Last = NULL;
		return TRUE;
	}
	P_Student PtrTemp = First;
	while (PtrTemp->Next != Last)
		PtrTemp = PtrTemp->Next;
	deleteAfter(PtrTemp);
	Last = PtrTemp;
	return TRUE;
}
