#pragma warning(disable:4996)
#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
	int num;
	char name[20];
public:
	static int total;//公有的静态数据成员
	Student() { total++; }
	~Student() { total--; }
	Student(int n, const char *p="Wang");
	void GetName();
	int Getnum();
};

int Student::total = 0;//静态数据成员初始化
Student::Student(int n, const char *p)//带参构造函数，每定义一个新对象，total+1
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

int main()
{
	cout << "The number of all students: " << Student::total << endl;//类名::静态成员名访问
	
	Student *p = new Student(13);//用指针申请动态空间并得到对象*p
	cout << "The number of all students: " << Student::total << endl;//类名::静态成员名访问
	cout << "The number of all students: " << p->total << endl;//用指针所指的对象去访问
	
	delete p;
	cout << "The number of all students: " << p->total << endl;//用指针所指的对象去访问
	cout << "The number of all students: " << Student::total << endl;//类名::静态成员名访问
	
	Student s[2];//定义两个对象，构造函数调用两次
	cout << "The number of all students: " << s[0].total << endl;//对象名访问
	cout << "The number of all students: " << s[1].total << endl; //对象名访问
	cout << "The number of all students: " << Student::total << endl;//类名::静态成员名访问

	system("pause");
	return 0;

}
