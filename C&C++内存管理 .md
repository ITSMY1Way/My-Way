﻿## 1.C/C++内存分布

> 1. **栈又叫堆栈**，非静态局部变量/函数参数/返回值等等，栈是向下增长的。
> 2. **内存映射段**是高效的I/O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口创建共享共
>   享内存，做进程间通信。
> 3. **堆**用于程序运行时动态内存分配，堆是可以上增长的。
> 4. **数据段**--存储全局数据和静态数据。
> 5. **代码段**--可执行的代码/只读常量。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190621230827151.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxMTAyNDczNDU0Ng==,size_16,color_FFFFFF,t_70)
## 2.C语言中动态内存管理方式 

### **2.1内存分配方式：**

> 从静态存储区域分配：在程序编译的时候已分配，这块内存在整个运行期都存咋。例如：static变量，全局变量；
>
> 在栈上创建：  在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放.栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限；
>
> 从堆上分配/动态内存分配： 程序在运行的时候用malloc或new申请任意多少的内存，程序员自己负责在何时用free或delete释放内存.动态内存的生存期由用户决定，使用非常灵活，但问题也最多.

### 2. 2malloc/calloc/realloc和free

`void* malloc(unsigned size)`      

> 在内存的动态存储区中分配一块长度为size字节的连续区域，参数size为需要内存空间的长度，返回该区域的首地址.
>
> 分配的内存位于堆中，没有初始化内存的内容，一般上调用memset函数来初始化这部分的内存空间
>
> - 如果开辟成功，则返回一个指向开辟好空间的指针。 
> - 如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。 
> - 返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定。 
> - 如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。

`void free (void* ptr);` 

> free函数用来释放动态开辟的内存。 
>
> - 如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。 
> - 如果参数 ptr 是NULL指针，则函数什么事都不做。 

```c
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int *ptr = (int *)malloc(n * sizeof(int));

	if (!ptr)
	{
		printf("Can't get memory.");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	for (; i < n; i++)
	{
		ptr[i] = 0;
	}
	free(ptr);
	ptr = NULL;//这一步是否重要？？？
//非常重要，在free之后，指针内容是不变的，但是此时指针已无法访问堆空间。这样的后果就是会造成野指针。
	system("pause");
	return 0;
}
```

`void calloc (size_t num, size_t size);`

> - 函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。 
> - 与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0。 
>
> 如果我们需要对开辟的内存进行初始化，可以使用`calloc`函数。
>
> 与malloc相似,参数size为申请地址的单位元素长度,num为元素个数，即在内存中申请num*size字节大小的连续地址空间.
>
> 他们都在stdlib.h函数库内，它们的返回值都是请求系统分配的地址,如果请求失败就返回NULL.

 `void* realloc(void* ptr, unsigned newsize)` 

> 给一个已经分配了地址的指针重新分配空间,参数ptr为原有的空间地址,newsize是重新申请的地址长度.     

> - realloc函数的出现让动态内存管理更加灵活。 它可以做到对动态开辟内存大小的调整。 
>
> - ptr是要调整的内存地址。
>
> - size是调整之后的大小。
>
> - 返回值为调整之后的内存起始位置。
>
> - 这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到新的空间。对malloc申请的内存的大小进行调整
>
>   > - 情况1：原有空间之后有足够大的空间，那么此时扩大空间或缩小空间之后，返回的地址都不会改变。
>   > - 情况2： 原有空间之后没有足够大的空间用来调整新的需求，所以该函数会将这个所有的数据复制到一个新的足够大能满足新的需求的空间，并返回新的地址。

```c
int *ptr = (int *)malloc(100);
	if (!ptr)
	{
		printf("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	//情况一
	ptr = realloc(ptr, 1000);
	if (!ptr)
	{
		printf("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	free(ptr);
	ptr = NULL;
//  情况二是一种安全的行为，因为，如果realloc申请内存失败，则情况一会将原内存的内容都丢失。
	int *p = realloc(ptr, 1000);
	if (!p)
	{
		printf("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	ptr = p;
	free(ptr);
	ptr = NULL;
```

### 柔性数组

