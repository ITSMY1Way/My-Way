### 1.关联式容器 

> STL中的部分容器，比如：vector、list、deque、forward_list(C++11)等，这些容器统称为序列式容器，因为其底层为线性序列的数据结构，里面存储的是元素本身。
>
> **关联式容器**也是用来存储数据的，与序列式容器不同的是，其**里面存储的是<key, value>结构的键值对，在 数据检索时比序列式容器效率更高。** 

### 特点

> - STL 关联容器的底层数据结构是红黑树，故其增删查的时间复杂度都是 O(logn)
> - map 默认按照 key 的升序进行插入，非基本数据类型要求重载 < 运算符
> - map 重载了 [] 运算符，使的插入和查找非常方便
> - map 用 [] 运算符访问元素时，如果不存在这个key，key会自动插入，value为初始化值
> - map 的 key 对象使用之后就不要再修改，如果必须修改，需要删除后重新插入
> - multimap 的 key-value 是一对多，没有重载 [] 运算符

参考：<https://blog.csdn.net/thisinnocence/article/details/39646813> 

### 2.键值对 

> 用来表示具有一一对应关系的一种结构，**该结构中一般只包含两个成员变量key和value，key代表键值，** 
>
> **value表示与key对应的信息**。 

### 3.树形结构的关联式容器 

> 根据应用场景的不桶，STL总共实现了两种不同结构的管理式容器：树型结构与哈希结构。
>
> 树型结构的关联式容器主要有四种：map、set、multimap、multiset。
>
> 这四种容器的共同点是：使用平衡搜索树(即红黑树) 作为其底层结果，容器中的元素是一个有序的序列。

> - map 键值对 key-value 存储，key 不可重复，即一个 key 只能对应一个 value, 对应头文件 <map>
> - multimap 键值对 key-value 存储，key 可以重复，即一个 key 可以对应多个 value, 对应头文件 <map>
> - set 只有 key, key 不可重复，对应头文件<set>
> - multiset 只有 key, key 可以重复，对应头文件<set>

### 3.1map

> 1. map是关联容器，它按照特定的次序(按照key来比较)存储由键值key和值value组合而成的元素。 
>
> 2. 在map中，键值key通常用于排序和惟一地标识元素，而值value中存储与此键值key关联的内容。键值 key和值value的类型可能不同，并且在map的内部，key与value通过成员类型value_type绑定在一起， 为其取别名称为pair: 
>
>    typedef pair value_type; 
>
> 3. 在内部，map中的元素总是按照键值key进行比较排序的。 
>
> 4. map中通过键值访问单个元素的速度通常比unordered_map容器慢，但map允许根据顺序对元素进行 直接迭代(即对map中的元素进行迭代时，可以得到一个有序的序列)。 
>
> 5. map支持下标访问符，即在[]中放入key，就可以找到与key对应的value。 
>
> 6. map通常被实现为二叉搜索树(更准确的说：平衡二叉搜索树(红黑树))。 

https://my.oschina.net/OkamiLiu/blog/1560034 

#### map的模板参数说明

> key: 键值对中key的类型 
>
> T： 键值对中value的类型 
>
> Compare: 比较器的类型，map中的元素是按照key来比较的，缺省情况下按照小于来比较，一般情况 
>
> 下(内置类型元素)该参数不需要传递，如果无法比较时(自定义类型)，需要用户自己显式传递比较规则 
>
> (一般情况下按照函数指针或者仿函数来传递) 
>
> Alloc：通过空间配置器来申请底层空间，不需要用户传递，除非用户不想使用标准库提供的空间配置器 
>
> 注意：在使用map时，需要包含头文件。
>
> ```cpp
> #include <iostream>
> #include <string>
> #include <map>
> using namespace std;
> int main()
> {
> 	map<string, string> m{
> 		{ "apple", "苹果" },
> 		{ "banan", "香蕉" },
> 		{ "orange", "橘子" },
> 		{ "peach", "桃子" },
> 		{ "waterme", "水蜜桃" } };
> 	for (auto it = m.begin(); it != m.end(); ++it)
> 		cout << (*it).first << "--->" << it->second << endl;
> 	cout << endl;
> 	getchar();
> 	return 0;
> }
> ```

#### map元素的容量与访问

