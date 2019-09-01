#pragma once//用于解释本文件中的内容只应用一次,够保证头文件被编译一次,防止某个头文件被多次include
#include <stdint.h>
#include<stdbool.h>
typedef int SDataType;
typedef struct SeqList{
	SDataType *array;  //指向动态开辟的数组—>堆上的空间
	int size;       //有效数据个数—>表示当前数组里面有多少个数，顺便表示了即将插入的下标
	int capacity;    //容量空间的大小
}SeqList;
//初始化 seqlist是一个变量的地址，capacity表示顺序表的初始容量
void SeqListInit(SeqList* seqlist, int capacity);
//销毁
void SeqListDestory(SeqList* seqlist);
//增删改查 之 尾插
void SeqListPushBack(SeqList* seqlist, SDataType value);
//头插
void SeqListPushFront(SeqList* seqlist, SDataType value);
// 中间插入，往 pos 所在的下标插入 value
void SeqListInsert(SeqList* seqlist, int pos, SDataType value);
//尾删
void SeqListPopBack(SeqList* seqlist);
//头删
void SeqListPopFront(SeqList* seqlist);
//删除 pos 所在的下标的数据
void SeqListErase(SeqList *seqlist, int pos);
// 打印
void SeqListPrint(const SeqList *seqlist);
// 修改 pos 所在下标的数据为 value
void SeqListModify(SeqList *seqlist, int pos, SDataType value);
// 查找    如果找到，返回第一个找到的下标; 如果没找到，返回 -1
int SeqListFind(const SeqList *seqlist, SDataType value);
// 找到并删除第一个遇到的 value
void SeqListRemove(SeqList *seqlist, SDataType value);
// 判断顺序表是否为空
bool SeqListEmpty(const SeqList *seqlist);
// 返回数据个数
int SeqListSize(const SeqList *seqlist);
//顺序表的冒泡排序
void SeqListBubbleSort(SeqList* seqlist);
//二分查找
int SeqListBinaryFind(SeqList* seqlist, SDataType value);
//删除顺序表中所有的指定的值 
void SeqListRemoveAll(SeqList* seqlist, SDataType value);
