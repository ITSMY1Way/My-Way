////////void my_memcpy(void* dst, const void* src, size_t count)
////////{
////////	void * ret = dst;
/////////*copy from lower addresses to higher addresses*/
////////	while (count--)
////////	{
////////		*(char *)dst = *(char *)src;
////////		dst = (char *)dst + 1;
////////		src = (char *)src + 1;
////////	}
////////	return ret;
////////}
////////void * memmove(void * dst, const void* src, size_t count)
////////{
////////	void * ret = dst;
////////	if (dst <= src || ((char *)src + count))
////////	{// copy from lower addresses to higher addresses
////////		while (count--)
////////		{
////////			*(char *)dst = *(char *)src;
////////			dst = (char *)dst + 1;
////////			src = (char *)src + 1;
////////		}
////////	}
////////	else
////////	{
////////		//copy from higher addresses to lower addresses
////////		dst = (char *)dst + count - 1;
////////		src = (char *)src + count - 1;
////////		while (count--) {
////////			*(char *)dst = *(char *)src;
////////			dst = (char *)dst - 1;
////////			src = (char *)src - 1;
////////		}
////////	}
////////	return(ret);
////////}
//////#include <stdio.h>
//////#include <assert.h>
//////char *my_strncpy(char *dest, const char *src, int n)
//////{
//////	assert(dest != NULL);
//////	assert(src != NULL);
//////	char *ret = *dest;
//////	while (n && (*src))
//////	{
//////		*dest++ = *src++;
//////		n--;
//////	}
//////	while (n > 0)
//////	{
//////		*dest++ = 0;
//////		n--;
//////	}
//////
//////	return ret;
//////}
//////int main()
//////{
//////	char dest[20] = "abcdefghijk";
//////	char src[] = "hello";
//////	//my_strncpy(dest, src, 3);
//////	//printf("%s\n", dest);
//////	//my_strncpy(dest, src, 6);
//////	//printf("%s\n", dest);
//////	my_strncpy(dest, src, 6);
//////	printf("%s\n", dest);
//////	getchar();
//////	return 0;
//////}
////#include<stdio.h>
////#include<stdlib.h>
////#include<assert.h>
////#include<string.h>
////char *my_strncat(char *dest, char *src, int len)
////{
////	assert(dest);
////	assert(src);
////	char* ret = dest;
////	while (*dest)
////	{
////		dest++;
////	}
////	while (len--)
////	{
////		*dest = *src;
////		dest++;
////		src--;
////	}
////	*dest = '\0';
////	return ret;
////}
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//int my_strncmp(const char* str1, const char* str2, int maxlen)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	int ret = 0;
//	while (!(ret = (*str1 - *str2)) && *str1 && (maxlen--))
//	{
//		str1++;
//		str2++;
//	}
//	if (ret < 0)
//		ret = -1;
//	else if (ret > 0)
//		ret = 1;
//	return ret;
//}
//int main()
//{
//	char *s1 = "abcd";
//	char *s2 = "abdd";
//	printf("%d\n", my_strncmp(s1, s2, 4));
//	getchar();
//	return 0;
//}
//struct S1
//{
//	char c1;//1
//	int i;//1xxx  1111
//	short s2;//1xxx 1111  11xx
//};//结构体大小是10字节
//struct S2
//{
//	char c1;
//	char s2;
//
//};
#include <stdio.h>
#include <windows.h>
//struct s1
//{
//	bool a;
//};
//int main()
//{
//	printf("%d\n",sizeof(s1));
//	getchar();
//	return 0;
//}
//struct A {
//int _a : 2;
//int _b : 5;
//int _c : 10;
//int _d : 30;
//};
//struct S {
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//struct S s = { 0 };
//s.a = 10; 
//s.b = 12;
//s.c = 3; 
//s.d = 4;
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	getchar();
//	return 0;
//}
//enum Color//颜色
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};
//enum Color clr = GREEN;//只能拿枚举常量给枚举变量赋值，才不会出现类型的差异。
//clr = 5;
//联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
////联合变量的定义
//union Un un;
////计算连个变量的大小
//int main()
//{
//	printf("%d\n", sizeof(un));
//	getchar();
//	return 0;
//}

//联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
////联合变量的定义
//union Un un;
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};

int main()
{
	//下面输出的结果是什么？
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	getchar();
	return 0;
}