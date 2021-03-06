#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
using namespace std; 
//名字修饰:编译器实际在底层使用的不是函数名字，而是被重新修饰过的一个比较复杂的名字，被重新修饰后的名字中包含了：函数的名字以及参数类型。
/*extern "C" int Add(int left, int right);
int main()
{
 Add(1,2);
 return 0;
}*///将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，将该函数按照C语言规则来编译。
//引用不是新定义一个变量，而是给已存在变量取了一个别名，编译器不会为引用变量开辟内存空间，它和它引用的变量共用同一块内存空间
//int main()
//{
//	int a = 10;
//	int& ra = a;//类型& 引用变量名(对象名) = 引用实体
//	printf("%p\n",&a);
//	printf("%p\n",&ra);//引用类型必须和引用实体是同种类型
//    return 0;//1. 引用在定义时必须初始化2. 一个变量可以有多个引用3. 引用一旦引用一个实体，再不能引用其他实体
//}
//常引用使用场景之做参数
//void Swap(oint & letf, int &right)
//{
//	int temp = left;
//	letf = right;
//	right = temp;
//}
//做返回值
//int& TestRefReturn(int& a)
//{
//	a += 10;
//  return a;
//}
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
{//函数返回时，离开函数作用域后，其栈上空间已经还给系统，因此不能用栈上的空间作为引用类型
//返回。如果以引用类型返回，返回值的生命周期必须不受函数的限制(即比函数生命周期长)。
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :"<< ret <<endl;
//	return 0;
//以值作为参数或者返回值类型，在传参和返回期间，函数不会直接传递实参或者将变量本身直接返回，而是传递实参或者返回变量的一份临时的拷贝，因此用值作为参数或者返回值类型，效率是非常低下的，尤其是当参数或者返回值类型非常大时，效率就更低。
//引用和指针的区别，语法上是一个别名，五独立空间，和其引用实体公用空间，底层实现由空间，因为是按指针方式实现。
//以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销，内联函数提升程序运行的效率。空间换时间，代码长循环递归不合适，最好声明定义在一起
//auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导而得。使用auto定义变量时必须对其进行初始化
int main()
{
	int x = 10;
	auto a = &x;//用auto声明指针类型时,用auto声明引用类型时则必须加&
	auto* b = &x；
	auto& c = x;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	*a = 20;
	*b = 30;
	c = 40;
	return 0;
}
//在同一行定义多个变量
void TestAuto()
{
    auto a = 1, b = 2; //类型必须相同
    auto c = 3, d = 4.0;  // 该行代码会编译失败，因为c和d的初始化表达式类型不同
}
//auto不能作为函数的参数
// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
void TestAuto(auto a)
{}
void TestAuto()//不能只能声明数组
{
    int a[] = {1,2,3};
    auto b[] = {4，5，6};
}
//for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量，第二部分则表示被迭代的范围。
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for(auto& e : array)     
		e *= 2;
	for(auto e : array)     
		cout << e << " ";return 0;
}//1. for循环迭代的范围必须是确定的 2.迭代的对象要实现++和==的操作
