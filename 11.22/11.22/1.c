//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//int main()
//{
//	char str[] = "i am a student";
//	StrReserve(str);
//	printf("%s\n",str);
//	return 0;
//}
//��������ʹ����ȫ����λ��ż��ǰ�档
//#include<stdlib.h>
//void swap(int arr[],int sz)
//{
//	int left = 0;
//	int right= sz -1;
//	int tmp = 0;
//	while(left<right)
//	{
//		while((left<right)&&(arr[left]%2==1))
//		{
//			left++;
//		}
//		while((left<right)&&(arr[right]%2==0))
//		{
//			right--;
//		}
//		if(left<right)
//		{
//			tmp = arr[left];
//			arr[left]=arr[right];
//			arr[right]=tmp;
//		}
//	}
//}
//void printf_arr(int arr[],int sz)
//{
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//}
//int main()
//{
//	int arr[]={1,2,3,4,5,6,7,8,9};
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	swap(arr,sz);
//	printf_arr(arr,sz);
//	return 0;
//}
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//int Find(int arr[4][4],int rows, int cols ,int num )
//{
//	int result = 0;
//	int row = 0;
//	int col = cols-1;
//	while(row<rows && col>=0)
//	{
//		if(arr[row][col]==num)//С��ÿ�����ұ�����ֱ���ų�һ��
//		{
//			result = 1;
//			break;
//		}
//		else if(arr[row][col]>num)
//		{
//			--row;
//		}
//		else
//		{
//			++col;
//		}
//	}
//	return result;
//}
//int main()
//{
//	int arr[4][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};
//	printf("%d ",Find(arr,4,4,7));
//	return 0;
//}
//ʵ��һ�����������������ַ����е�k���ַ�
//�����ַ���ƴ����һ�������Ӵ������ҵ���������ַ���
//void left_reverse(char* str, int len, int n)
//{
//	int newsize = 2 * len + 1;
//	char *aaa=(char *)malloc(sizeof(char)*newsize);�����ڴ�
//	assert(str);
//	assert(len>0);
//	assert(n>0);
//	n %= len;
//	strcpy(aaa,str);����str����
//	strcat(aaa,str);�ַ���strƴ��
//	strncpy(str,aaa+n,len);��aaa�дӵ�n���ַ���ʼ����(len��)�ַ���str��
//	free(aaa);�ͷ��ڴ�
//}
//int main()
//{
//    char str[]="abcdef";
//    int n = 0;
//    int sz = sizeof(str) / sizeof(str[0])-1;
//    printf("please input left_reverse num:");
//    scanf("%d", &n);
//    left_reverse(str, sz, n);
//    printf("%s", str);
//    return 0;
//}
//�ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����������ַ���
//int find_leftmove(char* str, char* substr)
//{
//	int len1 = strlen(str);
//	int len2 = strlen(substr);
//	int newsize = 2 * len1+1;
//	char* aaa=(char*)malloc(sizeof(char)*newsize);
//	assert(str);
//	assert(substr);
//	if(len1!=len2)//���Ȳ����ֱ��pass
//	{
//		return -1;
//	}
//	strcpy(aaa,str);
//	strcat(aaa,str);
//	if(strstr(aaa,substr))//��aaa�в���substr�ַ���
//	{
//		return 1;
//	}
//	free(aaa);	
//}
//int main()
//{
//	char str[]="abcdef";
//    int ret = find_leftmove(str,"bcdefa");
//	if(ret == 1)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//	return 0;
//}
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ��ҳ����������֣����ʵ�֡�
//void find_num(int arr[], int len)
//{
//	int i = 0;
//	int ret = 0;
//	int pos = 0;��¼ret������Ϊ��һ��Ϊ1��λ��
//	int x = 0;��һ��ֵ�����x���õ�1��û����ͬ���ֵ�ֵ
//	int y = 0;��һ�� y
//	for(i=0;i<len;i++)
//	{
//		ret^=arr[i];
//	}
//	for(i=0;i<32;i++)
//	{
//		 if(1==((ret>>i)&1))
//		 {
//			 pos = i;
//			 break;
//		 }�ҵ�ret������Ϊ��һ��Ϊ1��λ��
//	}
//	for(i=0;i<len;i++)
//	{
//		if(1==((arr[i]>>pos)&1))
//		{
//			x^=arr[i];
//		}
//		else
//		{
//			y^=arr[i];�������
//		}
//	}
//	printf("%d%d",x,y);
//}
//int main()
//{	
//	int arr[] = { 1, 2, 3, 1, 2, 3, 4, 5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);	
//	find_num(arr, sz);		
//	return 0;
//}