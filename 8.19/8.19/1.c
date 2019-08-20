////////////int main()
////////////{
////////////	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
////////////	int *ptr1 = (int *)(&aa + 1);
////////////	int *ptr2 = (int *)(*(aa + 1));
////////////	printf("%d, %d", *(ptr1 - 1), *(ptr2 - 1));
////////////	getchar();
////////////	return 0;
////////////}
////////////int main()
////////////{
////////////	char *a[] = { "work", "at", "alibaba" };
////////////	char **pa = a;
////////////	pa++;
////////////	printf("%s\n", *pa);
////////////	system("pause");
////////////	return 0;
////////////}
//////////int main()
//////////{
//////////	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
//////////	char **cp[] = { c + 3, c + 2, c + 1, c };
//////////	char ***cpp = cp;
//////////
//////////	printf("%s\n", **++cpp);
//////////	printf("%s\n", *--*++cpp + 3);
//////////	printf("%s\n", *cpp[-2] + 3);
//////////	printf("%s\n", cpp[-1][-1] + 1);
//////////	getchar();
//////////	return 0;
////////#include <stdio.h>
////////int main(){
////////	int a[] = { 1, 2, 3, 4 };
////////	printf("%d\n", sizeof(*a));//*a是第一个元素 4 
////////	printf("%d\n", sizeof(&a));//数组的地址  4
////////	printf("%d\n", sizeof(*&a));//对数组指针解引用就是数组a16
////////	printf("%d\n", sizeof(&a + 1));//指向下一个数组的地址 4 
////////	getchar();
////////	return 0;
////////}
////////#include <stdio.h>
////////int main(){
////////	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
////////	//字符数组初始化时为写入'\0'，所以不包括'\0'
////////	printf("%d\n", sizeof(arr));		//6，
////////
////////	printf("%d\n", sizeof(arr + 0));		//4，首元素的地址
////////	printf("%d\n", sizeof(*arr));		//1，首元素
////////	printf("%d\n", sizeof(arr[1]));		//1，第二个元素
////////	printf("%d\n", sizeof(&arr));		//4，整个数组的地址
////////	printf("%d\n", sizeof(&arr + 1));		//4，下一个数组的地址
////////	printf("%d\n", sizeof(&arr[0] + 1));	//4，第二个元素的地址
////////	getchar();
////////	return 0;
////////}
////////arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//////////字符数组初始化时为写入'\0'，所以不包括'\0'
////////printf("%d\n", sizeof(arr));		 //6，整个数组
////////printf("%d\n", sizeof(arr + 0));		//4，首元素的地址
////////printf("%d\n", sizeof(*arr));		//1，首元素
////////printf("%d\n", sizeof(arr[1]));		//1，第二个元素
////////printf("%d\n", sizeof(&arr));		//4，整个数组的地址
////////printf("%d\n", sizeof(&arr + 1));		//4，下一个数组的地址
////////printf("%d\n", sizeof(&arr[0] + 1));	//4，第二个元素的地址
////////getchar();
////////return 0;
//////#include <stdio.h>
//////int main(){
//////	int a[3][4] = { 0 };
//////	printf("%d\n", sizeof(a));			    //48
//////	printf("%d\n", sizeof(a[0][0]));		//4，第一个int类型的变量
//////	printf("%d\n", sizeof(a[0]));		    //16，可将a[0]类似看作数组名，a[0]中包括4个int类型的变量
//////	printf("%d\n", sizeof(a[0] + 1));		//4，a[0][1]的地址
//////	printf("%d\n", sizeof(*(a[0] + 1)));	//4，a[0][1]的内容
//////	printf("%d\n", sizeof(a + 1));			//4，数组a里第一个元素的的地址
//////	printf("%d\n", sizeof(*(a + 1)));       //16，a[1]的内容
//////	printf("%d\n", sizeof(&a[0] + 1));		//4，&a[0]为数组指针，加1为a[1]的地址
//////	printf("%d\n", sizeof(*(&a[0] + 1)));	//16，a[1]的内容
//////	printf("%d\n", sizeof(*a));			    //16，a[0]的内容
//////	printf("%d\n", sizeof(a[3]));	      	//16，虽然数组下标越界，但不会报错。
//////	                                 //允许读取超出范围的下一个元素，但不允许写入。
//////	getchar();
//////	return;
//////}
//////
////////
////////
////////char arr[] = "abcdef";
//////////字符串在字符常量区自动写入'\0'
////////printf("%d\n", sizeof(arr));		//7
////////printf("%d\n", sizeof(arr + 0));		//4
////////printf("%d\n", sizeof(*arr));		//1
////////printf("%d\n", sizeof(arr[1]));		//1
////////printf("%d\n", sizeof(&arr));		//4
////////printf("%d\n", sizeof(&arr + 1));		//4
////////printf("%d\n", sizeof(&arr[0] + 1));	//4
////////
////////printf("%d\n", strlen(arr));		//6
////////printf("%d\n", strlen(arr + 0));		//6
////////printf("%d\n", strlen(*arr));		//ERROR
////////printf("%d\n", strlen(arr[1]));		//ERROR
////////printf("%d\n", strlen(&arr));		//6，Warning
////////printf("%d\n", strlen(&arr + 1));		//随机值
////////printf("%d\n", strlen(&arr[0] + 1));	//5
////////
////////
////////char *p = "abcdef";
////////printf("%d\n", sizeof(p));			//4
////////printf("%d\n", sizeof(p + 1));		//4
////////printf("%d\n", sizeof(*p));			//1
////////printf("%d\n", sizeof(p[0]));		//4
////////printf("%d\n", sizeof(&p));			//4，p变量的地址
////////printf("%d\n", sizeof(&p + 1));		//4，下一个指针的地址
////////printf("%d\n", sizeof(&p[0] + 1));	//4
////////
////////printf("%d\n", strlen(p));			//6
////////printf("%d\n", strlen(p + 1));		//5
////////printf("%d\n", strlen(*p));			//ERROR
////////printf("%d\n", strlen(p[0]));		//ERROR
////////printf("%d\n", strlen(&p));			//ERROR，p的地址，为二级指针
////////printf("%d\n", strlen(&p + 1));		//ERROR，下一个指针的地址，为二级指针
////////printf("%d\n", strlen(&p[0] + 1));	//5
//////#include <stdio.h>
//////int main()
//////{
//////	const char*str1 = "abcdef";
//////	const char*str2 = "bbb";
//////	if (strlen(str2) - strlen(str1)>0)
//////	{
//////		printf("str2>str1\n");
//////	}
//////	else
//////	{
//////		printf("srt1>str2\n");
//////	}
//////	getchar();
//////	return 0;
//////}
//////方式一:计数器
////int my_strlen(const char * str)
////{
////	int count = 0;
////	while (*str)
////	{
////		count++;
////		str++;
////	}
////	return count;
////}
//////方式二:不能创建临时变量计数器
////int my_strlen(const char * str)
////{
////	if (*str == '\0')
////	{
////		return 0;
////	}
////	else
////		return 1 + my_strlen(str + 1);
////}
//////方式三:指针—指针
////int my_strlen(char *s)
////{
////	char * p = s;
////	while (*p != '\0')
////	{
////		p++;
////	}
////	return p - s;
////}
//char *my_strcpy(char* dest, char* src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//char *my_strcat(char* dest, char* src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//char * my_strstr(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	char* cp = (char*)str1;
//	char* substr = (char*)str2;
//	char* s1 = NULL;
//	if (*str2 == '\0')
//		return NULL;
//	while (*cp)
//	{
//		s1 = cp;
//		substr = str2;
//		while (*s1 && *substr && (*s1 == *substr))
//		{
//			s1++;
//			substr++;
//		}
//		if (*substr == '\0')
//			return cp;
//		cp++;
//	}
//}