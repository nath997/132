#pragma once

// Cay nhi phan tim kiem AVL 

#define TRUE 1
#define FALSE 0
#define CONTINUE -1

#define LEFT_HIGHER 1
#define RIGHT_HIGHER -1
#define EQUAL 0

struct Course
{
	char courseId[20];  // id cua khoa hoc
	char courseName[40]; // ten cua khoa hoc
	int theoryCredit; // so tin chi ly thuyet
	int praticeCredit; // so tin chi thuc hanh
};

struct AVLTree
{
	Course Data;
	AVLTree *Left;
	AVLTree *Right;
	int balFactor;
};

typedef AVLTree* P_AVL;

// search
P_AVL searchCourseID(P_AVL Root, char id[]); // tim khoa hoc co trung id va tra ve dia chi khoa hoc do, neu khong co thi tra ve NULL
P_AVL searchCourseName(P_AVL Root, char name[]);
void searchSmallestID(P_AVL Root, Course & Temp);  // tim khoa hoc co id la nho nhat va lay data cua khoa hoc do ra

// overloaded function
P_AVL newCourse(Course & Temp); // khoi tao khoa hoc va gan data vao 
void newCourse(P_AVL &Root);
P_AVL newAVLNode(); // cap phat mot vung nho 

//----------------Xoay--------------------------------------------------------
void rotateLL(P_AVL & Ptr); // xoay theo truong hop trai trai
void rotateLR(P_AVL & Ptr); // xoay theo truong hop trai phai
void rotateRL(P_AVL & Ptr); // xoay theo truong hop phai trai
void rotateRR(P_AVL & Ptr); // xoay theo trungo hop phai trai
void balanceLeft(P_AVL & Ptr);// xoay theo truong hop lech ve ben trai. Tu xac dinh la trai phai hay trai trai
void balanceRight(P_AVL & Ptr);// xoay theo truong hop lech ve ben phai. Tu xac dinh la phai trai hay phai phai
//----------------------------------------------------------------------------

//insert, delete---------------------------------------------------------------
int insertCourse(P_AVL &Root, Course &Temp); // them mot khoa hoc va tu dong can bang cay
int deleteCourse(P_AVL &Root, char id[]); // xoa mot khoa hoc va tu dong can bang cay
void clearAllCourses(P_AVL &Root);  // xoa het tat ca cac khoa cua cay AVL
void writeToFileAVL(Course &Data);
void writeToFileAVL(P_AVL Root);
void readFileAVL(P_AVL &Root);
void clearFileAVL();
//-----------------------------------------------------------------------------


//---------------------testConsole--------------------------------------
int createData(P_AVL Root, Course &DataTemp);
void traverseLNR(P_AVL Root);