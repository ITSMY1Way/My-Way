```cpp
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};
// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
class Student : public Person
{
protected:
	int _stuid; // 学号
};
class Teacher : public Person
{
protected:
	int _jobid; // 工号
};
int main()
{
	Student s;
	Teacher t; s.Print();
	t.Print();
	getchar();
	return 0;
}
```

### 继承方式和访问限定符





> // private: 在类外和子类都无法访问
> // protected: 在类外无法访问，但是在子类内部可以访问
> // public继承： 不改变基类成员在子类中的访问权限
> // protected继承：基类成员在子类中的最低访问权限为protected
> // private继承：基类成员在子类中的最低访问权限为private
>
> ```cpp
> /* Person:
> public:       string _name; // 姓名
> private:      int _age; // 年龄
> protected:    int _id;
> */
> 
> //_name	  _age		 _id
> //A	Public		B	Protected	C  Private  D 不可见
> //Student : 
> //Public继承:  		ADB
> //Protected继承:   	BDB
> //Private继承:     	CDC
> ```
>
> 

#### 继承基类成员访问方式的变化 

| 类成员/继承方式     | public继承            | protected继承         | private继承         |
| ------------------- | --------------------- | --------------------- | ------------------- |
| 基类的public成员    | 派生类的public成员    | 派生类的protected成员 | 派生类的private成员 |
| 基类的protected成员 | 派生类的protected成员 | 派生类的protected成员 | 派生类的private成员 |
| 基类的private成员   | 在派生类中不可见      | 在派生类中不可见      | 在派生类中不可见    |

> 1. 基类private成员在派生类中无论以什么方式继承都是不可见的。这里的不可见是指基类的私有成员还是 
>
> 被继承到了派生类对象中，但是语法上限制派生类对象不管在类里面还是类外面都不能去访问它。 
>
> 2. 基类private成员在派生类中是不能被访问，如果基类成员不想在类外直接被访问，但需要在派生类中能 
>
> 访问，就定义为protected。可以看出保护成员限定符是因继承才出现的。 
>
> 3. 实际上面的表格我们进行一下总结会发现，基类的私有成员在子类都是不可见。基类的其他成员在子类 
>
> 的访问方式 == Min(成员在基类的访问限定符，继承方式)，public > protected > private。 
>
> 4. 使用关键字class时默认的继承方式是private，使用struct时默认的继承方式是public，不过最好显示的 
>
> 写出继承方式。 
>
> 5. 在实际运用中一般使用都是public继承，几乎很少使用protetced/private继承，也不提倡使用 
>
> protetced/private继承，因为protetced/private继承下来的成员都只能在派生类的类里面使用，实际中 
>
> 扩展维护性不强

#### 基类和派生类对象赋值转换 

> - 派生类对象 可以赋值给 基类的对象 / 基类的指针 / 基类的引用。这里有个形象的说法叫切片或者切 
>
>   割。寓意把派生类中父类那部分切来赋值过去。 
>
> - 基类对象不能赋值给派生类对象 
>
> - 基类的指针可以通过强制类型转换赋值给派生类的指针。但是必须是基类的指针是指向派生类对象时才 
>
>   是安全的。这里基类如果是多态类型，可以使用RTTI(Run-Time Type Information)的dynamic_cast 来 
>
>   进行识别后进行安全转换。

```cpp
class Person
{
protected :
string _name; // 姓名
string _sex; // 性别
int _age; // 年龄
};
class Student : public Person
{
public :
int _No ; // 学号
};
void Test ()
{
Student sobj ;
    ////切片： 子类对象可以赋给父类对象
// 1.子类对象可以赋值给父类对象/指针/引用，引用的底层就是指针
Person pobj = sobj ;
Person* pp = &sobj;
Person& rp = sobj;
比特科技
//2.基类对象不能赋值给派生类对象
sobj = pobj;
// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
pp = &sobj
Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
ps1->_No = 10;
pp = &pobj;
Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
ps2->_No = 10; }//父类的指针不能赋给子类指针：可能会发生访问越界
```

### 派生类的默认成员函数 

