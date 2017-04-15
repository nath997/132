#pragma once
#include"Student.h"

// Quan li danh sach lop.

using namespace std;

#define TRUE 1
#define FALSE 0
#define CONTINUE -1


struct Class
{
	char classId[15]; // ma lop: khong duoc phep trung nhau.
	char className[30]; /* ten lop: ten lop co the trung nhau.
						Chi co the trung ten lop giua cac nam voi nhau,
						trong cung mot nam khong the co 2 lop trung ten.*/
	int year;
	P_Student First = NULL;  // con tro First chi vao danh sach hoc sinh.
};

struct ClassList
{
	Class Classes[MAX];
	int nClasses = 0;
};

// search
int searchClassId(ClassList &List, char id[]); // Search class theo id neu co thi tra ve TRUE nguoc lai neu khong co.
int searchClassName(ClassList &List, char name[], int year); // Tim kiem ten lop theo nam. TRUE neu trong nam do co ten lop can tim va nguoc lai.
int searchPos(ClassList &List, char id[]);  // tra ve vi tri phan tu , khong tim thay hoac that bai se tra ve -1

// set
int setClassId(ClassList &List, Class &Data, char id[]); // neu bi trung id tra ve FALSE ,nguoc lai la TRUE.
void setYear(Class &Data, int year);
int setClassName(ClassList &List, Class &Data, char name[]); // neu bi trung ten thi tra ve FALSE, nguoc lai. Can phai setYear truoc khi setName


// sort 
void sortClassList(ClassList &List, int check); // sap xep danh sach lop theo nam, check = 1 nhung lop trung nam thi sap xep theo id , check =2 xep theo ten
void insertOrder(ClassList &List, Class &Data); // them vao van giu thu tu
void insert(ClassList &List, Class &Data); // chi them vao

// file
void writeToClassFile(ClassList &List);
void readClassFile(ClassList &List);
void createClassFolder(Class &Data);

int deleteClass(ClassList &List, char id[]); // chi co the delete khi First == NULL , tra ve FALSE neu that bai

// test console
int createClassData(Class &Data, ClassList &List);
void addList(ClassList &List);
void showList(ClassList &List);