////// 2����ͷ˫��ѭ������
#include <stdio.h>
#include <stdlib.h>
//typedef int DLDataType;
////����������ṹ
//typedef struct DListNode{
//	DLDataType value;      //��Ϊ��ͷ�� ͷ����valueû������
//	struct DListNode* prev;//ָ��ǰһ���ڵ�
//	struct DListNode* next;//ָ���һ���ڵ�
//}DListNode;
////����˫������ṹ
//typedef struct DList{
//	DListNode  *head;       //��ʾ�����ͷ�ڵ�
//}DList;
////������
//DListNode* DListBuyNode(DLDataType value){
//	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
//	node->value = value;
//	node->prev = node->next = NULL;//����Ľ��ǰ���ǿ�
//	return node;
//}
////��ʼ��
//void DListInit(DList * dlist){
//	dlist->head = DListBuyNode(0);//ͷ�ڵ��0ֻ��Ϊ�˴��Σ�ͷ��valueû������
//	dlist->head->next = dlist->head;//˫��ģ�Ҫָ����
//	dlist->head->prev = dlist->head;//Ҫѭ��������ǰָ������ͷ
//};
////����֮ 1.�������
//void DListClear(DList *dlist){
//	DListNode *cur, *next;
//	cur = dlist->head->next;//cur����ʾ��ǰ�������Ľ��
//	while (cur != dlist->head)//ֻʣ��head1��ʱ���˳�ѭ��
//	{
//		next = cur->next;//�ߵ���һ������free
//		free(cur);
//		cur = next;//����cur
//	}
//	dlist->head->next = dlist->head->prev = dlist->head;//����ʼ��
//}
////����֮ 2.������������  �������� ����head
//void DListDestroy(DList *dlist){
//	DListClear(dlist);
//	free(dlist->head);
//	dlist->head = NULL;
//}
////��pos��ǰ�����
//void DListInsert(DListNode *pos, DLDataType value){
//	DListNode* node = DListBuyNode(value);
//	node->prev = pos->prev;
//	node->next = pos;
//	node->prev->next = node;
//	pos->prev = node;
//}
////ɾȥpos���
//void DListErase(DListNode *pos){
//	pos->prev->next = pos->next;
//	pos->next->prev = pos->prev;
//	free(pos);
//}
////ͷ��
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
////β��
//void DListPushBack(DList *dlist, DLDataType value){
//#if 0
//	DListNode* node = DListBuyNode(value);
//	node->prev = dlist->head->prev;//�Ⱥ;ɵ�last������ϵ
//	node->next = dlist->head;//�����nodeָ��head
//	node->prev->next = node;//��lastָ��node
//	node->next->prev = node;//ͷָ�����һ�����
//#endif
//	DListInsert(dlist->head, value);//��ͷ��ǰ����� ---> β��
//}
////ͷɾ
//void DListPopFront(DList *dlist){
//	assert(dlist->head->next != dlist->head);//ȷ������Ϊ��
//#if 0
//	DListNode* cur = dlist->head->next;//�����cur��Ҫɾ���Ľ��
//	dlist->head->next->cur->next;
//	cur->next-<prev= dlist->head;
//	free(cur);
//#endif
//	void DListErase(dlist->head->next);
//}
////βɾ
//void DListPopBack(DList *dlist){
//	assert(dlist->head->next != dlist->head);
//#if 0
//	DListNode* cur = dlist->head->prev;//cur��֮ǰ��last
//	cur->prev->next = dlist->head;
//	cur->next->prev = cur->prev;
//	free(cur);
//#endif
//	DListErase(dlist->head->prev);
//}
////���ҽ��
//DListNode * DListFind(const DList *dlist, DLDataType value){
//	DListNode* node;
//	DListNode* cur = dlist->head->next;//cur����Ϊ��һ��node��һֱ�����߱���
//	while (cur != dlist->head)//
//	{
//		cur->next = cur;//һֱ������
//		if (cur->value == value)
//			return cur;
//	}
//	return NULL;
//}
////��ӡ
//void DListPrint(const DList *dlist){
//	for (DListNode* cur = dlist->head->next; cur != dlist->head; cur = cur->next)
//	{
//		printf("%d --->", cur->value);
//	}
//	printf("\n");
//}



//OJ ֮ ɾ�������������е�val
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return NULL;
	struct ListNode* prev = head;//prev���������ҵ���val������������������
	struct ListNode* cur = head->next;//cur�����������
	//���1 �ҵ���val����ͷ
	while (cur != NULL){//����ѭ��
		if (cur->val = val){//�ҵ�val��
			prev->next = cur->next;//����ָ��Ҫɾ������ָ��
			free(cur);//ɾ��cur
			cur = prev->next;//cur free���ˣ���Ҫ�ߵ���ɾ���Ľ��ĺ���
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
