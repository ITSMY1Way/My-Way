#include <iostream>
using namespace std;
//int main()
//{   //���ڼ���OI  ���ڵ�������ת��
//	int list[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int y, m, d;
//	while (cin >> y >> m >> d)
//	{
//		int a , days = 0;
//		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
//			a = 1;
//		else
//		    a = 0;
//		for (int i = 0; i < m - 1; i++)//����� 5.3 mΪ5������1��2��3��4�µ����ڣ�i= 0��1��2��3
//			days += list[i];
//		if ((a == 1) && (m >= 2))
//			days++;
//		days += d;
//		cout << days << endl;
//	}
//	getchar();
//	return 0;
//}
//    ��1+2+3+..+n��������
//  ����N������ʵ��ѭ��
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
//		Solution* a = new Solution[n];//n������
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
////�����߼������&&�Ľض���������ֹ�ݹ顣
//class Solution{
//public:
//	int Sum_Solution(int n){
//		int ans = n;
//		ans && (ans += Sum_Solution(n - 1));
//		return ans;
//	}
//};
//���һ���ֻ࣬���ڶ��ϴ�������
class HeapOnly
{
public:
	static HeapOnly* CreatObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() {}
	//ֻ��������ʵ��   ������˽�У���ֹ�����ÿ�����ջ�����ɶ���
	HeapOnly(const HeapOnly&);

	//or

	HeapOnly(const HeapOnly&) = delete;

};
//ֻ����ջ��
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
//��ֻ�����ε�new�Ĺ��ܣ�������opreator new �붨λnew���ʽ
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