#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<iostream>
//命名空间
//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left+right;
//	}
//}
//三种使用方式 加命名空间名称及作用域限定符
//int main()
//{
//	printf("%d\n", N::a);
//    return 0;
//}
//using将命名空间中成员引入
//using N::b;
//int main()
//{
//	printf("%d\n",N::a);
//	printf("%d\n",b);
//	return 0;
//}
//使用using namespace 命名空间名称
//using namespce N;
//int main()
//{
//	printf("%d\n", N::a)
//	printf("%d\n", b);
//	Add(10, 20);
//	return 0;
//}
// C++输入 包含头文件<iostream>和std标准命名空间
//using namespace std;
//int main（）
//{
//	cout<<"Hello C++!!"<<end1;
//	return 0;
//}
using namespace std;//输入 cin>>
int main()
{
	int a;
	double b;
	char c;
	cin>>a;
	cin>>b>>c;
	cout<<a<<endl;
	cout<<b<<" "<<c<<endl;
	return 0;
}
//缺省参数 声明或定义函数时为函数的参数指定一个默认值,若无指定实参就用此值
void TestFunc(int a = 0)
{
	cout<<a<<end1;
}
int main()
{
	TestFunc();//无传参，使用0
	TestFunc(10);//传参，用指定的10
}
//分类之全缺省参数 函数每一个参数都带有缺省值
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
}
//半缺省 一部分带有 必须从右往左依次给，不能间隔着给
void TestFunc(int a, int b = 10, int c = 20)
{
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
}
//缺省参数不能在函数声明和定义中同时出现，最好在声明中，缺省值必须是常量或者全局变量
//函数重载 C++允许在同一作用域中声明几个功能类似的同名函数，他们的形参列表(参数个数 或 类型 或 顺序)必须不同
