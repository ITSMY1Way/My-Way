#include <iostream>
#include <windows.h>
using namespace std;
//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
//int main()
//{
//	system("pasue");
//	return 0;
//}
//����һ�����õݹ��Լ�&&�Ķ�·ԭ��
//int Sum(int num, int& sum)
//{//�ݹ飬�ж������� numΪ0ʱ�����ݹ�
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
//������������д���� ����������������д���麯��
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};
// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}//�ض��������д������
//������  ���麯���ĺ���д�� =0 �����������Ϊ���麯�������������࣬����ʵ����������
//�ӿڼ̳�
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
		cout << "Benz-����" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-�ٿ�" << endl;
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
// 2.override �����������麯��ǿ�������д
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-����" << endl; }
};
// 1.final ���λ�����麯�����ܱ���������д
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-����" << endl; }
};
class Car{ public: virtual void Drive(){} };// 2.override �����������麯��ǿ�������д�����û����д����뱨��
class Benz :public Car 
{
public: virtual void Drive() 
		override 
{
			cout << "Benz-����" << endl;
}
class Car{
public:
	virtual void Drive(){}
	;
	//2.override �����������麯��ǿ�������д�����û����д����뱨��
		class Benz : public Car{
	public:
		virtual void Drive() override { cout << "Benz-����" << endl; }
	};