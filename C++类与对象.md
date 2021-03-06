## 1.类的访问限定符及封装 

### 1.1访问限定符

> C++实现封装的方式：用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限选择性的将其 
>
> 接口提供给外部的用户使用。
>
> **【访问限定符说明】**
>
> > 1. public修饰的成员在类外可以直接被访问 
> > 2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的) 
> > 3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止 
> > 4. class的默认访问权限为private，struct为public(因为struct要兼容C) 
> >
> > 注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别
>
> **C++中struct和class的区别是什么？** 
>
> 答：C++需要兼容C语言，所以C++中struct可以当成结构体去使用。另外C++中struct还可以用来定义类。 
>
> 和class是定义类是一样的，区别是struct的成员默认访问方式是public，class是struct的成员默认访问方式 
>
> 是private。

### 1.2封装

> 面向对象的三大特性：**封装、继承、多态**。 
>
> 在类和对象阶段，我们只研究类的封装特性，那什么是封装呢？ 
>
> **封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行** 
>
> **交互。** 使用protected/private把成员封装起来。开放一些共有的成员函数对成员合理的访问。所以封装本质是一种管理。
>
> 
>
> C++是基于面向对象的程序，面向对象有三大特性即：封装、继承、多态。
>
> C++通过类，将一个对象的属性与行为结合在一起，使其更符合人们对于一件事物的认知，将属于该对象的所有东西打包在一起；通过访问限定符选择性的将其部分功能开放出来与其他对象进行交互，而对于对象内部的一些实现细节，外部用户不需要知道，知道了有些情况下也没有，反而增加了使用或者维护的难度，让整个事情复杂化。

### 2.this指针

> C++编译器给每个“成员函数“增加了一个隐藏的指针参数，让该指 针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有成员变量的操作，都是通过该指针去访 问。只不过所有的操作对用户是透明的，即用户不需要来传递，编译器自动完成。
>
> 特征：
>
> > 1. this指针的类型：类类型* const 
> > 2. 只能在“成员函数”的内部使用
> > 3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this 形参。所以对象中不存储this指针。 
> > 4. this指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户 传递
> >
> > **若this指针为空，就不可以在访问成员变量了。**
>
> - **this指针存在哪里？** 
>
>   其实编译器在生成程序时加入了获取对象首地址的相关代码。并把获取的首地址存放在了寄存器ECX中(VC++编译器是放在ECX中，其它编译器有可能不同)。也就是成员函数的其它参数正常都是存放在栈中。而this指针参数则是存放在寄存器中。类的静态成员函数因为没有this指针这个参数，所以类的静态成员函数也就无法调用类的非静态成员变量。
>
>   原文：https://blog.csdn.net/M_jianjianjiao/article/details/83419219 
>
> - **this指针可以为空吗？**
>
>   可以为空，当我们在调用函数的时候，如果函数内部并不需要使用到this,也就是不需要通过this指向当前对象并对其进行操作时才可以为空(当我们在其中什么都不放或者在里面随便打印一个字符串)，如果调用的函数需要指向当前对象，并进行操作，则会发生错误（空指针引用）就跟C中一样不能进行空指针的引用。原文：https://blog.csdn.net/M_jianjianjiao/article/details/83419219 

### 3.对象

> 对象是指一块能村粗数据并具有某种类型的内存空间
>
> 初始化≠赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值来替代
>
> 变量可被定义一次，单多次声明，
>
> C++支持分离式编译：声明使得名字为程序所知，而定义负责创建与名字关联的实体。4

> `it->empty()`  箭头运算符将解引用和成员访问两个操作结合在一起，他的作用和`(*it).empty()`相同。

### 4.缺省参数

> 缺省参数是声明或定义函数时为函数的参数指定一个默认值。在调用该函数时，如果没有指定实参则采用该默 认值，否则使用指定的实参。
>
> ```cpp
> void TestFunc(int a = 0) {
> cout<<a<<endl; }
> int main()
> {
> TestFunc();     // 没有传参时，使用参数的默认值
> TestFunc(10);   // 传参时，使用指定的实参
> }
> ```
>
> - 全缺省
>
> ```cpp
> void TestFunc(int a = 10, int b = 20, int c = 30) {
> cout<<"a = "<<a<<endl;
> cout<<"b = "<<b<<endl;
> cout<<"c = "<<c<<endl; }
> ```
>
> - 半缺省
>
> ```cpp
> void TestFunc(int a, int b = 10, int c = 20) {
> cout<<"a = "<<a<<endl;
> cout<<"b = "<<b<<endl;
> cout<<"c = "<<c<<endl; }
> //1. 半缺省参数必须从右往左依次来给出，不能间隔着给
> //2. 缺省参数不能在函数声明和定义中同时出现
> //3. 缺省值必须是常量或者全局变量
> //4. C语言不支持（编译器不支持）
> ```