> **C99中，结构中最后一个元素允许是位置大小的数组，这就叫做柔性数组**成员。
>
> ```c
> struct st_type
> {
>      int i;
>      int a[0];//柔性数组成员
> 或者  int a[]
> }type_a;
> ```
>
> - 结构中的柔性数组成员前面必须至少一个其他成员。
> - `sizeof`返回的这种结构体大小不包括柔性数组的内存。
> - 包含柔性数组成员的结构体用`malloc`函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。
> - 不管柔性数组有无元素，柔性数组的大小都不算进结构体大小。
>
> ```c
> 	//使用
>     int i = 0;
> 	struct FleArr *p = (struct FleArr*)malloc(sizeof(struct FleArr), 100 \
> 	* sizeof(char));
> 	if (!p)
> 	{
> 		exit(EXIT_FAILURE);
> 	}
> 	p->i = 100;
> 	for (i = 0; i < 100; i++)
> 	{
> 		p->a[i] = 'a';
> 	}
> 	free(p);
> 	p = NULL;
>     //在开辟空间的时候，就相当于先创建一个结构体大小的空间，在给柔性数组成员a创建了一个100个字符型元       素的连续空间。
> ```
>
> ```c
> 	typedef struct st_type
> 	{
>  		int i;
>  		int *p_a;
> 	}type_a;
> 	
> 	type_a *p = malloc(sizeof(type_a));
> 	p->i = 100;
> 	p->p_a = (int *)malloc(p->i*sizeof(int));
> 	
> 	for(i=0; i<100; i++)
> 	{
> 	 p->p_a[i] = i;
> 	}
> 	//释放空间
> 	free(p->p_a);
> 	p->p_a = NULL;
> 	free(p);
> 	p = NULL;
> //如果不采用柔性数组的形式，我们需要在一个结构体内创建一个变长的数组，就需要再次动态分配内存，这样就需要动态分配两次内存，再释放的时候也需要释放两次。
> //柔性数组的优势有两点：方便内存的释放，有利于访问速度。
> //            连续的内存有益于提高访问速度，也有益于减少内存碎片
> ```

#### 2.3区别

>  **(1)**函数malloc不能初始化所分配的内存空间,而函数calloc能.如果由malloc()函数分配的内存空间原来没有被使用过，则其中的每一位可能都是0;反之, 如果这部分内存曾经被分配过,则其中可能遗留有各种各样的数据.也就是说，使用malloc()函数的程序开始时(内存空间还没有被重新分配)能正常进行,但经过一段时间(内存空间还已经被重新分配)可能会出现问题.     
>
> **(2)**函数calloc() 会将所分配的内存空间中的每一位都初始化为零,也就是说,如果你是为字符类型或整数类型的元素分配内存,那么这些元素将保证会被初始化为0;如果你是为指针类型的元素分配内存,那么这些元素通常会被初始化为空指针;如果你为实型数据分配内存,则这些元素会被初始化为浮点型的零.     **(3)**函数malloc向系统申请分配指定size个字节的内存空间.返回类型是 void*类型.void*表示未确定类型的指针.C,C++规定，void* 类型可以强制转换为任何其它类型的指针.  
>
> **(4)**realloc可以对给定的指针所指的空间进行扩大或者缩小，无论是扩张或是缩小，原有内存的中内容将保持不变.当然，对于缩小，则被缩小的那一部分的内容会丢失.realloc并不保证调整后的内存空间和原来的内存空间保持同一内存地址.相反，realloc返回的指针很可能指向一个新的地址.    
>
>  **(5)**realloc是从堆上分配内存的.当扩大一块内存空间时，realloc()试图直接从堆上现存的数据后面的那些字节中获得附加的字节，如果能够满足，自然天下太平；如果数据后面的字节不够，问题就出来了，那么就使用堆上第一个有足够大小的自由块，现存的数据然后就被拷贝至新的位置，而老块则放回到堆上.这句话传递的一个重要的信息就是数据可能被移动.

## 3.C++内存管理方式	

>  C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力且麻烦，因此C++又提出了自己的内存管理方式：通过new和delete操作符进行动态内存管理
>
>  **注意：C语言的malloc之类的都是函数**，可是C++的new/delete都是**操作符**。

####  3.1new和delete操作自定义类型

```c++
void Test()
{
 // 申请单个Test类型的空间
 Test* p1 = (Test*)malloc(sizeof(Test));
 free(p1); 
 // 申请10个Test类型的空间
 Test* p2 = (Test*)malloc(sizoef(Test) * 10);
 free(p2);
}
void Test2()
{
 // 申请单个Test类型的对象
 Test* p1 = new Test;               //申请和释放单个元素的空间，使用new和delete操作符；
 delete p1;
 // 申请10个Test类型的对象
 Test* p2 = new Test[10];           //申请和释放连续的空间，使用new[]和delete[]。
 delete[] p2;
}//在申请自定义类型的空间时，new会调用自定义类型的构造函数，new --> operator new ---> 构造，malloc不会delete会调用自定义类型的析构函数，delete --> 析构 --> operator delete，free不会
```


