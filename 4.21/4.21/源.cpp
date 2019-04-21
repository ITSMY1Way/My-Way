#include <iostream>
#include <windows.h>
using namespace std;
//类与对象
//explicit关键字 构造初始化对象，对于单个参数的构造函数，还具有类型转换的作用
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//		explicit Date(int year)
//		:_year(year)
//	{}
//
//private:
//	int _year;
//	int _month :
//	int _day;
//}；
//void TestDate()
//{
//	Date d1(2018);
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2019;
//}//可读性不是很好，用explicit修饰构造函数，将会禁止单参构造函数的隐式转换。
////static成员 声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用static修饰的成员函数，称之为静态成员函数。静态的成员变量一定要在类外进行初始化
////为所有类共享 静态成员变量必须在类外定义，定义时不加static关键字 没有隐藏的this指针 
////C++11支持非静态成员变量在声明时，直接初始化
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// 非静态成员变量，可以在成员声明时，直接初始化。
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//	return 0;
//}
////友元 分为友元函数和友元类  突破封装，便利，增加耦合度，破坏了封装
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//prvate:
//	int _year;
//	int _month;
//	int _day
//};
//int main()
//{
//	Date d(2017, 12, 24);
//	d << cout;
//	return 0;
//}
//友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加friend关键字。
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
prvate:
	int _year;
	int _month;
	int _day
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;

	return _cout;
}
istream& operator>>(istream& _cin, const Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	system("pause");
	return 0;
}