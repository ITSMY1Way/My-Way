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
//			if (_ps == nullptr)
//			{
//				_ps = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _ps;
//	}
//	class GC{    //ʵ��һ����Ƕ����������
//	public:
//		~GC(){
//			if (Singleton::_ps)//���޵ݹ飬����ջ���
//				delete Singleton::_ps;
//			Singleton::_ps = nullptr;
//
//		}
//	};
//	static GC _gc;//����һ����̬������������������ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	private://���캯��˽��
//		Singleton(){};
//		Singleton(Singleton const&);////������
//		Singleton& operator=(Singleton const&);
//		static Singleton* _ps;//��������ָ��
//		static mutex _mtx;//������
//	};
//	Singleton* Singleton::_ps = nullptr;
//	Singleton::GC _gc;
//	mutex Singleton::_mtx;
//	void func(int n)
//	{
//		cout << Singleton::GetInstance() << endl;
//	}
//	// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
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
	//1.�ڴ�������û�ͷ�
	int* p1 = (int*)malloc(sizeof(int));
	int *p2 = new int;

	//2.�쳣��ȫ����
	int* p3 = new int[10];

	Func();//Func�������쳣���� delete[] p3��ִ�У�p3û���ͷ�
	delete[] p3;
}