#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//8.模仿qsort的功能实现一个通用的冒泡排序.
//int cmp(const void *p1 , const void* p2)
//{
//	return (*(int *) p1 > *(int *) p2);//大返回1 否则0
//}
//void _swap(void *p1, void *p2, int size)//排序
//{
//	int i = 0;
//	for(i=0;i<size;i++)
//	{
//		char tmp = *((char *)p1 + i);
//		*(( char *)p1 + i) = *((char *)p2 + i);
//		*(( char *)p2 + i) = tmp;
//	}
//}
//void bubble(void *base, int count , int size, int(*cmp)(void *, void*))
//{
//	int i = 0;
//	int j = 0;
//	for(i = 0;i<count-1;i++)
//	{
//		for(j = 0;j<count-i-1;j++)
//		{
//			if(cmp((char *)base+ j*size , (char *)base + (j + 1)*size)>0)
//			{
//				_swap((char *)base + j*size),(char *)base + (j+1)*size , size);
//			}
//		}
//	}
//}
//int main() 
//{    
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;    
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);    
//	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)    
//	{       
//		printf( "%d ", arr[i]);    
//	}    
//	printf("\n");    
//	return 0; 
//}
#include<stdlib.h>   
#include<math.h>   
#include<string.h>
//int cmp1(const void *a, const void *b)
//{
//	return (*(int *)a - *(int *)b);
//}
//int cmp2(const void *a, const void *b)
//{
//	return (*(char *)a - *(char *)b);
//}
//void main(void)
//{
//	int i = 0;
//	int a[10]={1,3,5,7,9,0,2,4,6,8};
//	char b[10]={'a','c','b','d','e','f','g','h','o','u'};
//	qsort(a,10,sizeof(int),&cmp1);//对于函数指针，直接传入函数名和函数名进行都是可以的,
//	qsort(b,10,sizeof(char),cmp2);//因为在调用函数时也是取的函数的地址
//	for (i = 0; i<10; i++) 
//		printf("%d ", a[i]); 
//	    printf("\n"); 
//	for (i = 0; i<10; i++) 
//		printf("%c ", b[i]); 
//		printf("\n"); 
//}