> 6个默认成员函数，“默认”的意思就是指我们不写，编译器会变我们自动生成一个，那么在派生类中，这几个 
>
> 成员函数是如何生成的呢？ 
>
> 1. 派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。如果基类没有默认的构造函 数，则必须在派生类构造函数的初始化列表阶段显示调用。 
>
> 2. 派生类的拷贝构造函数必须调用基类的拷贝构造完成基类的拷贝初始化。 
> 3. 派生类的operator=必须要调用基类的operator=完成基类的复制。 
> 4. 派生类的析构函数会在被调用完成后自动调用基类的析构函数清理基类成员。因为这样才能保证派生类 对象先清理派生类成员再清理基类成员的顺序。 
>
> 5. 派生类对象初始化先调用基类构造再调派生类构造。 
> 6. 派生类对象析构清理先调用派生类析构再调基类的析构。

### 实现一个不能被继承的类。

``` cpp
// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
//一个类不想被继承，也就是说它的子类不能构造父类，我们可以将一个类的构造函数声明为私有，使得这个类的构造函数对子类不可见，那么这个类也就不能被继承了。
#pragma once
#include<iostream>
using namespace std;
class A
{
private:
    A(int a)
    {}
    ~A()
    {}
public:
    int _a;
};

class B : public A
{
public:
    int _b;
};
void Test()
{
    B b;
    b._a = 1;

}
//or    //将A类虚继承E类，但是E类的构造函数是带private属性的，A类还是E类的友元。
//如果我们让A类虚继承E类，根据虚继承的特性，虚基类的构造函数由最终的子类负责构造，此时E类的构造函数虽然是私有的，但是A类是E类的友元，所以可以调用E类的构造函数完成初始化。
//B类如果要想继承A类，它必须能够调用E虚基类的构造函数来完成初始化，这是不可能的，因为它不是E类的友元！因此，我们的A类也就终于成为了一个无法继承的类，并且我们还可以在A类外实例化对象，可以正常使用。

#pragma once
#include<iostream>
using namespace std;

class E
{
private:
    friend class A;
    E()
    {}
};

class A : virtual public E
{
public:
    A()
    {}

};

//class B : public A
//{
//public:
//  B()
//  {
//
//  }
//};

void Test()
{
    //B a;
      A a；

}

 ———————————————————————————————————————————————————————————————————————————————————————————————

 
class NonInherit
{
public:
static NonInherit GetInstance()
 {
return NonInherit();
 }
private:
NonInherit()
 {}
};
// C++11给出了新的关键字final禁止继承
class NonInherit final
{};
```

### 菱形继承及菱形虚拟继承 

> **单继承：一个子类只有一个直接父类时称这个继承关系为单继承** 
>
>  多继承：一个子类有两个或以上直接父类时称这个继承关系为多继承 
>
> 菱形继承：菱形继承是多继承的一种特殊情况。两个子类同时继承一个父类，而又有子类同时继承这两个子类
>
> 菱形继承的问题：从下面的对象成员模型构造，可以看出菱形继承有数据冗余和二义性的问题。
>
> 
>
> 使用域访问限定符：：，虽然解决了二义性问题，但是没有解决数据冗余的问题.
>
> 
>
> **虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在Student和Teacher的继承** 
>
> **Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地方去使用。**
>
> 虚拟继承是一种机制，类通过虚拟继承指出它希望共享虚基类的状态。对给定的虚基类，无论该类在派生层次中作为虚基类出现多少次，只继承一个共享的基类子对象，共享基类子对象称为虚基类。虚基类用virtual声明继承关系就行了。这样一来，D就只有A的一份拷贝。 如果B类和C类在分别继承A类时都用virtual来标注，对于D类对象，C++会保证只有一个A类的子对象会被创建

**菱形继承的内存对象成员模型 ：数据冗余**

> D对象中将A放到的了对象组成的最下面，这个A 同时属于B和C，那么B和C如何去找到公共的A呢？
>
> **这里是通过了B和C的两个指针，指向的一张表。这两个指 针叫虚基表指针，这两个表叫虚基表。虚基表中存的偏移量。通过偏移量可以找到下面的A。**

### 继承和组合

