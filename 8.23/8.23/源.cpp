//
//////class A1 {
//////public:
//////	void f1(){}
//////private:
//////	int _a;
//////};//4
//////// ���н��г�Ա����
//////class A2 {
//////public:
//////	void f2() {}
//////};//1
//////// ����ʲô��û��---����
//////class A3
//////{};//1
//////int main()
//////{
//////	cout << sizeof(A3) << endl;
//////	getchar();
//////	return 0;
//////}
////class A {
////public: 
////	A() { ++_scount; }
////		A(const A& t) { ++_scount; }
////		static int GetACount()
////		{ return _scount; 
////		}
////private:
////	static int _scount;
////};
////int A::_scount = 0;
////
////int main(){
////	cout << A::GetACount() << endl;
////	A a1, a2;
////	A a3(a1);
////	cout << A::GetACount() << endl;
////	getchar();
////}
////const������
////void PrinttVector(const vector<int>& v)
////{
////	vector<int>::const_iterator it = v.begin();
////	while (it != v.cend())
////	{
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main(){
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
//	v.erase(pos);
//	cout << *pos << endl; //�˴����·Ƿ�����
//	// ��posλ�ò������ݣ�����pos������ʧЧ��
//	// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
//	// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
//	pos = find(v.begin(), v.end(), 3);
//	v.insert(pos, 30);
//	cout << *pos << endl; //�˴����·Ƿ�����
//	return 0;
//}
//
//
//int main(){
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// ʵ��ɾ��v�е�����ż��
//	// ����ĳ����������������ż����erase����itʧЧ
//	// ��ʧЧ�ĵ���������++it���ᵼ�³������
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	return 0;
//}
////�Ľ�
//vector<int>::iterator it = v.begin();
//while (it != v.end())
//{
//	if (*it % 2 == 0)
//		it = v.erase(it);
//	else
//		++it;
//}
//return 0;
//
//
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // ����
	int _age = 18; // ����
};
class Student : public Person
{
protected:
	int _stuid; // ѧ��
};
class Teacher : public Person
{
protected:
	int _jobid; // ����
};
int main()
{
	Student s;
	Teacher t; s.Print();
	t.Print();
	getchar();
	return 0;
}


class G
{
public:
	int _g;
};

class A : public G
{
protected:
	int _a;
};

class B : public G
{
protected:
	int _b;
};

class C : public A, public B
{
protected:
	int _c;
};

void test(void)
{
	C c;
	c._g = 1;
}

