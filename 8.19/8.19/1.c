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
////////	printf("%d\n", sizeof(*a));//*a�ǵ�һ��Ԫ�� 4 
////////	printf("%d\n", sizeof(&a));//����ĵ�ַ  4
////////	printf("%d\n", sizeof(*&a));//������ָ������þ�������a16
////////	printf("%d\n", sizeof(&a + 1));//ָ����һ������ĵ�ַ 4 
////////	getchar();
////////	return 0;
////////}
////////#include <stdio.h>
////////int main(){
////////	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
////////	//�ַ������ʼ��ʱΪд��'\0'�����Բ�����'\0'
////////	printf("%d\n", sizeof(arr));		//6��
////////
////////	printf("%d\n", sizeof(arr + 0));		//4����Ԫ�صĵ�ַ
////////	printf("%d\n", sizeof(*arr));		//1����Ԫ��
////////	printf("%d\n", sizeof(arr[1]));		//1���ڶ���Ԫ��
////////	printf("%d\n", sizeof(&arr));		//4����������ĵ�ַ
////////	printf("%d\n", sizeof(&arr + 1));		//4����һ������ĵ�ַ
////////	printf("%d\n", sizeof(&arr[0] + 1));	//4���ڶ���Ԫ�صĵ�ַ
////////	getchar();
////////	return 0;
////////}
////////arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//////////�ַ������ʼ��ʱΪд��'\0'�����Բ�����'\0'
////////printf("%d\n", sizeof(arr));		 //6����������
////////printf("%d\n", sizeof(arr + 0));		//4����Ԫ�صĵ�ַ
////////printf("%d\n", sizeof(*arr));		//1����Ԫ��
////////printf("%d\n", sizeof(arr[1]));		//1���ڶ���Ԫ��
////////printf("%d\n", sizeof(&arr));		//4����������ĵ�ַ
////////printf("%d\n", sizeof(&arr + 1));		//4����һ������ĵ�ַ
////////printf("%d\n", sizeof(&arr[0] + 1));	//4���ڶ���Ԫ�صĵ�ַ
////////getchar();
////////return 0;
//////#include <stdio.h>
//////int main(){
//////	int a[3][4] = { 0 };
//////	printf("%d\n", sizeof(a));			    //48
//////	printf("%d\n", sizeof(a[0][0]));		//4����һ��int���͵ı���
//////	printf("%d\n", sizeof(a[0]));		    //16���ɽ�a[0]���ƿ�����������a[0]�а���4��int���͵ı���
//////	printf("%d\n", sizeof(a[0] + 1));		//4��a[0][1]�ĵ�ַ
//////	printf("%d\n", sizeof(*(a[0] + 1)));	//4��a[0][1]������
//////	printf("%d\n", sizeof(a + 1));			//4������a���һ��Ԫ�صĵĵ�ַ
//////	printf("%d\n", sizeof(*(a + 1)));       //16��a[1]������
//////	printf("%d\n", sizeof(&a[0] + 1));		//4��&a[0]Ϊ����ָ�룬��1Ϊa[1]�ĵ�ַ
//////	printf("%d\n", sizeof(*(&a[0] + 1)));	//16��a[1]������
//////	printf("%d\n", sizeof(*a));			    //16��a[0]������
//////	printf("%d\n", sizeof(a[3]));	      	//16����Ȼ�����±�Խ�磬�����ᱨ��
//////	                                 //�����ȡ������Χ����һ��Ԫ�أ���������д�롣
//////	getchar();
//////	return;
//////}
//////
////////
////////
////////char arr[] = "abcdef";
//////////�ַ������ַ��������Զ�д��'\0'
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
////////printf("%d\n", strlen(&arr));		//6��Warning
////////printf("%d\n", strlen(&arr + 1));		//���ֵ
////////printf("%d\n", strlen(&arr[0] + 1));	//5
////////
////////
////////char *p = "abcdef";
////////printf("%d\n", sizeof(p));			//4
////////printf("%d\n", sizeof(p + 1));		//4
////////printf("%d\n", sizeof(*p));			//1
////////printf("%d\n", sizeof(p[0]));		//4
////////printf("%d\n", sizeof(&p));			//4��p�����ĵ�ַ
////////printf("%d\n", sizeof(&p + 1));		//4����һ��ָ��ĵ�ַ
////////printf("%d\n", sizeof(&p[0] + 1));	//4
////////
////////printf("%d\n", strlen(p));			//6
////////printf("%d\n", strlen(p + 1));		//5
////////printf("%d\n", strlen(*p));			//ERROR
////////printf("%d\n", strlen(p[0]));		//ERROR
////////printf("%d\n", strlen(&p));			//ERROR��p�ĵ�ַ��Ϊ����ָ��
////////printf("%d\n", strlen(&p + 1));		//ERROR����һ��ָ��ĵ�ַ��Ϊ����ָ��
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
//////��ʽһ:������
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
//////��ʽ��:���ܴ�����ʱ����������
////int my_strlen(const char * str)
////{
////	if (*str == '\0')
////	{
////		return 0;
////	}
////	else
////		return 1 + my_strlen(str + 1);
////}
//////��ʽ��:ָ�롪ָ��
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