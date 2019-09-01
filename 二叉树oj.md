## 前序遍历

```cpp
//迭代                 node--->left--->right
vector<int> preorderTraversal(TreeNode* root) {
vector<int> res; 
if (!root)
return res;
stack<TreeNode*> st;
st.push(root);//把根节点/父节点入栈
while (!st.empty()){
	TreeNode* cur = st.top();//方便访问根的左右结点
	res.push_back(cur->val);//根节点直接尾插，作为数组的第一个元素
	st.pop();//出栈
	if (cur->right)
		st.push(cur->right);
	if (cur->left)
		st.push(cur->left);
}
return res;
```

```cpp
//递归              
vector<int> preorderTraversal(TreeNode* root) {
     vector<int> res;
     preorderTraversal(root,res);
     return res;
}  
void preorderTraversal(TreeNode* root, vector<int>& res) {
    if(root){
         res.push_back(root->val);
         preorderTraversal(root->left,res);
         preorderTraversal(root->right,res);
       }
```

## 中序遍历

```cpp
//迭代                 left--->node--->right
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;//数组，用来存放返回值
    stack<TreeNode*> st;//st用来存放，然后出栈，然后加入队列（数组）
    TreeNode* cur = root;
    while(cur || !st.empty()){//当root结点不是空(从头节点开始) / 栈里还有元素
        while(cur){//还在遍历
            st.push(cur);//cur先入栈
            cur = cur->left;
        }
        cur = st.top();  //出栈的栈顶元素也就是最左边的元素
        st.pop();
        res.push_back(cur->val);//一一入队
        cur = cur->right;   
    }
       return res;
}
```

```cpp
//递归
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorderTraversal(root, res);
    return res;
}
void inorderTraversal(TreeNode* root, vector<int>& res){
    if(root){
        inorderTraversal(root->left,res);
        res.push_back(root->val);
        inorderTraversal(root->right,res);
    }
```

## 后序遍历

```cpp
//迭代         后续：left--->right--->node    反后续node--->right--->left
//定义2个栈：   st1，模仿前序的实现反后续    st2，保存stack的pop元素
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root) 
        return res;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* cur=st1.top();
        st1.pop();
        st2.push(cur);//st2一直保存st1 pop()，实现反序
        if(cur->left)
            st1.push(cur->left);
        if(cur->right)
            st1.push(cur->right);
    }
    while(!st2.empty()){
        TreeNode* node=st2.top();
        st2.pop();
        res.push_back(node->val);
    }
    return res;
}
```

```cpp
//递归
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorderTraversal(root,res);
    return res;
}
void postorderTraversal(TreeNode* root, vector<int>& res){
    if(root){
        postorderTraversal(root->left,res);
        postorderTraversal(root->right,res);
        res.push_back(root->val);
    }
```

## 检查两棵树是否相同

```cpp
//递推
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    return (p->val == q->val)
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}
```

## 对称二叉树

```cpp
bool isMirror(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return  false;
    return p->val == q->val
        && isMirror(p->left, q->right)
        && isMirror(p->right, q->left);
}
bool isSymmetric(TreeNode* root) {
    if(root == NULL)
        return true;
    return isMirror(root->left, root->right);
}
```

## 判断是否为子树

```cpp
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {//判断相同树
	if (p == NULL && q == NULL) 
		return true;
	if (p == NULL || q == NULL) 
		return false;
	return p->val == q->val         // 递推
		&& isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}
bool preorderTraversal(struct TreeNode *root, struct TreeNode *t) {//前序遍历
	if (root == NULL) 
		return false;
	if (root->val == t->val && isSameTree(root, t)) //s与t完全相同
		return true;
	// 左子树
	bool left = preorderTraversal(root->left, t);
	if (left == true) 
		return true;//这里不能直接返回false，函数会中断执行
	// 右子树
	bool right = preorderTraversal(root->right, t);
	return right;
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL) 
		return true;
	return preorderTraversal(s, t);
}
```

## 二叉树深度

```cpp
int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;//因为是高度，正常从2开始
}
```

## 平衡二叉树

```cpp
bool isBalanced(TreeNode* root) {
    return (isba(root) <0 ? false : true);
}
int isba(struct TreeNode* root){
    if (root == NULL) 
    return 0;
    int left = isba(root->left);
    if (left < 0)
    return -1;
int right = isba(root->right);
    if (right < 0) 
    return -1;
int tmp = left - right;
    if  ((tmp >= -1) && (tmp <= 1))
    return  (left > right ? left : right) + 1;
    return -1;
}
```

## 根据前序字符串构建二叉树，转为中序字符串

```cpp
int main(){  
string pre;
while(cin >> pre){
    stack<char> s;
    for(auto it: pre){
        if(it != '#')
            s.push(it);
        else{
            if(!s.empty()){
                 cout << s.top() <<" ";  
                s.pop();
            }
        }
    }
    cout << '\n';
}
}
```

## 前序二叉树转为字符串

