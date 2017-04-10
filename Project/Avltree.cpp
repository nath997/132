#include"AVLtree.h"
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

P_AVL searchCourseID(P_AVL Root, char id[])
{
	while (Root != NULL)
	{
		if (_stricmp(Root->Data.courseId, id) == 0) 
			return Root;
		else {
			if (_stricmp(Root->Data.courseId, id) < 0) // id be hon
				Root = Root->Left;
			else Root = Root->Right; // id lon hon
		}
	}
	return Root;
}

P_AVL searchCourseName(P_AVL Root, char name[])
{
	P_AVL STACK[100];
	int top = -1;
	if (Root == NULL)
		return NULL;
	while (1)
	{
		while (Root != NULL)
		{
			STACK[++top] = Root;
			Root = Root->Left;
		}
		/*if (top == -1)
			break;
		while (top != -1)
		{
			if (_stricmp(STACK[top]->Data.courseName, name) == 0)
				return STACK[top];
			else {
				if (STACK[top]->Right != NULL)
				{
					Root=STACK[top--]->Right;
				}
				top--;
			}
		}*/
		if (top != -1)
		{
			if (_stricmp(STACK[top]->Data.courseName, name) == 0)
				return STACK[top];
			Root = STACK[top--]->Right;
		}
		else break;
	}
	return NULL;
}

P_AVL newCourse(Course & Temp)  
{
	P_AVL Ptr = new AVLTree();
	Ptr->Data = Temp;
	Ptr->Left = Ptr->Right = NULL;
	Ptr->balFactor = EQUAL;
	return Ptr;
}

P_AVL newAVLNode()
{
	P_AVL Ptr = new AVLTree();
	return Ptr;
}

void rotateLL(P_AVL & Ptr)  // Truong hop bi lech trai trai
{
	P_AVL PtrTemp = Ptr->Left; 
	Ptr->Left = PtrTemp->Right;
	PtrTemp->Right = Ptr;
	switch (PtrTemp->balFactor)
	{
	case LEFT_HIGHER: // khoa trai bi lech trai
		Ptr->balFactor = EQUAL;
		PtrTemp->balFactor = EQUAL;
	case EQUAL: // khoa trai do cao nhu nhau
		Ptr->balFactor = LEFT_HIGHER;
		PtrTemp->balFactor = RIGHT_HIGHER;
	}
	Ptr = PtrTemp;
}

void rotateRR(P_AVL & Ptr) // truong hop bi lech phai phai
{
	P_AVL PtrTemp = Ptr->Right;
	Ptr->Right = PtrTemp->Left;
	PtrTemp->Left = Ptr;
	switch (PtrTemp->balFactor)
	{
	case RIGHT_HIGHER:
		Ptr->balFactor = EQUAL;
		PtrTemp->balFactor = Ptr->balFactor = RIGHT_HIGHER;
		PtrTemp->balFactor = LEFT_HIGHER;
	}
	Ptr = PtrTemp;
}

void rotateLR(P_AVL & Ptr)// truong hop bi lech trai phai
{
	P_AVL PtrTemp_1 = Ptr->Left;     
	P_AVL PtrTemp_2 = PtrTemp_1->Right;
	PtrTemp_1->Right = PtrTemp_2->Left;
	PtrTemp_2->Left = PtrTemp_1;
	Ptr->Left = PtrTemp_2->Right;
	PtrTemp_2->Right = Ptr;
	switch (PtrTemp_2->balFactor)
	{
	case LEFT_HIGHER: 
		PtrTemp_1->balFactor = EQUAL;
		Ptr->balFactor = RIGHT_HIGHER;
	case RIGHT_HIGHER:
		PtrTemp_1->balFactor = LEFT_HIGHER;
		Ptr->balFactor = EQUAL;
	case EQUAL:
		PtrTemp_1->balFactor = EQUAL;
		Ptr->balFactor = EQUAL;
	}
	Ptr = PtrTemp_2;
	Ptr->balFactor = EQUAL;
}

