////链表相交 之方式1:时间复杂度非常高O(n^2)  双指针遍历，若链表相交，返回任一地址
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		if (!headA || !headB)//任一者走到最后了还没找到
//			return nullptr;
//		while (headA)         //headA = headA->next，A的遍历
//		{
//			ListNode* tmp = headB;
//			if (headA == tmp)//第一个结点开始就要判断
//				return headA;
//			while (tmp->next != nullptr){
//				tmp = tmp->next;
//				if (headA == tmp)
//					return headA;
//			}
//			headA = headA->next;
//		}
//		return nullptr;
//	}
//};
//
////方式2：若相交，割去长度多的那条链表，再从前往后对比指针，若指针相同就输出指针
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		if (!headA || !headB)
//			return nullptr;
//		ListNode* countA = headA;
//		ListNode* countB = headB;
//		int lA = 0;
//		int lB = 0;
//		while (countA){
//			++lA;
//			countA = countA->next;
//		}//A 和 B 计数有多少结点
//		while (countB){
//			++lB;
//			countB = countB->next;
//		}
//		int i = max(lA, lB) - min(lA, lB);//它们之间的距离
//		if (lA > lB){
//			for (i; i > 0; i--)
//				headA = headA->next;//删1+1+1+1
//		}
//		else{
//			for (i; i > 0; i--)
//				headB = headB->next;
//		}
//
//		while (headA == headB)  {//处理结束，如果最后一个结点也不指向同一个空间，返回headA 
//				headA = headA->next;//下一个是空，直接返回
//				headB = headB->next;
//		}
//		return headA;
//	}
//};
////判断链表是否带环  双指针快慢遍历，当指针相同则相遇带环
////双指针快慢遍历
//class Solution {
//public:
//	bool hasCycle(ListNode *head) {
//		ListNode* slow = head;//都从头开始走
//		ListNode* fast = head;
//		while (fast != nullptr && fast->next != nullptr){
//			fast = fast->next->next;//一下走两步，就算走到空直接返回false
//			slow = slow->next;
//			if (fast == slow)//相遇即带环
//				return true;
//		}
//		return false;
//	}
//};
////返回链表的第一个结点
///*双指针快慢遍历
//设快慢指针第一次相遇时，fast走了f步，slow走了s步，
//设环的长度为c，从表头到入环点需走t步，那么：
//*（1）当fast指针追上slow指针时，fast比slow多走了n个环的长度，即 f = s + n * c；
//*（2）同时，因为fast一次走2步，slow一次走1步，因此有 f = 2s；
//*    由此可得：s = n * c，f = 2 * n * c     这是相遇情况下的满足条件
//*    将slow退到起始点，fast不动，然后每人一次各走一步：
//* 当slow走到入环点时，它走了t（ = 0 * c + t ）步；而此时fast走了 2 * n * c + t 步，也到达了入环点         s-t 与 f+t  照样f是2倍速
//* 说明他们正好相遇在了入环点。
//*/
//class Solution {
//public:
//	ListNode *detectCycle(ListNode *head) {
//		bool isCycle = false;//先判断是否带环，不带环直接返回NULL
//		ListNode* slow = head;//都从头开始走
//		ListNode* fast = head;
//		while (fast && fast->next)
//		{//找到他们相交的第一个结点
//			fast = fast->next->next;
//			slow = slow->next;
//			if (fast == slow){
//				isCycle = true;
//				break;//当相遇，要直接跳出循环
//			}//fast是第一个相遇的点
//		}//fast是第一个相遇的结点
//		if (!isCycle)//非环
//			return NULL;
//		slow = head;//当他们第一次相遇的时候，把slow置于head，和fast一起往后走，此时的相遇即入口
//		while (fast != slow){
//			fast = fast->next;
//			slow = slow->next;
//		}
//		return fast;
//	}
//};

//复制复杂链表

class Node {
public:int val;Node* next;Node* random;
Node() {}
Node(int _val, Node* _next, Node* _random) {val = _val;next = _next;random = _random;
}
};
//Round3：copy the next---->copy the random---->disconnect them  都需要去做一件事:cur = head
Node* copyRandomList(Node* head) {
	if (head == NULL)
		return NULL;//如果是空链表，直接返回空
	Node* cur = head;//1.copy原链表，先copy他们的结点，紧跟再原结点的后面
	while (cur != nullptr){
		Node* copy = new Node(cur->val, nullptr, nullptr);//申请新节点
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
	Node *copylist = head->next;
	while (cur && cur->next){
		Node* copy = cur->next;
		cur->next = cur->next->next;
		cur = copy;
	}
	return copylist;
}