```cpp
    string tree2str(TreeNode* t) {
        if( !t)
            return "";
        string res = to_string(t->val);//把数字接到字符串后
        if(t->left || t->right)
            res += "(" + tree2str(t->left) + ")";
        if(t->right)
            res += "(" + tree2str(t->right) + ")";
        return res;
    } 
```

## 层序遍历

```cpp
//深度优先搜索（BFS）
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;//用来存放每层结点
    pre(root,0,res);
    return res;
}
void pre(TreeNode *root,int depth,vector<vector<int>> &res)
{
    if(!root)
        return;
    if(depth>=res.size())   //说明需要增加一层
        res.push_back(vector<int>{});//插入的层是空的
    res[depth].push_back(root->val);//先入头   -----> 把该层元素插进对应层的vector
    pre(root->left,depth+1,res);
    pre(root->right,depth+1,res);
}
//广度优先搜索（BFS）
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(!root)
        return res;
    queue<TreeNode*> q;//q是用来更替一层结点的
    TreeNode* p;//代表当前结点
    q.push(root);//先根节点入队
    while(!q.empty()){
        vector<int> a;// a存放所有层的结点
        int width = q.size();//一层有几个元素
        while(width--){
            p = q.front();//该层的第一个元素给p,循环，直至取完
            a.push_back(p->val);
            q.pop();//取了后弹出
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
        res.push_back(a);
    }
    return res;
}
```

### 二叉树的最近公共祖先

```cpp
//递归
//分别在左右子树中找p和q，若出现在同一侧，则返回较近的结点；
//若p和q分别分布在左、右子树，则返回根节点root
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q)
        return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return left == nullptr? right : (right == nullptr? left : root); 
    //如果left为空，说明left走完了都没有找到p/q，返回right（两者其一是空）；
    //left不为空，返回 left（若right是空）  /   root（p，q分布在左右子树）
}
```

## 二叉搜索树转双向链表

```cpp
//二叉搜索树是递增的有序数列    
//是中序遍历  左———>根———>右
//在原有的树结构上进行操作
//中序遍历后得到有序序列，然后调整各元素的指针，将有序序列调整为双向链表
//找到跟接待你的左子树的最后一个结点，对根节点的左右指针分别进行改变，使得和左子树的最后一个结点互相指向
//到这里了，如果有右子树，再对右子树进行判断
TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        TreeNode* list_last = nullptr;//定义此结点记录头节点/尾结点
        ConvertNode(pRootOfTree, list_last);//递归建立双向链表
        while(list_last->left != nullptr)
            list_last = list_last->left;
        return list_last;//返回双向链表的头节点
    }
    void ConvertNode(TreeNode* cur,TreeNode *&list_last)
    {//引用作为函数参数进行传参，穿的是实参本身。（利用形参作为指针的引用）
        if(cur == nullptr)
            return;//边界条件（递归出口）
        if(cur->left != nullptr)//遍历左子树
            ConvertNode(cur->left, list_last);
        
        //建立双向链表
        //走到这，说明当前结点的左子树已经转好了， list_last指向左子树中的最后一个结点
        cur->left = list_last;//用list_last指向已经转换好的链表的最后一个结点
        if(list_last != nullptr)
            list_last->right = cur;
        list_last = cur;//将list_last指向当前结点
        
        if(cur->right != nullptr)//遍历右子树
            ConvertNode(cur->right, list_last);
    }

```

## 前序与中序构建二叉树

```cpp
//先序遍历结果,每一个值都是当前区间的根r,由当前根r在中序遍历中寻找r,将其分割成两个区间left,right,分别对应当前根的左右子树.
TreeNode *preordered(vector<int> &preorder, vector<int> &inorder, int begin, int end, int &pos){
    if(begin>=end || pos>=preorder.size()) return NULL;
    TreeNode *r=new TreeNode(preorder[pos++]);//用每个前序里的r在中序中寻找相同的值，可切割左右子树
    int cur=0;
    for(cur=begin; cur<end && inorder[cur]!=r->val; ++cur);//在中序里面找r,找到了跳出for执行下面语句
    r->left=preordered(preorder,inorder,begin,cur,pos);
    r->right=preordered(preorder,inorder,cur+1,end,pos);
    return r;
}
public:
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pos=0;
    return preordered(preorder,inorder,0,inorder.size(),pos);//end是元素个数
}
```

## 中序与后续构建二叉树

```cpp
//前序 ：root——>left——>right
//中序 ：left——>root——>right
//后续 ：left——>right——>root
//在后续最后面取元素，它是root，在中序里面找到，
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        TreeNode* result = buildTree1(inorder,postorder,size - 1,0,size - 1);
        return result;
    }
    TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder,int a,int a1,int b1) {
        if(a < 0 || b1 < a1 || a1 >= inorder.size() || b1 < 0)
            return NULL;
        TreeNode* result = new TreeNode(postorder[a]);
        int i = 0;
        for(i = b1; i >= a1; i--)
        {
           if(inorder[i] == postorder[a])
                break;
        }
        result->right = buildTree1(inorder,postorder,a - 1,i + 1,b1);
        result->left = buildTree1(inorder,postorder,a - b1 + i - 1,a1,i - 1);
        return result;       
    }
};
```

