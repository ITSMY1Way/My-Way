#include <iostream>
#include <windows.h>
using namespace std;
//�������
//explicit�ؼ��� �����ʼ�����󣬶��ڵ��������Ĺ��캯��������������ת��������
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
//}��
//void TestDate()
//{
//	Date d1(2018);
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
//	d1 = 2019;
//}//�ɶ��Բ��Ǻܺã���explicit���ι��캯���������ֹ���ι��캯������ʽת����
////static��Ա ����Ϊstatic�����Ա��Ϊ��ľ�̬��Ա����static���εĳ�Ա��������֮Ϊ��̬��Ա��������static���εĳ�Ա��������֮Ϊ��̬��Ա��������̬�ĳ�Ա����һ��Ҫ��������г�ʼ��
////Ϊ�����๲�� ��̬��Ա�������������ⶨ�壬����ʱ����static�ؼ��� û�����ص�thisָ�� 
////C++11֧�ַǾ�̬��Ա����������ʱ��ֱ�ӳ�ʼ��
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
//	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ֱ�ӳ�ʼ����
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
////��Ԫ ��Ϊ��Ԫ��������Ԫ��  ͻ�Ʒ�װ��������������϶ȣ��ƻ��˷�װ
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
//��Ԫ��������ֱ�ӷ������˽�г�Ա�����Ƕ��������ⲿ����ͨ�������������κ��࣬����Ҫ������ڲ�����������ʱ��Ҫ��friend�ؼ��֡�
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