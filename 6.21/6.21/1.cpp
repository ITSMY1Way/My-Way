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

//
//class heap
//{
//public:
//	static Heap* getHeap()
//	{
//		return new Heap;
//	}
//private:
//	Heap(){}//C++98 只声明，不实现
//	//or
//	Heap(const Heap& hp) = delete;
//};

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
//		return Stack;
//	}
//private:
//	stack()
//	{}
//};
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
//or
//class Stack2{
//public:
//	void* operator new(size_t) = delete;
//private:
//	void* operator new(size_t n);
//
//
//};
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
//	static Singleton* GetInstance()
//	{
//		return &_sin;
//	}
//private://构造函数私有
//	Singleton(){}
//	//防拷贝 C++98
//	Singleton(const Singleton& s);
//	Singleton& operator =(const Singleton& s);
//	//or   C++11
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator = (const Singleton& s);
//};
//Singleton Singleton::_sin;
//class Singleton
//{
//public:
//	static Singleton* getInstance()
//	{
//		return &_sin;
//	}
//
//private://构造函数私有
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
////	
////	return 0;
////}
//#include <iostream>
//#include <thread> 
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance(){
//		//Double-Check的方式加锁，才能保证效率和线程安全
//		if (_ps == nullptr)
//		{
//			_mtx.lock();
//			if (_ps = nullptr)
//			{
//				_ps = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _ps;
//	}
//	//实现一个内嵌垃圾回收类
//	class GC
//	{
//	public:
//		~GC(){
//		{
//			if (Singleton::_ps)//无限递归，导致栈溢出
//				delete Singleton::_ps;
//			Singleton::_ps = nullptr;
//		}
//	};
//	static GC _gc;//定义一个静态程序变量，程序结束后，系统会自动调用它的析构函数从而释放单例对象
//private:
//	Singleton(){};//构造函数私有
//	Singleton(Singleton const &);
//	Singleton& operator=(Singleton const&)//防拷贝
//		static Singleton* _ps;//单例对象指针
//		static mutex _mtx;	  //互斥锁
//	};
//	Singleton* Singleton::_ps = nullptr;
//	Singleton::GC _gc;
//	mutex Singleton::_mtx;
////	
////	void fun()
////{
////	for (int i = 0; i < 10; i++)
////	{
////		cout << i << endl;
////	}
////}
////
////void testSing()
////{
////	cout << Singleton::getInstance() << endl;
////}
////int main()
////{
////	/*Singleton* ps = Singleton::getInstance();
////	Singleton* ps2 = Singleton::getInstance();
////	int i = 0;
////	i++;*/
////	/*fun();
////	fun();*/
////	/*thread t1(fun);
////	thread t2(fun);*/
////	/*testSing();
////	testSing();*/
////
////	thread t1(testSing);
////	thread t2(testSing);
////
////	t1.join();
////	t2.join();
////	return 0;
////}
////
////int main()
////{
////	Singleton* ps = Singleton::getInstance();
////	delete ps;
////	return 0;
////}