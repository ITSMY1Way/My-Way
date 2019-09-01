#pragma once//���ڽ��ͱ��ļ��е�����ֻӦ��һ��,����֤ͷ�ļ�������һ��,��ֹĳ��ͷ�ļ������include
#include <stdint.h>
#include<stdbool.h>
typedef int SDataType;
typedef struct SeqList{
	SDataType *array;  //ָ��̬���ٵ����顪>���ϵĿռ�
	int size;       //��Ч���ݸ�����>��ʾ��ǰ���������ж��ٸ�����˳���ʾ�˼���������±�
	int capacity;    //�����ռ�Ĵ�С
}SeqList;
//��ʼ�� seqlist��һ�������ĵ�ַ��capacity��ʾ˳���ĳ�ʼ����
void SeqListInit(SeqList* seqlist, int capacity);
//����
void SeqListDestory(SeqList* seqlist);
//��ɾ�Ĳ� ֮ β��
void SeqListPushBack(SeqList* seqlist, SDataType value);
//ͷ��
void SeqListPushFront(SeqList* seqlist, SDataType value);
// �м���룬�� pos ���ڵ��±���� value
void SeqListInsert(SeqList* seqlist, int pos, SDataType value);
//βɾ
void SeqListPopBack(SeqList* seqlist);
//ͷɾ
void SeqListPopFront(SeqList* seqlist);
//ɾ�� pos ���ڵ��±������
void SeqListErase(SeqList *seqlist, int pos);
// ��ӡ
void SeqListPrint(const SeqList *seqlist);
// �޸� pos �����±������Ϊ value
void SeqListModify(SeqList *seqlist, int pos, SDataType value);
// ����    ����ҵ������ص�һ���ҵ����±�; ���û�ҵ������� -1
int SeqListFind(const SeqList *seqlist, SDataType value);
// �ҵ���ɾ����һ�������� value
void SeqListRemove(SeqList *seqlist, SDataType value);
// �ж�˳����Ƿ�Ϊ��
bool SeqListEmpty(const SeqList *seqlist);
// �������ݸ���
int SeqListSize(const SeqList *seqlist);
//˳����ð������
void SeqListBubbleSort(SeqList* seqlist);
//���ֲ���
int SeqListBinaryFind(SeqList* seqlist, SDataType value);
//ɾ��˳��������е�ָ����ֵ 
void SeqListRemoveAll(SeqList* seqlist, SDataType value);
