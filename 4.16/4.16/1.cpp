#include <iostream>
#include <windows.h>
using namespace std;
//���������
// ȫ�ֵ�operator==
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
//	// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
//��ֵ��������� �������� ����ֵ ����Ƿ���ֽڸ�ֵ ����*this
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
//const��Ա ��const���ε����Ա������֮Ϊconst��Ա������const�������Ա������ʵ�����θó�Ա����������thisָ�룬�����ڸó�Ա�����в��ܶ�����κγ�Ա�����޸�
//��const�����ǿ��Ե���c��Ա�����ģ���СȨ��ԭ�� c����ֻ�ܵ���c��Ա���������ܵ��÷�c��Ա����
//ȡ��ַ��constȡ��ַ����������
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
}; //������Ĭ�ϳ�Ա����һ�㲻�����¶��� ��������Ĭ�ϻ�����