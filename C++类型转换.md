参考链接： <https://blog.csdn.net/baidu_37964044/article/details/82150532> 

### C++强制类型的转换有四种 

> ####  static_cast 
>
> static_cast用于非多态类型的转换（**静态**转换），编译器隐式执行的任何类型转换都可用static_cast，
>
> 但它 不能用于两个不相关的类型进行转换。
>
> 相当于C语言的隐式类型转换。
>
> ```cpp
> void test2()
> {
> 	int i = 1;
> 	double d = static_cast<double>( i);//注意要给i带括号
> 	printf("%d,%.2f", i, d);
>  
> }
> ```
>
> ###  reinterpret_cast 
>
> 常为操作数的位模式提供较低层次的**(重新解释)**，用于将一种类型转换为另一种不同的类型。
>
> 相当于C语言中的强制类型转换。
>
> ``` cpp
> typedef void (* FUNC)();
> int DoSomething (int i)
>  {
>     cout<<"DoSomething" <<endl;
>     return 0;
>  }
> void Test ()
>  {
> //
> // reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
> // 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
> // C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
> //
>     FUNC f = reinterpret_cast< FUNC>(DoSomething );
>     f();
>  }
> ```
>
> ###  const_cast 
>
> const_cast最常用的用途就是删除变量的const属性，方便赋值
>
> ```cpp
> //一个小练习0.0
> void test3()
> {
> 	const int a = 2;
> 	int *p =(int *) &a;
> 	*p = 3;
> 	cout << a << endl; 
> 	cout << *p << endl;
> //如果是.cpp文件，结果是2，3；如果是.c，结果是3，3
> a作用域下在C++中所有的常量a在编译阶段就已经做了类似于宏替换的工作，"常量折叠"是在编译器进行语法分析的时候，将常量表达式计算求值，并用求得的值来替换表达式，放入常量表。可以算作一种编译优化。
> ∴输出是它的常量值，但是若取调试就发现a的地址和p相同，且p指向的地址内容已经修改为20，即我们对此部分地址的内容做出了修改。         a被修改了，但编译器优化，在寄存器中取值.
> const变量在编译期会被编译期编译成一张常量表，所有读取常量的操作都会从这个常量表里直接读取
> const变量会在编译阶段替换成对应的常量，类似define，但是和define不同的是，define是在预编译阶段替换的，而且const有类型检查。
>    
> 在纯C环境下，const所修饰的变量不是真正的常量，只是标明这个变量是只读的，编译期并不会为其生成常量表，通过指针的修改是直接针对变量修改的，两者是同步的。
> ///////////////////////////////////////////////////////////////////////////////////////////
>  //volatile（adj.易变的）的作用就是取消编译器优化，并且每次读取这个变量的值都从原来的地址上读取，而不是从寄存器上读取。
> 	volatile const int a = 2;
> 	int *p = (int *)&a;
> 	*p = 3;
> 	cout << a << endl;//3  a被修改,加上volatile不让编译器优化，保证内存的可见性
> 	cout << *p << endl;//3
> }
> ```
>
> ```cpp
> int main()
> {
> 	const int a = 2;
> 	int *p = const_cast<int *>(&a);//不用强转，const类型指针都可以付给非const 类型
> 	*p = 3;
> 	cout << a << endl;//2 
> 	cout << *p << endl;//3
> 	getchar();
> 	return 0;
> }
> ```
>
> #### dynamic_cast 
>
> dynamic_cast用于将一个父类对象的指针转换为子类对象的指针或引用(**(动态)**转换) 
>
> 向上转型：子类对象指针->父类指针/引用(不需要转换，赋值兼容规则) 向下转型：父类对象指针->子类指针/ 
>
> 引用(用dynamic_cast转型是安全的) 
>
> 注意： 1. dynamic_cast只能用于含有虚函数的类 2. dynamic_cast会先检查是否能转换成功，能成功则转 
>
> 换，不能则返回0
>
> ```cpp
> class A
> {
> public:
> 	virtual void f(){}
> };
> class B : public A
> {};
> void fun(A* pa)
> {
> 	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
> 	B* pb1 = static_cast<B*>(pa);
> 	B* pb2 = dynamic_cast<B*>(pa);
> 	cout << "pb1:" << pb1 << endl;
> 	cout << "pb2:" << pb2 << endl;
> }
> int main()
> {
> 	A a; B b;
> 	fun(&a);
> 	fun(&b);
> 	getchar();
> 	return 0;
> }
> //强制类型转换关闭或挂起了正常的类型检查，每次使用强制类型转换前，程序员应该仔细考虑是否还有其他不同的方法达到同一目的，如果非强制类型转换不可，则应限制强制转换值的作用域，以减少发生错误的机会。强烈建议：避免使用强制类型转换
> //pb1:005EF87C
> //pb2:00000000
> //pb1:005EF870
> //pb2:005EF870
> 
> //explicit关键字阻止单参数构造函数进行的隐式转换的发生。
> ```

C风格的转换格式很简单，但是有不少缺点的： 

> 1. 隐式类型转化有些情况下可能会出问题 
> 2. 显式类型转换将所有情况混合

#### RTTI 

RTTI：Run-time Type identifification的简称，即：运行时类型识别。 

C++通过以下方式来支持RTTI： 

> 1. typeid运算符 
> 2. dynamic_cast运算符