## 30.连续子数组的最大和 

> HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1) 

```cpp
//分析：时间复杂度为 O(n)。思路是：定义两个变量 sum 和 maxSum，sum 用于记录连续子序 列的和，maxSum 记录最大和。当遍历到一个元素 array[i]时，先判断 sum 是否小于 0，如果 sum<0，说明前面的连续子序列的和为负数，那加上 array[i]一定比 array[i]小，所以抛弃 sum 的值，令其等于 array[i]；如果 sum>0，则加上 array[i]一定比 array[i]要大，所以 sum+=array[i]。 maxSum 在这个过程中，记录最大的 sum。
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int m = array[0];
        int sum = 0;//走到这里点的值
        for(int i =0;i<array.size();i++)
        {
            if (sum<0) sum=array[i];
            else sum += array[i];
            m = max(m,sum);
        }
        return m;
    }
};
```

## 31.整数中 1 出现的次数（从 1 到 n 整数中 1 出现的次数） 

> 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。 

```cpp
//将原数字按10的倍数进行分割，求个、十、百....位上1的个数。以a=31415 and b=92为例，讨论百位上1的个数，由于5是大于1的，所以当百位上出现1时，个位、十位的范围是0—99，所以此时乘以100，而5的前面可以是0-3141，总共（3141+1）=3142个。然而当所求位上为0和1时，其后面的位上不一定能达到0-99，这时候就考虑减1操作。
//综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
//之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
//其实就是我们先把所有的数列出来，然后独立地去数每位上为1的个数，最后加起来
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){ 
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
         return ones;
    }
};
//字符串拼接
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
       string s;
        int m,sum = 0;
        for(int i = 1;i <= n;i++)
        {
            s = to_string(i);
            m = count(s.begin(),s.end(),'1');
            sum = sum + m;
        }
        return sum;
    }
};
```

## 32.把数组排成最小的数 

> 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。 

```cpp
 // 对vector容器内的数据进行排序，按照 将a和b转为string后
 //若 a＋b<b+a  a排在在前 的规则排序,
 //如 2 21 因为 212 < 221 所以 排序后为 21 2 
 //to_string() 可以将int 转化为string
//sort是O(nlogn),后面循环是O(n), 所以总体复杂度是O(nlogn)，空间复杂度为 O(n）
//sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。 
//因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法在sort中调用非静态成员函数。静态成员函数或者全局函数是不依赖于具体对象的, 可以独立访问，无须创建任何对象实例就可以访问。同时静态成员函数不可以调用类的非静态成员。
//另外一种方法，可以不使用static，把bool cmp()放到class solution{}外面，一样起到全局函数的作用，
2019-08-11 16:17:49
class Solution {
public:
     static bool cmp(int a,int b){
         string A="";
         string B="";
         A+=to_string(a);
         A+=to_string(b);
         B+=to_string(b);
         B+=to_string(a);
         return A<B;
     }
     string PrintMinNumber(vector<int> numbers) {
         string  answer="";
         sort(numbers.begin(),numbers.end(),cmp);
         for(int i=0;i<numbers.size();i++){
             answer+=to_string(numbers[i]);
         }
         return answer;
     }
};
```

## 33.丑数

> 把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。 

```cpp
//可以将以上序列（a1除外）可以分成3类，必定满足：
//包含2的有序丑数序列：2*a1, 2*a2, 2*a3 .....
//包含3的有序丑数序列：3*a1, 3*a2, 3*a3 .....
//包含5的有序丑数序列：5*a1, 5*a2, 5*a3 .....
//以上3个序列的个数总数和为n个，而且已知a1 = 1了，将以上三个序列合并成一个有序序列即可 
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7)return index;//1-6肯定都是丑数，所以当丑数数量小于7个时直接返回数量
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));//一个min只能判断两个数的大小
            if (res[i] == res[t2] * 2)t2++;//这三个实现了去重
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
        }
        return res[index - 1];
    }
};
```

## 34.第一个只出现一次的字符位置 

> 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）. 

```cpp
//map
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<int,char> mp;
        for(int i=0;i<str.size();i++)
            mp[str[i]]++;
        for(int i=0;i<str.size();i++)
            if (mp[str[i]] == 1)
                return i;
        return -1;
    }
};
```

