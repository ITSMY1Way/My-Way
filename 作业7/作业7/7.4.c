//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void Init(int arr[],int sz)
//{
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		arr[i]=i;
//	}
//}
//void Print(int arr[],int sz)
//{
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		printf("%d",arr[i]);
//	}
//	printf("\n");
//}
//void Empty(int arr[],int sz)
//{
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		arr[i]=0;
//	}
//}
//void Reserve(int arr[],int left,int right)
//{
//	while(left<right)
//	{
//		int a=arr[right];
//		arr[right]=arr[left];
//		arr[left]=a;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = {0};
//	int left = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int right = sz-1;
//  Init(arr,sz);
//  Print(arr,sz);
//  Reserve(arr,left,right);
//  Print(arr,sz);
//	return 0;
//}