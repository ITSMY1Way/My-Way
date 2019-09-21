## 01.二维数组的查找

> 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该数。

```cpp
//分析：时间复杂度 O(m+n)，m 和 n 分别是行数和列数。空间复杂度 O(1)。 思想是从右上角开始判断，每次判断可以排除一行或一列。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();//行数
        if(row==0) return false;
        int col = array[0].size();
        if(col==0) return false;
        
        int i=0, j=col-1;//从右上角开始
        while(i<row && j>=0)
        {
            if(target==array[i][j])
                return true;
            else if (target>array[i][j]) i++;//往下走一行
            else j--;//向前走一列
        }
        if(i == row||j < 0)
            return false;//没找到
        return true;//执行不到，为了编译通过
    }
};
```

## 02.替换空格 

> 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为 We Are Happy. 则经过替换之后的字符串为 We%20Are%20Happy。

```cpp
//length 为牛客系统规定字符串输出的最大长度，固定为一个常数
//分析：时间复杂度 O(N)，N 为字符串长度。 思想是先遍历一次得到字符串的长度和空格个数，计算出替换后的字符串长度，这样会在原字符串后面空出一段；然后从后往前，碰到空格就替换。 
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count=0;
        for(int i=0;i<length;i++){
            if(str[i]==' ')
                count++;
        }
        for(int i=length-1;i>=0;i--){
            if(str[i]!=' '){
                str[i+2*count]=str[i];
            }
            else{
                count--;
                str[i+2*count]='%';
                str[i+2*count+1]='2';
                str[i+2*count+2]='0';
            }
        }
    }
};
//
class Solution {
public:
    void replaceSpace(char *str,int n) {
        string s = str;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s.replace(i, 1, "%20");//在位置i处（空白处）往后将1个字符(空格)替换为"%20"
            }
        }
        strcpy(str, s.c_str());
    }
};
```

##  03.从尾到头打印链表 

> 输入一个链表，从尾到头打印链表每个节点的值。

```cpp
//分析：递归，时间复杂度 O(N)，N 为链表长度。因为要返回一个 vector，所以必须另外写个函数，以便把 vector作为参数
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        print(head,vec);
        return vec;
    }
    void print(ListNode* head , vector<int> &vec)
    {
        if(head == NULL) return;
        print(head->next, vec);
        vec.push_back(head->val);
    }
};
```

## 04.重建二叉树

> 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中 序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列 {4,7,2,1,5,3,8,6}，则重建二叉树并返回。

```cpp
// 前序遍历中，第一个数字是二叉树的根节点
// 中序遍历中，根节点的左侧是左子树的节点，根节点的右侧是右子树的节点。
//时间复杂度O(logn)，空间复杂度n/2
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return nullptr;
        // 建立根节点
        TreeNode* head = new TreeNode(pre[0]);
        // 查找中序遍历中根节点的索引值
        int root = 0;
        for(int i = 0;i<vin.size();++i)
        {
            if(vin[i] == pre[0])
            {
                root = i;
                break;
            }
        }
        // 先序遍历和中序遍历的左右子树vector
        vector<int> pre_left,pre_right,vin_left,vin_right;
        for(int i =0;i<root;++i)
        {
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);
        }    
        for(int i = root+1;i<pre.size();++i)
        {
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);
        }   
        // 根节点的左右节点
        head->left = reConstructBinaryTree(pre_left,vin_left);
        head->right = reConstructBinaryTree(pre_right,vin_right);   
        return head;
    }
};
```

## 05.用两个栈实现队列 

> 用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。 队列中的元素为 int 类型。

