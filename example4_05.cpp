/*************************************************
** 编号 : example4_05
** 功能 :   
** 知识 : 常成员函数与常对象的使用
** 作者 : 910850332@qq.com
** 版本 : 2018-11-19 / 00:10
/**************************************************/

#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

/*----------------------------------*
         Class Defination
*-----------------------------------*/
class Person
{
private:
	int age;
	char *name;
protected:
public:
	Person(const int n = 1,const char *na = "Zhuli");//构造函数
	~Person();
	void Print();//重载函数，用于输出普通成员函数
	void Print()const;//重载函数，用于输出常成员函数，const参与重载
	void ModifyAge();//用于修改年龄的普通成员函数
};

Person::Person(const int n,const char *na)//构造函数定义
{
	age = n;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
}
	
Person::~Person()//析构函数的定义
{
	delete[]name;
}

void Person::Print()//普通成员函数的定义Print（）
{
	cout << "age:" << age << " name:" << name << endl;
	cout << "This is general Print()." << endl<<endl;
}

void Person::Print()const//常成员函数Print（）的定义，const不能省略
{
	cout << "age:" << age << " name:" << name << endl;
	cout << "This is const Print()." << endl << endl;
}

void Person::ModifyAge()//普通成员函数，用于修改年龄
{
	age++;
}
/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	const Person p1(17, "wu");//定义常对象时必须初始化
	cout << "Output const object p1" << endl;
	p1.Print();

	Person p2(18, "zhang");
	cout << "Output general object p2" << endl;
	p2.ModifyAge();
	p2.Print();


	system("pause");
	
	return 0;
}
/*Print()函数有重载版本，一个常成员函数，一个普通成员函数，通过函数首部的最后是否有const加以区分*/