![在这里插入图片描述](https://img-blog.csdnimg.cn/2019062123091325.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxMTAyNDczNDU0Ng==,size_16,color_FFFFFF,t_70)
#### 3.2operator new与operator delete函数

> new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是系统提供的
> 全局函数，new在底层调用operator new全局函数来申请空间，delete在底层通过operator delete全局
> 函数来释放空间.

> operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常.
>
> operator new 实际也是通过malloc来申请空间，如果malloc申请空间成功就直接返回，否则执行用户提供的空间不足应对措施，如果用户提供该措施就继续申请，否则就抛异常。
>
> **operator delete 最终是通过free来释放空间的。**

## 4.new和delete的实现原理

#### 内置类型

> 如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是：new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申请空间失败时会抛异常，malloc会返回NULL。

#### 自定义类型

- **new的原理**

> 1.调用operator new函数申请空间
>
> 2.在申请的空间上执行构造函数，完成对象的构造

- **delete的原理**

> 1.在空间上执行析构函数，完成对象中资源的清理工作
>
> 2.调用operator delete函数释放对象的空间

- **new T[N]的原理**

> 1.调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
>
> 2.在申请的空间上执行N次构造函数

- **delete[]的原理**

> 1.在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理
>
> 2.调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间

## 5. malloc/free和new/delete的区别

> malloc/free和new/delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。不同的地方是：
>
> 1. malloc和free是函数，new和delete是操作符
> 2. malloc申请的空间不会初始化，new可以初始化
> 3. malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可
> 4. malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
> 5. malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常
> 6. 申请自定义类型对象时，malloc/free只会开辟空间，不会调用构造函数与析构函数，而new在申请空间
>   后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成空间中资源的清理
> 7. new/delete比malloc和free的效率稍微低点，因为new/delete的底层封装了malloc/free

## 6.定位new表达式

> **是在已分配的原始内存空间种调用构造函数初始化一个对象**
>
> 使用：
>
> **new (place_address) type或者new (place_address) type(initializer-list)** 
>
> **place_address必须是一个指针，initializer-list是类型的初始化列表**
>
> 场景：一般配合内存池，因为内存池分配的内存没有初始化，若是自定义类型的对象，需要new定义表达式进行显示构造函数进行初始化

```c++
class Test
{
public:
 Test()
 : _data(0)
 {
 cout<<"Test():"<<this<<endl;
 }
 ~Test()
 {
 cout<<"~Test():"<<this<<endl;
 } 
private:
 int _data;
};
void Test()
{
 // pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
 Test* pt = (Test*)malloc(sizeof(Test));
 new(pt) Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
 }
```

## 7.单例模式

> 一个类只能创建一个对象，即单例模式，
>
> 该模式可以保证系统中该类只有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。比如在某个服务器程序中，该服务器的配置信息存放在一个文件中，这些配置数据由一个单例对象统一读取，然后服务进程中的其他对象再通过这个单例对象获取这些配置信息，这种方式简化了在复杂环境下的配置管理
>
> 两种实现模式：

- **饿汉模式  **不管你将来用不用，程序启动时就创建一个唯一的实例对象。 

```c++
//1.饿汉模式
//优点：简单
//缺点：启动比较慢；没有办法控制多个单例之间的初始化顺序
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &_sin;
	}
private://构造函数私有
	Singleton(){};
	//防拷贝 C++98
	Singleton(const Singleton& s);
	//or   C++11
	Singleton(const Singleton& s) = delete;
	Singleton& operator = (const Singleton& s);
};
Singleton Singleton::_sin;   //在程序入口之间就完成单例对象的初始化
//如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，那么显然使用饿汉模式来避免资源竞争，提高响应速度更好。
```

> 1.我们将对象声明为静态变量，这样就可以延长它的生命周期，并且，因为它的类型是这个类，所以声明为静态变量不算进类的大小里，不然类还没定义完，怎么计算大小。
> 2.因为，这个变量只能定义一次，也就是说整个程序里就只能有一个变量对象。所以我们要把这个类的默认构造函数放进私有域里，这样就不能再定义其他对象了。我个人觉得，copy 构造也有必要放进私有域，copy assignment（赋值运算符重载）没必要放进私有域。因为copy 构造也是在创建类的对象的时候调用，copy 构造也可以使用初始化列表来初始化对象。而copy assignment 就没必要，因为只有已有对象才可以调用它，无法创建新的对象就没办法调用它，所以可以不把它放进私有域，但是为了统一还是放吧。
> 3.在共有域里，定义了一个静态函数，用来返回这个静态成员的地址。这个时候就可以保证，在没有对象的时候可以通过类名去调用这个函数获取静态成员的地址。

- **懒汉模式**

```c++
//2.懒汉模式
//缺点：设计复杂
//优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
//如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等等，而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化，就会导致程序启动时非常的缓慢。 所以这种情况使用懒汉模式（延迟加载）更好
#include <iostream>
#include <thread> 
#include <mutex>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance(){
		//Double-Check的方式加锁，才能保证效率和线程安全
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
	class GC{    //实现一个内嵌垃圾回收类
	public:
		~GC(){
			if (Singleton::_ps)//无限递归，导致栈溢出
				delete Singleton::_ps;
			Singleton::_ps = nullptr;
		}
	};
	static GC _gc;//定义一个静态程序变量，程序结束后，系统会自动调用它的析构函数从而释放单例对象
	private://构造函数私有
		Singleton(){};
		Singleton(Singleton const&);////防拷贝
		Singleton& operator=(Singleton const&);
		static Singleton* _ps;//单例对象指针
		static mutex _mtx;//互斥锁
	};
	Singleton* Singleton::_ps = nullptr;
	Singleton::GC _gc;
	mutex Singleton::_mtx;
	void func(int n)
	{
		cout << Singleton::GetInstance() << endl;
	}
	// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
	int main()
	{
		thread t1(func, 10);
		thread t2(func, 10);
		t1.join();
		t2.join();
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		getchar();
	}
```

> 1.懒汉模式是在用的时候调用创建对象，所以我们声明一个指针，创建的时候直接new， 得到地址返回地址。
>
>
> 2.如果在多线程情况下，无法保证线程的执行顺序，或者有可能同时执行，所以一个if的判断，有可能两个线程的_m_pInstance指针都为nullptr。所以我们需要加锁。但是如果不用double check，那么效率是非常低下的。就是这种情况：
>
> ```cpp
> Idler* GetInstance(void)
> {
> 	_m_mtx.lock();
> 	if (_m_instance == nullptr)
> 	{
> 		_m_instance = new Idler();
> 	}
> 	_m_mtx.unlock();
> 	return _m_instance;
> }
> ```
>
>
> 所有的线程判断前，全部被挡住，一个一个判断，这样的效率非常低。double check就是保证了，第一次创建完成后，其他的线程只需要第一层判断即可，大大提高了效率。
>
>
> 3.这里有一个内部类，完成清理的工作，这个内部类也是定义了一个静态变量，程序启动时，就有，当程序结束时，它会自动调用内部类的析构函数，完成对单例对象的清理。

## 8.内存泄漏

> 内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费

```c++
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
```

#### 8.1内存泄漏分类

> - **堆内存泄漏**：程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，
>   用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak
> - **系统资源泄漏**：程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定。





常见面试题：https://blog.csdn.net/weixin_42678507/article/details/84563041

常见的动态内存错误：

> - 对NULL指针的解引用操作 
> - 对动态开辟空间的越界访问 
> - 对非动态开辟内存使用free释放
> - 使用free释放一块动态开辟内存的一部分
> - 对同一块动态内存多次释放 
> - 动态开辟内存忘记释放（内存泄漏）



**设计一个类，该类只能在堆上创建对象**

```cpp
//构造函数私有化
1. 将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
2. 提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
class HeapOnly
{ 
public: 
    static HeapOnly* CreateObject() 
 { 
return new HeapOnly; 
 }
private: 
    HeapOnly() {}
    // C++98
    // 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
    // 2.声明成私有
    HeapOnly(const HeapOnly&)；
    // or
    // C++11 
    HeapOnly(const HeapOnly&) = delete;
};
```

**设计一个类，该类只能在栈上创建对象** 

```cpp
class StackOnly
{ 
public: 
static StackOnly CreateObject() 
 { 
return StackOnly(); 
 }
private:
StackOnly() {}
};
//只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可，即屏蔽掉operator new和定
位new表达式，注意：屏蔽了operator new，实际也将定位new屏蔽掉。
class StackOnly
{ 
public: 
StackOnly() {}
private: 
void* operator new(size_t size);
void operator delete(void* p);
};
```

