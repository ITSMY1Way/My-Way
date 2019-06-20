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
//void Test2()
//{
//	Test* p1 = (Test)*malloc(sizeof(Test));
//	free(p1);
//	Test* p2 = (Test)*malloc(sizeof(Test)* 10);
//	free(p2);
//}
//void Tesrt2()
//{
//	Test* p1 = new Test;
//	delete p1;
//	Test* p2 = new Test[10];
//	delete p2;
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
//              	A* pb = new A;
//	// delete会调用自定义类型的析构函数， free不会
//	// delete --> 析构 --> operator delete
//	                 delete pb;
//A*pb new A;
//delete pb;
//A*pc new A[10];
//delete [] pc;
//	A* pc = new A[10];
//	delete[] pc;
//  
//
//
//}
//void *__CRTDECL operator new(size_t n)
//int main()
//{
//	Date* operator&(Date& d)
//	{
//		return &d;
//	};
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


	// operator new : malloc + 异常


	
	return 0;

}



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









#include <iostream>
using namespace std;
//class A
//{
//	int _a;
//};
//int main()
//{
//	A* pa = new A;
//	delete pa;
//	return 0;
//}

// 只能在堆上创建对象的类：
// 1. 构造函数私有化
// 2. 提供公共接口：在堆上创建对象
// 3. 在类外无法创建对象，函数用类名调用，公共接口必须为static接口
// 4. 防止拷贝：<1>拷贝构造私有化，只声明不实现 
//    <2>拷贝构造声明成delete函数(C++11)

//class Heap
//{
//	friend void fun1();
//public:
//	static Heap* getHeap()
//	{
//		return new Heap;
//	}
//
//	Heap(const Heap& hp) = delete;
//private:
//	Heap(){}
//};
//
//
//
//Heap::Heap(const Heap& hp)
//{}


//void fun1()
//{
//	Heap* hp = Heap::getHeap();
//	Heap hp2(*hp);
//}
//int main()
//{
//	/*Heap* hp = new Heap;
//	Heap hhp;
//	hp->getHeap();
//	hhp.getHeap();*/
//	Heap* hp = Heap::getHeap();
//	Heap hp2(*hp);
//	return 0;
//}

// 只能在栈上创建对象
// new ---> operator new --> 构造
// 一： 
//	 1. 构造函数私有化，间接阻止new关键字的执行逻辑
//   2. 提供公共接口：在栈上创建对象
//   3. 在类外无法创建对象，函数用类名调用，公共接口必须为static接口 

//class Stack
//{
//public:
//	static Stack getStack()
//	{
//		return Stack();
//	}
//private:
//	Stack()
//	{}
//};
//// 二：
////   1. 重载operator new函数，声明成私有的，并且不实现
////   2. 构造函数公有
//class Stack2
//{
//public:
//	// new --> operator new
//	void* operator new(size_t n) = delete;
//private:
//	//void* operator new(size_t n);
//	
//};
//
//int main()
//{
//	Stack s = Stack::getStack();
//	Stack cp(s);
//	//Stack2 ps = new Stack2;
//	return 0;
//}

//单例模式： 全局只有唯一一份
//1. 饿汉
//: 1 启动比较慢
//  2 没有办法控制多个单例之间的初始化顺序
//class Singleton
//{
//public:
//	static Singleton* getInstance()
//	{
//		return &_sin;
//	}
//
//private:
//	Singleton(){}
//	//防拷贝
//	//Singleton(const Singleton& s);
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s);
//	
//	static Singleton _sin;
//};
//
//Singleton Singleton::_sin;
//
//
//int main()
//{
//	Singleton* ps = Singleton::getInstance();
//	//Singleton s(*ps);
//	Singleton* ps2 = Singleton::getInstance();
//	
//	return 0;
//}
#include <thread> 
#include <mutex>
class Singleton
{
public:
	static Singleton* getInstance()
	{
		// double check
		if (_ps == nullptr)
		{
			_mtx.lock();
			if (_ps == nullptr)
			{
				_ps = new Singleton;
			}
			_mtx.unlock();
		}

		return _ps;
	}

	//~Singleton()
	//{
	//	if (_ps)
	//	{
	//		//无限递归，导致栈溢出
	//		delete _ps;
	//		_ps = nullptr;
	//	}
	//}

	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}

	class GC
	{
	public:
		~GC()
		{
			if (_ps)
			{
				delete _ps;
				_ps = nullptr;
			}
		}
	};
private:
	Singleton(){
		for (int i = 0; i < 10000000; i++)
		{
			int b = i;
		}
	}
	Singleton(const Singleton& s);
	static Singleton* _ps;
	static mutex _mtx;
	static GC _gc;
};

Singleton* Singleton::_ps = nullptr;
mutex Singleton::_mtx;
Singleton::GC Singleton::_gc;


void fun()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
}

void testSing()
{
	cout << Singleton::getInstance() << endl;
}
//int main()
//{
//	/*Singleton* ps = Singleton::getInstance();
//	Singleton* ps2 = Singleton::getInstance();
//	int i = 0;
//	i++;*/
//	/*fun();
//	fun();*/
//	/*thread t1(fun);
//	thread t2(fun);*/
//	/*testSing();
//	testSing();*/
//
//	thread t1(testSing);
//	thread t2(testSing);
//
//	t1.join();
//	t2.join();
//	return 0;
//}

int main()
{
	Singleton* ps = Singleton::getInstance();
	//delete ps;
	return 0;
}