### 5.extern “C” 

```cpp
//有时候在C++工程中可能需要将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，将该函数按照C语言规则来编译。
extern "C" int Add(int left, int right);
int main()
{
Add(1,2);
return 0; }
```

### 6.内联函数 

> 以**inline修饰**的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销， 
>
> 内联函数提升程序运行的效率。
>
> 特征：
>
> > 1. inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环/递归的函数不适宜使 用作为内联函数。 
> >
> > 2. inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环/递归等 等，编译器优化时会忽略掉内联。 
> > 3. inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。

### 7.const成员

> **将const修饰的类成员函数称之为const成员函数**，const修饰类成员函数，实际修饰该成员函数**隐含的this** 
>
> **指针**，表明在该成员函数中**不能对类的任何成员进行修改**。
>
> ```cpp
> class Date
> { 
> public :
> void Display ()
>  {
> cout<<"Display ()" <<endl;
> cout<<"year:" <<_year<< endl;
> cout<<"month:" <<_month<< endl;
> cout<<"day:" <<_day<< endl<<endl ;
>  }
> void Display () const
>  {
> cout<<"Display () const" <<endl;
> cout<<"year:" <<_year<< endl;
> cout<<"month:" <<_month<< endl;
> cout<<"day:" <<_day<< endl<<endl;
>  }
> private :
> int _year ; // 年
> int _month ; // 月
> int _day ; // 日
> };
> void Test ()
> {
> Date d1 ;
> d1.Display ();
> const Date d2;
> d2.Display ();
> }
> ```
>
> - const对象可用调用其他的const函数；
> - 非const对象可用调用const成员函数和const成员函数；
> - const成员函数内可用调用其他的const成员函数；
> - 非const成员函数可用调用其他的const成员函数和非const成员函数；

#### 取地址及const取地址操作符重载 

> 这两个默认成员函数一般不用重新定义 ，编译器默认生成。
>
> 这两个运算符一般不需要重载，使用编译器生成的默认取地址的重载即可，只有特殊情况，才需要重载，比 
>
> 如想让别人获取到指定的内容。
>
> ```cpp
> class Date
> { 
> public :
> Date* operator&()
>  {
> return this ;
>  }
> const Date* operator&()const
>  {
> return this ;
>  }
> private :
> int _year ; // 年
> int _month ; // 月
> int _day ; // 日
> };
> ```

### 8.explicit关键字 

> 构造函数不仅可以构造与初始化对象，对于单个参数的构造函数，还具有**类型转换**的作用。 
>
> ```cpp
> class Date
> {
> public:
> Date(int year)
>  :_year(year)
>  {}
> 比特科技
> explicit Date(int year)
>  :_year(year)
>  {}
> private:
> int _year;
> int _month:
> int _day; }；
> void TestDate()
> {
> Date d1(2018);
> // 用一个整形变量给日期类型对象赋值
> // 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
> 
> //上述代码可读性不是很好，用explicit修饰构造函数，将会禁止单参构造函数的隐式转换。
> ```

### 指针和引用的区别

- 在**语法概念上**引用就是一个别名，没有独立的空间，和其引用实体公用一块空间。
- 在**底层实现上**实际是有空间的，因为引用是按照指针方式来实现的。

指针和引用的不同点：

> 1. 引用在定义时必须初始化，指针没有要求。
> 2. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型实体。
> 3. 没有NULL引用。
> 4. 在sizeof中含义不用：引用的结果为引用类型的大小，但指针始终是地址空间所占字节个数（32位平带下占4个字节）。
> 5. 引用自加即引用实体加1，指针自加即指针向后偏移一个类型大小。
> 6. 有多级指针，没有多级引用。
> 7. 访问实体方式不同，指针需要显示解引用，引用编译器自己处理。
> 8. 引用比指针使用起来相对安全。

宏的优缺点？ 

> 优点： 
>
> 1.增强代码的复用性。 
>
> 2.提高性能。 
>
> 缺点： 
>
> 1.不方便调试宏。（因为预编译阶段进行了替换） 
>
> 2.导致代码可读性差，可维护性差，容易误用。 
>
> 3.没有类型安全的检查 。 

C++有哪些技术替代宏？ 

> 1. 常量定义 换用const 
> 2. 函数定义 换用内联函数 

不能重载的运算符只有5个：

