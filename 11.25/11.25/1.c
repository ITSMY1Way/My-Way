//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
////����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ��
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
//ģ��ʵ��strcpy(���� ��һ���ַ��������ݸ��Ƶ�����һ���ַ������У������ַ������ս��)
#include <assert.h>
//char * my_strcpy(char *dest, const char *src)
//{	
//	char *ret = dest;	
//	assert(dest&&src);
//	while (*dest++ = *src++)//�ȸ�����++������ֵ����\0��ʱ���˳�ѭ��	
//	{		
//		;	
//	}	
//	return ret;
//} 
//int main()
//{	
//	char a[10]={0};//��������㹻��Ŀռ䣬ʹ���ܽ��ַ���ȫ����	
//	char *q = "abcd";	
//	printf("%s\n", my_strcpy(a, q));	
//	return 0;
//}
//ģ��ʵ��strcat(�ַ�����ӵ�dest��β��(����dest��β���ġ�\0��)
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
/*1.ʵ��strcpy*/ //�ַ��������������ս��
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
//2.ʵ��strcat //�ַ���ƴ�ӣ�����'\0'
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
//3.ʵ��strstr//���ַ���haystack�в����ַ���needle���ֵ�λ��
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
//				if(!*(s2+n+1))//�ж�s2�Ľ�����
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
//4.ʵ��strchr //�����ַ���s���״γ���c�ַ���λ��
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
//5.ʵ��strcmp //�Ƚ��ַ����Ƿ���ͬ
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
//6.ʵ��memcpy   �ڴ濽������
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
//7.ʵ��memmove
//��Ŀ��������Դ����û���ص����memcpy����������ͬ��
//��Ŀ�������Դ�������ص���memmove�ܹ���֤Դ���ڱ�����֮ǰ���ص�������ֽڿ�����Ŀ�������С�
//�����ƺ�src���ݻᱻ���ġ�
//��ȷ��û���ظ����������memcpy���ڲ�ȷ���Ƿ����ڴ��ظ��������memmove��
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
//strcpy,strcat,strcmp������ͨ�������������������������
//strncpy,strncat,strncmp���������ô��εķ�ʽ��ʵ�ַ����ĸı䳤��
//1.ģ��ʵ��strncpy
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
////2.ģ��ʵ��strncat
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
////3.ģ��ʵ��strncmp 
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