> - public继承是一种**is-a**的关系。也就是说每个派生类对象都是一个基类对象。 
>
> - 组合是一种**has-a**的关系。假设B组合了A，每个B对象中都有一个A对象。 
>
> - 优先使用对象组合，而不是类继承 。 
>
> - 继承允许你根据基类类的实现来定义派生类的实现。这种通过生成派生类的复用通常被称为白箱复用(white-box reuse)。术语“白箱”是相对可视性而言：在继承方式中，基类的内部细节对子类可见 。继承一定程度破坏了基类的封装，基类的改变，对派生类类有很大的影响。派生类和基类间的依 赖关系很强，耦合度高。 
>
> - 对象组合是类继承之外的另一种复用选择。新的更复杂的功能可以通过组装或组合对象来获得。对 象组合要求被组合的对象具有良好定义的接口。这种复用风格被称为黑箱复用(black-box reuse)， 因为对象的内部细节是不可见的。对象只以“黑箱”的形式出现。 组合类之间没有很强的依赖关系， 耦合度低。优先使用对象组合有助于你保持每个类被封装。 
>
> - 实际尽量多去用组合。组合的耦合度低，代码维护性好。不过继承也有用武之地的，有些关系就适合继承那就用继承，另外要实现多态，也必须要继承。类之间的关系可以用继承，可以用组合，就用组合。 组合体现为实现层面，继承主要体现在扩展方面。我觉得如果并不是需要一个类的所有东西（包括接口和属性），那么就不需要用继承，相反就用组合。
>
>   用继承那就必须是所有的都继承，不是所有的都继承，那么就是滥用继承。
>
>   组合在编译依赖和不同版本的运行时兼容性上优于继承；继承在合理复用实现的潜力优于组合
>
>   继承偏重集体，具有特殊性的集体(派生类)可以看作是一般性集体(基类)的一部分，如汽车对于交通工具。
>
>   组合偏重个体，某个功能对象被宿主对象看成自己的一部分，如轮子对于汽车。
>
>   与看待事物的角度有关，继承偏抽象，组合偏具体。

```cpp
// Car和BMW Car和Benz构成is-a的关系
class Car{
protected:
string _colour = "白色"; // 颜色
string _num = "陕ABIT00"; // 车牌号
 };
class BMW : public Car{
public:
void Drive() {cout << "好开-操控" << endl;}
 };
class Benz : public Car{
public:
void Drive() {cout << "好坐-舒适" << endl;}
 };

// Tire和Car构成has-a的关系
class Tire{
protected:
string _brand = "Michelin"; // 品牌
size_t _size = 17; // 尺寸
 };
class Car{
protected:
string _colour = "白色"; // 颜色
string _num = "陕ABIT00"; // 车牌号
Tire _t; // 轮胎
 };
```

```cpp
class Person
{
public:
	Person(const char* name = "hello")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)  // Person(Person* this, const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person() // ~destructor
	{
		cout << "~Person()" << endl;
	}
	
protected:
	string _name; // 姓名
};

class Student : public Person
{
public:
	//父类的成员变量不能直接在子类的构造和拷贝构造中直接初始化，
	//必须调用父类的构造和拷贝构造进行初始化

	//子类构造函数先调用父类构造函数，在执行子类构造函数
	Student(const char* name = "helo")
		:_id(10)
		,Person(name)
	{
		cout << "Student(const char* name)" << endl;
	}
	// 如果子类不显示调用父类的拷贝构造，则调用父类的默认构造函数
	// 如果子类显示调用父类的拷贝构造，就不会再去调用父类的默认构造函数
	Student(const Student& s)  // (Student* this, const Student& s)
		:Person(s)
		,_id(10)
	{
		cout << "Student(const Student& s)" << endl;
	}

	//父类的成员变量可以在子类的赋值运算符重载函数中直接赋值
	//如果是编译器默认生成的子类赋值运算符重载函数，会调用父类的赋值运算符重载函数进行赋值
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			//_name = s._name;
			//建议直接显示调用父类的赋值运算符重载函数，代码复用
			Person::operator=(s);
			_id = 10;
		}
		return *this;
	}
	//析构函数：不允许显式调用父类的析构函数
	~Student()  // ~destructor  同名隐藏，编译器底层对析构函数的名字做了修改，为了使用多态
	{
		cout << "~Student()" << endl;
		//Person::~Person();
	}
private:
	int _id;
};
int main()
{
	Student s;
	Student cpy(s);
	Student s2 = s;  //拷贝构造
	//s2 = s;  //赋值运算符重载
	//构造和析构的调用顺序：
	//构造顺序： 基类构造-->派生类构造
	//析构顺序： 派生类析构-->基类析构
	return 0;
}
```

//A 重载    // 函数在同一个作用域中，函数名形同， 参数不同
//B 重定义  // 重定义/隐藏：子类函数和父类函数名相同
//C 覆盖    // 覆盖/重写
//D 重写
//E 隐藏



https://blog.csdn.net/weixin_42678507/article/details/89376647