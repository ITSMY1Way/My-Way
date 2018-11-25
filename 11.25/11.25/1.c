//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。
//int Soda(int n)
//{
//	int rep = n;
//	while (n > 1)
//    {
//        rep += n/2;
//        n = n/2 + n%2;
//    }
//    return rep;
//}
//int main()
//{
//	int num = 20;
//	printf("%d\n",Soda(num));
//	return 0;
//}
//模拟实现strcpy(作用 将一个字符串的内容复制到另外一个字符数组中，包括字符串的终结符)
#include <assert.h>
//char * my_strcpy(char *dest, const char *src)
//{	
//	char *ret = dest;	
//	assert(dest&&src);
//	while (*dest++ = *src++)//先复制再++，当赋值到‘\0’时，退出循环	
//	{		
//		;	
//	}	
//	return ret;
//} 
//int main()
//{	
//	char a[10]={0};//必须给够足够大的空间，使其能将字符完全复制	
//	char *q = "abcd";	
//	printf("%s\n", my_strcpy(a, q));	
//	return 0;
//}
//模拟实现strcat(字符串添加到dest结尾处(覆盖dest结尾处的‘\0’)
//char* my_strcat(char* dest,char* src)
//{
//  char *cp=dest;
//  assert(src && dest);
//  while(*dest!='\0')
//  {
//    dest++;
//  }
//  while(*dest++=*src++)
//  {
//    ;
//  }
// return cp;
//}
//int main()
//{
//   char arr1[15]="abcd";
//   char *arr2="ef";
//   printf("%s\n",my_strcat(arr1,arr2));
//   return 0;
//}
/*1.实现strcpy*/ //字符串拷贝，包括终结符
//char* my_strcpy(char* dest,const char* src)
//{
//	char* ret = dest;
//	assert(dest&&src);
//	while(*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[10]={0};
//	printf("%s\n",my_strcpy(arr,"abcdef"));
//	return 0;
//}
//2.实现strcat //字符串拼接，覆盖'\0'
//char* my_strcat(char* dest,char* src)
//{
//	char* ret = dest;
//	assert(dest&&src);
//	while(*dest!='\0')
//	{
//		dest++;
//	}
//	while(*dest++ = *src++)
//	{
//		;
//	}
//	return ret;	 
//}
//int main()
//{
//	char arr1[10]="abce";
//	char* arr2="lolol";
//	printf("%s\n",my_strcat(arr1,arr2));
//	return 0;
//}
//3.实现strstr//在字符串haystack中查找字符串needle出现的位置
//char *my_strstr(char* s1 ,char* s2)
//{
//	int n = 0;
//	assert(s1&&s2);
//	if(*s2)
//	{
//		while(*s1)
//		{
//			for(n = 0;*(s1+n) == *(s2+n);n++)
//			{
//				if(!*(s2+n+1))//判断s2的结束符
//				return (char *)s1;
//			}
//			s1++;
//		}
//		return 0;
//	}
//	else
//		return (char *)s1;
//}
//int main()
//{
//	char src[]= "abcdbcaeee";
//  char* p =my_strstr(src,"cae");
//	printf("%s\n",p);
//	return 0;
//}
//4.实现strchr //查找字符串s中首次出现c字符的位置
#include <string.h>
//char* my_strstr(const char *s,int c)
//{
//	if(s == NULL)
//	return NULL;
//	while(*s)
//	{
//		if(*s++ == 'c')
//		{
//			return(char *)s;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char* arr ="khyuhjkcsss";
//	printf("%s\n",my_strstr(arr,'c'));
//	return 0;
//}
//5.实现strcmp //比较字符串是否相同
//int my_strcmp(const char *str1, const char *str2 )
//{   
//	int ret=0;   
//	while(!(ret = *(unsigned char*)str1 - *(unsigned char*)str2)&& *str1)     
//	{       
//		str1++;       
//		str2++;     
//	}     
//	if(ret < 0)        
//		return -1;     
//	else if(ret > 0)         
//		return 1;     
//	return 0;     
//}
//int main()
//{
//	char *arr1 ="aaaaaa";
//	char *arr2 ="aaaaaa";
//	printf("%d\n",my_strcmp(arr1,arr2));
//	return 0;
//}
//6.实现memcpy   内存拷贝函数
//void *my_memcpy(void *dest, void *src, int num)
//{
//	char *pdest;	
//	char *psrc;	pdest = dest;	
//	psrc = src;
//	if((dest == NULL)||(src == NULL))	
//	{		
//		printf("parameter error!\n");		
//		return 0;	
//	} 	
//	while(num --)	
//	{		
//		*pdest = *psrc;		
//		*pdest ++;		
//		*psrc++;	
//	}	
//	return dest;
//}
//int main(int argc, char *argv[])
//{                                         
//	int pdes[10] = {0};	
//	char psrc[] = "abcdef";	
//	my_memcpy(pdes, psrc, sizeof(psrc));	
//	printf("src : %s\n", (char *)psrc);	
//}
//7.实现memmove
//当目标区域与源区域没有重叠则和memcpy函数功能相同；
//若目标区域和源区域有重叠，memmove能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中。
//但复制后src内容会被更改。
//在确定没有重复的情况下用memcpy，在不确定是否有内存重复的情况用memmove。
//void* my_memmove(void* dst,const void* src,size_t count)
//{
//	char* tmpdst = (char*)dst;
//    char* tmpsrc = (char*)src;
//    assert(src&&dst);
//    if (tmpdst <= tmpsrc || tmpdst >= tmpsrc + count)
//    {
//        while(count--)
//        {
//            *tmpdst++ = *tmpsrc++; 
//        }
//    }
//    else
//    {
//        tmpdst = tmpdst + count - 1;
//        tmpsrc = tmpsrc + count - 1;
//        while(count--)
//        {
//            *tmpdst-- = *tmpsrc--;
//        }
//    }
//    return dst; 
//}
//int main()
//{
//	char *arr[10]={0};
//	printf("%s\n",my_memmove(arr,"abcde",5));
//	return 0;
//}
//strcpy,strcat,strcmp三函数通过传递数组的内容来限制它们
//strncpy,strncat,strncmp三个函数用传参的方式现实字符串的改变长度
//1.模拟实现strncpy
//char* my_strncpy(char*dest, const char*src, int n)
//{
//	char*p = dest;
//	assert(dest&&src);
//	while (n--)
//	{
//		*p++ = *src++;
//	}
//	*p = 0;
//	return dest;
//}
////2.模拟实现strncat
//char* my_strncat(char*dest, const char*src, int n)
//{
//	char*p = dest;
//	assert(dest&&src);
//	while (*p)
//	{
//		p++;
//	}
//	while (n--)
//	{
//		*p++ = *src++;
//	}
//	*p = 0;
//	return dest;
//}
////3.模拟实现strncmp 
//int my_strncmp(const char*str1, const char*str2, int n)
//{
//	while (n--)
//	{
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		else
//		{
//			if ((*str1-*str2)<0)return -1;
//			else
//				return 1;
//		}
//	}return 0;
//}
//int main()
//{
//	char arr1[]="abcd";
//    char arr2[]="eee";
//	printf("%s\n",my_strncpy(arr1,arr2,3));
//    printf("%s\n",my_strncat(arr1,arr2,3));
//	printf("%s\n",my_strncmp(arr1,arr2,3));
//	return 0;
//}

