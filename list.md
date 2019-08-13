> 1. list是可以在常数范围内在任意位置进行插入和删除的序列式容器，并且该容器可以前后双向迭代。 
> 2. list的底层是双向链表结构，双向链表中每个元素存储在互不相关的独立节点中，在节点中通过指针指向 其前一个元素和后一个元素。 
>
> 3. list与forward_list非常相似：最主要的不同在于forward_list是单链表，只能朝前迭代，已让其更简单高 效。
>
> 4. 与其他的序列式容器相比(array，vector，deque)，list通常在任意位置进行插入、移除元素的执行效率 更好。 
>
> 5. 与其他序列式容器相比，list和forward_list最大的缺陷是不支持任意位置的随机访问，比如：要访问list 的第6个元素，必须从已知的位置(比如头部或者尾部)迭代到该位置，在这段位置上迭代需要线性的时间 开销；list还需要一些额外的空间，以保存每个节点的相关联信息(对于存储类型较小元素的大list来说这 可能是一个重要的因素) 



> 1. begin与end为正向迭代器，对迭代器执行++操作，迭代器向后移动 
> 2. rbegin(end)与rend(begin)为反向迭代器，对迭代器执行++操作，迭代器向前移动 
> 3. cbegin与cend为const的正向迭代器，与begin和end不同的是：该迭代器指向节点中的元素值不能修改 
> 4. crbegin与crend为const的反向得带器，与rbegin和rend不同的是：该迭代器指向节点中的元素值不 能修改 

### list的迭代器失效 

> 迭代器失效即迭代器所指向的节点的无效，即该节 点被删除了。因为list的底层结构为带头结点的双向循环链表，因此在list中进行插入时是不会导致list的迭代 器失效的，只有在删除时才会失效，并且失效的只是指向被删除节点的迭代器，其他迭代器不会受到影响。 

```cpp
/*
List 的迭代器
迭代器有两种实现方式：
1. 原生态指针，比如：vector
2. 将原生态指针进行封装，因迭代器的使用形式与指针完全相同，因此，在自定义的类中必须实现以下方
法：
1. 指针可以解引用，迭代器的类中必须重载operator*()
2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前
移 动，所以需要重载，如果是forward_list就不需要重载--
4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
*/
/*
List 的反向迭代器，反向迭代器与正向迭代器刚好是相反的，反向迭代器++，迭代器往前移动，反向迭代
器--， 迭代器往后移动，因此反向迭代器可以在正向迭代器的基础之上来实现
*/
```

### list与vector的对比 

|                         | vector                                                       | list                                                         |
| :---------------------: | :----------------------------------------------------------- | :----------------------------------------------------------- |
|        底层结构         | 动态顺序表，一段连续空间                                     | 带头结点的双向循环链表                                       |
|        随机访问         | 支持随机访问，访问某个元素  效率O(1)                         | 不支持随机访问，访问某个元素  效率O(N)                       |
|       插入和删除        | 任意位置插入和删除效率低，需要搬移元素，时间复杂 为O(N)，插入时有可能需要增容，增容：开辟新空 间，拷贝元素，释放旧空间，导致效率更低 | 任意位置插入和删除效率高，不 需要搬移元素，时间复杂度为O(1)  |
|       空间利用率        | 底层为连续空间，不容易造成内存碎片，空间利用率高，缓存利用率高 | 底层节点动态开辟，小节点容易 造成内存碎片，空间利用率低，缓存利用率低 |
|         迭代器          | 原生态指针                                                   | 对原生态指针(结点指针)进行封装                               |
| 缓存利用率低 迭代器失效 | 在插入元素时，要给所有的迭代器重新赋值，因为插入元素有可能会导致重新扩容，致使原来迭代器失效，删 除时，当前迭代器需要重新赋值否则会失效 | 插入元素不会导致迭代器失效，删除元素时，指挥导致当前迭代器失效，其他迭代器不受影响 |
|        使用场景         | 需要高效存储，支持随机访问，不关心插入删除效率               | 大量插入和删除操作，不关心随机访问                           |

