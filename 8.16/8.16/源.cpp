//////////////#include <stdio.h>
//////////////int main(){
//////////////	int  b[5] = { 1, 11, 34, 41, 54 };
//////////////	int *p = b;
//////////////	for (int j = 0; j < 5; j++)
//////////////	{
//////////////		printf("%d\n", *p++);
//////////////	}
//////////////	//printf("%d\n", p);
//////////////	//for (int j =0 ; j < 5; j++)
//////////////	//printf("%d ", *p++);
//////////////	//printf("\n");
//////////////	//printf("%d\n", p);
//////////////		getchar();
//////////////		return 0;
//////////////	}
//////////////#include <stdio.h>
//////////////int main(){
//////////////	int  b[5] = { 1, 2, 3, 4, 5 };
//////////////	int *p = b;
//////////////	printf("%d\n", p);
//////////////	for (int j = 0; j < 4; j++)
//////////////	printf("%d ", *++p);
//////////////	printf("\n");
//////////////	printf("%d\n", p);
//////////////	getchar();
//////////////	return 0;
//////////////}
//////////////#include <stdio.h>
//////////////int main(){
//////////////	int  b[5] = { 11, 22, 33, 44,55 };
//////////////	int *p = b;
//////////////	printf("%d\n", p);
//////////////	for (int j = 0; j < 5; j++)
//////////////		printf("%d ", *++p);
//////////////
//////////////
//////////////	printf("\n");
//////////////	printf("%d\n", p);
//////////////	getchar();
//////////////	return 0;
//////////////}
////////////#include <stdio.h>
//////////////void test(int arr[])//ok?
//////////////{}
////////////void test(int arr[10])//ok?
////////////{}
////////////void test(int arr[10])//ok?
////////////{}
//////////////void test(int *arr)//ok?
//////////////{}
//////////////void test2(int *arr[])//ok?
//////////////{}
//////////////void test2(int *arr[20])//ok?
//////////////{}
////////////////void test2(int **arr)//ok?
////////////////{}
////////////int main()
////////////{
////////////	int arr[10] = { 0 };
////////////	int *arr2[20] = { 0 };
////////////	test(arr);
////////////	//test2(arr2);
////////////	getchar();
////////////	return 0;
////////////}
//////////
//////////void test(int* arr[5])      //×
//////////{}
//////////int main()
//////////{
//////////	int arr[3][5] = { 0 };
//////////	test(arr);
//////////	return 0;
//////////}
////////#include <stdio.h>
////////void print(int *p, int sz) {
////////	int i = 0;
////////	for (i = 0; i<sz; i++)
////////	{
////////		printf("%d\n", *(p + i));
////////	}
////////}
////////int main()
////////{
////////	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////////	int *p = arr;
////////	//一级指针p，传给函数
////////	print(&arr);
////////	getchar();
////////	return 0;
////////}
//////#include <stdio.h>
//////#include <string.h>
//////char* fun1(char* p)
//////{
//////	printf("%s\n", p);
//////	return p;
//////}
//////char* fun2(char* p)
//////{
//////	printf("%s\n", p);
//////	return p;
//////}
//////char* fun3(char* p)
//////{
//////	printf("%s\n", p);
//////	return p;
//////}
//////int main()
//////{
//////	char* (*pf[3])(char* p);
//////	pf[0] = fun1; // 可以直接用函数名
//////	pf[1] = &fun2; // 可以用函数名加上取地址符
//////	pf[2] = &fun3;
//////	pf[0]("fun1");
//////	pf[0]("fun2");
//////	pf[0]("fun3");
//////	getchar();
//////	return 0;
//////}
//#include<stdio.h>
////int main()
////{
////	int a[5] = { 1, 2, 3, 4, 5 };
////	int *ptr = (int *)(&a + 1);
////	printf("%d,%d", *(a + 1), *(ptr - 1));
////	getchar();
////	return 0;
////}
////struct Test
////{
////	int Num;
////	char *pcName;
////	short sDate;
////	char cha[2];
////	short sBa[4];
////}*p;
//////假设p 的值为0x100000。 如下表表达式的值分别为多少？
//////p + 0x1 = 0x___ ? (unsigned long)p + 0x1 = 0x___ ? (unsigned int*)p + 0x1 = 0x___ ?
//////笔试题3
////int main()
////{
////	printf("%d\n", sizeof(Test));//20
////	int a[4] = { 1, 2, 3, 4 };
////	int *ptr1 = (int *)(&a + 1);
////	int *ptr2 = (int *)((int)a + 1);
////	printf("%x,%x", ptr1[-1], *ptr2);
////	getchar();
////	return 0;
////}
//int main()
//{
//	int a[4] = { 11, 22, 33, 44 };
//	int *ptr1 = (int *)(&a + 1);
//	int *ptr2 = (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	getchar();
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *p1 = (int *)(&a + 1);
//	int *p2 = (int *)((int)a + 1);
//	printf("%x, %x", p1[-1], *p2);
//	getchar();
//	return 0;
//}
#include <stdio.h>
//int main(int argc, char * argv[])
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int *p;
//	p = a[0];
//	printf("%d", p[0]);
//	getchar();
//	return 0;
////}
//int main()
//{
//	int a[5][5];
//	int(*p)[5];
//	p = a;
//	printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	getchar();
//	return 0;
//}
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5,
		             6, 7, 8, 9, 10 
					 0 0 0     0  0;
	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)(*(aa + 1));
	printf("%d, %d", *(ptr1 - 1), *(ptr2 - 1));// 10.   5
	getchar();
	return 0;
}
