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
//			if (_ps == nullptr)
//			{
//				_ps = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _ps;
//	}
//	class GC{    //实现一个内嵌垃圾回收类
//	public:
//		~GC(){
//			if (Singleton::_ps)//无限递归，导致栈溢出
//				delete Singleton::_ps;
//			Singleton::_ps = nullptr;
//
//		}
//	};
//	static GC _gc;//定义一个静态程序变量，程序结束后，系统会自动调用它的析构函数从而释放单例对象
//	private://构造函数私有
//		Singleton(){};
//		Singleton(Singleton const&);////防拷贝
//		Singleton& operator=(Singleton const&);
//		static Singleton* _ps;//单例对象指针
//		static mutex _mtx;//互斥锁
//	};
//	Singleton* Singleton::_ps = nullptr;
//	Singleton::GC _gc;
//	mutex Singleton::_mtx;
//	void func(int n)
//	{
//		cout << Singleton::GetInstance() << endl;
//	}
//	// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
//	int main()
//	{j0
//		thread t1(func, 10);
//		thread t2(func, 10);
//		t1.join();
//		t2.join();
//		cout << Singleton::GetInstance() << endl;
//		cout << Singleton::GetInstance() << endl;
//		getchar();
//	}
//
void MemoryLeaks()
{
	//1.内存申请了没释放
	int* p1 = (int*)malloc(sizeof(int));
	int *p2 = new int;

	//2.异常安全问题
	int* p3 = new int[10];

	Func();//Func函数抛异常导致 delete[] p3来执行，p3没被释放
	delete[] p3;
}