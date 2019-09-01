#define _CRT_SECURE_NO_WARNINGS
//在屏幕上打印杨辉三角。
#include <stdio.h>
#include <math.h>
//int main()
//{     
//	int arr[10][10]={0};     
//    int i=0,j=0;     
//	for(i=0;i<10;i++)  //第一列和对角线元素都为1
//	{            
//		arr[i][0]=1;
//        arr[i][i]=1;
//	}
//		for(i=2;i<10;i++)// 第三行开始处理，上与左元素之和   
//        for(j=1;j<i;j++)
//		arr[i][j]=arr[i-1][j-1]+arr[i-1][j];        
//	for(i=0;i<10;i++)
//	{
//		for(j=0;j<(2*10-2*i);j++)
//		{
//			printf(" ");
//		}
//		for(j=0;j<=i;j++)  
//		{
//			printf("%4d",arr[i][j]);
//		}
//		printf("\n");     
//	}        
//	return 0;
//}
//返回函数的二进制位模式从左到右翻转后的值。
//unsigned int  reverse_bit(unsigned int value)//方法1
//{
//	int i = 0;
//	unsigned int ret = 0;
//	while(i<32)
//	{
//		if((value >> i)&1)//从低位开始判断每一位是否为1,为0不操作
//		{
//			ret|=1 << (31-i);//若为1 对应高位转换为1
//		}
//		i++;
//	}
//	return ret;
//}
//unsigned int  reverse_bit(unsigned int value)  /*方法2和3*/
//{
//    int i = 0;
//	unsigned int ret = 0;
//	for(i=0;i<32;i++)
//	{
//      ret+=((value >> i)&1)*pow(2,31-i);//调用pow函数的开销是很大
//		ret+=((value >> i)&1)<<(31-i);           //方法3 
//	}
//	return ret;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//	printf("%u\n",reverse_bit(a));
//	return 0;	
//}
//不使用（a+b）/2这种方式，求两个数的平均值。
//int main()
//{     
//	int a,b;    
//	int avg=0;     
//	scanf("%d%d",&a,&b);     
//	avg=(a&b) + (a^b)>>1;//&提取出相同部分^拿出不同的部分的和，相同的加上不同部分的和/2即得到两个数的平均值。   
//	printf("%d\n",avg);  
//	return 0;
//}
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。
//int main()
//{
//	int arr[]={1,1,2,2,3,3,4,4,5,5,6};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int num = 0;
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		num=num^arr[i];
//	}
//	printf("The single num is:");
//	printf("%d",num);
//	return 0;
//}
//不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
//student a am i
//i ma a tneduts
//i am a student
//先整体反转，再局部反转,/0为结束标志
void String_Reverse(int a)
{

}
void String_reverse(int a)
{

}
int main()
{
	char str="student a am i";

	return 0;
}






