#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<iostream>
//�����ռ�
//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left+right;
//	}
//}
//����ʹ�÷�ʽ �������ռ����Ƽ��������޶���
//int main()
//{
//	printf("%d\n", N::a);
//    return 0;
//}
//using�������ռ��г�Ա����
//using N::b;
//int main()
//{
//	printf("%d\n",N::a);
//	printf("%d\n",b);
//	return 0;
//}
//ʹ��using namespace �����ռ�����
//using namespce N;
//int main()
//{
//	printf("%d\n", N::a)
//	printf("%d\n", b);
//	Add(10, 20);
//	return 0;
//}
// C++���� ����ͷ�ļ�<iostream>��std��׼�����ռ�
//using namespace std;
//int main����
//{
//	cout<<"Hello C++!!"<<end1;
//	return 0;
//}
using namespace std;//���� cin>>
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
//ȱʡ���� �������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ,����ָ��ʵ�ξ��ô�ֵ
void TestFunc(int a = 0)
{
	cout<<a<<end1;
}
int main()
{
	TestFunc();//�޴��Σ�ʹ��0
	TestFunc(10);//���Σ���ָ����10
}
//����֮ȫȱʡ���� ����ÿһ������������ȱʡֵ
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
}
//��ȱʡ һ���ִ��� ��������������θ������ܼ���Ÿ�
void TestFunc(int a, int b = 10, int c = 20)
{
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
}
//ȱʡ���������ں��������Ͷ�����ͬʱ���֣�����������У�ȱʡֵ�����ǳ�������ȫ�ֱ���
//�������� C++������ͬһ�����������������������Ƶ�ͬ�����������ǵ��β��б�(�������� �� ���� �� ˳��)���벻ͬ
