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
//////////	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
//////////	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
//////////	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
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
//////////	//"�����۵�"���ڱ����������﷨������ʱ�򣬽��������ʽ������ֵ��������õ�ֵ���滻���ʽ�����볣������������һ�ֱ����Ż���
//////////    volatile int a = 2;
//////////	int *p =(int *) &a;
//////////	*p = 3;
//////////	cout << a << endl;//2  a���޸��ˣ����������Ż����ڼĴ�����ȡֵ  
//////////	cout << *p << endl;//3
//////////	cout << &a << endl << p << endl;//0095F778  0095F778
//////////	getchar();
//////////	return 0;
//////////}
//////////int main()
//////////{
//////////	const int a = 2;
//////////	int *p = const_cast<int *>(&a);//����ǿת��const����ָ�붼���Ը�����const ����
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
//////////	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
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
////////	// key��value�����Ͷ������ַ���
////////	// C++11 ������ʼ��
//////	//map<string, string> m2{ 
//////	//{ "apple", "ƻ��" },
//////	//{ "banan", "�㽶" },
//////	//{ "orange", "����" },
//////	//{ "peach", "����" },
//////	//{ "waterme", "ˮ����" } };
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
//////		{ "apple", "ƻ��" },
//////		{ "banan", "�㽶" },
//////		{ "orange", "����" },
//////		{ "peach", "����" },
//////		{ "waterme", "ˮ����" } };
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
//////	// ����һ���յ�map����ʱm��һ��Ԫ�ض�û��
//////	map<string, string> m;
//////	m["apple"] = "ƻ��";
//////	cout << m["apple"] << endl;
//////	cout << m.size() << endl;
//////	// ��banan����map�У��ú������쳣�� 
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
////	// ��map�в���Ԫ�صķ�ʽ��
////	// ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ��
////	m.insert(pair<string, string>("peach", "����"));
////	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ��
////		m.insert(make_pair("banan", "�㽶"));
////	// ����operator[]��map�в���Ԫ��
////	m["apple"] = "ƻ��";
////	// key������ʱ���쳣
////	//m.at("waterme") = "ˮ����";
////	m.insert(m.find("banan"), make_pair("waterme", "ˮ����"));
////	cout << m.size() << endl;
////	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
////	for (auto& e : m)
////		cout << e.first << "--->" << e.second << endl;
////	cout << endl;
////	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
////	auto ret = m.insert(make_pair("peach", "��ɫ"));
////	if (ret.second)
////		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
////	else
////		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" <<
////		ret.first->second << " ����ʧ��" << endl;
////	// ɾ��keyΪ"apple"��Ԫ��
////	m.erase("apple");
////	for (auto& e : m)
////		cout << e.first << "--->" << e.second << endl;
////	if (1 == m.count("apple"))
////		cout << "apple����" << endl;
////	else
////		cout << "apple������" << endl;
////	getchar();
////	return 0;
////}
#include <map>
#include <string>
#include <iostream>
using namespace std;
void TestMultimap1()
{
	multimap<string, string> m; m.insert(make_pair("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("³��", "������"));
	// ���Բ���key��ͬ��Ԫ��
		m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;
	// keyΪ���ӵ�Ԫ���ж��ٸ�
	cout << m.count("����") << endl;
}
void TestMultimap2()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i) m.insert(pair<int, int>(i, i));
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// ����m�д��ڵ���5�ĵ�һ��Ԫ��
	auto it = m.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;
	// ����m�д���5��Ԫ��
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
////	// ������array�е�Ԫ�ع���set
////	int array[] = { 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
////	set<int> s(array, array + sizeof(array) / sizeof(int));
////	cout << s.size() << endl;
////	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
////	for (auto& e : s)
////		cout << e << " ";
////	cout << endl;
////	// ʹ�õ����������ӡset�е�Ԫ��
////	for (auto it = s.rbegin(); it != s.rend(); ++it)
////		cout << *it << " ";
////	cout << endl;
////	// set��ֵΪ3��Ԫ�س����˼���
////	cout << s.count(3) << endl;
////	getchar();
////	return 0;
////}
//int main()
//{
//	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
//	// ע�⣺multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ��
//	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// ����multiset���Ƿ���Դ洢ֵ��ͬ��Ԫ��
//	s.insert(5);
//	cout << s.count(5) << endl;
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// ɾ������ֵΪ5��Ԫ��
//	s.erase(5);
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	getchar();
//	return 0;
//}
