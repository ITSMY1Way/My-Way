//删除重复结点 不保留

using namespace std;
//struct ListNode{
//	int val;//当前结点的值
//	struct ListNode *next;//下个结点
//	ListNode(int x) :
//		val(x), next(NULL) {}
//};
//class Solution {//递归
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)//结点为0/1直接返回头
//			return pHead;
//		if (pHead->val == pHead->next->val)//如果当前结点是重复结点
//		{
//			ListNode *cur = pHead->next;//cur用来走重复节点，和上个pHead比较
//			while (cur != NULL && cur->val == pHead->val)//条件含义：下个结点也是重复结点,
//				cur = cur->next;//cur遍历，直到走到第一个非重复结点
//			return deleteDuplication(cur);//以此达到更新pHead的目的     当此时的cur已非重复结点，传给pHead,继续判断
//		}
//		else
//		{//当前结点不是重复结点
//			pHead->next = deleteDuplication(pHead->next);//pHead非重复节点，继续更新
//			return pHead;//最后cur走到尾返回
//		}
//	}
//};
链表回文
//1.找到中间结点 + 反转 + 两者比较
ListNode* middleNode(ListNode* head){//找中间
	if (head == NULL)
		return NULL;
	ListNode* slow = slow;
	ListNode* fast = fast;
	while (1)
	{
		fast = fast->next;//2 4 6
		if (fast == NULL){
			break;
		}
		slow = slow->next;//2 3 4
		fast = fast->next;//3 5 7
		if (fast == NULL){
			break;
		}
	}
	return slow;//slow是中间结点的第一个
}
ListNode* reverseList(ListNode* head){//反转第一条
	if (head == NULL)
		return NULL;
	ListNode *cur, *prev, *next;
	prev = NULL;
	cur = head;
	next = head->next;
	while (cur != NULL){//cur是遍历
		cur->next = prev;//改变指向
		prev = cur;//更新cur
		cur = next;

		if (next != NULL)
			next = next->next;
	}
	return prev;//prev最后变成头,顺便断开两条
}
bool chkPalindrome(ListNode* A){
	ListNode * middle = middleNode(A);//middle是第一个
	ListNode * r = reverseList(middle->next);//反转后的前半条链表
	ListNode *n1 = A,   *n2 = r;
	while (n1 != NULL && n2 != NULL){
		if (n1->val != n2->val){
			return false;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	return true;
}
