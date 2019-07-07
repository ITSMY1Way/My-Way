//typedef struct TreeNode {
//	struct TreeNode *left;//左子树
//	struct TreeNode *right;//右子树
//	char val;
//}	TreeNode;
//typedef struct Result {
//	TreeNode *root;	// 构建的树的根结点
//	int used;		// 构建过程中用掉的 val 个数
//}	Result;
////构建二叉树
//Result CreateTree(char preorder[], int size)
//{
//	//特殊情况
//	if (size == 0){
//		Result result;
//		result.root = NULL;
//		result.used = 0;
//		result = 0;
//	}
//	char rootVal = preorder[0];
//	if (rootVal == '#') {
//		Result result;
//		result.root = NULL;
//		result.used = 1;
//		return result;
//	}
//	//递推遍历
//	//根
//	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
//	root->val = rootVal;
//	root->left = root->right = NULL;
//	//左子树
//	Result left_result = CreateTree(preorder + 1, size - 1);
//	//右子树
//	Result right_result = CreateTree(preorder + 1 + left_result.used,
//		size - 1 - left_result.used);
//	root->left = left_result.root;
//	root->right = right_result.root;
//	Result result;
//	result.root = root;
//	result.used = 1 + left_result.used + right_result.used;
//	return result;
//}
//
//// 求二叉树中所有结点的个数
//// 遍历的思想
//void TreeSize(TreeNode *root, int *size) {
//	if (root == NULL) 
//		return;
//	(*size)++;
//	TreeSize(root->left, size);
//	TreeSize(root->right, size);
//}
//// 递推的思想
//int TreeSize2(TreeNode *root) {
//	if (root == NULL) 
//		return 0;
//	return 1 + TreeSize2(root->left) + TreeSize2(root->right);
//}
//
//// 叶子结点的个数
//// 遍历的思想
//void LeafSize(TreeNode *root, int *leaf_size) {
//	if (root == NULL) 
//		return;
//	if (root->left == NULL && root->right == NULL) 
//		(*leaf_size)++;
//	LeafSize(root->left, leaf_size);
//	LeafSize(root->right, leaf_size);
//}
//// 递推的思想
//int LeafSize2(TreeNode *root) {
//	if (root == NULL) 
//		return 0;
//	if (root->left == NULL && root->right == NULL) {
//		return 1;
//	// 递推
//	return LeafSize2(root->left) + LeafSize2(root->right);
//}
//
//// 求第 k 层结点个数
//// 用递推思想
//	int LevelK(TreeNode *root, int k) {
//		if (root == NULL) 
//			return 0;
//		// 这里肯定不是空树
//		if (k == 1) 
//			return 1;
//		// 递推
//		return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);
//	}
//	// 查找
//	TreeNode *Find(TreeNode *root, char x) {
//		if (root == NULL) 
//			return NULL;
//		// 根
//		if (root->val == x)
//			return root;
//		TreeNode *result = Find(root->left, x);
//		if (result != NULL) 
//			return result;
//		// 左子树肯定没找到
//		result = Find(root->right, x);
//		if (result != NULL) 
//			return result;
//		else 
//			return NULL;
//	}
//
//// 二叉树的前序 | 中序 | 后序   
////递归的版本
//	void Preorder(TreeNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		printf("%c ", root->val);	// 根
//		Preorder(root->left);		// 左子树
//		Preorder(root->right);		// 右子树
//	}
//
//	void Inorder(TreeNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		Inorder(root->left);		// 左子树
//		printf("%c ", root->val);	// 根
//		Inorder(root->right);		// 右子树
//	}
//
//	void Postorder(TreeNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		Postorder(root->left);		// 左子树
//		Postorder(root->right);		// 右子树
//		printf("%c ", root->val);	// 根
//	}
////  非递归写法     用栈实现
//	void PreorderTraversalNor(TreeNode *root)
//	{
//		TreeNode *cur = root;	// 遍历结点的指针
//		TreeNode *top;	// 返回栈顶数据的指针
//		TreeNode *last = NULL;
//		std::stack<TreeNode *>	st;// <> 模板，表示栈里存的数据类型是 TreeNode *
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// 第一次访问结点：cur
//				printf("%c ", cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// 从栈里取出栈顶元素
//			st.pop();
//			if (top->right == NULL) {
//				// 既是第二次访问，也是第三次访问
//				cur = top->right;
//				st.pop();
//				last = top;
//			}
//			else {
//				if (top->right != last)
//					// 第二次访问
//					cur = top->right;
//				else {
//					// 第三次访问
//					st.pop();
//					last = top;
//				}
//			}
//		}
//	}
//	void PreorderTraversalNor2(TreeNode *root)
//	{
//		TreeNode *cur = root;	// 遍历结点的指针
//		TreeNode *top;	// 返回栈顶数据的指针
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// 第一次访问结点：cur
//				printf("%c ", cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// 从栈里取出栈顶元素
//			st.pop();
//			cur = top->right;
//		}
//	}
//	void InorderTraversalNor(TreeNode *root)
//	{
//		TreeNode *cur = root;	// 遍历结点的指针
//		TreeNode *top;	// 返回栈顶数据的指针
//		TreeNode *last = NULL;
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// 第一次访问结点：cur
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// 从栈里取出栈顶元素
//			if (top->right == NULL) {
//				// 既是第二次访问，也是第三次访问
//				printf("%c ", top->val);
//				cur = top->right;
//				st.pop();
//				last = top;
//			}
//			else {
//				if (top->right != last) {
//					// 第二次访问
//					printf("%c ", top->val);
//					cur = top->right;
//				}
//				else {
//					// 第三次访问
//					st.pop();
//					last = top;
//				}
//			}
//		}
//	}
//	void InorderTraversalNor2(TreeNode *root)
//	{
//		TreeNode *cur = root;	// 遍历结点的指针
//		TreeNode *top;	// 返回栈顶数据的指针
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// 第一次访问结点：cur
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// 从栈里取出栈顶元素
//			// 既是第二次访问，也是第三次访问
//			printf("%c ", top->val);
//			cur = top->right;
//			st.pop();
//		}
//	}
//	void PostorderTraversalNor(TreeNode *root)
//	{
//		TreeNode *cur = root;	// 遍历结点的指针
//		TreeNode *top;	// 返回栈顶数据的指针
//		TreeNode *last = NULL;
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// 第一次访问结点：cur
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// 从栈里取出栈顶元素
//			if (top->right == NULL) {
//				// 既是第二次访问，也是第三次访问
//				printf("%c ", top->val);
//				cur = top->right;
//				st.pop();
//				last = top;
//			}
//			else {
//				if (top->right != last)
//					// 第二次访问
//					cur = top->right;
//				else {
//					// 第三次访问
//					printf("%c ", top->val);
//					st.pop();
//					last = top;
//				}
//			}
//		}
//	}
vector<int> res;
if (!root)
return res;
stack<TreeNode*> st;
st.push(root);//把根结点都入栈 
while (!st.empty()){//栈内没取完
	TreeNode* cur = st.top();
	res.push_back(cur->val);
	st.pop();
	if (cur->right)
		st.push(cur->right);
	if (cur->left)
		st.push(cur->left);
}
return res;


public List<Integer> preorderTraversal(TreeNode root) {
	return new ArrayList(){ {
		if (root != null) {
			add(root.val);
			addAll(preorderTraversal(root.left));
			addAll(preorderTraversal(root.right));
		}
	} };
}

作者：rremix - 2
链接：https://leetcode-cn.com/problems/two-sum/solution/di-gui-shi-xian-by-rremix-2-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。