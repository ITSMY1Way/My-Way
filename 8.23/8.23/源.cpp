//
//////class A1 {
//////public:
//////	void f1(){}
//////private:
//////	int _a;
//////};//4
//////// 类中仅有成员函数
//////class A2 {
//////public:
//////	void f2() {}
//////};//1
//////// 类中什么都没有---空类
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
////const迭代器
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
//	// 使用find查找3所在位置的iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// 删除pos位置的数据，导致pos迭代器失效。
//	v.erase(pos);
//	cout << *pos << endl; //此处导致非法访问
//	// 在pos位置插入数据，导致pos迭代器失效。
//	// insert会导致迭代器失效，是因为insert可
//	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
//	pos = find(v.begin(), v.end(), 3);
//	v.insert(pos, 30);
//	cout << *pos << endl; //此处导致非法访问
//	return 0;
//}
//
//
//int main(){
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// 实现删除v中的所有偶数
//	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
//	// 对失效的迭代器进行++it，会导致程序崩溃
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	return 0;
//}
////改进
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
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};
class Student : public Person
{
protected:
	int _stuid; // 学号
};
class Teacher : public Person
{
protected:
	int _jobid; // 工号
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

