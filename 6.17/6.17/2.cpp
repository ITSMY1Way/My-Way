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
// ��̬��Ա����û�����ص�thisָ��
//��Ԫ�ṩ��һ��ͻ�Ʒ�װ�ķ�ʽ����ʱ�ṩ�˱�����������Ԫ��������϶ȣ��ƻ��˷�װ��������Ԫ���˶�
//�á���Ԫ������г�Ա��������������һ�������Ԫ�����������Է�����һ�����еķǹ��г�Ա��
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
//����Ϊstatic�����Ա��Ϊ��ľ�̬��Ա����static���εĳ�Ա��������֮Ϊ��̬��Ա��������static���ε�
//��Ա��������֮Ϊ��̬��Ա��������̬�ĳ�Ա����һ��Ҫ��������г�ʼ��

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
		if (&d != this)//�����Ը��Լ���ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool LeapYear(int year)
	{//���� ��400���� �� ��4����100
		return ( year % 400 == 0 )||(year % 4 == 0 && year % 100);
	}
	int GetMonthDay(int year, int month)
	{//�ж�������ж�����  2����28�죨����29���� 4.6.9.11��30�죻 1.3.5.7.8.10.12��31�졣
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
	{//����   ����days���������µĵڼ��죿
		_day += days;  
		while (_day > GetMonthDay(_year,_month))//�����������µ�������
		{
			_day -= GetMonthDay(_year, _month);//��ȥ�ϸ��µ�����
			_month += 1;//����
			if (_month > 12)//����
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
			--_month;//һ���ڸ���֮ǰ
			if (_month < 1)//����
				_year--;
			_month = 12 ;//����仯����days���Ϊ28�����·ݺ����������Ϊ1,
		}
		_day += GetMonthDay(_year, _month);
		return *this;
	}
	int operator-(const Date& d);//����ǰ
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

	Date& operator++()//ǰ��
	{
		operator+(1);
		return *this;
	}		
	Date operator++(int)//����
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
