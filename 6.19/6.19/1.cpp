#include <iostream>
using namespace std;
//int main()
//{   //日期计算OI  日期到天数的转换
//	int list[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int y, m, d;
//	while (cin >> y >> m >> d)
//	{
//		int a , days = 0;
//		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
//			a = 1;
//		else
//		    a = 0;
//		for (int i = 0; i < m - 1; i++)//如果是 5.3 m为5；加上1，2，3，4月的日期；i= 0，1，2，3
//			days += list[i];
//		if ((a == 1) && (m >= 2))
//			days++;
//		days += d;
//		cout << days << endl;
//	}
//	getchar();
//	return 0;
//}
//    求1+2+3+..+n，，，，
//  创建N个对象实现循环
//class Solution
//{
//public:
//Solution()
//	{
//	Sum += N;
//	--N;
//	}
//	int sum_Solution(int n)
//	{
//		N = 0;
//		Sum = 0;
//		Solution* a = new Solution[n];//n个对象
//		delete[]a;
//		a = nullptr;
//		return Sum;
//	}
//private:
//	static int N;
//	static int Sum;
//};
//int Solution::N = 0;
//int Solution::Sum = 0;
////利用逻辑运算符&&的截断性质来终止递归。
//class Solution{
//public:
//	int Sum_Solution(int n){
//		int ans = n;
//		ans && (ans += Sum_Solution(n - 1));
//		return ans;
//	}
//};
//设计一个类，只能在堆上创建对象
class HeapOnly
{
public:
	static HeapOnly* CreatObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() {}
	//只声明，不实现   声明成私有，防止被调用拷贝在栈上生成对象
	HeapOnly(const HeapOnly&);

	//or

	HeapOnly(const HeapOnly&) = delete;

};
//只能在栈上
class StackOnly
{
public:
	static StackOnly CreatObject()
	{
		return StackOnly;
	}
private:
	StackOnly()  {}
};
//即只需屏蔽掉new的功能，即屏蔽opreator new 与定位new表达式
class StackOnly
{
public:
	StackOnly() {}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

class Test
{
public:
	Test()
		: _data(0);
	{}
	~Test()
	{}
private:
	int _data;
};
void Test()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	new (pt)Test;
}