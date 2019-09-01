#include <iostream>
#include <windows.h>
using namespace std;
//友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
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
//静态成员是类成员，所有对象共有的
//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员
//class Person//单继承
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}
//单继承：一个子类只有一个直接父类时称这个继承关系为单继承
//多继承：一个子类有两个或以上直接父类时称这个继承关系为多继承
//菱形（钻石）继承：菱形继承是多继承的一种特殊情况，有数据冗余和二义性的问题
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{//虚拟继承可以解决菱形继承的二义性和数据冗余的问题。
//protected:
//	int _num; //学号
//};
//class Teacher :virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "z1";
//	a.Teacher::_name = "y2";
//}
//虚拟继承原理
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
//构成多态有两个条件:1. 调用函数的对象必须是指针或者引用。 2. 被调用的函数必须是虚函数，且完成了虚函数的重写
//虚函数：就是在类的成员函数的前面加virtual关键字
//虚函数的重写：派生类中有一个跟基类的完全相同虚函数，我们就称子类的虚函数重写了基类的虚函数，完全相同是指：函数名、参数、返回值都相同。另外虚函数的重写也叫作虚函数的覆盖。
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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