## 35.数组中的逆序对

> 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 

```CPP
//过程：先把数组分割成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个相邻子数组之间的逆序对的数目。在统计逆序对的过程中，还需要对数组进行排序。如果对排序算法很熟悉，我们不难发现这个过程实际上就是归并排序。
class Solution {
public:
    int InversePairs(vector<int> data) {
        int length=data.size();
        if(length<=0)  return 0;
       vector<int> copy;  //vector<int> copy=new vector<int>[length];
       for(int i=0;i<length;i++)
           copy.push_back(data[i]);
       long long count=InversePairsCore(data,copy,0,length-1);
        //delete[]copy;
       return count%1000000007;
    }
    long long InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end)
    {
       if(start==end)  return 0;
       int length=(end-start)/2;
       long long left=InversePairsCore(copy,data,start,start+length);
       long long right=InversePairsCore(copy,data,start+length+1,end); 
       int i=start+length;
       int j=end;
       int indexcopy=end;
       long long count=0;
       while(i>=start && j>=start+length+1)
          {
             if(data[i]>data[j])
                {
                  copy[indexcopy--]=data[i--];
                  count=count+j-start-length;          //count=count+j-(start+length+1)+1;
                }
             else copy[indexcopy--]=data[j--];
          }
       for(;i>=start;i--)
           copy[indexcopy--]=data[i];
       for(;j>=start+length+1;j--)
           copy[indexcopy--]=data[j];       
       return left+right+count;
    }
};
```

## 36.两个链表的第一个公共结点 

> 输入两个链表，找出它们的第一个公共结点。

```cpp
//传统做法  求出2条长度，让长的先走长度查，然后一起走
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1= Lenth(pHead1);
        int len2= Lenth(pHead2);
        if(len1>len2) pHead1=Walk(pHead1,len1-len2);//长的先走距离差
        else  pHead2=Walk(pHead2,len2-len1);
        while(pHead1!=NULL)
        {
            if(pHead1==pHead2) return pHead1;
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return NULL;
    }
    int Lenth(ListNode *pHead)//求2者的长度
    {
        if(pHead==NULL) return 0;
        int sum=1;
        while(pHead = pHead->next) sum++;
        return sum;
    }
    ListNode* Walk(ListNode *pHead,int step)//走距离差
    {
        while(step--) pHead=pHead->next;
        return pHead;
    }
};
//他用2圈就可以俘获自己的短链表，我好像看不到未来。
//但我想我们也会在未来的某个结点相遇，过程多远具体我不想知道，我喜欢遥望未知的方向，它感人肺腑，它和你一样迷人。我好期待参与你的那条短链表，如果我们在某一刻相交的话，我愿意转向你的那一条。
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};
```

## 37.数字在排序数组中出现的次数 

> 统计一个数字在排序数组中出现的次数。 

```cpp
//由于数组有序，所以使用二分查找方法定位k的第一次出现位置和最后一次出现位置
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return getUpper(data,k) - getLower(data,k) + 1;
    }
    //获取k第一次出现的下标
    int getLower(vector<int> data,int k){
        int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
        while(start <= end){
            if(data[mid] < k)  start = mid + 1;
            else end = mid - 1; mid = (start + end)/2;
        }
        return start;
    }
    //获取k最后一次出现的下标
    int getUpper(vector<int> data,int k){
        int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
        while(start <= end){
            if(data[mid] <= k) start = mid + 1;
            else end = mid - 1;  mid = (start + end)/2;
        }
        return end;
    }
};
//因为data中都是整数，不是搜索k的两个位置，而是搜索k-0.5和k+0.5.这两个数应该插入的位置，然后相减即可。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return Search(data,k+0.5)-Search(data,k-0.5);
    }
    int Search(vector<int> data,double num)
    {
        int begin=0, end=data.size()-1;
        while(begin <= end){
            int mid=(end-begin)/2+begin;
            if(data[mid]<num) begin=mid+1;
            else if(data[mid]>num) end=mid-1;
        }
        return end;
    }
};
//利用C++ stl的二分查找
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
    }
};
```

## 38.二叉树的深度 

> 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成 树的一条路径，最长路径的长度为树的深度。