```cpp

#include <iostream>
using namespace std;
template <class T>
struct ListNode
{
	ListNode(const T& val = T())
	:_next(nullptr)
	, _prev(nullptr)
	, _data(val)
	{}
	ListNode<T>* _next;
	ListNode<T>* _prev;
	T _data;
};
template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> self;
	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	// ++iterator
	self& operator++() 
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	//移动到下一个节点的位置
	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	// it--, 返回没有变之前的值，然后自身--
	self operator--(int)
	{
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
	//*iterator
	//获取节点的data
	Ref operator*()
	{
		return _node->_data;
	}

	// struct a{int b, int c, int d}   a *pa, pa->b,
	// iterator->->
	Ptr operator->()
	{
		return &_node->_data;
	}

	// iterator != l.end()
	//比较两个迭代器封装的节点是否一样
	bool operator!=(const self& it)
	{
		return _node != it._node;
	}
};

//template <class T>
//struct ConstListIterator
//{
//	typedef ListNode<T>* pNode;
//	typedef ConstListIterator<T> self;
//	pNode _node;
//
//	ConstListIterator(pNode node)
//		:_node(node)
//	{}
//
//	// ++iterator
//	self& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	//iterator++
//	//移动到下一个节点的位置
//	self operator++(int)
//	{
//		self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	self& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	// it--, 返回没有变之前的值，然后自身--
//	self operator--(int)
//	{
//		self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//	//*iterator
//	//获取节点的data
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//
//	// struct a{int b, int c, int d}   a *pa, pa->b,
//	// iterator->->
//	const T* operator->()
//	{
//		return &_node->_data;
//	}
//
//	// iterator != l.end()
//	//比较两个迭代器封装的节点是否一样
//	bool operator!=(const self& it)
//	{
//		return _node != it._node;
//	}
//};


template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	//const对象不能调用非const成员函数，只能调用const成员函数，
	//但是const成员函数operator++， operator--，就不能修改成员_node的值，
	//导致const迭代器无法执行++，--操作,故如下定义const迭代器不行
	//typedef const ListIterator<T> const_iterator;
	// *it  ->
	typedef ListIterator<T, const T&, const T*> const_iterator;
	List(const T& val = T())
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	List(const List<T>& lst)
	{
		//首先创建头指针
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//拷贝每一个节点,迭代器从头开始遍历每一个节点
		//插入到当前list对象中去
		for (const auto& e : lst)
		{
			PushBack(e);
		}
	}

	//传统写法
	//List<T>& operator=(const List<T>& lst)
	//{
	//	if (this != &lst)
	//	{
	//		//释放原有节点
	//		Clear();
	//		for (const auto& e : lst)
	//		{
	//			PushBack(e);
	//		}
	//	}
	//	return *this;
	//}
	//现代写法
	list<T>& operator=(List<T> lst)
	{
		swap(_head, lst._head);
		return *this;
	}

	void PushBack(const T& val)
	{
		/*pNode curNode = new Node(val);
		pNode prev = _head->_prev;
		prev->_next = curNode;
		curNode->_prev = prev;
		curNode->_next = _head;
		_head->_prev = curNode;*/
		Insert(end(), val);
	}
	void PushFront(const T& val)
	{
		Insert(begin(), val);
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const 
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	void Insert(iterator pos, const T& val)
	{
		pNode newnode = new Node(val);
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}

	void PopFront()
	{
		Erase(begin());
	}

	void PopBack()
	{
		Erase(--end());
	}

	void Clear()
	{
		if (_head)
		{
			pNode cur = _head->_next;
			while (cur != _head)
			{
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
	}



	//Erase： 迭代器失效
	//获取Erase的返回值(当前被删除的节点的下一个位置)，更新迭代器
	iterator Erase(iterator pos)
	{
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			//更新迭代器,指向下一个位置
			pos = iterator(next);
		}
		return pos;
	}

	~List()
	{
		Clear();
		if (_head)
		{
			delete _head;
			_head = nullptr;
		}

	}


private:
	pNode _head;
};


class Date
{
public:
	int _year;
	int _month;
	int _day;
};

```

