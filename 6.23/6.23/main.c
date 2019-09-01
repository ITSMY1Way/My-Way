#include "SeqList.h"


void TestSeqList1() {
	SeqList seqlist;

	SeqListInit(&seqlist, 100);//初始化

	SeqListPushBack(&seqlist, 3);//尾插
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 15);
	SeqListPushBack(&seqlist, 102);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 14);
	SeqListPrint(&seqlist);
		

	// 3 1 2

//	SeqListPushFront(&seqlist, 11);//头插
//	SeqListPushFront(&seqlist, 12);
//	SeqListPushFront(&seqlist, 13);
//	
//	// 13, 12, 11, 3 , 2 ,1
//
	//SeqListInsert(&seqlist, 4, 100);//中间插
	//SeqListPrint(&seqlist);
	// 13, 12, 11, 3,100, 2, 1
//
//
//	SeqListPopBack(&seqlist);//尾删
//	
//	// 13, 12, 11, 3, 100, 2
//
//	SeqListPopFront(&seqlist);//头删
//	
//	// 12, 11, 3, 100, 2
//
//	SeqListErase(&seqlist, 2);//删除pos下标数据
//	SeqListPrint(&seqlist);
//	// 12, 11, 100, 2
	/*SeqListRemove(&seqlist, 1);
	SeqListRemove(&seqlist, 1);*/
	SeqListRemoveAll(&seqlist, 1);
	SeqListPrint(&seqlist);

}

int main() {
	TestSeqList1();
	getchar();
	return 0;
}