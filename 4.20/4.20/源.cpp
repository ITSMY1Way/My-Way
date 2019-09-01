#include <iostream>
#include <windows.h>
using namespace std;
//类与对象 下。
//构造函数 创建变量时，编译器调用构造函数，给对象中哥哥成员变量一个合理的初始值
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; 
//	int _month; 
//	int _day;
//};//构造函数体中的语句只能将其称作为赋初值，而不能称作初始化。因为初始化只能初始化一次，而构造函数体内可以多次赋值
////初始化列表：以冒号开始，接着以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括号中的初始值或表达式。
//class Date
//{//每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;//类中包含以下成员，必须放在初始化列表位置进行初始化：
//};//引用成员变量 const成员变量 类类型成员
//class A
//{ 
//public: 
//	A(int a) 
//		:_a(a)
//	{}
//private: 
//	int _a; 
//}; 
//class B{
//public: 
//	B(int a, int ref) 
//		: _aobj(a)
//		, _ref(ref)
//		, _n(10) 
//	{}
//private: 
//	A _aobj; // 类类型成员  没有默认构造函数 
//	int& _ref; // 引用 
//	const int _n; // const 
//};
class Time//对于自定义类型成员变量，一定会先使用初始化列表初始化。
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};
class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;
};
int main()
{
	Date d(1);
	system("pause");
	return 0;
}
//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后顺序无关
class Array
{
public:
	Array(int size)
		:_size(size)
		, _array((int*)malloc(sizeof(int)*_size))
	{}
private:
	int* _array;
	int _size;
};
// explicit（明确的；清楚的；直率的；详述的）关键字

