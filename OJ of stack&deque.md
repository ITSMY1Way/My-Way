### 栈的弹出、压入序列

```cpp
//题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
bool IsPopOrder(vector<int> pushV,vector<int> popV) {        
    if(pushV.size() == 0 || popV.size() == 0)            
        return false;        
    stack<int> st;       
    int popIndex = 0;        
    for(int i=0; i<pushV.size(); i++){            
        st.push(pushV[i]);           
        while(!st.empty() &&  st.top() == popV[popIndex]){                
            st.pop();                
            popIndex++;            
        }        
    }        
    return st.empty();                    
}
```

### 逆波兰表达式求

```cpp
//逆波兰式（Reverse Polish notation，RPN，或逆波兰记法），也叫后缀表达式（将运算符写在操作数之后）
//遇到数字就入栈，遇到运算符则从栈中弹出2个数字，将运算结果再次入栈，知道遍历结束，当栈剩下最后一个数字就是结果啦。
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;//存放一组数字和符号
        int n1,n2;
        for(auto token:tokens){//遍历每个字符串
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                n2 = s.top();//上面的是n2，后入栈，是运算符右值
                s.pop();
                n1 = s.top();//再取n1
                s.pop();//栈空了
                char c = token[0];//取出这个符号
                switch(c){
                    case '+':
                        s.push(n1+n2);
                        break;
                    case '-':
                        s.push(n1-n2);
                        break;
                    case '*':
                        s.push(n1*n2);
                        break;
                    case '/':
                        s.push(n1/n2);
                        break;
                }
            }
            else
                s.push(atoi(token.c_str()));//atoi是把字符串转换成整型数的一个函数
        }//string.c_str  是Borland封装的String类中的一个函数，它返回当前字符串的首字符地址。
        return s.top();
    }
};
```

### 数组中的第K个最大元素

```cpp
//1.将数组排序，直接返回
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end(),ismax);
    return nums[k-1];
}
static bool ismax(const int &a,const int &b)
{
    return a>b;
}
//2.1 维护一个大小为k的小根堆
int findKthLargest(vector<int>& nums, int k) {
    vector<int> minstack(k);
    for(int i=0;i<k;i++)
    {
        minstack[i]=nums[i];
    }
    make_heap(minstack.begin(),minstack.end(),greater<int>());//创建小根堆
    for(int i=k;i<nums.size();i++)
    {
        if(nums[i]>minstack[0])//若比根节点大则插入
        {
            minstack.push_back(nums[i]);
            push_heap(minstack.begin(),minstack.end(),greater<int>());
        }
        if(minstack.size()>k)
        {
            pop_heap(minstack.begin(),minstack.end(),greater<int>());
            minstack.pop_back();
        }
    }
    return minstack[0];
}
//2.2用优先队列创建小根堆
int findKthLargest(vector<int>& nums, int k) {
// 将数组中的元素先放入优先级队列中
    priority_queue<int> p(nums.begin(), nums.end());
// 将优先级队列中前k-1个元素删除掉
    for(int i= 0; i < k-1; ++i)
        p.pop();
    return p.top();
}
```

### 二叉树的层次遍历 II

```cpp
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> a;
    if(!root) return a;
    queue<TreeNode*> q;//首先将该层节点存入q中
    q.push(root);
    while(!q.empty()) {
        vector<int> b;//将每一层的数值存入b中，q同时存入下一层的节点；
        int s = q.size();//记录此时q中节点的数量，对这些节点进行遍历
        for(int i = 0; i < s; ++i) {////遍历后，把b存入a中，最后反转a即为从下往上的结果。
            TreeNode* t = q.front();
            b.push_back(t->val);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        a.push_back(b);
    }
    reverse(a.begin(), a.end());
    return a;
}
```

### 二叉树的层平均值

```cpp
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;//用来存放结果
    if(!root) 
        return res;
    queue<TreeNode*> q;//放每一层的节点
    q.push(root);
    while(!q.empty()){
        double sum = 0;//一层的和
        int n = q.size();
        for (int i = 0; i < n; i++)  {
            root = q.front();//每层的root都要遍历
            sum += root->val;//记录该层每个节点的值，然后出队列
            q.pop();
            if(root->left) q.push(root->left);//遍历下一层的节点，放在了队列的后面
            if(root->right) q.push(root->right);
        }
        res.push_back(sum/n);
    }
    return res;
}
```

### 在每个树行中找最大值

```cpp
//广度优先BFS
vector<int> largestValues(TreeNode* root) {
    if(!root) return{};
    vector<int> res;//用来存放结果
    queue<TreeNode*> q;//放每一层的节点
    q.push(root);
    while(!q.empty()){
        int max_num= INT_MIN;//INT_MIN = -2147483648，初始值设定如此比较安全
        int size = q.size();
        while(size--) {
            root = q.front();
            q.pop();
            max_num=max(max_num,root->val);
            if(root->left) q.push(root->left);//遍历下一层的节点，放在了队列的后面
            if(root->right) q.push(root->right);
        }
        res.push_back(max_num);
    }
    return res;
}
```

### N叉树的层序遍历

```cpp
//层序遍历过程中，堆当前的队列树木进行了计数，然后每次循环都完全谈粗了当前层的节点，只有处理完了当前层的节点才会进入下一层的处理。循环来压入每个节点的子节点。
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<int> layer;//层
        vector<vector<int>> res;//存放结果
        if(root==NULL) return res;
        queue<Node*> q;
        Node* temp;
        q.push(root);
        while(!q.empty()){//一直循环，直到队列空，队列层序遍历的基本框架
            int num=q.size();
            for(int i=0;i<num;i++){//统计每一层的节点树，保证处理完当前层的节点*/
                temp=q.front();
                q.pop();
                layer.push_back(temp->val);
                if(temp->children.size()!=0){
                    for(int i=0;i<temp->children.size();i++){
                    q.push(temp->children[i]);/*将每个节点的子节点压入队列*/
                    }
                }
            }
            res.push_back(layer);/*处理完一层后，压入结果*/
            layer.clear();/*压入结果后清空layer*/
        }        
        return res;
    }
};
```

### 前K个高频元素

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};
```

### 前K个高频单词

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //1.[] 2.find insert 3.insert
        map<string,int> countmap; 
        //将字符串按照字母顺序排序，并统计出字符串出现的次数                
        for(auto& e : words)
            countmap[e]++;
        
        multimap<int,string,greater<int>> sortmap;//出现次数为key，字符串为value
        //按照出现次数从大到小进行排序
        for(const auto& kv:countmap)
        {
            sortmap.insert(make_pair(kv.second,kv.first));
        }
        
        vector<string> v;
        multimap<int,string>::iterator it = sortmap.begin();
        while(it != sortmap.end() && k--)
        //遍历排好序的map取出前k个出现频率最高的字符串放入vector中
        {
            v.push_back(it->second);
            ++it;
        }        
        return v;  
    }
};
```