>  .             （成员访问运算符）
>
>  .*            （成员指针访问运算符）
>
>  ::             （域运算符）
>
>  sizeof    （长度运算符）
>
>  ?:            （条件运算符）
>
> 前两个运算符不能重载是为了保证访问成员的功能不能被改变，域运算符合sizeof运算符的运算对象是类型而不是变量或一般表达式，不具备重载的特征。

###  auto关键字(C++11) 

> 在早期C/C++中auto的含义是：使用auto修饰的变量，是具有自动存储器的局部变量.
>
> C++11中， auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导而得。
>
> 使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类 
>
> 型。因此auto并非是一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译期会将auto替换为变 
>
> 量实际的类型。

**使用规则：**

> 1.auto与指针和引用结合起来使用 
>
> 用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&
>
> ```
> // 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
> void TestAuto(auto a)
> {}
> ```
>
> 2.auto不能直接用来声明数组 
>
> ```
> void TestAuto()
> {
>     int a[] = {1,2,3};
>     auto b[] = {4，5，6};
> }
> ```
>
> 3.为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法 
>
> 4.auto在实际中最常见的优势用法就是跟以后会讲到的C++11提供的新式for循环，还有lambda表达式等进 行配合使用。 
>
> 5.auto不能定义类的非静态成员变量
>
> 6.实例化模板时不能使用auto作为模板参数

实现一个类，计算中程序 中创建出了多少个类对象？

```cpp
class A {
public: 
	A() { ++_scount; }
		A(const A& t) { ++_scount; }
		static int GetACount()
		{ return _scount; 
		}
private:
	static int _scount;
};
int A::_scount = 0;

int main(){
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
	getchar();
}
```

 **1.静态成员函数可以调用非静态成员函数吗？**

> 不可以，非静态成员函数有一个默认的参数this指针，静态成员函数没有this指针，参数传递不进来，非静态成员函数无法使用。

**2.非静态成员函数可以调用类的静态成员函数吗？**   

> 可以，静态成员函数不需要this指针，所以不管是否有this指针和静态成员函数没有任何关系。

### 友元 

> 友元分为：**友元函数和友元类** 
>
> 友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多 
>
> 用。 
>
> 问题：现在我们尝试去重载operator<<，然后发现我们没办法将operator<<重载成成员函数。**因为cout的** 
>
> **输出流对象和隐含的this指针在抢占第一个参数的位置**。this指针默认是第一个参数也就是左操作数了。但是 
>
> 实际使用中cout需要是第一个形参对象，才能正常使用。所以我们要将operator<<重载成全局函数。但是这 
>
> 样的话，又会导致类外没办法访问成员，那么这里就需要友元来解决。operator>>同理。
>
> **友元函数可以直接访问类的私有成员**，它是定义在**类外部的普通函数**，不属于任何类，但需要在类的内部声 
>
> 明，声明时需要加**friend关键字**。

### 友元类

> 友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。 
>
> - 友元关系是单向的，不具有交换性。 
>
>   比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time 
>
>   类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。 
>
> - 友元关系不能传递 
>
>   如果B是A的友元，C是B的友元，则不能说明C时A的友元。

### 内部类 

> 概念：如果一个类定义在另一个类的内部，这个内部类就叫做内部类。注意此时这个内部类是一个独立的 
>
> 类，它不属于外部类，更不能通过外部类的对象去调用内部类。外部类对内部类没有任何优越的访问权限。 
>
> 注意：内部类就是外部类的友元类。注意友元类的定义，内部类可以通过外部类的对象参数来访问外部类中 
>
> 的所有成员。但是外部类不是内部类的友元。
>
> 特性： 
>
> 1. 内部类可以定义在外部类的public、protected、private都是可以的。 
> 2. 注意内部类可以直接访问外部类中的static、枚举成员，不需要外部类的对象/类名。 
> 3. sizeof(外部类)=外部类，和内部类没有任何关系。

命名空间：https://blog.csdn.net/weixin_42678507/article/details/88179130

函数重载：https://blog.csdn.net/weixin_42678507/article/details/88181829

为什么C语言不支持函数重载？https://blog.csdn.net/simplehap/article/details/53710178

C++中函数重载底层是怎么处理的？https://www.cnblogs.com/weizhixiang/articles/5759322.html

引用：https://blog.csdn.net/weixin_42678507/article/details/88184611

C++初始类和对象:https://blog.csdn.net/weixin_42678507/article/details/883944654

C++类的6个默认成员函数:https://blog.csdn.net/weixin_42678507/article/details/88398615

C++构造函数的初始化：https://blog.csdn.net/weixin_42678507/article/details/88596082