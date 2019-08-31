////////#include <iostream>
////////using namespace std;
//////////typedef void(*FUNC)();
//////////int DoSomething(int i)
//////////{
//////////	cout << "DoSomething" << endl;
//////////	return 0;
//////////}
//////////void Test()
//////////{
//////////	//
//////////	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
//////////	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
//////////	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
//////////	//
//////////	FUNC f = reinterpret_cast< FUNC>(DoSomething);
//////////	f();
//////////}
//////////int main()
//////////{
//////////	Test();
//////////	getchar();
//////////	return 0;
//////////}
////////
//////////int main()
//////////{
//////////	//"常量折叠"是在编译器进行语法分析的时候，将常量表达式计算求值，并用求得的值来替换表达式，放入常量表。可以算作一种编译优化。
//////////    volatile int a = 2;
//////////	int *p =(int *) &a;
//////////	*p = 3;
//////////	cout << a << endl;//2  a被修改了，但编译器优化，在寄存器中取值  
//////////	cout << *p << endl;//3
//////////	cout << &a << endl << p << endl;//0095F778  0095F778
//////////	getchar();
//////////	return 0;
//////////}
//////////int main()
//////////{
//////////	const int a = 2;
//////////	int *p = const_cast<int *>(&a);//不用强转，const类型指针都可以付给非const 类型
//////////	*p = 3;
//////////	cout << a << endl;//2 
//////////	cout << *p << endl;//3
//////////	getchar();
//////////	return 0;
//////////}
//////////class A
//////////{
//////////public:
//////////	virtual void f(){}
//////////};
//////////class B : public A
//////////{};
//////////void fun(A* pa)
//////////{
//////////	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//////////	B* pb1 = static_cast<B*>(pa);
//////////	B* pb2 = dynamic_cast<B*>(pa);
//////////	cout << "pb1:" << pb1 << endl;
//////////	cout << "pb2:" << pb2 << endl;
//////////}
//////////int main()
//////////{
//////////	A a; B b;
//////////	fun(&a);
//////////	fun(&b);
//////////	getchar();
//////////	return 0;
//////////}
////////#include <iostream>
////////#include <map>
////////#include <string>
////////using namespace std;
////////void TestMap()
////////{
////////	// key和value的类型都给成字符串
////////	// C++11 的类表初始化
//////	//map<string, string> m2{ 
//////	//{ "apple", "苹果" },
//////	//{ "banan", "香蕉" },
//////	//{ "orange", "橘子" },
//////	//{ "peach", "桃子" },
//////	//{ "waterme", "水蜜桃" } };
////////	cout << m2["apple"] << endl;
////////	cout << m2["waterme"] << endl;
////////	map<string, string> m3(m2);
////////}
////////int main()
////////{
////////	TestMap();
////////	getchar();
////////	return 0;
////////}
//////#include <iostream>
//////#include <string>
//////#include <map>
//////using namespace std;
//////int main()
//////{
//////	map<string, string> m{
//////		{ "apple", "苹果" },
//////		{ "banan", "香蕉" },
//////		{ "orange", "橘子" },
//////		{ "peach", "桃子" },
//////		{ "waterme", "水蜜桃" } };
//////	for (auto it = m.begin(); it != m.end(); ++it)
//////		cout << (*it).first << "--->" << it->second << endl;
//////	cout << endl;
//////	getchar();
//////	return 0;
//////}
//////#include <string>
//////#include <map>
//////#include <iostream>
//////using namespace std;
//////void TestMap()
//////{
//////	// 构造一个空的map，此时m中一个元素都没有
//////	map<string, string> m;
//////	m["apple"] = "苹果";
//////	cout << m["apple"] << endl;
//////	cout << m.size() << endl;
//////	// “banan不在map中，该函数抛异常” 
//////	m.at("banan");
//////}
//////int main()
//////{
//////	TestMap();
//////	getchar();
//////	return 0;
//////}
////#include <string>
////#include <map>
////#include <iostream>
////using namespace std;
////int main()
////{
////	map<string, string> m;
////	// 向map中插入元素的方式：
////	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
////	m.insert(pair<string, string>("peach", "桃子"));
////	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
////		m.insert(make_pair("banan", "香蕉"));
////	// 借用operator[]向map中插入元素
////	m["apple"] = "苹果";
////	// key不存在时抛异常
////	//m.at("waterme") = "水蜜桃";
////	m.insert(m.find("banan"), make_pair("waterme", "水蜜桃"));
////	cout << m.size() << endl;
////	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
////	for (auto& e : m)
////		cout << e.first << "--->" << e.second << endl;
////	cout << endl;
////	// map中的键值对key一定是唯一的，如果key存在将插入失败
////	auto ret = m.insert(make_pair("peach", "桃色"));
////	if (ret.second)
////		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
////	else
////		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
////		ret.first->second << " 插入失败" << endl;
////	// 删除key为"apple"的元素
////	m.erase("apple");
////	for (auto& e : m)
////		cout << e.first << "--->" << e.second << endl;
////	if (1 == m.count("apple"))
////		cout << "apple还在" << endl;
////	else
////		cout << "apple被吃了" << endl;
////	getchar();
////	return 0;
////}
#include <map>
#include <string>
#include <iostream>
using namespace std;
void TestMultimap1()
{
	multimap<string, string> m; m.insert(make_pair("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("鲁达", "花和尚"));
	// 尝试插入key相同的元素
		m.insert(make_pair("李逵", "铁牛"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	// key为李逵的元素有多少个
	cout << m.count("李逵") << endl;
}
void TestMultimap2()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i) m.insert(pair<int, int>(i, i));
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// 返回m中大于等于5的第一个元素
	auto it = m.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;
	// 返回m中大于5的元素
	it = m.upper_bound(5);
	cout << it->first << "--->" << it->second << endl;
}
int main()
{
	TestMultimap1();
	TestMultimap2();
	getchar();
	return 0;
}
//#include <map>
//#include <string>
//#include <iostream>
//using namespace std;
////int main()
////{
////	// 用数组array中的元素构造set
////	int array[] = { 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
////	set<int> s(array, array + sizeof(array) / sizeof(int));
////	cout << s.size() << endl;
////	// 正向打印set中的元素，从打印结果中可以看出：set可去重
////	for (auto& e : s)
////		cout << e << " ";
////	cout << endl;
////	// 使用迭代器逆向打印set中的元素
////	for (auto it = s.rbegin(); it != s.rend(); ++it)
////		cout << *it << " ";
////	cout << endl;
////	// set中值为3的元素出现了几次
////	cout << s.count(3) << endl;
////	getchar();
////	return 0;
////}
//int main()
//{
//	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
//	// 注意：multiset在底层实际存储的是<int, int>的键值对
//	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// 测试multiset中是否可以存储值相同的元素
//	s.insert(5);
//	cout << s.count(5) << endl;
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// 删除所有值为5的元素
//	s.erase(5);
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	getchar();
//	return 0;
//}
