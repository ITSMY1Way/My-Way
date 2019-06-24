//#include <stdlib.h>
//#include <assert.h>
//#include <stdio.h>
////��ͷ��ѭ����������
//typedef int SLDataType;
//typedef struct SLNode{
//	SLDataType value;//����ڵ��ֵ
//	struct SLNode *next;//ָ���¸��ڵ�
//}SListNode;//����ڵ�
//typedef struct SList{
//	SListNode* first;    //  SLNode *head ��ͷ����ĵ�һ���ڵ�
//}	SList;//ʵ������ṹ
////��ʼ��
//void SListInit(SList *list){
//	assert(list != NULL);
//	list->first = NULL;
//}
////����
//void SListDestroy(SList *list){
//	assert(list != NULL);
//	SListNode* cur = list->first;//cur ָ��ǰ�ڵ�
//	SLDataType* next;
//	while (cur != NULL)
//	{
//		next = cur->next;//������һ���ڵ�
//		free(cur);//�ͷŵ�ǰ�ڵ�
//		cur = next;//cur��ָ���¸��ڵ�
//	}
//	list->first = NULL;
//}
////�����½ڵ�
//SListNode * SListBuyNode(SLDataType value){
//	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
//	assert(node);
//	node->value = value;
//	node->next = NULL;
//	return node;
//}
//// ͷ��
//void SListPushFront(SList *list, SLDataType value){
//	assert(list != NULL);
//	SListNode* node =  SListBuyNode(value);//�����½ڵ�
//	node->next =list->first;//���ȥ
//	list->first = node;//����first
//}
////β��
//void SListPushBack(SList *list, SLDataType value){
//	assert(list != NULL);
//	//����ǿ�����������β����൱��ͷ��
//	if (list->first == NULL){
//		SListPushFront(list, value);
//		return;
//	}
//	SListNode* cur; //cur ָ��ǰ�ڵ�
//	for (cur = list->first; cur->next != NULL; cur = cur->next){//�ҵ����һ���ڵ�
//		//cur�������һ���ڵ�
//	}SListNode* node = SListBuyNode(value);
//	cur->next = node;
//}
////ͷɾ
//void SListPopFront(SList *list){
//	assert( list != NULL);
//	assert(list->first != NULL);
//	SListNode* old_first = list->first;
//	list->first= list->first->next;
//	free(old_first);
//}
////βɾ
//void SListPopBack(SList *list)
//{
//	assert(list != NULL);
//	assert(list->first != NULL);
//	if (list->first->next == NULL)//���ֻ��һ�����
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
////��pos�ĺ�����в��룬posһ���������ֵ�һ����Ч�ڵ�
//void SListInsertAfter(SListNode *pos, SLDataType value){
//	SListNode* node = SListBuyNode(value);//�ȸ�value����ڵ�
//	node->next = pos->next;//value���ڵĽڵ�nodeָ��pos
//	pos->next = node;//pos�ڵ�Ҫ����ָ������node�ڵ�
//}
////ɾ��pos��Ľڵ�
//void SListEraseAfter(SListNode *pos){
//	SListNode* next = pos->next;//nextָ��ָ��pos����һ���ڵ㣬����nextȥ����pos->next
//	pos->next = next->next;//pos����Ҫָ��pos->next��next ��next->next
//	free(next);
//}
////��posǰ���в���
//void SListInsertBefore(SList *list, SListNode *pos, SLDataType value){
//	SListNode* cur = list->first;
//	while (cur->next != pos){
//		
//	}
//	SListNode* node = SListBuyNode(value);
//	node->next = pos;
//	cur->next = node;
//}
////����node�ڵ��ֵ
//void SListUpdate(SListNode *node, SLDataType value){
//	node->value = value;
//}
////ȥ�������е�һ��value��û�ҵ�����NULL
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
////��ӡ
//void SListPrint(const SList *list){
//	for (SListNode* cur = list->first; cur != NULL; cur = cur->next){
//		printf("%d --->", cur->value);
//	}
//	printf("NULL\n");
//}
//int main()
//{
//	SList list;//ʵ������ṹ
//	SListInit(&list);//��ʼ������
//	SListPushFront(&list,1);
//	SListPushFront(&list,2);
//	SListPushFront(&list,3);
//	SListPrint(&list);
//	getchar();
//	return 0;
//}
//// 2����ͷ˫��ѭ������
#include <stdio.h>
#include <stdlib.h>
typedef int DLDataType;
//����������ṹ
typedef struct DListNode{
	DLDataType value;      //��Ϊ��ͷ�� ͷ����valueû������
	struct DListNode* prev;//ָ��ǰһ���ڵ�
	struct DListNode* next;//ָ���һ���ڵ�
}DListNode;
//����˫������ṹ
typedef struct DList{
	DListNode  *head;       //��ʾ�����ͷ�ڵ�
}DList;
//������
DListNode* DListBuyNode(DLDataType value){
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->value = value;
	node->prev = node->next = NULL;//����Ľ��ǰ���ǿ�
	return node;
}
//��ʼ��
void DListInit(DList * dlist){
	dlist->head = DListBuyNode(0);//ͷ�ڵ��0ֻ��Ϊ�˴��Σ�ͷ��valueû������
	dlist->head->next = dlist->head;//˫��ģ�Ҫָ����
	dlist->head->prev = dlist->head;//Ҫѭ��������ǰָ������ͷ
};
//����֮ 1.�������
void DListClear(DList *dlist){
	DListNode *cur, *next;
	cur = dlist->head->next;//cur����ʾ��ǰ�������Ľ��
	while (cur != dlist->head)//ֻʣ��head1��ʱ���˳�ѭ��
	{
		next = cur->next;//�ߵ���һ������free
		free(cur);
		cur = next;//����cur
	}
	dlist->head->next = dlist->head->prev = dlist->head;//����ʼ��
}
//����֮ 2.������������  �������� ����head
void DListDestroy(DList *dlist){
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}
//��pos��ǰ�����
void DListInsert(DListNode *pos, DLDataType value){
	DListNode* node = DListBuyNode(value);
	node->prev = pos->prev;
	node->next = pos;
	node->prev->next = node;
	pos->prev = node;                                                                                                                                                    
}
//ɾȥpos���
void DListErase(DListNode *pos){
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//ͷ��
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
