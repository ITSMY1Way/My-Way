#define _CRT_SECURE_NO_WARNINGS
////һά���� 
//int a[] = {1,2,3,4};
//printf("%d\n",sizeof(a));16
//printf("%d\n",sizeof(a+0)); 4
//printf("%d\n",sizeof(*a));*a�ǵ�һ��Ԫ�� 4 
//printf("%d\n",sizeof(a+1));4 
//printf("%d\n",sizeof(a[1])); 4
//printf("%d\n",sizeof(&a));����ĵ�ַ  4
//printf("%d\n",sizeof(*&a));������ָ������þ�������a16
//printf("%d\n",sizeof(&a+1));ָ����һ������ĵ�ַ 4 
//printf("%d\n",sizeof(&a[0]));4
//printf("%d\n",sizeof(&a[0]+1))��4
// 
////�ַ����� 
//char arr[] = {'a','b','c','d','e','f'}; 
//printf("%d\n", sizeof(arr));6 
//printf("%d\n", sizeof(arr+0));4 
//printf("%d\n", sizeof(*arr));��һ��Ԫ��1
//printf("%d\n", sizeof(arr[1])); 1
//printf("%d\n", sizeof(&arr));4 
//printf("%d\n", sizeof(&arr+1));4 
//printf("%d\n", sizeof(&arr[0]+1));4
// printf("%d\n", strlen(arr));��ȷ����û��\0,����6��������10��
// printf("%d\n", strlen(arr+0));10
// printf("%d\n", strlen(*arr)); ���� ���Ͳ�ƥ��
// printf("%d\n", strlen(arr[1]));����
// printf("%d\n", strlen(&arr)); 10  
// printf("%d\n", strlen(&arr+1));4
// printf("%d\n", strlen(&arr[0]+1));�ڶ���Ԫ�� ��ʼ9
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
//printf("%d\n", strlen(*p)); //��ƥ��
//printf("%d\n", strlen(p[0])); //��ƥ��
//printf("%d\n", strlen(&p)); //��ȷ��3
//printf("%d\n", strlen(&p+1)); //��ȷ��7
////printf("%d\n", strlen(&p[0]+1));//5
//return 0;
//}

////��ά���� 
//int a[3][4] = {0}; 
//printf("%d\n",sizeof(a));//48
//printf("%d\n",sizeof(a[0][0])); //4
//printf("%d\n",sizeof(a[0]));// 16
//printf("%d\n",sizeof(a[0]+1));//a[0]�������� +1���ǵڶ���Ԫ�صĵ�ַa[0][1] 4 
//printf("%d\n",sizeof(*(a[0]+1))); //4 
//printf("%d\n",sizeof(a+1)); //4 �ڶ���Ԫ�صĵ�ַa[1]
//printf("%d\n",sizeof(*(a+1))); //16 �ڶ�������

//printf("%d\n",sizeof(&a[0]+1)); //4 �൱��a+1  a[1]�ĵ�ַ
//printf("%d\n",sizeof(*(&a[0]+1))); //16   a[1]  �ڶ�������
//printf("%d\n",sizeof(*a)); // ��һ������ a[0] 16
//printf("%d\n",sizeof(a[3]));// ��� ���Է��� 
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
 