```cpp
//普通递归
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL) return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return (left>=right? left: right)+1;
    }
};
//升级版本
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL) return 0;
        return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
    }
};
//迭代版本
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        queue<TreeNode*> que;
        que.push(pRoot);int depth=0;
        while (!que.empty()) {
            int size=que.size();
            depth++;
            for (int i=0;i<size;i++) {      //一次处理一层的数据
                TreeNode *node=que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};
```

## 39.平衡二叉树

> 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。 

```cpp
// 解法一: 判断每个结点的左右子树的深度之差不超过一
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        if(abs(left - right) > 1)  return false;
        // 继续判断左右子树
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
        // 左右子树深度的最大值 + 1
    int TreeDepth(TreeNode* pRoot) {
        if(!pRoot) return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return 1 + max(left, right);
    }
}；
//二：后续遍历二叉树，遍历过程中求子树高度，判断是否平衡
class Solution {
public:
    bool IsBalanced(TreeNode *root, int & dep){
        if(root == NULL) return true;
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right, right)){
            int dif = left - right;
            if(dif<-1 || dif >1)
                return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
    }
};
```

## 40.数组中只出现一次的数字 

> 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现 一次的数字。 

```cpp
//1.使用异或，但是与在成对出现的数字中查找一个单独的数字不同的是需要利用异或结果的最低位为1的flag将数组中的数字分为两类，一类是与flag按位与为0，另一类为不为0，这样再分别异或一次就能够找出这两个数。
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2) return;
        int all =0;//所有异或的结果
        int index=1;//区分元素
        for(int i=0;i<data.size();++i)
            all ^= data[i];//异或
        while((all&index)==0) index <<=1;//用1左移位操作找出两个元素第一个不同位
        *num1=all,  *num2=all;
        for(int i=0;i<data.size();++i){//开始区分
            if((index & data[i]) == 0) *num1 ^= data[i];//优先级
            else *num2 ^= data[i];
        }
    }
};
//2.简洁
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int ans=0;
        for(int a : data) ans^=a;//int 可换 auto
        *num1 = ans,*num2 = ans;
        ans = ans & (~ans+1);//找到第一个1 取最右边1
        for(int a : data){
            if(a & ans) *num2^=a;
            else *num1^=a;
        }
    }
};
```

## 41.和为 S 的连续正数序列 

> 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 
>
> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

```cpp
//1.利用数学公式。连续序列 m,m+1,m+2,m+3,…,n 累加和为(n+m)(n-m+1)/2，令其等于 S， 即(n+m)(n-m+1)=2S，进一步 n(n+1) – m(m-1)=2S。此时，我们从 m=1 遍历到 m=sum/2，对 于每一个 m，计算出 n=sqrt(2S+m(m-1))，然后检验 n(n+1)= 2S+m(m-1)是否成立，若成立，则输出。
class Solution { 
    public: 
    vector<vector<int> > FindContinuousSequence(int sum) { 
        vector<vector<int> > seq; 
        if(sum<=1) return seq; 
        for(int m=1;m<=sum/2;m++){ 
            int tmp = 2*sum + m*(m-1); 
            int n = sqrt(tmp); 
            if(n*(n+1)==tmp){//加入结果集 
                vector<int> vec; 
                for(int j=m;j<=n;j++)
                    vec.push_back(j); 
                seq.push_back(vec); 
            } 
        }return seq; 
    } 
};
//2.双指针问题   当总和小于sum，大指针继续+   否则小指针+
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int phigh = 2,plow = 1;
        while(phigh > plow){
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if( cur == sum){
                vector<int> res;
                for(int i = plow; i<=phigh; i++)
                    res.push_back(i);
                allRes.push_back(res);
                plow++;
            } 
            if( cur < sum)  phigh++;
            if(cur > sum)  plow++;
        }
        return allRes;
    }
};
```

## 42.和为 S 的两个数字 

> 输入一个递增排序的数组和一个数字 S，在数组中查找两个数，使得他们的和正好是 S，如 果有多对数字的和等于 S，输出两个数的乘积最小的。

