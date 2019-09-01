#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
//typedef int DataType;
//class Seqlist//析构函数 类
//{
//public:
//	Seqlist(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//特征：类名前_,无返回值，无显示定义系统会默认生成
//	~Seqlist()
//	{
//		if (_pData)
//		{
//			free(_pData); //释放堆上的空间
//			_pData = NULL; //将指针置为空
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//拷贝构造 是构造函数的一个重载形式 参数只有一个且必须使用引用传参
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//若未显式定义，系统生成默认的拷贝构造函数，默认的拷贝构造函数对象按内存储存按字节完成拷贝，这是浅拷贝/值拷贝
//1.运算符重载  为增强代码可读性   .*   ::   sizeof   ?:  .  五个运算符不能重载
//分全局和类内
//bool operator==(Date* this, const Date& d2)  左操作数是this指向的调用函数的对象
//bool operator==(const Date& d2)
//2.赋值运算符重载   Date& operator=(const Date& d)
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		free(_str);
//		cout << "~String()" << endl;
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2("world");
//	s1 = s2;
//}

//class Date
//{
//public:
//
//	void Display1()
//	{
//		cout << "Display () const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//
//	void Display() const
//	{
//		cout << "Display () const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//		Display1();
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//void Test()
//{
//	Date d1;
//	d1.Display();
//
//	const Date d2;
//	d2.Display();
//}
//
//int main()
//{
//	Test();
//	getchar();
//}

//class Date
//{
//public:
//	Date* operator&() = delete;
//	/*{
//		cout << "&" << endl;
//		return this;
//	}
//
//	const Date* operator&()const
//	{
//		cout << "const &" << endl;
//		return this;
//	}*/
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//int main()
//{
//	Date a;
//	//const Date b;
//	//a.operator&();
//	&a;
//	cout << "-----------" << endl;
//	//&b;
//
//	getchar();
//	return 0;
//}
//const对象可以调用其他的const函数（他们不是一一对应的关系）
//const成员函数内可以调用其他的const成员函数
//非const对象可以调用非const成员函数和const成员函数
//非const成员函数内可以调用其他的const成员函数和非const成员函数