| 函数声明                       | 功能简介                                           |
| ------------------------------ | -------------------------------------------------- |
| bool empty ( ) const           | 检测map中的元素是否为空，是返回true，否则返回false |
| size_type size() const         | 返回map中有效元素的个数                            |
| mapped_type& operator[] (const | 返回去key对应的value                               |

```cpp
//在元素访问时，有一个与operator[]类似的操作at()(该函数不常用)函数，都是通过key找到与key对应的value然后返回其引用，
//不同的是：当key不存在时，operator[]用默认value与key构造键值对然后插入，返回该默认value，at()函数直接抛异常。
#include <string>
#include <map>
void TestMap()
{
// 构造一个空的map，此时m中一个元素都没有
map<string, string> m;
/*
operator[]的原理是：
用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中
如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器
如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器
operator[]函数最后将insert返回值键值对中的value返回
*/
// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，
// 即修改与"apple"对应的value""为"苹果" m["apple"] = "苹果";
// 将<"apple", "">插入map中，插入失败，将<"apple", "苹果">中的"苹果"返回
cout << m["apple"] << endl; 
cout << m.size() << endl;
// “banan不在map中，该函数抛异常” m.at("banan");
}
```

```cpp
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	map<string, string> m;
	// 向map中插入元素的方式：
	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
	m.insert(pair<string, string>("peach", "桃子"));
	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
		m.insert(make_pair("banan", "香蕉"));
	// 借用operator[]向map中插入元素
	m["apple"] = "苹果";
	// key不存在时抛异常
	//m.at("waterme") = "水蜜桃";
	m.insert(m.find("banan"), make_pair("waterme", "水蜜桃"));
	cout << m.size() << endl;
	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
		ret.first->second << " 插入失败" << endl;
	// 删除key为"apple"的元素
	m.erase("apple");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
	getchar();
	return 0;
}
```

### 3.2multimap 

> 1. Multimaps是关联式容器，它按照特定的顺序，存储由key和value映射成的键值对<key, value>，其中 多个键值对之间的key是可以重复的。 
>
> 2. 在multimap中，通常按照key排序和惟一地标识元素，而映射的value存储与key关联的内容。key和 value的类型可能不同，通过multimap内部的成员类型value_type组合在一起，value_type是组合key 和value的键值对: 
>
>    `typedef pair<const Key, T> value_type;` 
>
> 3. 在内部，multimap中的元素总是通过其内部比较对象，按照指定的特定严格弱排序标准对key进行排序 的。 
>
> 4. multimap通过key访问单个元素的速度通常比unordered_multimap容器慢，但是使用迭代器直接遍历 multimap中的元素可以得到关于key有序的序列。 
>
> 5. multimap在底层用二叉搜索树(红黑树)来实现。 
>
> **注意：multimap和map的唯一不同就是：map中的key是唯一的，而multimap中key是可以重复的。**

#### multimap的使用

> 1. multimap中的key是可以重复的。 
> 2. multimap中的元素默认将key按照小于来比较 
> 3. multimap中没有重载operator[]操作
> 4. 使用时与map包含的头文件相同： 

### 3.3set

> 1. set是按照一定次序存储元素的容器比特科技 
> 2. 在set中，元素的value也标识它(value就是key，类型为T)，并且每个value必须是唯一的。set中的元素 不能在容器中修改(元素总是const)，但是可以从容器中插入或删除它们。 
> 3. 在内部，set中的元素总是按照其内部比较对象(类型比较)所指示的特定严格弱排序准则进行排序。 
> 4. set容器通过key访问单个元素的速度通常比unordered_set容器慢，但它们允许根据顺序对子集进行直 接迭代。 
> 5. set在底层是用二叉搜索树(红黑树)实现的。 
>
> 注意： 
>
> 1. 与map/multimap不同，map/multimap中存储的是真正的键值对<key, value>，set中只放value，但在底层实际存放的是由<value, value>构成的键值对。 
> 2. set中插入元素时，只需要插入value即可，不需要构造键值对。 
> 3. set中的元素不可以重复(因此可以使用set进行去重)。 
> 4. 使用set的迭代器遍历set中的元素，可以得到有序序列 
> 5. set中的元素默认按照小于来比较 
> 6. set中查找某个元素，时间复杂度为： `log2n`
> 7. set中的元素不允许修改   为什么
> 8. set中的底层使用二叉搜索树(红黑树)来实现。 
>
> std::set的特点是: 
>
> 1. set是一个有序的、可以前向和后向遍历的容器（双向迭代器）； 
> 2. set是一个元素类型和比较函数可以配置的容器，但是一经配置，就不可更改； 
>
>    **4. set的元素可以插入、删除，但是不可更改。** 

#### set的模板参数列表 

> T: set中存放元素的类型，实际在底层存储<value, value>的键值对。 
>
> Compare：set中元素默认按照小于来比较 
>
> Alloc：set中元素空间的管理方式，使用STL提供的空间配置器管理

#### set的应用

```cpp
#include <string>
#include <iostream>
using namespace std;
int main()
{
	// 用数组array中的元素构造set
	int array[] = { 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(int));
	cout << s.size() << endl;
	// 正向打印set中的元素，从打印结果中可以看出：set可去重
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	// 使用迭代器逆向打印set中的元素
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set中值为3的元素出现了几次
	cout << s.count(3) << endl;
	getchar();
	return 0;
}
```

### 3.4 multiset 

> 1. multiset是按照特定顺序存储元素的容器，其中元素是可以重复的。 
> 2. 在multiset中，元素的value也会识别它(因为multiset中本身存储的就是<value, value>组成的键值对， 因此value本身就是key，key就是value，类型为T). multiset元素的值不能在容器中进行修改(因为元素 总是const的)，但可以从容器中插入或删除。 
> 3. 在内部，multiset中的元素总是按照其内部比较规则(类型比较)所指示的特定严格弱排序准则进行排 序。 
> 4. multiset容器通过key访问单个元素的速度通常比unordered_multiset容器慢，但当使用迭代器遍历时 会得到一个有序序列。 
> 5. multiset底层结构为二叉搜索树(红黑树)。 
>
> 注意： 
>
> 1. multiset中再底层中存储的是<value, value>的键值对 
> 2. mtltiset的插入接口中只需要插入即可 
> 3. 与set的区别是，multiset中的元素可以重复，set是中value是唯一的
> 4. 使用迭代器对multiset中的元素进行遍历，可以得到有序的序列 
> 5. multiset中的元素不能修改 
> 6. 在multiset中找某个元素，时间复杂度为  O(log2N)
> 7. multiset的作用：可以对元素进行排序
>
> ```cpp
> void TestSet()
> {
> int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
> // 注意：multiset在底层实际存储的是<int, int>的键值对
> multiset<int> s(array, array + sizeof(array)/sizeof(array[0]));
> for (auto& e : s)
> cout << e << " ";
> cout << endl;
> // 测试multiset中是否可以存储值相同的元素
> s.insert(5);
> cout << s.count(5) << endl;
> for (auto& e : s)
> cout << e << " ";
> cout << endl;
> // 删除所有值为5的元素
> s.erase(5);
> for (auto& e : s)
> cout << e << " ";
> cout << endl;
> return 0; }
> ```

### 4.1二叉搜索树

#### 概念

> 二叉搜索树又称二叉排序树，它或者是一棵空树，或者是具有以下性质的二叉树: 
>
> - 若它的左子树不为空，则左子树上所有节点的值都小于根节点的值 
> - 若它的右子树不为空，则右子树上所有节点的值都大于根节点的值 
> - 它的左右子树也分别为二叉搜索树 
> - **二叉搜索树的中序遍历是一个有序的。** 

#### 二叉搜索树操作

> #### 1.查找
>
> a.若根节点不为空：
>
> - ​    如果根节点key == 查找key 返回ture
> - ​    如果根节点key  >  查找key 在其左子树查找
> - ​    如果根节点key  <  查找key 在其左子树查找
>
> b.否则 返回false
>
> 搜索任意一个结点的时间复杂度是 O(Log2 N); 
>
> #### 2.插入
>
> a. 树为空，则直接插入 
>
> b. 树不空，按二叉搜索树性质查找插入位置，插入新节点 
>
> #### 3.删除
>
> 首先查找元素是否在二叉搜索树中，如果不存在，则返回；
>
> 否则要删除的结点可能分下面四种情况： 
>
> > a. 要删除的结点无孩子结点 
> >
> > b. 要删除的结点只有左孩子结点 
> >
> > c. 要删除的结点只有右孩子结点 
> >
> > d. 要删除的结点有左、右孩子结点 
>
> 看起来有待删除节点有4中情况，实际情况a可以与情况b或者c合并起来，因此真正的删除过程如下： 
>
> - 情况b：删除该结点且使被删除节点的双亲结点指向被删除节点的左孩子结点 
> - 情况c：删除该结点且使被删除节点的双亲结点指向被删除结点的右孩子结点 
> - 情况d：在它的右子树中寻找中序下的第一个结点(关键码最小)，用它的值填补到被删除节点中， 再来处理该结点的删除问题 

#### 二叉搜索树的实现

```cpp
template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	:_val(val),
	_left(nullptr),
	_right(nullptr)
	{}
	T _val;
	BSTNode<T>* _left;
	BSTNode<T>* _right;
};
template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;
	BSTree(const pNode root = nullptr)
		:_root(root)
	{}
	pNode Find(const T& val)
	{
		if (_root == nullptr)
			return nullptr;
		pNode cur = _root;
		while (cur)
		{
			if (cur->_val == val)
				return cur;
			else if (cur->_val > val)
				cur = cur->_left;
			else if (cur->_val < val)
				cur = cur->_right;
		}
		return nullptr;
	}
	bool Insert(const T& val)
	{
        //如果树为空，直接插入
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
        // 按照二叉搜索树的性质查找val在树中的插入位置
		pNode cur = _root;
        // 记录pCur的双亲，因为新元素最终插入在pCur双亲左右孩子的位置
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val > val)
				cur = cur->_left;
			else if (cur->_val < val)
				cur = cur->_right;// 元素已经在树中存在
			else
				return false;
		}
        //插入元素
		pNode newNode = new Node(val);
		if (parent->_val > val)
			parent->_left = newNode;
		else
			parent->_right = newNode;
		return true;
	}
	bool Erase(const T& val)
	{   
        // 如果树为空，删除失败 
		if (_root == nullptr)
			return false;
         // 查找在data在树中的位置
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_val == val)
				break;
			else if (cur->_val > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_val < val)
			{
				parent = cur;
				cur = cur->_right;
			}
		}
        // 当前节点只有左孩子或者左孩子为空---可直接删除
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			else
				_root = nullptr;
			delete cur;
			cur = nullptr;
		}
// 当前节点左右孩子都存在，直接删除不好删除，可以在其子树中找一个替代结点，比如：
// 找其左子树中的最大节点，即左子树中最右侧的节点，或者在其右子树中最小的节点，即右子树中最左的节点
// 替代节点找到后，将替代节点中的值交给待删除节点，转换成删除替代节点
		else if (cur->_left == nullptr && cur->_right != nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else if (parent->_right == cur)
					parent->_right = cur->_right;
			}
			else
				_root = _root->_right;
			delete cur;
			cur = nullptr;
		}
		else if (cur->_left != nullptr && cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else if (parent->_right == cur)
					parent->_right = cur->_left;
			}
			else
				_root = _root->_left;
			delete cur;
			cur = nullptr;
		}
		else
		{
			pNode exchange = cur;
			if (cur == _root)
				cur = cur->_left;
			pNode newNode = cur;
			pNode nParent = nullptr;
			while (newNode)
			{
				if (newNode->_right)
				{
					nParent = newNode;
					newNode = newNode->_right;
				}
				else
					break;
			}
			if (nParent == nullptr)
				exchange->_left = newNode->_left;
			exchange->_val = newNode->_val;
			if (nParent)
				nParent->_right = nullptr;
			delete newNode;
			newNode = nullptr;
		}
		return true;
	}
	void Inorder(void)
	{
		_Inorder(_root);
		std::cout << std::endl;
	}
private:
	void _Inorder(const pNode root)
	{
		if (root)
		{
			_Inorder(root->_left);
			std::cout << root->_val << " ";
			_Inorder(root->_right);
		}
	}
	pNode _root;
};
```

#### 4.1.3 二叉数的性能分析 

> 插入和删除操作都必须先查找，查找效率代表了二叉搜索树中各个操作的性能。 
>
> 对有n个结点的二叉搜索树，若每个元素查找的概率相等，则二叉搜索树平均查找长度是结点在二叉搜索树的 深度的函数，即结点越深，则比较次数越多。 
>
> 但对于同一个关键码集合，如果各关键码插入的次序不同，可能得到不同结构的二叉搜索树：





> 最优情况下，二叉搜索树为完全二叉树，其平均比较次数为：log 2N
>
> 最差情况下，二叉搜索树退化为单支树，其平均比较次数为： N/2.
>
> 这个时候再去搜索任何一个结点的时间复杂度就又变成了 O(N)。 

<https://blog.csdn.net/weixin_42678507/article/details/90703826> 

