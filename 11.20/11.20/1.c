#define _CRT_SECURE_NO_WARNINGS
//����Ļ�ϴ�ӡ������ǡ�
#include <stdio.h>
#include <math.h>
//int main()
//{     
//	int arr[10][10]={0};     
//    int i=0,j=0;     
//	for(i=0;i<10;i++)  //��һ�кͶԽ���Ԫ�ض�Ϊ1
//	{            
//		arr[i][0]=1;
//        arr[i][i]=1;
//	}
//		for(i=2;i<10;i++)// �����п�ʼ����������Ԫ��֮��   
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
//���غ����Ķ�����λģʽ�����ҷ�ת���ֵ��
//unsigned int  reverse_bit(unsigned int value)//����1
//{
//	int i = 0;
//	unsigned int ret = 0;
//	while(i<32)
//	{
//		if((value >> i)&1)//�ӵ�λ��ʼ�ж�ÿһλ�Ƿ�Ϊ1,Ϊ0������
//		{
//			ret|=1 << (31-i);//��Ϊ1 ��Ӧ��λת��Ϊ1
//		}
//		i++;
//	}
//	return ret;
//}
//unsigned int  reverse_bit(unsigned int value)  /*����2��3*/
//{
//    int i = 0;
//	unsigned int ret = 0;
//	for(i=0;i<32;i++)
//	{
//      ret+=((value >> i)&1)*pow(2,31-i);//����pow�����Ŀ����Ǻܴ�
//		ret+=((value >> i)&1)<<(31-i);           //����3 
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
//��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
//int main()
//{     
//	int a,b;    
//	int avg=0;     
//	scanf("%d%d",&a,&b);     
//	avg=(a&b) + (a^b)>>1;//&��ȡ����ͬ����^�ó���ͬ�Ĳ��ֵĺͣ���ͬ�ļ��ϲ�ͬ���ֵĺ�/2���õ���������ƽ��ֵ��   
//	printf("%d\n",avg);  
//	return 0;
//}
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡�
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
//����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//student a am i
//i ma a tneduts
//i am a student
//�����巴ת���پֲ���ת,/0Ϊ������־
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






