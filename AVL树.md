### 4.2AVL树

#### 4.2.1 AVL树的概念 

> 二叉搜索树虽可以缩短查找的效率，但如果**数据有序或接近有序二叉搜索树将退化为单支树，查找元素相当 于在顺序表中搜索元素，效率低下。**解决上述问题的方法：当向二叉搜索树中插入新结点后，如果能保证每个结点的左右子树高度之 差的绝对值不超过1(需要对树中的结点进行调整)，即可降低树的高度，从而减少平均搜索长度。 
>
> 一棵AVL树或者是空树，或者是具有以下性质的二叉搜索树： 
>
> - **它的左右子树都是AVL树** 
> - **左右子树高度之差(简称平衡因子)的绝对值不超过1(-1/0/1)**
>
> 如果一棵二叉搜索树是高度平衡的，它就是AVL树。如果它有n个结点，其高度可保持在 O(log2n)，
>
> 搜索时间复杂度  O(log2n)，

#### 4.2.2 AVL树节点的定义 

```cpp
template<class T>
struct AVLTreeNode
 {
AVLTreeNode(const T& data)
 : _pLeft(nullptr)
 , _pRight(nullptr)
 , _pParent(nullptr)
 , _data(data)
 , _bf(0)
 {}
AVLTreeNode<T>* _pLeft; // 该节点的左孩子
AVLTreeNode<T>* _pRight; // 该节点的右孩子
AVLTreeNode<T>* _pParent; // 该节点的双亲
T _data;
int _bf; // 该节点的平衡因子
 };
```

#### 4.2.3 AVL树的插入

