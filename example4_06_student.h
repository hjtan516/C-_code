//example4_06_student.h

#pragma once
#ifndef _STUDENT

#define _STUDENT
#include <iostream>
#include<string.h>

using namespace std;


/*----------------------------------*
		 Class Defination
*-----------------------------------*/



class Student
{
private:
	char *name;
	char ID[19];
	char number[10];
	char speciality[20];
	int age;
	static int counts;//实际有效的学生个数，小于等于对象的个数
	//静态数据成员，所有对象共享此成员
protected:
public:
	Student();
	Student(char *na, char *id, char *num, char *spec, int ag);
	Student(const Student &per);
	~Student();
	char *GetName()const;//可以定义为常成员函数,不能修改对象的数据成员
	char *GetID();//不可以定义为常成员函数
	char *GetNumber();//不可以定义为常成员函数
	char *GetSpec();//不可以定义为常成员函数
	int GetAge()const;
	void Display()const;
	void Input();
	void Insert();
	void Delete();
	static int GetCounts();//静态成员函数，只能访问静态数据成员，不能访问普通数据成员
};

#endif
