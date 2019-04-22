#include <iostream>
#include <windows.h>
using namespace std;
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//int main()
//{
//	system("pasue");
//	return 0;
//}
//方法一：利用递归以及&&的短路原理
//int Sum(int num, int& sum)
//{//递归，判断条件当 num为0时跳出递归
//	num&&Sum((num-1),sum);
//	return sum += num;
//}
//int main()
//{
//	int sum = 0;
//	int num = 0;
//	cin >> num;
//	cout << Sum(num,sum) << endl;
//	system("pause");
//	return 0;
//}
//class Sum
//{
//public:
//	Sum()
//	{
//		++n;
//		sum += n;
//	}
//	static void Reset()
//	{
//		n = 0; sum = 0;
//	}
//	static unsigned int GetSum()
//	{
//		return sum;
//	}
//private:
//	static unsigned int n;
//	static unsigned int sum;
//};
//unsigned int Sum::n = 0;
//unsigned int Sum::sum = 0;
//unsigned int Sum_Solution(unsigned int n)
//{
//	Sum::Reset();
//	Sum* a = new Sum[n];
//	//delete[]a;
//	//a = NULL;
//	return Sum::GetSum();
//}
//int main()
//{
//	int n = 3;
//	cout << Sum_Solution(n) << endl;
//	system("pause");
//	return 0;
//}
//析构函数的重写问题 基类的析构函数最好写成虚函数
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};
// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}//重定义包含重写，，，
//抽象类  在虚函数的后面写上 =0 ，则这个函数为纯虚函数。不完整的类，不能实例化出对象
//接口继承
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
	}
};
void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}
class Car{
public:
	virtual void Drive(){}
};
// 2.override 修饰派生类虚函数强制完成重写
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
};
// 1.final 修饰基类的虚函数不能被派生类重写
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-舒适" << endl; }
};
class Car{ public: virtual void Drive(){} };// 2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错
class Benz :public Car 
{
public: virtual void Drive() 
		override 
{
			cout << "Benz-舒适" << endl;
}
class Car{
public:
	virtual void Drive(){}
	;
	//2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错
		class Benz : public Car{
	public:
		virtual void Drive() override { cout << "Benz-舒适" << endl; }
	};