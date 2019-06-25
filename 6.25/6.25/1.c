////// 2、带头双向循环链表
#include <stdio.h>
#include <stdlib.h>
//typedef int DLDataType;
////定义链表结点结构
//typedef struct DListNode{
//	DLDataType value;      //因为带头， 头结点的value没有意义
//	struct DListNode* prev;//指向前一个节点
//	struct DListNode* next;//指向后一个节点
//}DListNode;
////定义双向链表结构
//typedef struct DList{
//	DListNode  *head;       //表示链表的头节点
//}DList;
////申请结点
//DListNode* DListBuyNode(DLDataType value){
//	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
//	node->value = value;
//	node->prev = node->next = NULL;//申请的结点前后都是空
//	return node;
//}
////初始化
//void DListInit(DList * dlist){
//	dlist->head = DListBuyNode(0);//头节点的0只是为了传参，头的value没有意义
//	dlist->head->next = dlist->head;//双向的，要指回来
//	dlist->head->prev = dlist->head;//要循环，即向前指回它的头
//};
////销毁之 1.清空链表
//void DListClear(DList *dlist){
//	DListNode *cur, *next;
//	cur = dlist->head->next;//cur来表示当前遍历到的结点
//	while (cur != dlist->head)//只剩下head1的时候退出循环
//	{
//		next = cur->next;//走到下一个了再free
//		free(cur);
//		cur = next;//更新cur
//	}
//	dlist->head->next = dlist->head->prev = dlist->head;//即初始化
//}
////销毁之 2.彻底销毁链表  即额外做 销毁head
//void DListDestroy(DList *dlist){
//	DListClear(dlist);
//	free(dlist->head);
//	dlist->head = NULL;
//}
////在pos的前面插入
//void DListInsert(DListNode *pos, DLDataType value){
//	DListNode* node = DListBuyNode(value);
//	node->prev = pos->prev;
//	node->next = pos;
//	node->prev->next = node;
//	pos->prev = node;
//}
////删去pos结点
//void DListErase(DListNode *pos){
//	pos->prev->next = pos->next;
//	pos->next->prev = pos->prev;
//	free(pos);
//}
////头插
//void DListPushFront(DList * dlist, DLDataType value){
//	DListInsert(dlist->head->next, value);
//#if 0
//	DListNode* node = DListBuyNode(value);
//	node->prev = dlist->head;
//	node->next = dlist->head->next;
//	dlist->head->next = node;
//	node->next->prev = node;
//#endif
//}
////尾插
//void DListPushBack(DList *dlist, DLDataType value){
//#if 0
//	DListNode* node = DListBuyNode(value);
//	node->prev = dlist->head->prev;//先和旧的last建立关系
//	node->next = dlist->head;//安插的node指向head
//	node->prev->next = node;//旧last指向node
//	node->next->prev = node;//头指向最后一个结点
//#endif
//	DListInsert(dlist->head, value);//在头的前面插入 ---> 尾插
//}
////头删
//void DListPopFront(DList *dlist){
//	assert(dlist->head->next != dlist->head);//确定链表不为空
//#if 0
//	DListNode* cur = dlist->head->next;//这里的cur是要删除的结点
//	dlist->head->next->cur->next;
//	cur->next-<prev= dlist->head;
//	free(cur);
//#endif
//	void DListErase(dlist->head->next);
//}
////尾删
//void DListPopBack(DList *dlist){
//	assert(dlist->head->next != dlist->head);
//#if 0
//	DListNode* cur = dlist->head->prev;//cur是之前的last
//	cur->prev->next = dlist->head;
//	cur->next->prev = cur->prev;
//	free(cur);
//#endif
//	DListErase(dlist->head->prev);
//}
////查找结点
//DListNode * DListFind(const DList *dlist, DLDataType value){
//	DListNode* node;
//	DListNode* cur = dlist->head->next;//cur设置为第一个node，一直往后走遍历
//	while (cur != dlist->head)//
//	{
//		cur->next = cur;//一直往后走
//		if (cur->value == value)
//			return cur;
//	}
//	return NULL;
//}
////打印
//void DListPrint(const DList *dlist){
//	for (DListNode* cur = dlist->head->next; cur != dlist->head; cur = cur->next)
//	{
//		printf("%d --->", cur->value);
//	}
//	printf("\n");
//}



//OJ 之 删除单向链表所有的val
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return NULL;
	struct ListNode* prev = head;//prev用来保存找到的val，方便完成链表的重组
	struct ListNode* cur = head->next;//cur用来遍历结点
	//情况1 找到的val不是头
	while (cur != NULL){//遍历循环
		if (cur->val = val){//找到val了
			prev->next = cur->next;//保存指向要删除结点的指针
			free(cur);//删掉cur
			cur = prev->next;//cur free掉了，它要走到被删除的结点的后面
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	if (head->val == val){
		struct Listnode* newHead = head->next;
		free(head);
		return newHead;
	}
	else
		return head;

}
