#pragma once
#include"Point.h"

// Quan li danh sach sinh vien

#define TRUE 1
#define FALSE 0
#define CONTINUE -1

struct Student
{
	char id[100];
	char lastName[100];
	char firstName[20];
	char sex[10];
	char phoneNumber[20];
	P_Point First = NULL; // con tro chi vao danh sach diem hoc sinh
};

struct StudentNode
{
	Student Data;
	StudentNode *Next;
};
typedef StudentNode* P_Student;

// make node
P_Student newStudentNode();
P_Student newStudent(Student &Temp);

P_Student searchId(P_Student First, char id[]);

// insert
void insertFirst(P_Student &First, Student &Temp);
int insertAfter(P_Student Ptr, Student &Temp);
void insertLast(P_Student &First, P_Student &Last, Student &Temp); // them phan tu vao vi tri cuoi

// delete
int deleteAfter(P_Student Ptr);
int deleteFirst(P_Student &First);
int deleteLast(P_Student &First, P_Student &Last);

// file
//void writeToStudentFile(P_Student First);
//void readStudentFile(P_Student First);


