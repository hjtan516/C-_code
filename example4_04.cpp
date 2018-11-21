/*************************************************
** 编号 : example4_04
** 功能 : 计算圆的周长和面积
** 知识 : 常成员函数
** 作者 : 910850332@qq.com
** 版本 : 2018-11-17 / 18:06
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

/*----------------------------------*
		 Class Defination
*-----------------------------------*/
class Circle
{
private:
	double Radius;
	const double PI;//定义一个常数据成员PI代表圆周率
public:
	Circle(double r = 0) :PI(3.1415926)//只能通过初始化列表初始化常数据成员
	{
		Radius = r;
	}
	double Area();
	double Circumference();
	double GetRadius()const;//常成员函数，获取半径值，此例为新增加
};


double Circle::Area()
{
	return PI * Radius*Radius;
}

double Circle::Circumference()
{
	return 2 * PI*Radius;
}

double Circle::GetRadius()const//常成员函数，取半径值的实现代码，此例新增加
{
	return Radius;
}


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	Circle c1(3.5), c2;//定义两个对象，c2的半径用默认值
	cout << "radius of c1=" << c1.GetRadius();//调用常成员函数输出半径
	cout << "， area of c1=" << c1.Area() << " , circumference of c1=" << c1.Circumference() << endl;
	cout << "radius of c2=" << c2.GetRadius();//调用常成员函数输出半径
	cout << "， area of c2=" << c2.Area() << " , circumference of c2=" << c2.Circumference() << endl;

	system("pause");

	return 0;
}

