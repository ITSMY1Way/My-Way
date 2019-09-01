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
//调整数组使奇数全部都位于偶数前面。
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
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//int Find(int arr[4][4],int rows, int cols ,int num )
//{
//	int result = 0;
//	int row = 0;
//	int col = cols-1;
//	while(row<rows && col>=0)
//	{
//		if(arr[row][col]==num)//小于每行最右边数字直接排除一行
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
//实现一个函数，可以左旋字符串中的k个字符
//将两字符串拼接在一起，利用子串查找找到左旋后的字符串
//void left_reverse(char* str, int len, int n)
//{
//	int newsize = 2 * len + 1;
//	char *aaa=(char *)malloc(sizeof(char)*newsize);开辟内存
//	assert(str);
//	assert(len>0);
//	assert(n>0);
//	n %= len;
//	strcpy(aaa,str);符串str拷贝
//	strcat(aaa,str);字符串str拼接
//	strncpy(str,aaa+n,len);再aaa中从第n个字符开始拷贝(len个)字符到str上
//	free(aaa);释放内存
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
//判断一个字符串是否为另一个字符串左旋后的字符串
//int find_leftmove(char* str, char* substr)
//{
//	int len1 = strlen(str);
//	int len2 = strlen(substr);
//	int newsize = 2 * len1+1;
//	char* aaa=(char*)malloc(sizeof(char)*newsize);
//	assert(str);
//	assert(substr);
//	if(len1!=len2)//长度不相等直接pass
//	{
//		return -1;
//	}
//	strcpy(aaa,str);
//	strcat(aaa,str);
//	if(strstr(aaa,substr))//在aaa中查找substr字符串
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
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。找出这两个数字，编程实现。
//void find_num(int arr[], int len)
//{
//	int i = 0;
//	int ret = 0;
//	int pos = 0;记录ret二进制为第一个为1的位置
//	int x = 0;将一组值异或在x，得到1个没有相同数字的值
//	int y = 0;另一组 y
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
//		 }找到ret二进制为第一个为1的位置
//	}
//	for(i=0;i<len;i++)
//	{
//		if(1==((arr[i]>>pos)&1))
//		{
//			x^=arr[i];
//		}
//		else
//		{
//			y^=arr[i];分组异或
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