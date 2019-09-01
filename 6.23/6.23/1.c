//// 顺序表的静态存储
//#define N 100
//typedef int SLDataType;
//
//typedef struct SeqList;
//{
//	SLDataType array[N];  //定长数组
//	size_t size;          //有效数组的个数
//}SeqList;
//
////顺序表的动态存储
//typedef struct SeqList
//{
//	SLDataType* array;   //指向动态开辟的数组
//	size_t size;   //有效数个数
//	size_t capicity;    //容量空间的大小
//}SeqList;

#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>//#include是用来加载库文件的，在不同的C语言编译平台下，对于一些常用的函数，可以不可强调加载相应的库文件。
//检查是否需要扩容，保证函数结束后容量够用
static void CheckCapacity(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size <= seqlist->capacity){
		return;//当函数类型是viod的时候，这样写是返回空,
	}          //中断函数执行，返回调用函数处，可当成一个用于返回主函数的命令
	// 走到这里一定需要扩容了
	int capacity = 2 * seqlist->capacity;
	SDataType* array = (SDataType*)malloc(sizeof(SDataType)* capacity);
	assert(array);
	//把老数据搬过来
	for (int i = 0; i < seqlist->size; i++){
		array[i] = seqlist->array[i];
	}
	free(seqlist->array);
	seqlist->array = array;
}
void SeqListInit(SeqList *seqlist, int capacity)
{//初始化
	assert(seqlist != NULL);
	seqlist->array = (SDataType*)malloc(sizeof(SDataType) * capacity);
	assert(seqlist->array);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}
void SeqListDestroy(SeqList *seqlist)
{//销毁
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	free(seqlist->array);/////////
	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
}
void SeqListPushFront(SeqList *seqlist, SDataType value)
{//头插 1.从后往前搬，防止覆盖；
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);//检查容量是否够用
	//2.循环，确定循环边界, 2个元素的话，size=2,   范围[size，0)
	//3.数据搬移 i为空间下标 
	for (int i = seqlist->size; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}
void SeqListPopFront(SeqList *seqlist)
{//头删
	assert(seqlist != 0);
	assert(seqlist->array != 0);
	assert(seqlist->size > 0);
	//数据搬移，i为数组下标，  范围[1，size-1]
	for (int i = 1; i < seqlist->size; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}
void SeqListInsert(SeqList* seqlist, int pos, SDataType value)
{// 中间插入，往 pos 所在的下标插入 value
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos <= seqlist->size);
	CheckCapacity(seqlist);
	//从后往前进行数据搬移，往后搬   
	// i为数组下标  范围[i-1,pos]
	for (int i = seqlist->size-1; i >=pos; i--)
	{//即头插
		seqlist->array[i+1] = seqlist->array[i ];	
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}
void SeqListErase(SeqList *seqlist, int pos)
{//删除 pos 所在的下标的数据
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);//要有元素才能删
	assert(pos >= 0 && pos < seqlist->size);
	CheckCapacity(seqlist);
	//i为数组下标 范围[pos+1,size]
	for (int i = pos + 1; i < seqlist->size; i++){
		seqlist->array[i-1] = seqlist->array[i];
	}
	seqlist->size--;
}

void SeqListPushBack(SeqList *seqlist, SDataType value)
{//尾插
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}
void SeqListPopBack(SeqList *seqlist){
//尾删
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	seqlist->size--;
}
void SeqListPrint(const SeqList *seqlist)
{//打印
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d  ", seqlist->array[i]);
	}
	printf("\n");
}
void SeqListModify(SeqList *seqlist, int pos, SDataType value)
{//修改 pos 所在下标的数据为 value
	assert(pos >= 0 && pos < seqlist->size);
	seqlist->array[pos] = value;
}
int SeqListFind(const SeqList *seqlist, SDataType value)
{//查找
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] == value){
			return i;
		}		
	}
	return -1;
}
void SeqListRemove(SeqList *seqlist, SDataType value)
{//找到并删除第一个遇到的value
	int pos = SeqListFind(seqlist, value);
	if (pos!= -1)
	{
		SeqListErase(seqlist, pos);
	}
}
bool SeqListEmpty(const SeqList *seqlist)
{// 判断顺序表是否为空
	return seqlist->size == 0;
}
int SeqListSize(const SeqList *seqlist)
{//返回数据个数
	return seqlist->size;
}
void SeqListBubbleSort(SeqList* seqlist)
{//冒泡排序 
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	for (int a = seqlist->size; a > 0; --a)
	{
		int change = 0;
		for (int i = 1; i <a ; ++i)
		{  //循环比较 array[i]与array[i - 1] 若[i]小
			if (seqlist->array[i] < seqlist->array[i - 1]){
				SeqListInsert(seqlist, i - 1, seqlist->array[i]);//把它插到下标i - 1的位置
				SeqListErase(seqlist, i + 1 );//并且删去 < 操作符左值array[i],此时下标已改变，应该+1
					change = 1;
			}
		}
		if (change == 0)
			break;
}
}
int SeqListBinaryFind(SeqList* seqlist, SDataType value)//二分查找
{//找到返回这个数字，没找到返回0.0
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	SeqListBubbleSort(seqlist);//先排序
	//scanf_s("%d", &value);
	int begin = 0;
	int end = seqlist->size - 1;
	while (begin <= end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (seqlist->array[mid] == value)
			printf("找到了这个数是%d\n",value);
		else if (value > seqlist->array[mid])
			begin = mid + 1;
		else
			end = mid - 1;
	}
	printf("没找到");
	return -1;
}
void SeqListRemoveAll(SeqList *seqlist, SDataType value)
{//删除顺序表中所有的指定的值 
#if 0	// 时间O(N^2)	空间O(1)
	int pos;//调用查找的函数，查一个删除一个，，如此循环
	while ((pos = SeqListFind(seqlist, value)) != -1) {
		SeqListErase(seqlist, pos);
	}
#endif

#if 0		// O(N)		O(N)
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)* seqlist->size);
	assert(array);            //申请空间，拷贝符合条件的
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
