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

// ֻ���ڶ��ϴ���������ࣺ
// 1. ���캯��˽�л�
// 2. �ṩ�����ӿڣ��ڶ��ϴ�������
// 3. �������޷��������󣬺������������ã������ӿڱ���Ϊstatic�ӿ�
// 4. ��ֹ������<1>��������˽�л���ֻ������ʵ�� 
//    <2>��������������delete����(C++11)

//
//class heap
//{
//public:
//	static Heap* getHeap()
//	{
//		return new Heap;
//	}
//private:
//	Heap(){}//C++98 ֻ��������ʵ��
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

// ֻ����ջ�ϴ�������
// new ---> operator new --> ����
// һ�� 
//	 1. ���캯��˽�л��������ֹnew�ؼ��ֵ�ִ���߼�
//   2. �ṩ�����ӿڣ���ջ�ϴ�������
//   3. �������޷��������󣬺������������ã������ӿڱ���Ϊstatic�ӿ� 
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
//// ����
////   1. ����operator new������������˽�еģ����Ҳ�ʵ��
////   2. ���캯������
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
//����ģʽ�� ȫ��ֻ��Ψһһ��
//1. ����
//: 1 �����Ƚ���
//  2 û�а취���ƶ������֮��ĳ�ʼ��˳��
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &_sin;
//	}
//private://���캯��˽��
//	Singleton(){}
//	//������ C++98
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
//private://���캯��˽��
//	Singleton(){}
//	//������
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
//		//Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
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
//	//ʵ��һ����Ƕ����������
//	class GC
//	{
//	public:
//		~GC(){
//		{
//			if (Singleton::_ps)//���޵ݹ飬����ջ���
//				delete Singleton::_ps;
//			Singleton::_ps = nullptr;
//		}
//	};
//	static GC _gc;//����һ����̬������������������ϵͳ���Զ������������������Ӷ��ͷŵ�������
//private:
//	Singleton(){};//���캯��˽��
//	Singleton(Singleton const &);
//	Singleton& operator=(Singleton const&)//������
//		static Singleton* _ps;//��������ָ��
//		static mutex _mtx;	  //������
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