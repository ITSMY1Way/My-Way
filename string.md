> 1. 字符串是表示字符序列的类 
> 2. 标准的字符串类提供了对此类对象的支持，其接口类似于标准字符容器的接口，但添加了专门用于操作 单字节字符字符串的设计特性。 
>
> 3. string类是使用char(即作为它的字符类型，使用它的默认char_traits和分配器类型。
>
> 4. string类是basic_string模板类的一个实例，它使用char来实例化basic_string模板类，并用char_traits 和allocator作为basic_string的默认参数。
>
> 5. 这个类独立于所使用的编码来处理字节:如果用来处理多字节或变长字符(如UTF-8)的序列，这个 类的所有成员(如长度或大小)以及它的迭代器，将仍然按照字节(而不是实际编码的字符)来操作。

> 1. string是表示字符串的字符串类 
> 2. 该类的接口与常规容器的接口基本相同，再添加了一些专门用来操作string的常规操作。 
> 3. string在底层实际是：basic_string模板类的别名，typedef basic_string<char, char_traits, allocator>  string; 
>
> 4. 不能操作多字节或者变长字符的序列
>
> **在使用string类时，必须包含头文件以及using namespace std;** 

> 当把string对象和字符字面值及字字符串面值混在一条语句中使用时，必须确保每个+的两侧的运算对象至少有一个是string
>
> `string s2 = (s1 + ",") + "world";` 这样是可以的。  

```cpp
void TestString()
{
string s1; // 构造空的string类对象s1
string s2("hello bit"); // 用C格式字符串构造string类对象s2
string s3(10, 'a'); // 用10个字符'a'构造string类对象s3
string s4(s2); // 拷贝构造s4
string s5(s3, 5); // 用s3中前5个字符构造string对象s5
}
```

> 1. size()与length() 方法底层实现原理完全相同，引入size()的原因是为了与其他容器的接口保持一 致，一般情况下基本都是用size()。 
>
> 2. clear()只是将string中有效字符清空，不改变底层空间大小。 
> 3. resize(size_t n) 与 resize(size_t n, char c)都是将字符串中有效字符个数改变到n个，不同的是当字符个数增多时：resize(n)用0来填充多出的元素空间，resize(size_t n, char c)用字符c来填充多出的 元素空间。注意：resize在改变元素个数时，如果是将元素个数增多，可能会改变底层容量的大 小，如果是将元素个数减少，底层空间总大小不变。 
>
> 4. reserve(size_t res_arg=0)：为string预留空间，不改变有效元素个数，当reserve的参数小于 string的底层空间总大小时，reserver不会改变容量大小。

> 1. 在string尾部追加字符时，s.push_back(c) / s.append(1, c) / s += 'c'三种的实现方式差不多，一般 情况下string类的+=操作用的比较多，+=操作不仅可以连接单个字符，还可以连接字符串。 
>
> 2. 对string操作时，如果能够大概预估到放多少字符，可以先通过reserve把空间预留好。

### 浅拷贝

> 浅拷贝：也称位拷贝，编译器只是将对象中的值拷贝过来。如果对象中管理资源，最后就会导致多个对象共 
>
> 享同一份资源，当一个对象销毁时就会将该资源释放掉，而此时另一些对象不知道该资源已经被释放，以为 
>
> 还有效，所以 当继续对资源进项操作时，就会发生发生了访问违规。要解决浅拷贝问题，C++中引入了深拷 
>
> 贝。

### 深拷贝

> 如果一个类中涉及到资源的管理，其拷贝构造函数、赋值运算符重载以及析构函数必须要显式给出。一般情 
>
> 况都是按照深拷贝方式提供。

```cpp
class String
{
public:
	String(const char* str = "")
	{
		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//深拷贝： 拷贝成员变量 + 资源
	//浅拷贝： 拷贝成员变量
	//传统写法
	/*String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}*/
	//现代写法
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//深拷贝,传统写法
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];  // while(*str != '\0') count++;
	//		strcpy(_str, s._str);
	//	}
	//	
	//	return *this;
	//}
	//现代写法
	String& operator=(String s)
	{
		//String tmp(s);
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str; //释放堆上空间
			_str = nullptr;
		}
	}
	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};
```

### string类的模拟实现

```cpp
#include <iostream>
#include <assert.h>
using namespace std;

//class String
//{
//public:
//	//字符串指针输出会作解引用，对于空指针解引用奔溃
//	//其它类型指针输出为地址
//	//对于无参构造，应申请一个字节的空间，存放'\0'
//	//申请一个字节的空间，也需要用 new [], 析构时用的是delete[],保持全局统一
//	/*String()
//		:_str(new char[1])
//	{
//		_str[0] = '\0';
//	}*/
//	//带参构造，需要申请和输入字符串一样大的空间
//	//把输入字符串拷贝进去
//	//如果只拷贝字符串指针，
//	//释放可能会有问题： 1. 二次释放(两个指针同时指向同一片空间)， 
//	//				  2. 如果传入的为字符串常量，析构就会奔溃（不能主动释放代码段的字符串常量）
//	/*String(char* str)
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}*/
//
//	//全缺省构造函数,缺省值为""
//	String(char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	//拷贝构造（深拷贝）, 1，申请空间， 2. 拷贝内容
//	/*String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}*/
//
//	//拷贝构造，现代写法
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//
//	//返回引用，连续赋值
//	//一定要检查是否自己给自己赋值，如果不检查
//	// 要拷贝的字符串长度不一定和当前对象的字符串长度一致
//	// 如果直接拷贝，空间不足的时候，会导致数据丢失
//	// 所以直接释放原有空间，申请一个和当前要拷贝的字符串一样大的空间
//	// _str至少有一个字节的空间，由构造函数保证的
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{	
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//	// 现代写法
//	// 传入参数： 传值， 并不会引发赋值运算符无穷递归，通过调用拷贝构造完成值拷贝
//	// 传值相当于在函数栈帧中生成一个临时对象
//	// 和拷贝构造相比， 生成临时对象的时机不同， 拷贝构造： 函数内部生成， 赋值： 传值时生成
//	// 
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//
//	const char* c_str()
//	{
//		return _str;
//	}
//
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};

//int main()
//{
//	String s;
//	cout << s.c_str() << endl;
//	return 0;
//}

const char* StrStr(const char* dest, const char* substr);

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	
	//全缺省构造函数,缺省值为""
	String(const char* str = "")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);  // while(*_str++ = *str++) ;  会拷贝'\0'
	}

	//拷贝构造，现代写法
	// String(this, const String& s)
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		// Swap(this, tmp)
		Swap(tmp);
	}
	
	// 现代写法
	// String& operator=(this, String s)
	String& operator=(String s)
	{
		// Swap(this, s)
		Swap(s);
		return *this;
	}

	const char* c_str()
	{
		return _str;
	}

	void Swap(String& tmp)
	{
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}

	// 首先检查capacity够不够，如果容量已满，则扩容
	// 
	void PushBack(const char c)
	{
		//if (_size == _capacity)
		//{
		//	//已存满， 扩容, 检测初始空间是否为0，如果是0， 增容为15byte
		//	size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
		//	Reserve(newC);
		//}
		////尾插
		//_str[_size++] = c;
		////++_size;
		//_str[_size] = '\0';

		Insert(_size, c);
	}
	// 只增容，不减少容量， 不改变size
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			//增容
			char* tmp = new char[n + 1];
			//拷贝原有空间的内容到新的空间
			strcpy(tmp, _str);
			//释放原有空间
			delete[] _str;
			//指向新空间
			_str = tmp;
			//更新容量值
			_capacity = n;
		}
	}
	// 尾删
	void PopBack()
	{
		//确保含有至少一个有效字符
		assert(_size > 0);
		_str[--_size] = '\0';

	}
	//尾插
	void Append(const char* str)
	{
		/*size_t sz = strlen(str);
		if (_size + sz > _capacity)
		{
		Reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size += sz;*/

		Insert(_size, str);
	}
	/*
		n < _size: _size = n, 更新'\0'位置
	*/
	void Resize(size_t n, char c = '\0')
	{
		assert(n > 0);
		if (n > _capacity)
		{
			Reserve(n);
		}
		if (n > _size)
		{
			/*for (int i = _size; i < n; i++)
			{
				_str[i] = c;
			}*/

			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}
	void Insert(size_t pos, const char c)
	{
		assert(pos <= _size);

		//检查空间是否已满
		if (_size == _capacity)
		{
			//增容
			size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newC);
		}

		size_t end = _size;
		while (end > pos)  // max end : pos + 1
		{
			//从后向前挪动
			_str[end] = _str[end - 1];
			--end;
		}

		// 在pos插入c
		_str[pos] = c;
		_str[++_size] = '\0';

	}

	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		//从后先前挪动数据
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			//第一个挪动的为'\0'
			_str[end] = _str[end - len];
			--end;
		}
		//从pos位置拷贝str
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;

	}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//从pos开始向后的字符全部被删除
		if (pos + len > _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			//以pos + len位置开始一个一个向前挪动len个位置
			while (start < _size)
			{
				_str[pos++] = _str[start];
				start++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	// s1 += s2   -->  改变s1
	// s1.operator+=(&s1, s2)  --> Append(&s1, s2._str)
	String& operator+=(const String& s)
	{
		Append(s._str);
		return *this;   // this --> &s1
	}
	String& operator+=(const char c)
	{
		PushBack(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	size_t find(const char c)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}
	size_t find(size_t pos, const char* str)
	{

		// char*  strstr(char* dest, char* substr)
		//char* start = strstr(_str, str);
		const char* start = StrStr(_str, str);

		if (start)
			return start - _str;
		else
			return npos;
	}


	size_t Size() const
	{
		return _size;
	}

	char& operator[](size_t pos)
	{
		//防止访问越界
		assert(pos < _size);
		return _str[pos];
	}

	//只读接口，不允许修改，返回const引用
	const char& operator[](size_t pos) const
	{
		//防止访问越界
		assert(pos < _size);
		return _str[pos];
	}


	iterator begin()
	{
		//返回第一个元素的位置(地址）
		return _str;
	}

	iterator end()
	{
		//返回最后一个元素的下一个位置
		return _str + _size;
	}

	const_iterator begin() const
	{
		//返回第一个元素的位置(地址）
		return _str;
	}

	const_iterator end() const
	{
		//返回最后一个元素的下一个位置
		return _str + _size;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	friend ostream& operator<<(ostream& _cout, const String& s);
private:
	// _size: 有效字符长度， 不含'\0'
	size_t _size;
	// _capacity: 实际能存放的最大字符数，不含'\0', 它比实际申请的空间小一个字节
	size_t _capacity;
	char* _str;
	static const size_t npos;
};
// s1 + s2   :  s1: "hello"   s2: "world"    s3 :"hello world"
String operator+(const String& s1, const String& s2)
{
	String s3(s1);
	s3 += s2;   // += String   += 'c'   += "str"
	return s3;
}
String operator+(const String& s1, const char* s2)
{
	String s3(s1);
	s3 += s2;
	return s3;
}
String operator+(const char* s1, const String& s2)
{
	String s3(s1);
	s3 += s2;
	return s3;
}

const size_t String::npos = -1;

// "abc"   "abd"
const char* StrStr(const char* dest, const char* substr)
{
	while (*dest)
	{
		//首先判断第一个字符是否相等
		if (*substr == *dest)
		{
			const char* msubstr = substr;
			const char* mdest = dest;
			//判断substr每一个字符
			while (*msubstr && *mdest)
			{
				if (*msubstr != *mdest)
					break;
				msubstr++;
				mdest++;
			}
			// 匹配成功，返回substr在dest中的起始位置
			if (*msubstr == '\0')
				return dest;
		}
		dest++;
	}

	return nullptr;
}

ostream& operator<<(ostream& _cout, const String& s)
{
	for (auto& e : s)
	{
		_cout << e;
	}
	return _cout;
}

void PrintString(const String& s)
{
	for (int i = 0; i < s.Size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void PrintStringIIterator(const String& s)
{
	String::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

void PrintStringFor(const String& s)
{
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
```

### 写时拷贝

> 写时才拷贝（Copy-On-Write）技术，就是编程界“懒惰行为”——拖延战术的产物。

> #### **Copy—On—Write原理：**
>
> 使用了“引用计数”，是的，必然有一个变量类似于RefCnt。当第一个类构造时，string的构造函数会根据传入的参数从堆上分配内存，当有其它类需要这块内存时，这个计数为自动累加，当有类析构时，这个计数会减一，直到最后一个类析构时，此时的RefCnt为1或是0，此时，程序才会真正的Free这块从堆上分配的内存。

> #### string类在什么情况下才共享内存的？
>
>  使用别的类的数据时，两种情况，1）以别的类构造自己，2）以别的类赋值。第一种情况时会触发拷贝构造函数，第二种情况会触发赋值操作符。这两种情况我们都可以在类中实现其对应的方法。对于第一种情况，只需要在string类的拷贝构造函数中做点处理，让其引用计数累加；同样，对于第二种情况，只需要重载string类的赋值操作符，同样在其中加上一点处理。

> #### **string类在什么情况下触发写时才拷贝（Copy-On-Write）?**
>
> 是在共享同一块内存的类发生内容改变时，才会发生Copy-On-Write。比如string类的[]、=、+=、+、操作符赋值，还有一些string类中诸如insert、replace、append等成员函数,包括类的析构时。修改数据才会触发Copy-On-Write，不修改不会。这就是托延战术的真谛，非到要做的时候才去做。

> ### Copy-On-Write的具体实现是怎么样的？
>
> 每当我们为string分配内存时，我们总是要多分配一个空间用来存放这个引用计数的值，只要发生拷贝构造可是赋值时，这个内存的值就会加一。而在内容修改时，string类为查看这个引用计数是否为0，如果不为零，表示有人在共享这块内存，那么自己需要先做一份拷贝，然后把引用计数减去一，再把数据拷贝过来。
>
> _Ptr[-1]，标准库中，把这个引用计数的内存分配在了前面，当string的长度扩展时，只需要在后面扩展其内存，而不需要移动引用计数的内存存放位置，这又节省了一点时间。