> 1. ##### 按照二叉搜索树的方式插入新节点 
>
> ```cpp
> bool Insert(const T& data)
> {
> // 1. 先按照二叉搜索树的规则将节点插入到AVL树中
> if (nullptr == _pRoot)
>  {
> _pRoot = new Node(data);
> return true;
>  }
> // 按照二叉搜索树的性质找data在AVL中的插入位置
> PNode pCur = _pRoot;
> PNode pParent = nullptr;
> while (pCur)
>  {
> pParent = pCur;
> if (data < pCur->_data)
> pCur = pCur->_pLeft;
> else if (data > pCur->_data)
> pCur = pCur->_data;
> else
> return false; // 该节点在二叉搜索树中存在
>  }
> // 插入新节点：新节点一定插入在pParent的左侧或者右侧
> if (data < pParent->_data)
> pParent->_pLeft = pCur;
> else
> pParent->_pRight = pCur;
> // 更新pCur的双亲节点
> pCur->_pParent = pParent;
> // 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，此时就需要更新平衡因子，并检测是否破坏了AVL树的平衡性
> //...
> return true; }
> ```
>
> 2. ##### 调整节点的平衡因子 
>
> ```cpp
> bool Insert(const T& data) {
> // 1. 先按照二叉搜索树的规则将节点插入到AVL树中
> // ...
> // 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，此时就需要更新平衡因子，并检测是否破坏了AVL树
> // 的平衡性
> /*
> pCur插入后，pParent的平衡因子一定需要调整，在插入之前，pParent
> 的平衡因子分为三种情况：-1，0, 1, 分以下两种情况：
> 比特科技
> 1. 如果pCur插入到pParent的左侧，只需给pParent的平衡因子-1即可
> 2. 如果pCur插入到pParent的右侧，只需给pParent的平衡因子+1即可
> 此时：pParent的平衡因子可能有三种情况：0，正负1， 正负2
> 1. 如果pParent的平衡因子为0，说明插入之前pParent的平衡因子为正负1，插入后被调整成0，此时满
> 足
> AVL树的性质，插入成功
> 2. 如果pParent的平衡因子为正负1，说明插入前pParent的平衡因子一定为0，插入后被更新成正负1， 此
> 时以pParent为根的树的高度增加，需要继续向上更新
> 3. 如果pParent的平衡因子为正负2，则pParent的平衡因子违反平衡树的性质，需要对其进行旋转处理
> */
> while (pParent)
>  {
> // 更新双亲的平衡因子
> if (pCur == pParent->_pLeft)
> pParent->_bf--;
> else
> pParent->_bf++;
> // 更新后检测双亲的平衡因子
> if (0 == pParent->_bf)
> break;
> else if (1 == pParent->_bf || -1 == pParent->_bf)
>  {
> // 插入前双亲的平衡因子是0，插入后双亲的平衡因为为1 或者 -1 ，说明以双亲为根的二叉
> 树
> // 的高度增加了一层，因此需要继续向上调整
> pCur = pParent;
> pParent = pCur->_pParent;
>  }
> else
>  {
> // 双亲的平衡因子为正负2，违反了AVL树的平衡性，需要对以pParent
> // 为根的树进行旋转处理
> if(2 == pParent->_bf)
>  {
> // ...
>  }
> else
>  {
> // ...
>  }
>  }
>  }
> return true; }
> ```
>
> #### 4.2.3 AVL树的旋转 
>
> 如果在一棵原本是平衡的AVL树中插入一个新节点，可能造成不平衡，此时必须调整树的结构，使之平衡 
>
> 化。根据节点插入位置的不同，AVL树的旋转分为四种： 
>
> 1. ##### 新节点插入较高左子树的左侧---左左：右单旋 
>
> ​    
>
>  
>
> ```cpp
> /*上图在插入前，AVL树是平衡的，新节点插入到30的左子树(注意：此处不是左孩子)中，30左子树增加
> 了一层，导致以60为根的二叉树不平衡，要让60平衡，只能将60左子树的高度减少一层，右子树增加一
> 层，即将左子树往上提，这样60转下来，因为60比30大，只能将其放在30的右子树，而如果30有右子树，右
> 子树根的值一定大于30，小于60，只能将其放在60的左子树，旋转完成后，更新节点的平衡因子即可。在旋
> 转过程中，有以下几种情况需要考虑：
> 1. 30节点的右孩子可能存在，也可能不存在
> 2. 60可能是根节点，也可能是子树
> 如果是根节点，旋转完成后，要更新根节点
> 如果是子树，可能是某个节点的左子树，也可能是右子树
> */
> void _RotateR(PNode pParent) {
> 	// pSubL: pParent的左孩子
> 	// pSubLR: pParent左孩子的右孩子，注意：该
> 	PNode pSubL = pParent->_pLeft;
> 	PNode pSubLR = pSubL->_pRight;
> 	// 旋转完成之后，30的右孩子作为双亲的左孩子
> 	pParent->_pLeft = pSubLR;
> 	// 如果30的左孩子的右孩子存在，更新亲双亲
> 	if (pSubLR)
> 		pSubLR->_pParent = pParent;
> 	// 60 作为 30的右孩子
> 	pSubL->_pRight = pParent;
> 	// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
> 	PNode pPParent = pParent->_pParent;
> 	// 更新60的双亲
> 	pParent->_pParent = pSubL;
> 	// 更新30的双亲
> 	pSubL->_pParent = pPParent;
> 	// 如果60是根节点，根新指向根节点的指针
> 	if (NULL == pPParent)
> 	{
> 		_pRoot = pSubL;
> 		pSubL->_pParent = NULL;
> 	}
> 	else
> 	{
> 		// 如果60是子树，可能是其双亲的左子树，也可能是右子树
> 		if (pPParent->_pLeft == pParent)
> 			pPParent->_pLeft = pSubL;
> 		else
> 			pPParent->_pRight = pSubL;
> 	}
> 	// 根据调整后的结构更新部分节点的平衡因子
> 	pParent->_bf = pSubL->_bf = 0;
> }
> ```
>
> ##### 2.新节点插入较高右子树的右侧---右右：左左旋（参考右单旋）
>
> ​    
>
> ##### 3.新节点插入较高左子树的右侧---左右：先左单旋再右单旋 4
>
>  
>
>  
>
> 将双旋变成单旋后再旋转，即：先对30进行左单旋，然后再对90进行右单旋，旋转完成后再考虑平衡因 
>
> 子的更新。 
>
> ```cpp
> // 旋转之前，60的平衡因子可能是-1/0/1，旋转完成之后，根据情况对其他节点的平衡因子进行调整
> void _RotateLR(PNode pParent) {
> PNode pSubL = pParent->_pLeft;
> PNode pSubLR = pSubL->_pRight;
> // 旋转之前，保存pSubLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因
> 子
> int bf = pSubLR->_bf;
> // 先对30进行左单旋
> _RotateL(pParent->_pLeft);
> // 再对90进行右单旋
> _RotateR(pParent);
> if(1 == bf)
> pSubL->_bf = -1;
> else if(-1 == bf)
> pParent->_bf = 1; }
> ```
>
> 4. ##### 新节点插入较高右子树的左侧---右左：先右单旋再左单旋 （参考右左双旋）
>
>    #####   
>
> #### 总结：
>
> 假如以pParent为根的子树不平衡，即pParent的平衡因子为2或者-2，分以下情况考虑：
>
> 1.pParent的平衡因子为2，说明pParent的右子树高，设pParent的右子树的根为pSubR 
>
> > 当pSubR的平衡因子为1时，执行左单旋 
> >
> > 当pSubR的平衡因子为-1时，执行右左双旋 
>
> 2. pParent的平衡因子为-2，说明pParent的左子树高，设pParent的左子树的根为pSubL 
>
> > 当pSubL的平衡因子为-1是，执行右单旋 
> >
> > 当pSubL的平衡因子为1时，执行左右双旋 
>
> 旋转完成后，原pParent为根的子树个高度降低，已经平衡，不需要再向上更新。

