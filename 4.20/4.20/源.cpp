#include <iostream>
#include <windows.h>
using namespace std;
//������� �¡�
//���캯�� ��������ʱ�����������ù��캯�����������и���Ա����һ������ĳ�ʼֵ
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
//};//���캯�����е����ֻ�ܽ������Ϊ����ֵ�������ܳ�����ʼ������Ϊ��ʼ��ֻ�ܳ�ʼ��һ�Σ������캯�����ڿ��Զ�θ�ֵ
////��ʼ���б���ð�ſ�ʼ�������Զ��ŷָ������ݳ�Ա�б�ÿ��"��Ա����"�����һ�����������еĳ�ʼֵ����ʽ��
//class Date
//{//ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;//���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
//};//���ó�Ա���� const��Ա���� �����ͳ�Ա
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
//	A _aobj; // �����ͳ�Ա  û��Ĭ�Ϲ��캯�� 
//	int& _ref; // ���� 
//	const int _n; // const 
//};
class Time//�����Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ����
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
//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�˳���޹�
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
// explicit����ȷ�ģ�����ģ�ֱ�ʵģ������ģ��ؼ���

