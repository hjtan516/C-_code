#pragma warning(disable:4996)
#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
	static int total;//私有静态数据成员
	int num;
	char name[20];
public:
	Student() { total++; }
	~Student() { total--; }
	Student(int n, const char*p = "Wang");
	void GetName();
	int Getnum();
	static void Print();//声明一个公有的静态成员函数
};

int Student::total = 0;//静态数据成员定义并初始化
Student::Student(int n, const char *p)
{
	num = n;
	strcpy(name, p);
	total++;
}

void Student::GetName()
{
	cout << name << endl;
}

int Student::Getnum()
{
	return num;
}

void Student::Print()//定义公有静态成员函数，此处不能再加static
{
	cout << "The number of all students: " << total << endl;
}
//静态成员函数只能访问静态数据成员(公有私有都可以)，不能访问其他的数据

int main()
{
	Student::Print();//类名::静态数据成员名访问
	Student *p = new Student(13);//用指针申请动态空间并得到对象*P
	Student::Print();//类名::静态数据成员名访问
	p->Print();//用指针所指向的对象访问
	delete p;//通过指针删除动态对象，析构一次
	Student::Print();//类名::静态数据成员名访问
	Student s[2];//定义两个对象，构造函数调用两次
	s[0].Print();
	s[1].Print();//两行结构一定相同
	Student::Print();//类名::静态数据成员名访问

	system("pause");
	return 0;

}
