//// ˳���ľ�̬�洢
//#define N 100
//typedef int SLDataType;
//
//typedef struct SeqList;
//{
//	SLDataType array[N];  //��������
//	size_t size;          //��Ч����ĸ���
//}SeqList;
//
////˳���Ķ�̬�洢
//typedef struct SeqList
//{
//	SLDataType* array;   //ָ��̬���ٵ�����
//	size_t size;   //��Ч������
//	size_t capicity;    //�����ռ�Ĵ�С
//}SeqList;

#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>//#include���������ؿ��ļ��ģ��ڲ�ͬ��C���Ա���ƽ̨�£�����һЩ���õĺ��������Բ���ǿ��������Ӧ�Ŀ��ļ���
//����Ƿ���Ҫ���ݣ���֤������������������
static void CheckCapacity(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size <= seqlist->capacity){
		return;//������������viod��ʱ������д�Ƿ��ؿ�,
	}          //�жϺ���ִ�У����ص��ú��������ɵ���һ�����ڷ���������������
	// �ߵ�����һ����Ҫ������
	int capacity = 2 * seqlist->capacity;
	SDataType* array = (SDataType*)malloc(sizeof(SDataType)* capacity);
	assert(array);
	//�������ݰ����
	for (int i = 0; i < seqlist->size; i++){
		array[i] = seqlist->array[i];
	}
	free(seqlist->array);
	seqlist->array = array;
}
void SeqListInit(SeqList *seqlist, int capacity)
{//��ʼ��
	assert(seqlist != NULL);
	seqlist->array = (SDataType*)malloc(sizeof(SDataType) * capacity);
	assert(seqlist->array);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}
void SeqListDestroy(SeqList *seqlist)
{//����
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	free(seqlist->array);/////////
	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
}
void SeqListPushFront(SeqList *seqlist, SDataType value)
{//ͷ�� 1.�Ӻ���ǰ�ᣬ��ֹ���ǣ�
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);//��������Ƿ���
	//2.ѭ����ȷ��ѭ���߽�, 2��Ԫ�صĻ���size=2,   ��Χ[size��0)
	//3.���ݰ��� iΪ�ռ��±� 
	for (int i = seqlist->size; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}
void SeqListPopFront(SeqList *seqlist)
{//ͷɾ
	assert(seqlist != 0);
	assert(seqlist->array != 0);
	assert(seqlist->size > 0);
	//���ݰ��ƣ�iΪ�����±꣬  ��Χ[1��size-1]
	for (int i = 1; i < seqlist->size; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}
void SeqListInsert(SeqList* seqlist, int pos, SDataType value)
{// �м���룬�� pos ���ڵ��±���� value
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos <= seqlist->size);
	CheckCapacity(seqlist);
	//�Ӻ���ǰ�������ݰ��ƣ������   
	// iΪ�����±�  ��Χ[i-1,pos]
	for (int i = seqlist->size-1; i >=pos; i--)
	{//��ͷ��
		seqlist->array[i+1] = seqlist->array[i ];	
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}
void SeqListErase(SeqList *seqlist, int pos)
{//ɾ�� pos ���ڵ��±������
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);//Ҫ��Ԫ�ز���ɾ
	assert(pos >= 0 && pos < seqlist->size);
	CheckCapacity(seqlist);
	//iΪ�����±� ��Χ[pos+1,size]
	for (int i = pos + 1; i < seqlist->size; i++){
		seqlist->array[i-1] = seqlist->array[i];
	}
	seqlist->size--;
}

void SeqListPushBack(SeqList *seqlist, SDataType value)
{//β��
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}
void SeqListPopBack(SeqList *seqlist){
//βɾ
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	seqlist->size--;
}
void SeqListPrint(const SeqList *seqlist)
{//��ӡ
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d  ", seqlist->array[i]);
	}
	printf("\n");
}
void SeqListModify(SeqList *seqlist, int pos, SDataType value)
{//�޸� pos �����±������Ϊ value
	assert(pos >= 0 && pos < seqlist->size);
	seqlist->array[pos] = value;
}
int SeqListFind(const SeqList *seqlist, SDataType value)
{//����
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] == value){
			return i;
		}		
	}
	return -1;
}
void SeqListRemove(SeqList *seqlist, SDataType value)
{//�ҵ���ɾ����һ��������value
	int pos = SeqListFind(seqlist, value);
	if (pos!= -1)
	{
		SeqListErase(seqlist, pos);
	}
}
bool SeqListEmpty(const SeqList *seqlist)
{// �ж�˳����Ƿ�Ϊ��
	return seqlist->size == 0;
}
int SeqListSize(const SeqList *seqlist)
{//�������ݸ���
	return seqlist->size;
}
void SeqListBubbleSort(SeqList* seqlist)
{//ð������ 
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	for (int a = seqlist->size; a > 0; --a)
	{
		int change = 0;
		for (int i = 1; i <a ; ++i)
		{  //ѭ���Ƚ� array[i]��array[i - 1] ��[i]С
			if (seqlist->array[i] < seqlist->array[i - 1]){
				SeqListInsert(seqlist, i - 1, seqlist->array[i]);//�����嵽�±�i - 1��λ��
				SeqListErase(seqlist, i + 1 );//����ɾȥ < ��������ֵarray[i],��ʱ�±��Ѹı䣬Ӧ��+1
					change = 1;
			}
		}
		if (change == 0)
			break;
}
}
int SeqListBinaryFind(SeqList* seqlist, SDataType value)//���ֲ���
{//�ҵ�����������֣�û�ҵ�����0.0
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	SeqListBubbleSort(seqlist);//������
	//scanf_s("%d", &value);
	int begin = 0;
	int end = seqlist->size - 1;
	while (begin <= end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (seqlist->array[mid] == value)
			printf("�ҵ����������%d\n",value);
		else if (value > seqlist->array[mid])
			begin = mid + 1;
		else
			end = mid - 1;
	}
	printf("û�ҵ�");
	return -1;
}
void SeqListRemoveAll(SeqList *seqlist, SDataType value)
{//ɾ��˳��������е�ָ����ֵ 
#if 0	// ʱ��O(N^2)	�ռ�O(1)
	int pos;//���ò��ҵĺ�������һ��ɾ��һ���������ѭ��
	while ((pos = SeqListFind(seqlist, value)) != -1) {
		SeqListErase(seqlist, pos);
	}
#endif

#if 0		// O(N)		O(N)
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)* seqlist->size);
	assert(array);            //����ռ䣬��������������
	int index = 0;
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] != value) {
			array[index] = seqlist->array[i];
			index++;
		}
	}
	for (int j = 0; j < index; j++) {
		seqlist->array[j] = array[j];
	}
	seqlist->size = index;
#endif
	int index = 0;
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] != value) {
			seqlist->array[index] = seqlist->array[i];
			index++;
		}
	}
	seqlist->size = index;
}
