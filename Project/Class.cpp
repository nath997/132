#include<iostream>
#include<string.h>
#include"Class.h"
#include<fstream>
#include<direct.h>
#include<conio.h>


using namespace std;

int searchClassId(ClassList &List, char id[])  
{
	for (int i = 0; i < List.nClasses; i++)
	{
		if (_stricmp(List.Classes[i].classId, id) == 0)
			return TRUE;
	}
	return FALSE;
}

int searchPos(ClassList &List, char id[])
{
	for (int i = 0; i < List.nClasses; i++)
	{
		if (_stricmp(List.Classes[i].classId, id) == 0)
			return i;
	}
	return -1;
}

int searchClassName(ClassList &List, char name[], int year)
{
	for (int i = 0; i < List.nClasses; i++)
	{
		if (List.Classes[i].year == year && _stricmp(List.Classes[i].className, name) == 0)
			return TRUE;
	}
	return FALSE;
}

int setClassId(ClassList &List, Class &Data, char id[])
{
	if (searchClassId(List, id) == TRUE)
		return FALSE;
	strcpy_s(Data.classId, id);
	return TRUE;
}

int setClassName(ClassList &List, Class &Data, char name[])
{
	if (searchClassName(List, name, Data.year) == TRUE)
		return FALSE;
	strcpy_s(Data.className, name);
	return TRUE;
}

void setYear(Class &Data, int year)
{
	Data.year = year;
}

void sortClassList(ClassList &List, int check)
{
	Class Temp;
	if (check == 1)
	{
		for (int i = 0; i < List.nClasses - 1; i++)
		{
			for (int j = i + 1; j < List.nClasses; j++)
			{
				if (List.Classes[i].year > List.Classes[j].year)
				{
					Temp = List.Classes[i];
					List.Classes[i] = List.Classes[j];
					List.Classes[j] = Temp;
					continue;
				}
				if (_stricmp(List.Classes[i].classId, List.Classes[j].classId) > 0 && List.Classes[i].year == List.Classes[j].year)
				{
					Temp = List.Classes[i];
					List.Classes[i] = List.Classes[j];
					List.Classes[j] = Temp;
				}
			}
		}return;
	}if (check == 2)
	{
		for (int i = 0; i < List.nClasses - 1; i++)
		{
			for (int j = i + 1; j < List.nClasses; j++)
			{
				if (List.Classes[i].year > List.Classes[j].year)
				{
					Temp = List.Classes[i];
					List.Classes[i] = List.Classes[j];
					List.Classes[j] = Temp;
					continue;
				}
				if (_stricmp(List.Classes[i].className, List.Classes[j].className) > 0 && List.Classes[i].year == List.Classes[j].year)
				{
					Temp = List.Classes[i];
					List.Classes[i] = List.Classes[j];
					List.Classes[j] = Temp;
				}
			}
		}return;
	}
}

void insertOrder(ClassList &List, Class &Data)
{
	int i;
	for (i = 0; i < List.nClasses; i++)
	{
		if (List.Classes[i].year > Data.year)
			break;
		if (List.Classes[i].year == Data.year && _stricmp(List.Classes[i].classId, Data.classId) > 0)
			break;
	}
	for (int j = List.nClasses; j > i; j--)
	{
		List.Classes[j] = List.Classes[j - 1];
	}
	List.Classes[i] = Data;
	List.nClasses += 1;
}

void writeToClassFile(ClassList &List)
{
	fstream file("Data\\class.da", ios::out | ios::binary);
	for (int i = 0; i < List.nClasses; i++)
		file.write((char*)(&List.Classes[i]), sizeof(Class));
	file.close();
	return;
}


void readClassFile(ClassList &List)
{
	fstream file("Data\\class.da", ios::in | ios::binary);
	List.nClasses = 0;
	while (file)
		file.read((char*)(&List.Classes[List.nClasses++]), sizeof(Class));
	List.nClasses--;
	file.close();
	return;
}

int deleteClass(ClassList &List, char id[])
{
	int i;
	for (i = 0; i < List.nClasses && _stricmp(List.Classes[i].classId, id) != 0; i++);
	if (i == List.nClasses || List.Classes[i].First != NULL)
		return FALSE;
	for (i; i < List.nClasses-1; i++)
	{
		List.Classes[i] = List.Classes[i + 1];
	}
	List.nClasses -= 1;
	return TRUE;
}

int createClassData(Class &Data, ClassList &List)
{
	cout << "Nhap nam nam hoc :", cin >> Data.year, cin.ignore();
	if (Data.year == 0)
		return 0;
	cout << "Nhap ma lop: ", cin.getline(Data.classId, 15);
	fflush(stdin);
	if (searchClassId(List, Data.classId) == TRUE)
		return -1;
	cout << "Nhap ten lop: ", cin.getline(Data.className, 30);
	fflush(stdin);
	if (searchClassName(List, Data.className, Data.year) == TRUE)
		return -2;
	return TRUE;
}

void addList(ClassList &List)
{
	int err;
	Class Data;
	while (List.nClasses < MAX)
	{
		err = createClassData(Data, List);
		switch (err)
		{
		case TRUE:
			insertOrder(List, Data);
			break;
		case -1:
			cout << "Da co ma lop " << Data.classId << endl;
			break;
		case -2:
			cout << "Da co ten lop " << Data.className << endl;
			break;
		case 0:
			return;
		}
	}
}

void showList(ClassList &List)
{
	for (int i = 0; i < List.nClasses; i++)
	{
		cout << List.Classes[i].year << endl;
		cout << List.Classes[i].classId << endl;
		cout << List.Classes[i].className << endl;
		cout << endl;
	}
}

void insert(ClassList &List, Class &Data)
{
	List.Classes[List.nClasses++] = Data;
}

void createClassFolder(Class &Data)
{
	char temp[40] = "Data\\";
	strcat_s(temp, Data.classId);
	cout << temp;
	_mkdir(temp);
}