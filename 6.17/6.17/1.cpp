#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
//typedef int DataType;
//class Seqlist//�������� ��
//{
//public:
//	Seqlist(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//����������ǰ_,�޷���ֵ������ʾ����ϵͳ��Ĭ������
//	~Seqlist()
//	{
//		if (_pData)
//		{
//			free(_pData); //�ͷŶ��ϵĿռ�
//			_pData = NULL; //��ָ����Ϊ��
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//�������� �ǹ��캯����һ��������ʽ ����ֻ��һ���ұ���ʹ�����ô���
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
//��δ��ʽ���壬ϵͳ����Ĭ�ϵĿ������캯����Ĭ�ϵĿ������캯�������ڴ洢�水�ֽ���ɿ���������ǳ����/ֵ����
//1.���������  Ϊ��ǿ����ɶ���   .*   ::   sizeof   ?:  .  ����������������
//��ȫ�ֺ�����
//bool operator==(Date* this, const Date& d2)  ���������thisָ��ĵ��ú����Ķ���
//bool operator==(const Date& d2)
//2.��ֵ���������   Date& operator=(const Date& d)
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
//const������Ե���������const���������ǲ���һһ��Ӧ�Ĺ�ϵ��
//const��Ա�����ڿ��Ե���������const��Ա����
//��const������Ե��÷�const��Ա������const��Ա����
//��const��Ա�����ڿ��Ե���������const��Ա�����ͷ�const��Ա����


