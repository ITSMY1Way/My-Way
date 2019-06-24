//#include <stdlib.h>
//#include <assert.h>
//#include <stdio.h>
////无头非循环单向链表
//typedef int SLDataType;
//typedef struct SLNode{
//	SLDataType value;//这个节点的值
//	struct SLNode *next;//指向下个节点
//}SListNode;//定义节点
//typedef struct SList{
//	SListNode* first;    //  SLNode *head 无头链表的第一个节点
//}	SList;//实现链表结构
////初始化
//void SListInit(SList *list){
//	assert(list != NULL);
//	list->first = NULL;
//}
////销毁
//void SListDestroy(SList *list){
//	assert(list != NULL);
//	SListNode* cur = list->first;//cur 指向当前节点
//	SLDataType* next;
//	while (cur != NULL)
//	{
//		next = cur->next;//保存下一个节点
//		free(cur);//释放当前节点
//		cur = next;//cur再指向下个节点
//	}
//	list->first = NULL;
//}
////申请新节点
//SListNode * SListBuyNode(SLDataType value){
//	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
//	assert(node);
//	node->value = value;
//	node->next = NULL;
//	return node;
//}
//// 头插
//void SListPushFront(SList *list, SLDataType value){
//	assert(list != NULL);
//	SListNode* node =  SListBuyNode(value);//申请新节点
//	node->next =list->first;//插进去
//	list->first = node;//更新first
//}
////尾插
//void SListPushBack(SList *list, SLDataType value){
//	assert(list != NULL);
//	//如果是空链表的情况，尾插就相当于头插
//	if (list->first == NULL){
//		SListPushFront(list, value);
//		return;
//	}
//	SListNode* cur; //cur 指向当前节点
//	for (cur = list->first; cur->next != NULL; cur = cur->next){//找到最后一个节点
//		//cur就是最后一个节点
//	}SListNode* node = SListBuyNode(value);
//	cur->next = node;
//}
////头删
//void SListPopFront(SList *list){
//	assert( list != NULL);
//	assert(list->first != NULL);
//	SListNode* old_first = list->first;
//	list->first= list->first->next;
//	free(old_first);
//}
////尾删
//void SListPopBack(SList *list)
//{
//	assert(list != NULL);
//	assert(list->first != NULL);
//	if (list->first->next == NULL)//如果只有一个结点
//	{
//		SListPopFront(list);
//		return;
//	}
//	SListNode* cur = NULL;
//	for (cur = list->first;cur->next->next != NULL; cur = cur-> next){
//	}
//	free(cur->next);
//	cur->next = NULL;
//}
////在pos的后面进行插入，pos一定是链表种的一个有效节点
//void SListInsertAfter(SListNode *pos, SLDataType value){
//	SListNode* node = SListBuyNode(value);//先给value申请节点
//	node->next = pos->next;//value所在的节点node指向pos
//	pos->next = node;//pos节点要重新指向插入的node节点
//}
////删除pos后的节点
//void SListEraseAfter(SListNode *pos){
//	SListNode* next = pos->next;//next指针指向pos的下一个节点，即用next去保存pos->next
//	pos->next = next->next;//pos现在要指向pos->next的next 即next->next
//	free(next);
//}
////在pos前进行插入
//void SListInsertBefore(SList *list, SListNode *pos, SLDataType value){
//	SListNode* cur = list->first;
//	while (cur->next != pos){
//		
//	}
//	SListNode* node = SListBuyNode(value);
//	node->next = pos;
//	cur->next = node;
//}
////更改node节点的值
//void SListUpdate(SListNode *node, SLDataType value){
//	node->value = value;
//}
////去找链表中第一个value，没找到返回NULL
//SListNode * SListFind(const SList *list, SLDataType value){
//	SListNode* cur = list->first;
//	while (cur != NULL){
//		if (cur->value == value){
//			return cur;
//		}
//	}
//	return NULL;
//}
//
////打印
//void SListPrint(const SList *list){
//	for (SListNode* cur = list->first; cur != NULL; cur = cur->next){
//		printf("%d --->", cur->value);
//	}
//	printf("NULL\n");
//}
//int main()
//{
//	SList list;//实现链表结构
//	SListInit(&list);//初始化链表
//	SListPushFront(&list,1);
//	SListPushFront(&list,2);
//	SListPushFront(&list,3);
//	SListPrint(&list);
//	getchar();
//	return 0;
//}
//// 2、带头双向循环链表
#include <stdio.h>
#include <stdlib.h>
typedef int DLDataType;
//定义链表结点结构
typedef struct DListNode{
	DLDataType value;      //因为带头， 头结点的value没有意义
	struct DListNode* prev;//指向前一个节点
	struct DListNode* next;//指向后一个节点
}DListNode;
//定义双向链表结构
typedef struct DList{
	DListNode  *head;       //表示链表的头节点
}DList;
//申请结点
DListNode* DListBuyNode(DLDataType value){
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->value = value;
	node->prev = node->next = NULL;//申请的结点前后都是空
	return node;
}
//初始化
void DListInit(DList * dlist){
	dlist->head = DListBuyNode(0);//头节点的0只是为了传参，头的value没有意义
	dlist->head->next = dlist->head;//双向的，要指回来
	dlist->head->prev = dlist->head;//要循环，即向前指回它的头
};
//销毁之 1.清空链表
void DListClear(DList *dlist){
	DListNode *cur, *next;
	cur = dlist->head->next;//cur来表示当前遍历到的结点
	while (cur != dlist->head)//只剩下head1的时候退出循环
	{
		next = cur->next;//走到下一个了再free
		free(cur);
		cur = next;//更新cur
	}
	dlist->head->next = dlist->head->prev = dlist->head;//即初始化
}
//销毁之 2.彻底销毁链表  即额外做 销毁head
void DListDestroy(DList *dlist){
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}
//在pos的前面插入
void DListInsert(DListNode *pos, DLDataType value){
	DListNode* node = DListBuyNode(value);
	node->prev = pos->prev;
	node->next = pos;
	node->prev->next = node;
	pos->prev = node;                                                                                                                                                    
}
//删去pos结点
void DListErase(DListNode *pos){
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//头插
void DListPushFront(DList * dlist, DLDataType value){
	DListInsert(dlist->head->next, value);
#if 0
	DListNode* node = DListBuyNode(value);
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next = node;
	node->next->prev = node;
#endif
}
