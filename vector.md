> 1. vector是表示可变大小数组的序列容器。 
> 2. 就像数组一样，vector也采用的连续存储空间来存储元素。也就是意味着可以采用下标对vector的元素 进行访问，和数组一样高效。但是又不像数组，它的大小是可以动态改变的，而且它的大小会被容器自 动处理。 
>
> 3. 本质讲，vector使用动态分配数组来存储它的元素。当新元素插入时候，这个数组需要被重新分配大小 为了增加存储空间。其做法是，分配一个新的数组，然后将全部元素移到这个数组。就时间而言，这是构造函数声明 一个相对代价高的任务，因为每当一个新的元素加入到容器的时候，vector并不会每次都重新分配大 小。 
> 4. vector分配空间策略：vector会分配一些额外的空间以适应可能的增长，因为存储空间比实际需要的存 储空间更大。不同的库采用不同的策略权衡空间的使用和重新分配。但是无论如何，重新分配都应该是 对数增长的间隔大小，以至于在末尾插入一个元素的时候是在常数时间的复杂度完成的。 
> 5. 因此，vector占用了更多的存储空间，为了获得管理存储空间的能力，并且以一种有效的方式动态增 长。 
> 6. 与其它动态序列容器相比（deques, lists and forward_lists）， vector在访问元素的时候更加高效，在 末尾添加和删除元素相对高效。对于其它不在末尾的删除和插入操作，效率更低。比起lists和forward_lists统一的迭代器和引用更好。

###  vector iterator 的使用 

| iterator的使用 | 接口说明                                     |
| -------------- | -------------------------------------------- |
| begin()        | 获取第一个数据位置的iterator                 |
| end()          | 获取最后一个数据的下一个位置的iterator       |
| rbegin()       | 获取最后一个数据位置的reverse_iterator       |
| rend()         | 获取第一个数据前一个位置的reverse_iterator   |
| cbegin()       | 获取第一个数据位置的 const_iterator          |
| cend()         | 获取最后一个数据的下一个位置的const_iterator |

> - capacity的代码在vs和g++下分别运行会发现，vs下capacity是按1.5倍增长的，g++是按2倍增长的。 
>
>   具体增长多少是根据具体的需求定义的。vs是PJ版本STL，g++是SGI版本STL。 
>
> - reserve只负责开辟空间，如果确定知道需要用多少空间，reserve可以缓解vector增容的代价缺陷问 
>
>   题。 
>
> - resize在开空间的同时还会进行初始化，影响size。

```cpp
vector<int> v1(10);//v1有10个元素，每个的值都是0
vector<int> v2{10};//v2有1个，值是10

vector<int> v3(10, 1);//v3有10个，每个都是1
vector<int> v4{10, 1};//v4有2个，值分别是1和10
//如果使用的是圆括号提供的值是用来构造(construct)vector对象的。
//如果使用的是花括号，表述成想要列表初始化该vector对象。
```

```cpp

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
public:

	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}

	Vector(const Vector<T>& v)
	{
		//开辟空间
		T* _start = new T[v.Capacity()];
		//拷贝内容，深拷贝
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		//更新
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}

	T& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}



	size_t Size() const
	{
		return _finish - _start;
	}

	size_t Capacity() const
	{
		return _endOfStorage - _start;
	}

	void PushBack(const T& val)
	{
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		*_finish = val;
		//更新size
		++_finish;
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t sz = Size();
			//申请新的空间
			T* tmp = new T[n];
			//检查空间是否为空
			if (_start)
			{
				//拷贝原有空间内容, 浅拷贝
				//memcpy(tmp, _start, sizeof(T)* sz);
				//深拷贝，调用T类型的赋值运算符重载完成拷贝
				for (int i = 0; i < sz; i++)
				{
					tmp[i] = _start[i];
				}

				//释放原有空间
				delete[] _start;
			}
			//更新size, capacity
			_start = tmp;
			//更新size
			_finish = _start + sz;
			//更新容量
			_endOfStorage = _start + n;
		}
	}


	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	//insert, erase 存在迭代器失效问题
	//insert: 增容导致迭代器失效， 故增容之后更新迭代器
	void Insert(iterator pos, const T& val)
	{
		assert(pos >= _start && pos <= _finish);
		size_t len = pos - _start;
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		//增容以后更新迭代器
		pos = _start + len;
		iterator end = _finish;
		//从后向前挪动元素
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		//在pos位置插入元素val
		*pos = val;
		//更新_finish指针
		++_finish;
	}

	// Erase 导致迭代器失效：可能导致迭代器访问越界，或者位置访问异常
	// 获取Erase的返回值，更新迭代器
	iterator Erase(iterator pos)
	{
		assert(pos < _finish && pos >= _start);
		//起始挪动元素的位置, 从前向后依次挪动
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;
		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			// _finish -  _start
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			// Size() ~  n
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};

template <class T>
void PrintVector(const Vector<T>& v)
{
	for (int i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVectorFor(const Vector<T>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

```

### vector失效

https://blog.csdn.net/weixin_42678507/article/details/88952862

> - 在向容器添加元素后，如果储存空间未重新分配，指向插入位置之前的元素的迭代器、指针、引用有效，但指向插入位置之后的将会失效。
> - 在从容器删除元素之后，指向被删元素之前元素的迭代器、引用、指针仍有效。尾后迭代器也就失效。

```cpp
   1.遍历时插入元素
　　　　iter=v.insert(iter,*iter);//想要指向下一个元素，就要跳过当前和被添加的元素
　　　　iter+=2;
　　2.   遍历时删除元素
　　　　注意：erase函数返回的就是删除之后的元素的迭代器
　　　　iter=iter.erase(iter);
```

```cpp
// insert/erase导致的迭代器失效
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
int a[] = { 1, 2, 3, 4 };
vector<int> v(a, a + sizeof(a) / sizeof(int));
// 使用find查找3所在位置的iterator
vector<int>::iterator pos = find(v.begin(), v.end(), 3);
// 删除pos位置的数据，导致pos迭代器失效。
v.erase(pos);
cout << *pos << endl; // 此处会导致非法访问
// 在pos位置插入数据，导致pos迭代器失效。
// insert会导致迭代器失效，是因为insert可
// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
pos = find(v.begin(), v.end(), 3);
v.insert(pos, 30);
cout << *pos << endl; // 此处会导致非法访问
return 0; }
```