```cpp
//数列满足递增，设两个头尾两个指针i和j，
//若ai + aj == sum，就是答案（相差越远乘积越小）
//若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
//若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
//O(n)
class Solution {
public:
    vector<int>  FindNumbersWithSum(vector<int> a,int sum) {
        vector<int> res;
        int n = a.size();
        int i = 0, j = n - 1;
        while(i < j){
            if(a[i] + a[j] == sum){
                res.push_back(a[i]);
                res.push_back(a[j]);
                break;
            }
            if(a[i] + a[j] > sum) --j;
            if(a[i] + a[j] < sum) ++i;
        }
        return res;
    }
};
```

## 43.左旋转字符串 

> 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！ 

```cpp
//简易
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return str;
        n %= len;
        str += str;
        return str.substr(n, len);
//or    不拼接的话 return str.substr(n,len)+str.substr(0,n); len可省略
    }
};
//原理：YX = (X T   Y T)T    T指的是对应错位
class Solution {
public:
    string LeftRotateString(string str, int n) 
    {
        int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }
}
```

## 44.翻转单词顺序列 

> 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student  a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么 

```cpp
//整体+局部
class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(),str.end());
        int front=0,back=0;
        int size = str.size();
        while(front<size){
            while(front<size&&str[front]==' ')++front;
            back=front;
            while(back<size&&str[back]!=' ')++back;
            reverse(str.begin()+front, str.begin()+back);
            front=back;
        }
        return str;
    }
};
//一个个字母处理就好了
//tmp是当前正在处理的单词，res是反转之后的句子。当一个单词结束后将它拼接到res的前面。
class Solution {
public:
    string ReverseSentence(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i){
            if(str[i] == ' ') res = ' ' + tmp + res, tmp = "";
            else tmp += str[i];
        }
        if(tmp.size()) res = tmp + res;  return res;
    }
}; 
```

## 45.扑克牌顺子 

> LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。 

```cppp
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5) return false;
        sort(numbers.begin(),numbers.end());
        int i=0;
        while(numbers[i]==0) i++;//大小王在前面
        if(numbers[numbers.size()-1]-numbers[j]>4) return false;
        for(int j=i;j<numbers.size();j++){//遍历非0的牌面
            if(numbers[j]==numbers[j-1]) return false;
        }
        return true;
    }
};
```

## 46.孩子们的游戏(圆圈中最后剩下的数) 

> 每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1) 

```cpp
//1.list模拟循环链表实现
//时间复杂度为 O(n*m)，因为每次要走 m(m<n)步，要进行 n-1 次。空间复杂度为 O(n)。
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1) return -1;
        list<int> num;//用list来代替环形链表
        for(int i=0;i<n;i++) num.push_back(i);//把所有的小朋友的序号放入链表
        auto cur = num.begin();//cur是链表的头，初始化为0
        while(num.size()>1){//循环边界，剩下最后一个就是结果
            for(int i=1; i<m; i++)//走m-1步到达第m个数字  【1，m-1】
               if(++cur == num.end()) cur = num.begin();//这里的++cur，cur是指针，意思是指向下一个位置，当cur指向链表的尾结点的下一个位置时，就将该指针指向链表的头节点，就可以实现环形链表
            auto next = ++cur;//判断下一个元素是否为尾巴
            if(next == num.end()) next = num.begin();
            cur--;//cur回去   
            num.erase(cur);//并删掉
            cur= next;//从被删掉的下一个元素处开始遍历
        }
         return *cur;
    }
};
//2.用queue
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m <= 0) return -1;
        queue<int> temp;
        for(int i=0; i<n; ++i)
            temp.push(i);
        while(temp.size()>1)
        {
            for(int i=1; i<m; i++)//走m-1步到达第m个数字  【1，m-1】
            {
                int tmp = temp.front();
                temp.pop();
                temp.push(tmp);
            }
            temp.pop();
        }
        return temp.front();
    }
};
//3.数学公式
//3.1递归版
int LastRemaining_Solution(int n, int m)
{
     if(n<1 && m<1 ) return -1;
     if(n==1) return 0;
     return (LastRemaining_Solution(n-1,m)+m)%n;
}
//3.2迭代版
int LastRemaining_Solution(int n, int m)
{
    if(n<1 && m<1 ) return -1;
    int last=0;
    for(int i=2;i<=n;i++)  last=(last+m)%i; 
    return last;
}
```

## 47.求 1+2+3+...+n 

> 求 1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条 件判断语句（A?B:C）。