### 4.2.4  AVL树的验证 

> AVL树是在二叉搜索树的基础上加入了平衡性的限制，因此要验证AVL树，可以分两步： 
>
> 1. 验证其为二叉搜索树 
>
>    如果中序遍历可得到一个有序的序列，就说明为二叉搜索树 
>
> 2. 验证其为平衡树 
>
> - 每个节点子树高度差的绝对值不超过1(注意节点中如果没有平衡因子) 
> - 节点的平衡因子是否计算正确
>
> ```cpp
> // 注意：此处需要验证两个内容：
> // 1. 每个节点的平衡因子是否计算正确(通过节点的子树高度差来与当前节点的平衡因子比较)
> // 2. 每个节点的平衡因子的绝对值是否超过1
> int _Height(PNode pRoot)
>  {
> if (nullptr == pRoot)
> return 0;
> // 计算pRoot左右子树的高度
> int leftHeight = _Height(pRoot->_pLeft);
> int rightHeight = _Height(pRoot->_pRight);
> // 返回左右子树中较高的子树高度+1
> return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
>  }
> bool _IsBalanceTree(PNode pRoot) {
> // 空树也是AVL树
> if (nullptr == pRoot)
> return true;
> // 计算pRoot节点的平衡因子：即pRoot左右子树的高度差
> int leftHeight = _Height(pRoot->_pLeft);
> int rightHeight = _Height(pRoot->_pRight);
> int diff = rightHeight - leftHeight;
> // 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
> // pRoot平衡因子的绝对值超过1，则一定不是AVL树
> if (diff != pRoot->_bf || (diff > 1 || diff < -1))
> return false;
> // pRoot的左和右如果都是AVL树，则该树一定是AVL树
> return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
>  }
> ```

#### 验证用例

常规场景1 

{16, 3, 7, 11, 9, 26, 18, 14, 15}





特殊场景2 

{4, 2, 6, 1, 3, 5, 15, 7, 16, 14}



### 4.2. AVL树的性能 

> AVL树是一棵绝对平衡的二叉搜索树，其要求每个节点的左右子树高度差的绝对值都不超过1，这样可以保证 
>
> 查询时高效的时间复杂度，即 log2(N)
>
> 但是如果要对AVL树做一些结构修改的操作，性能非常低下，比如： 插入时要维护其绝对平衡，旋转的次数比较多，更差的是在删除时，有可能一直要让旋转持续到根的位置。 因此：如果需要一种查询高效且有序的数据结构，而且数据的个数为静态的(即不会改变)，可以考虑AVL树， 但一个结构经常修改，就不太适合。 