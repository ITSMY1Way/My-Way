#define _CRT_SECURE_NO_WARNINGS
////一维数组 
//int a[] = {1,2,3,4};
//printf("%d\n",sizeof(a));16
//printf("%d\n",sizeof(a+0)); 4
//printf("%d\n",sizeof(*a));*a是第一个元素 4 
//printf("%d\n",sizeof(a+1));4 
//printf("%d\n",sizeof(a[1])); 4
//printf("%d\n",sizeof(&a));数组的地址  4
//printf("%d\n",sizeof(*&a));对数组指针解引用就是数组a16
//printf("%d\n",sizeof(&a+1));指向下一个数组的地址 4 
//printf("%d\n",sizeof(&a[0]));4
//printf("%d\n",sizeof(&a[0]+1))；4
// 
////字符数组 
//char arr[] = {'a','b','c','d','e','f'}; 
//printf("%d\n", sizeof(arr));6 
//printf("%d\n", sizeof(arr+0));4 
//printf("%d\n", sizeof(*arr));第一个元素1
//printf("%d\n", sizeof(arr[1])); 1
//printf("%d\n", sizeof(&arr));4 
//printf("%d\n", sizeof(&arr+1));4 
//printf("%d\n", sizeof(&arr[0]+1));4
// printf("%d\n", strlen(arr));不确定，没有\0,至少6，若假设10，
// printf("%d\n", strlen(arr+0));10
// printf("%d\n", strlen(*arr)); 报错 类型不匹配
// printf("%d\n", strlen(arr[1]));报错
// printf("%d\n", strlen(&arr)); 10  
// printf("%d\n", strlen(&arr+1));4
// printf("%d\n", strlen(&arr[0]+1));第二个元素 开始9
//
//char arr[] = "abcdef"; 
//printf("%d\n", sizeof(arr)); 
//printf("%d\n", sizeof(arr+0)); 
//printf("%d\n", sizeof(*arr)); 
//printf("%d\n", sizeof(arr[1])); 
//printf("%d\n", sizeof(&arr)); 
//printf("%d\n", sizeof(&arr+1)); 
//printf("%d\n", sizeof(&arr[0]+1));
// 
//printf("%d\n", strlen(arr)); 
//printf("%d\n", strlen(arr+0)); 
//printf("%d\n", strlen(*arr)); 
//printf("%d\n", strlen(arr[1])); 
//printf("%d\n", strlen(&arr));
//printf("%d\n", strlen(&arr+1)); 
//printf("%d\n", strlen(&arr[0]+1));
/*#include <stdio.h>
#include<string.h>
int main()
{
char *p = "abcdef"; */ 
//printf("%d\n", sizeof(p)); //4
//printf("%d\n", sizeof(p+1)); //4
//printf("%d\n", sizeof(*p)); //1
//printf("%d\n", sizeof(p[0])); //1
//printf("%d\n", sizeof(&p));//4
//printf("%d\n", sizeof(&p+1));//4

//printf("%d\n", sizeof(&p[0]+1)); //4

//printf("%d\n", strlen(p)); //6
//printf("%d\n", strlen(p+1)); //5
//printf("%d\n", strlen(*p)); //不匹配
//printf("%d\n", strlen(p[0])); //不匹配
//printf("%d\n", strlen(&p)); //不确定3
//printf("%d\n", strlen(&p+1)); //不确定7
////printf("%d\n", strlen(&p[0]+1));//5
//return 0;
//}

////二维数组 
//int a[3][4] = {0}; 
//printf("%d\n",sizeof(a));//48
//printf("%d\n",sizeof(a[0][0])); //4
//printf("%d\n",sizeof(a[0]));// 16
//printf("%d\n",sizeof(a[0]+1));//a[0]即数组名 +1就是第二个元素的地址a[0][1] 4 
//printf("%d\n",sizeof(*(a[0]+1))); //4 
//printf("%d\n",sizeof(a+1)); //4 第二个元素的地址a[1]
//printf("%d\n",sizeof(*(a+1))); //16 第二个数组

//printf("%d\n",sizeof(&a[0]+1)); //4 相当于a+1  a[1]的地址
//printf("%d\n",sizeof(*(&a[0]+1))); //16   a[1]  第二个数组
//printf("%d\n",sizeof(*a)); // 第一个数组 a[0] 16
//printf("%d\n",sizeof(a[3]));// 错的 可以访问 
//int main() 
//{ 
//	int a[5] = { 1, 2, 3, 4, 5 }; 
//	int *ptr = (int *)(&a + 1); 
//	printf( "%d,%d", *(a + 1), *(ptr - 1));// 2  5  
//	return 0; 
//} 
//int main() 
//{ 
//	int a[4] = { 1, 2, 3, 4 }; 
//	int *ptr1 = (int *)(&a + 1); 
//	int *ptr2 = (int *)((int)a + 1); 
//	printf( "%x,%x", ptr1[-1], *ptr2); //4
//	return 0; 
//}
//int main() 
//{ 
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//	int *ptr1 = (int *)(&aa + 1); //10
//	int *ptr2 = (int *)(*(aa + 1)); //5
//	printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1)); 
//	return 0; 
//}
#include <stdio.h>
 int main() 
 {    
	 char *a[] = {"work","at","alibaba"};   
	 char**pa = a;    
	 pa++;    
	 printf("%s\n", *pa);    
	 return 0; 
 } 
 int main() 
 {    
	 char *c[] = {"ENTER","NEW","POINT","FIRST"};    
	 char**cp[] = {c+3,c+2,c+1,c};    
	 char***cpp = cp;    
	 printf("%s\n", **++cpp);    
	 printf("%s\n", *--*++cpp+3);    
	 printf("%s\n", *cpp[-2]+3);    
	 printf("%s\n", cpp[-1][-1]+1);    
	 return 0; 
 }
 