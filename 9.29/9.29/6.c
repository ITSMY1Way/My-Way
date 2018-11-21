//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int binary_serrch(int arr[],int key,int left,int right)
//{
//	while(left<=right)
//	{
//		int mid=left+(right-left)/2;
//		if(key>arr[mid])
//		{
//			left=mid+1;
//		}
//		else if(key<arr[mid])
//		{
//			right=mid-1;
//		}
//		else
//		{
//			return mid;
//		}	
//	}
//	return -1;
//}
//int main()
//{
//	int arr[]={1,2,3,4,5,6,7,8,9,10};
//	int key = 8;
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0]-1);
//	int ret = binary_serrch(arr,key,left,right);
//	if(ret==-1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了:%d\n", ret);
//	}
//	return 0;
//}