```cpp
//1.与操作  变相的递归
int Sum_Solution(int n) {
    int sum=n;
    sum && (sum+=Sum_Solution(--n));
    return sum;
}
//2.1这是一个等差数列，sum=(a1+an)n/2=>(1+n)n/2=>(n+n^2)/2；Math.pow(a,b)表示a^b；右移一位相当于除2
int Sum_Solution(int n) {
    int sum=(int)Math.pow(n, 2)+n;
    return sum>>1;
}
//2.2 用sizeof
int Sum_Solution(int n) {
    bool a[n][n+1];
    return sizeof(a)>>1;
}
//3.构造函数：设置一个静态变量N和sum，在构造函数中进行累加运算；
//然后构造一个以辅助类为类型、大小为n的数组，重复调用此构造函数n次来实现n次的累加运算
class Temp{ 
public:
    static int sum; 
    static int count; 
    Temp(){ count++; sum += count; } 
};
int Temp::sum = 0; 
int Temp::count = 0; 
class Solution { 
public: 
    int Sum_Solution(int n) { 
        Temp::count = 0; 
        Temp::sum = 0; 
        Temp * arr = new Temp[n]; 
        delete[] arr; 
        arr = nullptr;
        return Temp::sum; 
    } 
};
//4.使用虚函数来构造递归，在基类种定义虚函数Sum(n)返回0，通过将指针数组的两个元素分别绑定到基类和派生类，其中基类的Sum()结束递归，!!n来构造true(1) false(0)来对指针数组进行访问
class Base;
Base* Array[2];
class Base{
public:
     virtual int Sum(int n){return 0;}
};
class Derived : public Base{
public:
    virtual int Sum(int n){return Array[!!n]->Sum(n-1) + n;}
};
class Solution {
public:
    int Sum_Solution(int n) {
        Base a;
        Derived b;
        Array[0] = &a;
        Array[1] = &b;
        return b.Sum(n);
    }
};
//5.函数指针    通过!!n 来调用不同的函数
class Solution { 
public: 
    typedef int (*fun)(int); 
    static int Sum_Solution_Terminal(int n){ 
        return 0; 
    }
    static int Sum_Solution(int n) { 
        fun f[2] = {Sum_Solution_Terminal,Sum_Solution}; 
        return n+f[!!n](n-1); 
    } 
};
//6.用异常退出递归
public class Solution {
    public int Sum_Solution(int n) {
        return sum(n);
    }
    int sum(int n){
        try{
            int i = 1%n;
            return n+sum(n-1);
        }
        catch(Exception e){
            return 0;
        }
    }
}
//7.自己写乘法，O(n)复杂度的算法实在是太糟糕了
public:
    int multi(int a, int b){
        int res = 0;
        (a&1) && (res += b);
        a >>= 1; b <<=1;
        a && (res += multi(a, b));
        return res;
    }
    int Sum_Solution(int n) {
        return multi(n, n+1)>>1;
    }
//8.快速幂，俗称快速模乘，复杂度 32的，可以说O(logM)吧，M是数值大小
//原理是把a拆成2的幂的和，a = 2^e0 + 2^e1 + 2^e2....，那么 a * b = (2^e0 + 2^e1 + 2^e2+...) * b = b * 2^e0 + b * 2^e1 + b * 2^e2 + ...= (b << e0) + (b << e1) + ....
//一个数乘以2的幂次方，都等同左移幂次数。
//看a的哪个位置有1，然后让b对应位置左移对应位数
 int sumAB(int a, int b) {
    int sum = 0;
    bool flag1 = (a & 1) && (sum += b);
     //a该位为1的时候才操作，加的是b左移个对应位的结果
    bool flag2 = a && (sum += sumAB(a >> 1,b << 1));
     //当a为0的时候说明a已经没有位为1了结束递归，a右移位判断该位是否为1，b左移跟上
    return sum;
}
class Solution {
public:
    int Sum_Solution(int n) {
        int a = n, b = n + 1;
        return sumAB(a, b) >> 1;
    }
};

//最好把定义的函数写最上面，写solution里面也是可以的也可以static修饰
```

## 48.不用加减乘除做加法 

> 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。 