void rotateRL(P_AVL & Ptr)// truong hop bi lech phai trai
{
	P_AVL PtrTemp_1 = Ptr->Right;
	P_AVL PtrTemp_2 = PtrTemp_1->Left;
	PtrTemp_1->Left = PtrTemp_2->Right;
	PtrTemp_2->Right = PtrTemp_1;
	Ptr->Right = PtrTemp_2->Left;
	PtrTemp_2->Left = Ptr;
	switch (PtrTemp_2->balFactor)
	{
	case LEFT_HIGHER:
		PtrTemp_1->balFactor = RIGHT_HIGHER;
		Ptr->balFactor = EQUAL;
	case RIGHT_HIGHER:
		PtrTemp_1->balFactor = EQUAL;
		Ptr->balFactor = LEFT_HIGHER;
	case EQUAL:
		PtrTemp_1->balFactor = EQUAL;
		Ptr->balFactor = EQUAL;
	}
	Ptr = PtrTemp_2;
	Ptr->balFactor = EQUAL;
}

void balanceLeft(P_AVL & Ptr)
{
	if (Ptr->Left->balFactor == LEFT_HIGHER)
	{
		rotateLL(Ptr);
		return;
	}
	if (Ptr->Left->balFactor == RIGHT_HIGHER)
	{
		rotateLR(Ptr);
		return;
	}
	if (Ptr->Left->balFactor == EQUAL)
	{
		rotateLL(Ptr);
		return;
	}
}

void balanceRight(P_AVL & Ptr)
{
	if (Ptr->Right->balFactor == RIGHT_HIGHER)
	{
		rotateRR(Ptr);
		return;
	}
	if (Ptr->Right->balFactor == LEFT_HIGHER)
	{
		rotateRL(Ptr);
		return;
	}
	if (Ptr->Right->balFactor == EQUAL)
	{
		rotateRR(Ptr);
		return;
	}
}


int insertCourse(P_AVL &Root, Course &Temp)
{
	int res;// response
	if (Root == NULL)
	{
		Root = newCourse(Temp);
		return CONTINUE;
	}
	if (_stricmp(Root->Data.courseId, Temp.courseId) == 0)
		return FALSE;
	if (_stricmp(Root->Data.courseId, Temp.courseId) < 0)
	{
		res = insertCourse(Root->Left, Temp);
		if (res != CONTINUE)
			return res;
		switch (Root->balFactor)
		{
		case RIGHT_HIGHER:
			Root->balFactor = EQUAL;
			return TRUE;
		case EQUAL:
			Root->balFactor = LEFT_HIGHER;
			return CONTINUE;
		case LEFT_HIGHER:
			balanceLeft(Root);
			return TRUE;
		}
	}
	else {
		if (_stricmp(Root->Data.courseId, Temp.courseId) > 0)
		{
			res = insertCourse(Root->Right, Temp);
			if (res != CONTINUE)
				return res;
			switch (Root->balFactor)
			{
			case LEFT_HIGHER:
				Root->balFactor = EQUAL;
				return TRUE;
			case EQUAL:
				Root->balFactor = RIGHT_HIGHER;
				return CONTINUE;
			case RIGHT_HIGHER:
				balanceRight(Root);
				return TRUE;
			}
		}
	}
}

void searchSmallestID(P_AVL Root, Course & Temp)
{
	while (Root->Left != NULL)
	{
		Root = Root->Left;
	}
	Temp = Root->Data;
}

