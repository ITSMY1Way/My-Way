//typedef struct TreeNode {
//	struct TreeNode *left;//������
//	struct TreeNode *right;//������
//	char val;
//}	TreeNode;
//typedef struct Result {
//	TreeNode *root;	// ���������ĸ����
//	int used;		// �����������õ��� val ����
//}	Result;
////����������
//Result CreateTree(char preorder[], int size)
//{
//	//�������
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
//	//���Ʊ���
//	//��
//	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
//	root->val = rootVal;
//	root->left = root->right = NULL;
//	//������
//	Result left_result = CreateTree(preorder + 1, size - 1);
//	//������
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
//// ������������н��ĸ���
//// ������˼��
//void TreeSize(TreeNode *root, int *size) {
//	if (root == NULL) 
//		return;
//	(*size)++;
//	TreeSize(root->left, size);
//	TreeSize(root->right, size);
//}
//// ���Ƶ�˼��
//int TreeSize2(TreeNode *root) {
//	if (root == NULL) 
//		return 0;
//	return 1 + TreeSize2(root->left) + TreeSize2(root->right);
//}
//
//// Ҷ�ӽ��ĸ���
//// ������˼��
//void LeafSize(TreeNode *root, int *leaf_size) {
//	if (root == NULL) 
//		return;
//	if (root->left == NULL && root->right == NULL) 
//		(*leaf_size)++;
//	LeafSize(root->left, leaf_size);
//	LeafSize(root->right, leaf_size);
//}
//// ���Ƶ�˼��
//int LeafSize2(TreeNode *root) {
//	if (root == NULL) 
//		return 0;
//	if (root->left == NULL && root->right == NULL) {
//		return 1;
//	// ����
//	return LeafSize2(root->left) + LeafSize2(root->right);
//}
//
//// ��� k �������
//// �õ���˼��
//	int LevelK(TreeNode *root, int k) {
//		if (root == NULL) 
//			return 0;
//		// ����϶����ǿ���
//		if (k == 1) 
//			return 1;
//		// ����
//		return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);
//	}
//	// ����
//	TreeNode *Find(TreeNode *root, char x) {
//		if (root == NULL) 
//			return NULL;
//		// ��
//		if (root->val == x)
//			return root;
//		TreeNode *result = Find(root->left, x);
//		if (result != NULL) 
//			return result;
//		// �������϶�û�ҵ�
//		result = Find(root->right, x);
//		if (result != NULL) 
//			return result;
//		else 
//			return NULL;
//	}
//
//// ��������ǰ�� | ���� | ����   
////�ݹ�İ汾
//	void Preorder(TreeNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		printf("%c ", root->val);	// ��
//		Preorder(root->left);		// ������
//		Preorder(root->right);		// ������
//	}
//
//	void Inorder(TreeNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		Inorder(root->left);		// ������
//		printf("%c ", root->val);	// ��
//		Inorder(root->right);		// ������
//	}
//
//	void Postorder(TreeNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		Postorder(root->left);		// ������
//		Postorder(root->right);		// ������
//		printf("%c ", root->val);	// ��
//	}
////  �ǵݹ�д��     ��ջʵ��
//	void PreorderTraversalNor(TreeNode *root)
//	{
//		TreeNode *cur = root;	// ��������ָ��
//		TreeNode *top;	// ����ջ�����ݵ�ָ��
//		TreeNode *last = NULL;
//		std::stack<TreeNode *>	st;// <> ģ�壬��ʾջ�������������� TreeNode *
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// ��һ�η��ʽ�㣺cur
//				printf("%c ", cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// ��ջ��ȡ��ջ��Ԫ��
//			st.pop();
//			if (top->right == NULL) {
//				// ���ǵڶ��η��ʣ�Ҳ�ǵ����η���
//				cur = top->right;
//				st.pop();
//				last = top;
//			}
//			else {
//				if (top->right != last)
//					// �ڶ��η���
//					cur = top->right;
//				else {
//					// �����η���
//					st.pop();
//					last = top;
//				}
//			}
//		}
//	}
//	void PreorderTraversalNor2(TreeNode *root)
//	{
//		TreeNode *cur = root;	// ��������ָ��
//		TreeNode *top;	// ����ջ�����ݵ�ָ��
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// ��һ�η��ʽ�㣺cur
//				printf("%c ", cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// ��ջ��ȡ��ջ��Ԫ��
//			st.pop();
//			cur = top->right;
//		}
//	}
//	void InorderTraversalNor(TreeNode *root)
//	{
//		TreeNode *cur = root;	// ��������ָ��
//		TreeNode *top;	// ����ջ�����ݵ�ָ��
//		TreeNode *last = NULL;
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// ��һ�η��ʽ�㣺cur
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// ��ջ��ȡ��ջ��Ԫ��
//			if (top->right == NULL) {
//				// ���ǵڶ��η��ʣ�Ҳ�ǵ����η���
//				printf("%c ", top->val);
//				cur = top->right;
//				st.pop();
//				last = top;
//			}
//			else {
//				if (top->right != last) {
//					// �ڶ��η���
//					printf("%c ", top->val);
//					cur = top->right;
//				}
//				else {
//					// �����η���
//					st.pop();
//					last = top;
//				}
//			}
//		}
//	}
//	void InorderTraversalNor2(TreeNode *root)
//	{
//		TreeNode *cur = root;	// ��������ָ��
//		TreeNode *top;	// ����ջ�����ݵ�ָ��
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// ��һ�η��ʽ�㣺cur
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// ��ջ��ȡ��ջ��Ԫ��
//			// ���ǵڶ��η��ʣ�Ҳ�ǵ����η���
//			printf("%c ", top->val);
//			cur = top->right;
//			st.pop();
//		}
//	}
//	void PostorderTraversalNor(TreeNode *root)
//	{
//		TreeNode *cur = root;	// ��������ָ��
//		TreeNode *top;	// ����ջ�����ݵ�ָ��
//		TreeNode *last = NULL;
//		std::stack<TreeNode *>	st;
//		while (!st.empty() || cur != NULL) {
//			while (cur != NULL) {
//				// ��һ�η��ʽ�㣺cur
//				st.push(cur);
//				cur = cur->left;
//			}
//			top = st.top();	// ��ջ��ȡ��ջ��Ԫ��
//			if (top->right == NULL) {
//				// ���ǵڶ��η��ʣ�Ҳ�ǵ����η���
//				printf("%c ", top->val);
//				cur = top->right;
//				st.pop();
//				last = top;
//			}
//			else {
//				if (top->right != last)
//					// �ڶ��η���
//					cur = top->right;
//				else {
//					// �����η���
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
st.push(root);//�Ѹ���㶼��ջ 
while (!st.empty()){//ջ��ûȡ��
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

���ߣ�rremix - 2
���ӣ�https://leetcode-cn.com/problems/two-sum/solution/di-gui-shi-xian-by-rremix-2-2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������