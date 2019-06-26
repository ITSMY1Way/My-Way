#include <stdio.h>
////OJ 之 删除单向链表所有的val
//struct ListNode* removeElements(struct ListNode* head, int val){
//	if (head == NULL)
//		return NULL;
//	struct ListNode* prev = head;//prev用来保存找到的val，方便完成链表的重组
//	struct ListNode* cur = head->next;//cur用来遍历结点
//	//情况1 找到的val不是头
//	while (cur != NULL){//遍历循环
//		if (cur->val = val){//找到val了
//			prev->next = cur->next;//保存指向要删除结点的指针
//			free(cur);//删掉cur
//			cur = prev->next;//cur free掉了，它要走到被删除的结点的后面
//		}
//		else{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	if (head->val == val){
//		struct Listnode* newHead = head->next;
//		free(head);
//		return newHead;
//	}
//	else
//		return head;
//
//}
//2.反转单链表之 方式 1    头删+尾插
//struct ListNode* reverseList(struct ListNode* head){
//	struct ListNode* ret = NULL;//ret从NULL开始往后走
//	while (head != NULL){//判空链表
//		struct ListNode* node = head;//node同步head，即往后遍历
//		head = head->next;//设立head只是为了方便node的遍历
//		node->next = ret;// 改变node结点的指针指向
//		ret = node;//同步ret，ret要保持在node的前面
//	}
//	return ret;
//}
////方式2   三指针法
//struct ListNode* reverseList(struct ListNode* head){
//	struct ListNode *prev, *cur, *tmp;
//	prev = NULL;
//	cur = head;
//	if (head == NULL)
//		return head;
//	while (cur != 0)
//	{
//		tmp = cur->next;//遍历
//		cur->next = prev;//cur指向前面
//		prev = cur;//prev往后走  
//		cur = tmp;//遍历
//	}
//	return prev;
//}
////给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
//struct ListNode* middleNode(struct ListNode* head){
//	if (head == NULL)
//	return NULL;
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;//双指针游走，慢的走一下，快的两下
//	while (1)
//	{
//		fast = fast->next;
//		if (fast == NULL)
//			break;
//
//		slow = slow->next;
//
//		fast = fast->next;
//		if (fast == NULL)
//			break;	
//	}
//	return slow;
//}
//删除链表的倒数第 n 个节点，并且返回链表的头结点。
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
//	struct ListNode* fast = fast;
//	struct ListNode* slow = slow;
//	fast = slow = head;//都在头
//	for (int count = 0; count < n - 1; count++){
//		fast = fast->next;//fast领先slow  n-1下
//	}
//	if (fast->next == NULL){//如果n就是它的结点数
//		struct ListNode* newhead = head->next;//新头变成旧头的下一个
//		free(head);
//		return newhead;//返回新头
//	}
//	else{
//		struct ListNode* oldslow = slow;
//		while (fast->next != NULL){
//			oldslow = slow;//保存上一个slow
//			fast = fast->next;
//			slow = slow->next;
//		}
//		oldslow->next = oldslow->next->next;
//		free(slow);
//	}
//	return head;//返回慢的 
//}
//合并2个链表
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	if (l1->val < l2->val){
//		l1->next = mergeTwoLists(l1->next, l2);
//		return l1;
//	}
//	else{
//		l2->next = mergeTwoLists(l1, l2->next);
//		return l2;
//	}
//}
//以x割成两部分，所有小于x的结点排在大于或等于x的结点之前 
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {

		ListNode* slist = new ListNode(-1);
		ListNode* blist = new ListNode(-1);
		ListNode *cur = pHead, *pslist = slist, *pblist = blist;
		while (cur)
		{
			if (cur->val<x){
				pslist->next = cur;
				pslist = cur;
			}
			else{
				pblist->next = cur;
				pblist = cur;
			}
			cur = cur->next;
		}
		pblist->next = nullptr;
		pslist->next = blist->next;
		return slist->next;
	}
};