//example4_06_student.cpp

#include "example4_06_student.h"
#pragma warning(disable:4996)

int Student::counts = 0;//静态数据成员初始化


Student::Student()
{
	name = NULL;
	age = 0;
}

Student::Student(char *na, char*id, char *num, char *spec, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	strcpy(ID, id);//问：name需要开辟空间，ID为什么不需要？
	strcpy(number, num);
	strcpy(speciality, spec);
	age = ag;
	counts++;//构造一个，静态数据成员加1
}

Student::Student(const Student &per)//引用，可以对实参进行修改。但是，加上const后，保护起来，不能修改了。
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	strcpy(ID, per.ID);
	strcpy(number, per.number);
	strcpy(speciality, per.speciality);
	age = per.age;
	counts++;//构造一个，静态数据成员加1
}

Student::~Student()
{
	cout << "disCon" << endl;
	if (name)
		delete[]name;
	counts--;
}

char *Student::GetName()const//常成员函数，只作访问，不能直接间接修改。
{
	return name;
}

char *Student::GetID()
{
	return ID;
}

char *Student::GetSpec()
{
	return speciality;
}

int Student::GetAge()const//常成员函数，只作访问，不能直接间接修改。
{
	return age;
}

char *Student::GetNumber()
{
	return number;
}

void Student::Display()const//常成员函数，只作访问，不能直接间接修改。
{
	cout << "姓  名: " << name << endl;
	cout << "身份证: " << ID << endl;
	cout << "学  号: " << number << endl;
	cout << "专  业: " << speciality << endl;
	cout << "年  龄: " << age << endl << endl;
}



void Student::Input()
{
	char na[10];
	cout << "输入姓  名: ";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);

	cout << "输入身份证: ";
	cin >> ID;

	cout << "输入年  龄: ";
	cin >> age;

	cout << "输入专  业: ";
	cin >> speciality;

	cout << "输入学  号: ";
	cin >> number;

	counts++;//此句新增，每输入一个，学生总数+1
}




void Student::Insert()//新增
{
	if (!age)//当对象的age为0时，在此调用Input（）函数重新输入对象的值
		Input();
}

void Student::Delete()//新增
{
	age = 0;//只简单的将age置为0而不移动数组元素
	counts--;
}

int Student::GetCounts()//新增静态成员函数，专门用来访问静态数据成员
{
	return counts;
}
