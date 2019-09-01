#include <iostream>
#include <windows.h>
using namespace std;
//运算符重载
// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// bool operator==(Date* this, const Date& d2)
//	// 这里需要注意的是，左操作数是this指向的调用函数的对象
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year && _month == d2._month && _day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void Test()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
}
int main()
{
	Test();
	system("pause");
	return 0;
}
//赋值运算符重载 参数类型 返回值 检查是否给字节赋值 返回*this
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//const成员 将const修饰的类成员函数称之为const成员函数，const修饰类成员函数，实际修饰该成员函数隐含的this指针，表明在该成员函数中不能对类的任何成员进行修改
//非const对象是可以调用c成员函数的；最小权限原则； c对象只能调用c成员函数，不能调用非c成员函数
//取地址及const取地址操作符重载
class Date
{
public:
	Date* operator&()
	{
		return this;
	}

	const Date* operator&()const
	{
		return this;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
}; //这两个默认成员函数一般不用重新定义 ，编译器默认会生成