```cpp
//分析：push 时间复杂度为 O(1)，pop 时间复杂度为 O(n)。需要注意的是栈的操作 push、pop （并不返回元素）、top、empty。
class Solution
{
public:
    void push(int node) {
        stack1.push(node);//尾插，一会头删要删该元素
    }

    int pop() {
        while(!stack1.empty())//栈1不为空
        {
            stack2.push(stack1.top());
            stack1.pop();//把栈1的元素倒到栈2里面(反向)
        }
        int ret = stack2.top();
        stack2.pop();//pop掉了要处理的元素(stack1的最后一个元素)
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ret;//返回被pop的元素
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

## 06.旋转数组的最小数字 

> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
>
> 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。 
>
> 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为 1。 
>
> NOTE：给出的所有元素都大于 0，若数组大小为 0，请返回 0。 

```cpp
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if (size==0) return 0;
        int min = rotateArray[0];
        for(int i = 1;i< size; i++)
            if(min > rotateArray[i]) min = rotateArray[i];
        return min;
    }
};
```

## 07.斐波那契数列

> 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 n<=39

```cpp
//1）拒绝用递归，因为会导致大量的重复计算。 
//2）初始条件为 f(0)=0,f(1)=1,f(2)=1，递推公式 f(n)=f(n-1)+f(n-2),n>2
//动态规划版
class Solution {
public:
    int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n-- > 0) {
            g += f;
            f = g - f;
        }
        return f;
    }
};
```

## 08.跳台阶  

> 一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多 少种跳法。 

```cpp
//① 递归
//对于第n个台阶来说，只能从n-1或者n-2的台阶跳上来，所以 F(n) = F(n-1) + F(n-2)
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0)
            return 0;
        else if(number == 1)
            return 1;
        else if(number == 2)
            return 2;
        else
            return jumpFloor(number-1) + jumpFloor(number-2);
    }
};
//② 迭代
class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1 || number == 2 ) return number;
        int res1=1, res2=2, resN=0;
        for(int i = 3 ; i<= number; i++)
            {
                resN = res1+res2;
                res1 = res2;
                res2 = resN;
            }
        return resN;
    }
};
//③ 动态规划
class Solution {//动态规划
public:
    int jumpFloor(int number) {
        int res1 =1,res2 = 1;
        while(number--){
            res2+=res1;
            res1 =res2 - res1;
        }
        return res1;
    } 
};
```

## 09.变态跳台阶 

> 一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级……它也可以跳上 n 级。求该青蛙跳上一 个 n 级的台阶总共有多少种跳法 、

```cpp
//常规解法
class Solution {
public:
    int jumpFloorII(int number) {
        int *a=new int[number+1];
        a[0]=1;
        a[1]=1;
        for(int i=2;i<=number;i++){
            a[i]=0;
            for(int j=i-1;j>=0;j--){
                a[i]+=a[j];
            }
        }
        return a[number];
    }
};
//递归
//f(1)=1  f(2)=2  f(3)=f(2)+f(1)+1=4  f(n)=2*f(n-1)
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
            return -1;
        else if (number ==1)
            return 1;
        else 
            return 2*jumpFloorII(number-1);
    }
};
//更快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快快
class Solution {
public:
    int jumpFloorII(int number) {
        int a=1; 
        return a<<(number-1);
    }
};
```

## 10.矩形覆盖

> 我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 

```cpp
//递推公式 f(n)=f(n-1)+f(n-2)，f(1)=1,f(2)=2
//递归写烦了，，，，，，
public class Solution {
    public int RectCover(int target) {
        if (target <= 2){
            return target;
        }
        int pre1 = 2; // n 最后使用一块，剩下 n-1 块的写法
        int pre2 = 1; // n 最后使用两块，剩下 n-2 块的写法
        for (int i = 3; i <= target; i++){
            int cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1; //相对于 n+1 块来说，第 n 种的方法
    }
}
//动态规划
class Solution {
public:
    int rectCover(int number) {
        if(number<=0) return 0;
        int tmp =1;
        int ret =1;
        for(int i = 2;i<=number;i++)
        {
            ret += tmp;
            tmp = ret - tmp;
        }
        return ret;
    }
};
```

## 11.二进制中 1 的个数 

> 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。 

```cpp
//常规解法，有符号整数右移（算术右移）是最高位补符号位的，比如 -1 >> 1 其实是 -1，转成unsigned int 就可以了。
class Solution {
public:
     int  NumberOf1(int n) {
         for(unsigned int r = 0, m = n; ; r += m & 1, m >>= 1) if(m == 0) return r;
     }
};
//n &= (n-1)  每执行一次，可以消去二进制中的一个 1。
class Solution {
public:
     int  NumberOf1(int n) {
         int sum = 0;
         while(n){
             sum++;
             n &= (n-1);
//n -= n& -n;
//n&(-n)在树状数组中lowbit出现 用来求 t 中的因子中形如2^k的数为多少
             //用来取得n最右边的1，可以知道其因子中有几个2
//10:  0000 1010
//-10: 1111 0110
//10&(-10)为 0010  =  2  所以10的因子中为2的有一个，2^k的形式的为2^1
//8&(-8) = [1000] = 8   所以8的因子中为2的有3个，2^k的形式为2^3
         }
            return sum;
     }
};
```

## 12.数值的整数次方

> 给定一个 double 类型的浮点数 base 和 int 类型的整数 exponent。求 base 的 exponent 次 方。
>
> 保证base和exponent不同时为0 

```cpp
//常规解法，把所有的情况考虑在内
class Solution {
public:
    double Power(double base, int exp) {
    if(base==0){
        if(exp > 0) return 0;
        else if(exp==0) return 0;
        else throw invalid_argument("Invalid input!");
    }else{
        if(exp>0) return power(base,exp);
        else if(exp==0) return 1;
        else return 1 / power(base, -exp);
    }
    }
    double power(double base, int exp) {//计算平方
        if(exp == 1) return base;
        if((exp & 1)==0){
            int tmp = power(base, exp>>1);
            return tmp * tmp;
        }else{
            int tmp = power(base,(exp-1) >> 1);
            return tmp * tmp * base;
        }
    }
};
//简单快速幂
class Solution {
public:
    double Power(double base, int exp) {
        long long p =abs((long long)exp);
        double r =1.0;
        while(p){
            if(p & 1) r*=base;
            base *= base;
            p >>= 1;
        }
        return exp < 0? 1/r : r;
    }
};
```

## 13.调整数组顺序使奇数位于偶数前面 

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的 前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相 对位置不变。

```cpp
//用一个新的vector按顺序放进去，然后对应的一一赋值即可，时间复杂度为O(n)，空间复杂度也是O(n)
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector <int> my_array;
        for(auto i : array)
        {
            if(i %2 == 1)
               my_array.push_back(i);
        }
        for(auto i : array)
        {
            if(i %2 == 0)
               my_array.push_back(i);
        }
        array = my_array;
    }
};
//遍历过去，遇到偶数，则在数组的最后面加上一个这个偶数，并且删去原来的那个偶数，这样做空间复杂度为O(1)，时间复杂度为O(n)
class Solution 
{
public:
    void reOrderArray(vector<int>& array) 
    {
        int len = array.size();
        int count = 0;     
        for (int i = 0; i < len; i++)
        {
            if (array[i] % 2 == 0)
                count++;
        }    
        int ptr = 0;
        while (count != 0)
        {
            if (array[ptr] % 2 == 0)
            {
                array.push_back(array[ptr]);
                array.erase(array.begin() + ptr);
                count--;
            }
            else
                ptr++;
        }
        return;
    }
};
```

## 14.链表中倒数第 k 个结点 

> 输入一个链表，输出该链表中倒数第 k 个结点。 

```cpp
//分析：时间复杂度 O(n)，n 为节点个数。 思路：先让一个指针走 k-1 步，然后另一个指针从头开始，两个指针同步向后走，当第一个 指针走到最后一个节点时，第二个指针正好是倒数第 k 个节点。 注意一下几个地方： 
//1）链表为空；   2）k 为 0      3）链表长度小于 k； 
//4）当第一个指针到达最后一个节点时，而不是指向空时，第二个指针才指向倒数第 k 个节 点。
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k == 0 || pListHead==NULL) return NULL;
        ListNode* p = pListHead;//定义头节点
        int i = 1;
        while(i++ < k)
        {
            p = p->next;
            if(NULL==p) return NULL;//防止链表长度小于k
        }
        ListNode* node = pListHead;//走到了k第二个开始走
        while(p->next)//为空的时候,p指向最后一个节点
        {
            node = node->next;
            p = p->next;
        }
        return node;
    }
};
```

## 15.反转链表

> 输入一个链表，反转链表后，输出链表的所有元素。

```cpp
//递归实现。精髓在于如何返回头结点（原来的尾节点）：一旦找到尾节点，就一直返回它，不让它参与任何操作。
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(NULL == pHead) return NULL;//没有节点
        if(pHead->next==NULL) return pHead;//只有一个节点的情况 or 遍历到了最后一个节点，它就是头
        ListNode* head = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = NULL;
        return head;
    }
};
```

## 16.合并两个排序的链表 

> 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

```cpp
//递归
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* node=NULL;
        if(pHead1==NULL){return node=pHead2;}
        if(pHead2==NULL){return node=pHead1;}
        if(pHead1->val>pHead2->val){
            node=pHead2;
            node->next=Merge(pHead1,pHead2->next);
        }else
            {
            node=pHead1;
            node->next=Merge(pHead1->next,pHead2);
        }
        return node;       
    }   
};
```

## 17.树的子结构 

> 输入两颗二叉树 A，B，判断 B 是不是 A 的子结构。

```cpp
//递归
class Solution {
public:
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==NULL) return true;//注意这里先要判断pRoot2，否则不会执行这条
        if(pRoot1==NULL) return false;
        if(pRoot1->val == pRoot2->val)
        return isSubtree(pRoot1->left,pRoot2->left) &&
            isSubtree(pRoot1->right,pRoot2->right);
        else 
            return false;
    }
        
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        return isSubtree(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2)
           || HasSubtree(pRoot1->right,pRoot2);
    }
};
```

## 18.二叉树的镜像

> 操作给定的二叉树，将其变换为源二叉树的镜像。 

```cpp
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        TreeNode* node = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = node;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
```

## 19.顺时针打印矩阵 

> 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩 阵 ： 
>
> 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16     
>
> 则 依 次 打 印 出 数 字 
>
> 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10. 

```cpp
//顺时针打印就是按圈数循环打印，一圈包含两行或者两列，在打印的时候会出现某一圈中只包含一行，要判断从左向右打印和从右向左打印的时候是否会出现重复打印，同样只包含一列时，要判断从上向下打印和从下向上打印的时候是否会出现重复打印的情况
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        int row=matrix.size();//行数
        int collor=matrix[0].size();//列数
        //计算打印的圈数
        int circle=((row<collor?row:collor)-1)/2+1;//圈数
        for(int i=0;i<circle;i++){
            //从左向右打印
            for(int j=i;j<collor-i;j++)
                res.push_back(matrix[i][j]);         
            //从上往下的每一列数据
            for(int k=i+1;k<row-i;k++)
                res.push_back(matrix[k][collor-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            //row-i-1 是当前圈的最后一行，i 是当前圈第一行，如果 row-i-1 = i 说明只有一行则会出现重复
            for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--)
                res.push_back(matrix[row-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--)
                res.push_back(matrix[n][i]);}
        return res;
    }
};
```

### 20.包含 min 函数的栈 

> 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的 min 函数。

```cpp
//用一个 vector 来保存元素，当获取最小值时，遍历 vector 获得最小值，时间复杂度为 O(N),N为栈中元素个数。
class Solution {
    vector<int> vec; 
public: 
	void push(int value) { 
        vec.push_back(value); 
    }
	void pop() { 
        vec.pop_back(); 
    }
	int top() { 
        return vec.at(vec.size() - 1); 
    }
	int min() { 
        int size = vec.size(); 
        if (size == 1)
        return vec.at(0); 
	int min = vec.at(0); 
        for (int i = 1; i<size; i++) 
            if (vec.at(i)<min) 
                min = vec.at(i); 
        return min; 
    }
};
```

## 21.栈的压入、弹出序列 

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列 1,2,3,4,5 是某栈的压入顺序，序列 4，5,3,2,1 是该压栈序列对应的一个弹出序列，但 4,3,5,1,2 就不可能是该压栈序列的弹出序列。

```cpp
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()) return false;
        vector <int> res;
        for(int i=0,j=0;i<pushV.size();)
        {
            res.push_back(pushV[i++]);
            while(j<popV.size() && res.back()==popV[j])
            {
                res.pop_back();
                j++;
            }
        }
        return res.empty();
    }
};
```

## 22.从上往下打印二叉树 

> 从上往下打印出二叉树的每个节点，同层节点从左至右打印。 

```cpp
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;//vector存放的是所有结点的值
        if(root == NULL)
            return res;
        queue<TreeNode*> q;//queue里面存放每个结点
        q.push(root);//先入根节点
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }
        return res;
    }
};
```

## 24.二叉搜索树的后序遍历序列 

> 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出 Yes, 否则输出 No。假设输入的数组的任意两个数字都互不相同。

```cpp
//BST的中序遍历是递增的。BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。
class Solution {
    bool judge(vector<int>& a, int l; int r)
    {
        if(l>=r) return true;//l==r对应的是叶子结点，l>r对应的是空树，这两种情况都是合法的二叉搜索树
        int i = r;//把下标赋给i，用i去遍历
        while(i>1 && a[i-1]>a[r])//区分开左右子树
            --i；
            for(int j=i-1;j>=l;j--)//处理左子树
                if(a[j] > a[r]) return false;
        return (judge(a,1,i-1)) && (judge(a,i,r-1));//l到i-1是左子树，i到r-1是右子树
    }
public:
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size()-1);//r传的是size-1，也就是下标
    }
};
```

## 25.二叉树中和为某一值的路径 

> 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前) 

```cpp
//不是笔试测试用例不全，是题目描述不清楚，默认该树为二叉搜索树
//从上往下搜索的,找完左子树的路径，再找右子树的路径。
//找到路径了直接入vector，
class Solution {
public:
    vector<vector<int> > res;//存放路径
    vector<int> tmp;//每个路径里面的root
void dfsFind(TreeNode* node,int left)
{
    tmp.push_back(node->val);//每一遍都是先入根
    if(left-node->val==0 && !node->left && !node->right)
        res.push_back(tmp);
    else
    {
        if(node->left) dfsFind(node->left,left-node->val);
        if(node->right) dfsFind(node->right,left-node->val);
    }
    tmp.pop_back();//移除最后一个元素,深度遍历完一条路径要回退，否则tmp的元素只增加不减少
}
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if(root) dfsFind(root, expectNumber);
    return res;
}
};
```

## 26.复杂链表的复制 

> 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
>
> 
>
>  

```cpp
class Solution {
public:
    RandomListNode* Clone(RandomListNode* head)
    {
        if(!head) return NULL;
        RandomListNode* cur = head;
        while (cur){
		RandomListNode* copy = new RandomListNode(cur->label);
		copy->next = cur->next;//copy放在结点1 2之间
		cur->next = copy;//接上去了
		cur = copy->next;//处理下个cur
	}
        cur = head;//2.copy他们的random指针
	while (cur != nullptr){
		if (cur->random != nullptr)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	cur = head;//3.拆分链表
	RandomListNode*copylist = head->next;
	while (cur && cur->next){
		RandomListNode* copy = cur->next;
		cur->next = cur->next->next;
		cur = copy;
	}
	return copylist;
    }
};
```

## 27.二叉搜索树与双向链表 

> 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。 

```cpp
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;//用它去遍历
        convertHelper(pRootOfTree,pre);
        TreeNode* res = pRootOfTree;
        while(res->left)
            res = res->left;//返回最左边的元素，链表的头
        return res;
    }
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    //必须要加引用，因为pre是动态变化的，如果不加的话，调用结束后很可能pre没有变化，一直为空
    //后面pre的改变要返回去给前一次的调用
    //普通传参递归层数高的不会传给层数低，这个引用可以让递归层数高的改变的pre作用到层数低的函数中。
    {//递归出口
        if(cur == nullptr) return;
        //这里不用判断，处理左子树
        convertHelper(cur->left,pre);
        cur->left = pre;//左子树创建好了，增加pre的指向
        if(pre) pre->right = cur;
        pre = cur;//返回上一层父节点，去访问右子树
        convertHelper(cur->right,pre);
    }
};
```

## 28.字符串的排列 

> 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。  
>
> 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

```cpp
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str!= "") dfs(str,0);//s初始是0，和第一个元素互换即原顺序输出
        return ret;
    }
    vector<string> ret;
    void dfs(string str,int s)
    {
        int sz=str.size();
        if(s==sz)//已经换到最后一个元素了，这里是递归的出口
        {
            ret.push_back(str);//每种组合都入vector
            return;
        }
        for(int i=s;i<sz;i++)//s在循环内是不变的，循环各种互换的可能
        {
            if(i!=s && str[s]==str[i]) continue;//这里重复项，互换后会冗余
            swap(str[s],str[i]);//s和自身||它后面的每一个不等于自己的元素互换
            dfs(str,s+1);//s要往后走了
            
        }
    }
};
```

## 29.数组中出现次数超过一半的数字 

> 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。 

```cpp
//map   O(n)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n =  numbers.size();
        map<int,int> m;
        int count=0;
        int r = n;
        while(r--)
        {
            count = ++m[numbers[r]];
            if (count > n/2) return numbers[r];
        }
            return 0;//可能不存在这个数字
    }
};
//思路：数组排序后，如果符合条件的数存在，则一定是数组中间那个数。
//假定中间的该数为所求，然后再去统计它出现的次数是否符合。
//快排sort，其时间复杂度为O(NlogN)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        sort(numbers.begin(),numbers.end());//排序，取数组中间
        int middle = numbers[numbers.size()/2];//middle是出现次数最多的数字
        int count = 0;//出现次数
        for(int i=0;i<numbers.size();i++)//遍历每个元素，记录middle出现的次数
            if (numbers[i]==middle) count++;
        return (count>numbers.size()/2) ? middle :  0;//可能不存在这个数字
    }
};
//思路：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int times = 0;
        int result;
        for(int i=0;i<numbers.size();++i)
        {
            if(times==0)
                // 更新result的值为当前元素，并置次数为1
            {
                result = numbers[i];
                times++;
            }
            else if(numbers[i]==result)
                ++times;
            else
                --times;
        }
         // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for(int i=0;i<numbers.size();++i)
            if(numbers[i]==result) ++times;
        return (times>numbers.size()/2 ? result:0);        
    }
};
```

## 30.最小的 K 个数 

> 输入 n 个整数，找出其中最小的 K 个数。例如输入 4,5,1,6,2,7,3,8 这 8 个数字，则最小的 4 个数字是 1,2,3,4。

```CPP
//1、全排序  时间复杂度O（nlogn）
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector <int> res;
        if(input.empty() || k>input.size()) return res;
        sort(input.begin(),input.end());
        for(int i =0;i<k;i++)
            res.push_back(input[i]);
        return res;
    }
};
//最大堆 时间复杂度O（nlogk）
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len||k<=0) return vector<int>();
        vector<int> res(input.begin(),input.begin()+k);
        //建堆
        make_heap(res.begin(),res.end());
         
        for(int i=k;i<len;i++)
        {
            if(input[i]<res[0])
            {
                //先pop,然后在容器中删除
                pop_heap(res.begin(),res.end());
                res.pop_back();
                //先在容器中加入，再push
                res.push_back(input[i]);
                push_heap(res.begin(),res.end());
            }
        }
        //使其从小到大输出
        sort_heap(res.begin(),res.end());
        return res;
    }
};
```