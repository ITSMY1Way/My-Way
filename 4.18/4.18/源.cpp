#include <iostream>
#include <windows.h>
using namespace std;
//��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}
//��̬��Ա�����Ա�����ж����е�
//���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա
//class Person//���̳�
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}
//���̳У�һ������ֻ��һ��ֱ�Ӹ���ʱ������̳й�ϵΪ���̳�
//��̳У�һ������������������ֱ�Ӹ���ʱ������̳й�ϵΪ��̳�
//���Σ���ʯ���̳У����μ̳��Ƕ�̳е�һ���������������������Ͷ����Ե�����
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : virtual public Person
//{//����̳п��Խ�����μ̳еĶ����Ժ�������������⡣
//protected:
//	int _num; //ѧ��
//};
//class Teacher :virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "z1";
//	a.Teacher::_name = "y2";
//}
//����̳�ԭ��
//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
class Base1 {
public:
	int _b1;
};
class Base2 {
public:
	int _b2;
};
class Derive : public Base1, public Base2 {
public:
	int _d;
};
int main()
{
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	system("pause");
	return 0;
}
//���ɶ�̬����������:1. ���ú����Ķ��������ָ��������á� 2. �����õĺ����������麯������������麯������д
//�麯������������ĳ�Ա������ǰ���virtual�ؼ���
//�麯������д������������һ�����������ȫ��ͬ�麯�������Ǿͳ�������麯����д�˻�����麯������ȫ��ͬ��ָ��������������������ֵ����ͬ�������麯������дҲ�����麯���ĸ��ǡ�
class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);
	return 0;
}