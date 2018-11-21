/*************************************************
** 编号 : example4_03
** 功能 : 圆的周长和面积的计算 
** 知识 : 常数据成员的初始化及访问示例
** 作者 : 910850332@qq.com
** 版本 : 2018-11-16 / 19:46
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
	Circle(double r = 0):PI(3.1415926)//只能通过初始化列表初始化常数据成员
	{
		Radius = r;
	}
	double Area();
	double Circumference();
};


double Circle::Area()
{
	return PI * Radius*Radius;
}

double Circle::Circumference()
{
	return 2 * PI*Radius;
}

	


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	
	Circle c1(3.5), c2;
	cout << "area of c1=" << c1.Area() << " , circumference of c1=" << c1.Circumference() << endl;
	cout << "area of c2=" << c2.Area() << " , circumference of c2=" << c2.Circumference() << endl;

	system("pause");
	
	return 0;
}

