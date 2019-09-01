//#include <iostream>
//using namespace std;
//////class person
//////{
//////public:
//////	virtual void buy()
//////	{
//////		cout << "a" << endl;
//////	}
//////};
//////class student : public person
//////{
//////public:
//////	virtual void buy()
//////	{
//////		cout << "b" << endl;
//////	}
//////};
//////void fun(person & obj)//调用函数的形参必须是基类对象
//////{
//////	obj.buy();
//////}
//////int main()
//////{
//////	person a;
//////	student b;
//////	fun(a);
//////	fun(b);
//////	getchar();
//////	return 0;
//////}
//////class Person {
//////public:
//////	virtual ~Person() { cout << "~Person()" << endl; }
//////};
//////class Student : public Person {
//////public:
//////	virtual ~Student() { cout << "~Student()" << endl; }
//////};
//////int main()
//////{
//////	Person* p1 = new Person;
//////	Person* p2 = new Student;
//////	delete p1;
//////	delete p2;
//////	return 0;
//////}
//////class A {
//////public:
//////	A() { ++_scount; }
//////	A(const A& t) { ++_scount; }
//////	static int GetACount()
//////	{
//////		return _scount;
//////	}
//////private:
//////	static int _scount;
//////};
//////int A::_scount = 0;
//////
//////int main(){
//////	cout << A::GetACount() << endl;
//////	A a1, a2;
//////	A a3(a1);
//////	cout << A::GetACount() << endl;
//////	getchar();
//////}
////class Base
////{
////public:
////	virtual void Func1()
////	{
////		cout << "Base::Func1()" << endl;
////	}
////	virtual void Func2()
////	{
////		cout << "Base::Func2()" << endl;
////	}
////	void Func3()
////	{
////		cout << "Base::Func3()" << endl;
////	}
////private:
////	int _b = 1;
////};
////class Derive : public Base
////{
////public:
////	virtual void Func1()
////	{
////		cout << "Derive::Func1()" << endl;
////	}
////private:
////	int _d = 2;
////};
////int main()
////{
////	Base b;
////	Derive d;
////	getchar();
////	return 0;
////}
////class Base
////{
////public:
////	virtual void Fun1()
////	{
////		std::cout << "Base::Fun1()" << std::endl;
////	};
////	virtual void Fun2()
////	{
////		std::cout << "Base::Fun2()" << std::endl;
////	};
////};
////
////class Derive : public Base
////{
////public:
////	virtual void Fun2() override
////	{
////		std::cout << "Derive::Fun2()" << std::endl;
////	}
////	virtual void Fun3()
////	{
////		std::cout << "Derive::Fun3()" << std::endl;
////	}
////	virtual void Fun4()
////	{
////		std::cout << "Derive::Fun4()" << std::endl;
////	}
////};
////
////
////typedef void(*VFTPtr)();
////
////void Print(VFTPtr table[])
////{
////	std::cout << table << std::endl;
////	for (int i = 0; table[i] != nullptr; i++)
////	{
////		std::cout << table[i] << ":  ";
////		VFTPtr v = table[i];
////		v();
////	}
////}
////void Test(void)
////{
////	Base b;
////	Derive d;
////	//Derive2 d2;
////
////	std::cout << "Base的虚表:  ";
////	Print((VFTPtr*)(*(int*)&b));
////
////	std::cout << "Derive的虚表:  ";
////	Print((VFTPtr*)(*(int*)&d));
////}
////int main()
////{
////	Test();
////	getchar();
////	return 0;
////}
////template <typename T1>
////void swap(T1&x, T1& y)
////{
////	T1 tmp = x;
////	x = y;
////	y = tmp;
////}
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}
//	catch (...){
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//	getchar();
//}void Func()
{
	int *array = new int[10];

	try
	{
		int lhs, rhs;
		std::cin >> lhs >> rhs;
		Division(lhs, rhs);
	}
	catch (...)//...表示接收任何异常
	{
		std::cout << "delete[] array" << std::endl;
		delete[] array;
		throw;//重新抛出异常信息
	}

	std::cout << "delete[] array" << std::endl;
	delete[] array;
}

