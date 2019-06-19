#include <iostream>
using namespace std;
//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetACount()scount;
//};
//int A::_scount = 0;
//void TestA() { return _scount; }
//private:
//	static int _
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//int main()
//{
//	TestA();
//	getchar();
//	return 0;
//	
//}
// 静态成员函数没有隐藏的this指针
//友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多
//用。友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1(2);
//	d1 = 2019;
//}
//
//int main()
//{
//	TestDate();
//	return 0;
//}
//声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用static修饰的
//成员函数，称之为静态成员函数。静态的成员变量一定要在类外进行初始化

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	
		: _year(year)
			, _month(month)
			, _day(day)
		{}
	
	
	Date(const Date& d)

		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date& operator=(const Date& d)
	{
		if (&d != this)//不可以给自己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool LeapYear(int year)
	{//闰年 被400整除 或 被4不被100
		return ( year % 400 == 0 )||(year % 4 == 0 && year % 100);
	}
	int GetMonthDay(int year, int month)
	{//判断这个月有多少天  2月是28天（闰月29）； 4.6.9.11月30天； 1.3.5.7.8.10.12是31天。
		if (month == 2 && LeapYear(year))
			return 29;
		else if (month == 2)
			return 28;
		else{
			if ((month< 8 && month % 2) || (month>8 && month % 2 == 0))
				return 31;
			return 30;
		}
			
	}
	Date operator+(int days)
	{//进月   加上days天后是这个月的第几天？
		_day += days;  
		while (_day > GetMonthDay(_year,_month))//如果大于这个月的总天数
		{
			_day -= GetMonthDay(_year, _month);//减去上个月的天数
			_month += 1;//进月
			if (_month > 12)//进年
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator-(int days)
	{
		_day -= days;
		while (_day < 1)
		{
			--_month;//一定在该月之前
			if (_month < 1)//退年
				_year--;
			_month = 12 ;//假设变化天数days最多为28，即月份和年份起伏最大为1,
		}
		_day += GetMonthDay(_year, _month);
		return *this;
	}
	int operator-(const Date& d);//几天前
	{
		if (*this == d)
			return 0;
		Date max = *this;
		Date min = d;
		if (max < d){
			max = d;
			min = *this;		
		}
		int count = 0;
		while (min < max)
		{
			//min++;
			max--;
			count++;
		}
		return 0;		
	}

	Date& operator++()//前置
	{
		operator+(1);
		return *this;
	}		
	Date operator++(int)//后置
	{//0
		Date tmp = *this;
		operator +(1);
		return tmp;
	}

	Date operator--(int)
	{
		Date tmp = *this;
		operator -(1);
		return tmp;
	}
	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		if (_year < d._year)
			return false;
		//year=
		if (_month > d._month)
			return true;
		if (_month < d._month)
			return false;
		if (_day_ > d._day)
			return true;
		else
			return false;
	}

	bool operator>=(const Date& d)const
	{
		if (*this > d || *this == d)
			return ture;
	}

	bool operator<(const Date& d)const
	{
		if (*this >= d)
			return false;
		return true;
	}
	bool operator<=(const Date& d)const
	{
		if (*this > d)
			return false;
		return true;
	}
	bool operator==(const Date& d)const
	{
		return   !(*this > d && *this < d);
	}

	bool operator!=(const Date& d)const
	{
		return  !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};
