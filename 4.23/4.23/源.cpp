#include <iostream>
#include <windows.h>
using namespace std;
//【华为 OJ 】计算日期到天数的转换
//int main()
//{ 
//	int list[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    
//	int y, m, d;    
//	while (cin >> y >> m >> d)    
//	{ 
//		int  leap, sum = 0;    
//		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))        
//			leap = 1;    
//		else        
//			leap = 0;    
//		for (int i = 0; i < m - 1; i++)        
//			sum += list[i];    
//		if ((leap == 1) && (m > 2))
//			sum += 1;    
//		sum += d;    
//		cout << sum << endl; 
//	}    
//	return 0; 
//}
//c/c++内存管理
//内存分布
int globalVar = 1;//数据段 （全集变量、静态数据）
static int staticGlobalVar = 1;//数据段 （全集变量、静态数据）
void Test()
{
	static int staticVar = 1;//数据段 （全集变量、静态数据）
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof (int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
}
//realloc函数函数适用于修改一块原来已经分配好的内存，使用这个函数可以将这块内存扩大或者缩小
//new/delete动态管理对象。 new[]/delete[]动态管理对象数组。 
//栈又叫堆栈，非静态局部变量/函数参数/返回值等等，栈是向下增长的
//堆用于程序运行时动态内存分配，堆是可以上增长的
// malloc/free只是动态分配内存空间/释放空间。⽽new/delete除了分配空间还会调⽤构 造函数和析构函数进⾏初始化与清理（清理成员）
//malloc / free需要⼿动计算类型⼤⼩且返回值会void*，new / delete可⾃⼰计算类型的⼤ ⼩，返回对应类型的指针。
//int main()
//{
//	int* pi = (int*)malloc(sizeof(int)* 20);
//	char* pc = (char*)malloc(20);
//	char* ppc = (char*) realloc(pc, 40);
//	// new/delete单个    new []/ delete []
{
	int* ptr1 = new int;
int* ptr2 = new int(10);//一个大小为10
int* ptr3 = new int[3];//三个
delete ptr3;
delete ptr2;
delete[] ptr1;
}
//	return 0;
//}
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		//释放资源
//		//if(_pi)
//		// {free(_pi); 
//		// _pi = nullptr;
//		// }
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int* _pi;
//};

//int main()
//{
//	A* pa = (A*)malloc(sizeof(A));
//	free(pa);
//
//	// new会调用自定义类型构造函数， malloc不会
//	// new --> operator new ---> 构造
//	/*A* pb = new A;
//	// delete会调用自定义类型的析构函数， free不会
//	// delete --> 析构 --> operator delete
//	delete pb;*/
//
//	/*A* pc = new A[10];
//	delete[] pc;*/
//
//
//
//}

// void *__CRTDECL operator new(size_t n)
//int main()
//{
//	// Date* operator&(Date& d){return &d};
//	// &d;
//	/*int* p = (int*) operator new(sizeof(int));
//	operator delete(p);*/
//	//delete(p);
//	cout << "malloc: " << endl;
//	char* p = (char*)malloc(0x7fffffff);
//	cout << (void*)p << endl;
//
//	cout << "operator new: " << endl;
//	try
//	{
//		char* p = (char*) operator new(0x7fffffff);
//		cout << (void*)p << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//
//	// operator new : malloc + 异常
//
//
//	
//	return 0;
//
//}

//struct ListNode
//{
//	ListNode* _prev;
//	ListNode* _next;
//	int _data;
//
//	void* operator new(size_t n)
//	{
//		void* p = allocator<ListNode>().allocate(1);
//		cout << "mem pool allocate" << endl;
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "mem pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//
//		}
//		delete _head;
//		_head = nullptr;
//		
//	}
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	/*List* pl = new List[10];
//	delete[] pl;*/
//
//	List* pl = (List*)malloc(sizeof(List));
//	free(pl);
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date* pd = (Date*)malloc(sizeof(Date));
	Date* pd2 = (Date*)malloc(sizeof(Date));

	new(pd)Date;
	new(pd2)Date(1939, 2, 3);
}
