#include<iostream>
#include<string>
using namespace std;
//���������Ա�ڱ���ԭ�������ԵĻ����Ͻ�����չ�����ӹ��ܣ����������µ��࣬�������ࡣ
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
//	string _name = "peter"; // ����
//private:
//	int _age = 18; // ����
//protected:
//	int _id;
//};
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//	//private ��������඼�����Է���
//	//protected �����޷����ʣ��������ڲ�����
//	//public�̳� ���ı������Ա������ķ���Ȩ��
//	//protected�̳� �����Ա�������е���ͷ���Ȩ�ޡ�
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
//	//��ʽ����ת�����������Ƶ����Ϳ��Ի��ำֵ��ͨ����ʽ����ת��
//	a = b;
//	int *pa = &a;
//	int c = 10;
//	//ǿ������ת��
//	pa = (int*)c;
//	person p;
//	Student s;
//	//��Ƭ:���������Ը����������
//	p = s;
//	//��������ܸ����������
//	s = pl;
//	Person* ptr = &s;
//	//ָ������;����ܿ����Ŀռ� char* 1���ֽڵ����� int* 4  doublue* 8
//	Person& ref = Stu;
//	//����Ҳ����ʵ�֣��ײ���һ��ָ��
//	Student* ptr2 = &p;
//	//�����ָ�벻�ܸ�������ָ�롣�����Ƿ��ģ������˷���Խ��
//	Student* = ��Student*�� ptr;
//	//����ָ���������
//}
//// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};

// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//public:
//	int _num = 999; // ѧ��
//}
//int main()
//{
//	Person p;
//
//	s1.Print();
//	return 0;
//};
//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
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
//����  //������ͬһ�������У���������ͬ��������ͬ
//�ض���  //�ض���/���أ����ຯ���͸��ຯ������ͬ
//����    // ����/��д
//��д
//����
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
	string _name; // ����
};


class Student : public Person
{
public:
	//���๹�캯���ȵ��ø��๹�캯������ִ�����๹�캯����
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{//������಻��ʾ���ø���Ŀ������죬����ø����Ĭ�Ϲ��캯��
		//   ��ʾ  ������
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
	int _num; //ѧ��
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