```cpp
//非递归
//第一步：相加各位的值，不算进位，二进制每位相加就相当于各位做异或操作；
//第二步：计算进位值，相当于各位做与操作，再向左移一位；
//第三步重复上述两步， 各位相加；
//继续重复上述两步：进位值为0，跳出循环。
class Solution {
public:
    int Add(int num1, int num2)
    {
        while (num2!=0) {
            int temp = num1^num2;//第一步，不算进位，
            num2 = (num1&num2)<<1;//第二步，算进位，
            num1 = temp;//把第一步的值给num1
        }
        return num1;
    }
};

//递归
classSolution {
public:
    intAdd(intnum1,intnum2)
    {
      return num2 ?  Add(num1^num2,(num1&num2)<<1)：num1 ;
    }
};
//直接return，嵌套条件表达式递归求解。
//一、当num1或者num2任一为0，则结果返回另外一个num；
//二、当num1与num2都不为0，三个步骤：
//   1. 只有1+0 / 0+1 =1 ，其他情况都是0，该过程相当与异或：
//     ^              (相加各位的值，不算进位，二进制每位相加就相当于各位做异或)；
//   2. 当1+1 才会进位，就相当于按位与操作：
//     &后<<    (计算进位值，相当于位与操作后左移)
//   3.重复上述2个过程，结果相加，直至进位为0，跳出递归循环。
//最后的结果是当num2 也就是进位为0的时候，返回num1。

//reinterpret_cast强制类型转换符
//new_type a = reinterpret_cast <new_type> (value)
//将value的值转成new_type类型的值，a和value的值一模一样。比特位不变
//reinterpret_cast用在任意指针（或引用）类型之间的转换；以及指针与足够大的整数类型之间的转换；从整数类型（包括枚举类型）到指针类型，无视大小。
//需要注意的是：reinterpret_cast<xx>(yyy)，xx与yyy必须有一个值为指针类型。
class Solution {
public:
    int Add(int num1, int num2)
    {
        char* a = reinterpret_cast<char*>(num1);
        return reinterpret_cast<long>(&(a[num2]));
    }
};//a是char数组，把num1的值赋给a的首地址，再取a[num2]的地址

//自增自减
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2--) num1++;
        return num1;
    }
};
```

## 49.把字符串转换成整数 

> 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 

```cpp
class Solution {
public:
    int StrToInt(string str) {
        int size = str.size(); 
        if(size==0) return 0; 
        int i = 0;//下标
        bool less0 = true; //默认true是正数
        if(str[0]=='-' || str[0]=='+'){
            i++;//遇到符号位就越过
            if(str[0]=='-') less0=false;//负号要特殊处理
        }
        int ret=0;//ret即为转成的数字
        while(i<size && str[i]>='0' && str[i]<='9'){
            ret = ret*10 + str[i] - '0';//str里面存放的是字符，要减去'0'转为数字，上一次保存的数值*10+当前遍历到的数字
            ++i;//每转成一个字符就i++一下，统计转成的个数
        }
        if(i<size) return 0;//含有非法字符
        if(less0) return ret;//正数
        else return -ret;//负数
    }
};
```

## 50.数组中重复的数字

> 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

```cpp
//机智版本   时间复杂度 O(n)，空间复杂度 O(1)。因为元素大小在[0,n-1]之间
bool duplicate(int numbers[], int length, int* duplication) {
    for(int i=0;i!=length;++i){
        int index=numbers[i]%length;//这里%是防止数组越界，index即下标对应的每个元素
        if(numbers[index]>=length){
            //其实使用index作为索引遍历的，当再次遍历到第一个重复数字的时候，它已经被记录过了
            *duplication=index;
            return 1;
        }              
        numbers[index]+=length;//如果出现过该元素，则找到它对应的下标+len
    }
    return 0;
}
};
//常规   桶的应用。时间复杂度 O(n)，空间复杂度 O(n)。
class Solution {
public:
bool duplicate(int numbers[], int length, int* duplication) {
    if(numbers==NULL || length<1) return false; 
    int arr[length],i; 
    for(i=0;i<length;i++) arr[i] = 0; 
    for(i=0;;i++){
        arr[numbers[i]]++;
        if(i==length) return false;
        if(arr[numbers[i]]==2){
        *duplication = numbers[i]; 
        return true; 
        }
    }
}
};
```

