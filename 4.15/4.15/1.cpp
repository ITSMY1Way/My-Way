#include<iostream>
#include<string>
using namespace std;
//它允许程序员在保持原有类特性的基础上进行扩展，增加功能，这样产生新的类，称派生类。
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//public:
//	string _name = "peter"; // 姓名
//private:
//	int _age = 18; // 年龄
//protected:
//	int _id;
//};
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//	//private 类外和子类都不可以访问
//	//protected 类外无法访问，但子类内部可以
//	//public继承 不改变量类成员在子类的访问权限
//	//protected继承 是类成员在子类中的最低访问权限、
//};
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 1.5;
//	//隐式类型转换：类型相似的类型可以互相赋值，通过隐式类型转换
//	a = b;
//	int *pa = &a;
//	int c = 10;
//	//强制类型转换
//	pa = (int*)c;
//	person p;
//	Student s;
//	//切片:子类对象可以赋给父类对象
//	p = s;
//	//父类对象不能赋给子类对象；
//	s = pl;
//	Person* ptr = &s;
//	//指针的类型决定能看多大的空间 char* 1个字节的内容 int* 4  doublue* 8
//	Person& ref = Stu;
//	//引用也可以实现，底层是一个指针
//	Student* ptr2 = &p;
//	//父类的指针不能赋给子类指针。。。非法的，发生了访问越界
//	Student* = （Student*） ptr;
//	//还是指向子类对象
//}
//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//public:
//	int _num = 999; // 学号
//}
//int main()
//{
//	Person p;
//
//	s1.Print();
//	return 0;
//};
//// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
//// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//};
//重载  //函数在同一作用域中，函数名相同，参数相同
//重定义  //重定义/隐藏：子类函数和父类函数名相同
//覆盖    // 覆盖/重写
//重写
//隐藏
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};


class Student : public Person
{
public:
	//子类构造函数先调用父类构造函数，再执行子类构造函数，
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{//如果子类不显示调用父类的拷贝构造，则调用父类的默认构造函数
		//   显示  不调用
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
int main()
{
	Test();
	return 0;
}