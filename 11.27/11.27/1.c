#define _CRT_SECURE_NO_WARNINGS
//int check_sys() 
//{    
//	int i = 1;    
//	return (*(char *)&i); 
//} 
//int check_sys() 
//{    
//	union    
//	{        
//		int i;        
//		char c;    
//	}
//	un;    
//	un.i = 1;    
//	return un.c;
//}
//int main() 
//{    
//	int ret = check_sys();    
//	if(ret == 1)    
//	{        
//		printf("我的电脑是小端\n");  
//	}小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位,，保存在内存的高地址中。   
//	else    
//	{        
//		printf("是大端\n");   
//	}大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；    
//	return 0; 
//}
#include <stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d",a,b,c);
//	return 0;
//}
//回调函数就是一个通过函数指针调用的函数。如果把函数的指针（地址）作为参数传递给另一个函数，
//当这个指针被用来调用其所指向的函数时，就说这是回调函数。回调函数不是由该函数的实现方直接调用，
//而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
//qosrt函数的使用者得实现一个比较函数 
//int int_cmp(const void * p1, const void * p2)
//{
//	return (*(int*)p1 > *(int*)p2);
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);
//	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf( "%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//8.模仿qsort的功能实现一个通用的冒泡排序.
int cmp(const void *p1 , const void* p2)
{
	return (*(int *) p1 > *(int *) p2);
}
void _swap(void *p1, void *p2, int size)
{
	 
}
//void _swap(void *p1, void * p2, int size) 
//{    
// int i = 0;    
// for (i = 0; i< size; i++)    
// {        
//	 char tmp = *((char *)p1 + i);       
//	 *(( char *)p1 + i) = *((char *) p2 + i);       
//	 *(( char *)p2 + i) = tmp;    
// } 
//} 
//void bubble(void *base, int count , int size, int(*cmp )(void *, void *))
//{    
//int i = 0;    
//int j = 0;    
//for (i = 0; i< count - 1; i++)    
//{       
//	for (j = 0; j<count-i-1; j++)       
//	{            
//		if (cmp ((char *) base + j*size , (char *)base + (j + 1)*size) > 0)           
//		{               
//			_swap(( char *)base + j*size, 
//				(char *)base + (j + 1)*size, size);           
//		}       
//	}    
//} 
//} 
//int main() 
//{    
//int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };    //char *arr[] = {"aaaa","dddd","cccc","bbbb"};    
//int i = 0;    
//bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);    
//for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)    
//{       
//	printf( "%d ", arr[i]);    
//}    
//printf("\n");    
//return 0; 
//}