int deleteCourse(P_AVL &Root, char id[])
{
	int res;
	if (Root == NULL)
		return FALSE;
	if (_stricmp(Root->Data.courseId, id) < 0)
	{
		res = deleteCourse(Root->Left, id);
		if (res != CONTINUE)
			return res;
		switch (Root->balFactor)
		{
		case EQUAL:
			Root->balFactor = RIGHT_HIGHER;
			return TRUE;
		case LEFT_HIGHER:
			Root->balFactor = EQUAL;
			return CONTINUE;
		case RIGHT_HIGHER:
			balanceRight(Root);
			return TRUE;
		}
	}
	else {
		if (_stricmp(Root->Data.courseId, id) > 0)
		{
			res = deleteCourse(Root->Right, id);
			if (res != CONTINUE)
				return res;
			switch (Root->balFactor)
			{
			case EQUAL:
				Root->balFactor = LEFT_HIGHER;
				return TRUE;
			case RIGHT_HIGHER:
				Root->balFactor = EQUAL;
				return CONTINUE;
			case LEFT_HIGHER:
				balanceLeft(Root);
				return TRUE;
			}
		}
		else { // tim duoc khoa can xoa
			if (Root->Left == NULL)
			{
				P_AVL Ptr = Root;
				Root = Ptr->Right;
				delete Ptr;
				return CONTINUE;
			}
			else {
				if (Root->Right == NULL)
				{
					P_AVL Ptr = Root;
					Root = Ptr->Left;
					delete Ptr;
					return CONTINUE;
				}
				else { // xoa khoa ma do can bang cua no la 0
					Course Temp; 
					searchSmallestID(Root->Right, Temp);
					deleteCourse(Root, Temp.courseId);
					Root->Data = Temp;
					return TRUE;
				}
			}
		}
	}
}

int createData(P_AVL Root, Course &DataTemp)
{
	cout << "Nhap ma mon hoc: ", cin.getline(DataTemp.courseId, 20);
	if (searchCourseID(Root, DataTemp.courseId) != NULL)
		return -1;
	if (strlen(DataTemp.courseId) < 1)
		return FALSE;
	cout << "Nhap ten mon hoc: ", cin.getline(DataTemp.courseName, 40);
	if (searchCourseName(Root, DataTemp.courseName) != NULL)
		return -2;
	cout << "Nhap so tin chi thuc hanh: ", cin >> DataTemp.praticeCredit;
	cout << "Nhap so tin chi ly thuyet: ", cin >> DataTemp.theoryCredit;
	cin.ignore();
	return TRUE;
}

void newCourse(P_AVL &Root)
{
	Course Data;
	int error;
	while (1)
	{
		error = createData(Root, Data);
		if(error == TRUE)
			insertCourse(Root, Data);
		if (error == FALSE)
			return;
		if(error == -1)
			cout << "Ma mon hoc bi trung" << endl;
		if (error == -2)
			cout << "Ten mon bi trung" << endl;
	}
}

void traverseLNR(P_AVL Root)
{
	if (Root != NULL)
	{
		traverseLNR(Root->Left);
		cout << Root->Data.courseId << endl;
		cout << Root->Data.courseName << endl;
		cout << Root->Data.theoryCredit << endl;
		cout << Root->Data.praticeCredit << endl;
		traverseLNR(Root->Right);
	}
}

void clearAllCourses(P_AVL &Root)
{
	if (Root != NULL)
	{
		clearAllCourses(Root->Left);
		clearAllCourses(Root->Right);
		delete Root;
	}
}

void clearFileAVL()
{
	fstream file("Tree\\Text.txt", ios::out);
	file.close();
	return;
}

void writeToFileAVL(Course &Data)
{
	fstream file("Tree\\Text.txt", ios::app || ios::binary);
	file.write(reinterpret_cast<char *>(&Data), sizeof(Course));
	file.close();
}

void writeToFileAVL(P_AVL Root)
{
	if (Root != NULL)
	{
		writeToFileAVL(Root->Left);
		writeToFileAVL(Root->Right);
		fstream file("Tree\\Text.txt", ios::app || ios::binary);
		file.write(reinterpret_cast<char *>(&Root->Data), sizeof(Course));
		file.close();
	}
}

void readFileAVL(P_AVL &Root)
{
	
	fstream file("Tree\\Text.txt", ios::in || ios::binary);
	Course Data;
	while (file)
	{
		file.read(reinterpret_cast<char *>(&Data), sizeof(Course));
		insertCourse(Root, Data);
	}
	file.close();
}