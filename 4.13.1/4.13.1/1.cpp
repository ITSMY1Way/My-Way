#include <iostream>
using namespace std;
//int main()
//{
//	int* pi = (int*)malloc(sizeof(int)* 20);
//	free(pi);
//
//	char* pc = (char*)malloc(20);
//	char* ppc = (char*) realloc(pc, 40);
//	//free(pc);
//	free(ppc);
//
//	// new/delete    new []/ delete []
//	int* pa = new int;
//	delete pa;
//
//	int* pb = new int(1);
//	delete pb;
//	int* pc = new int[10];
//	delete[] pc;
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