#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���ض�������1�ĸ���
//int  count_one_bits(unsigned int value)//����1 %2��������һλ������Ϊ1������Ϊ1
//{
//	int count = 0;
//	while(value)
//	{
//		if(value%2)
//		{
//			count++;
//		}
//		value/=2;
//	}
//	return count;
//}
//int  count_one_bits(unsigned int value)//����2 ��λ���� ��1��λ�� 0��0 1��1  
//{
//	int count = 0;
//	int i = 32;
//	while(i)
//	{
//		if(value&1)
//		{
//			count++;
//		}
//		value>>=1;
//		i--;	
//	}
//	return count;
//}
//int  count_one_bits(unsigned int value)//����3 -1�� ��0���� ������һλ��1(1,1110;2,1100;3,1000;4,0000)
//{  
//	int count = 0;
//	while(value)
//	{
//		count++;
//		value=value&(value-1);
//	}
//	return count;
//}
//int main()
//{
//	unsigned int num = 0;
//	int ret = 0;
//	scanf("%d",&num);
//	ret	= count_one_bits(num);
//	printf("count=%d",ret);
//	return 0;
//}
//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
//int main()//&�ķ��� 2Ϊ��λ�ƶ� ���ǲ���16��
//{
//	int num = 0;
//	int i = 0;
//	scanf("%d",&num);
//	printf("��������Ϊ:");
//	for(i=31;i>=0;i-=2)
//	{
//		printf("%d ",1&(num>>i));
//	}
//	printf("\n");
//	printf("ż������Ϊ:");
//	for(i=30;i>=0;i-=2)
//	{
//		printf("%d ",1&(num>>i));
//	}
//	return 0;
//}
//���һ��������ÿһλ��
//void print(int n)//�õݹ�ʵ�֣�����������������Եݹ�������
//{
//	if(n>9)
//	{
//		print(n/10);
//	}
//	printf("%d ",n%10);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//	print(a);
//	return 0;
//}
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	int count = 0;
//	scanf("%d%d",&m,&n);//�����ַ�����m^n��˲��ּ����ض�������1�ĸ�������ʡ�ԣ���
//	for(i=0;i<32;i++)
//	{
//		if(((m>>i)&1)!=((n>>i)&1))
//		{
//			count++;
//		}
//	}
//	printf("%d",count);
//	return 0;
//}
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//#include<stdio.h>
//int main()//˵��һ�� -> �������γ���һ�� -> ���������Ĳ���ֵ���Ϊ1
//{
//    int a = 0, b = 0, c = 0, d = 0, e = 0;
//    for (a = 1; a <= 5; a++)
//    {
//        for (b = 1; b <= 5; b++)
//        {
//            for (c = 1; c <= 5; c++)
//            {
//                for (d = 1; d <= 5; d++)
//                {
//                    for (e = 1; e <= 5; e++)
//                    {
//                        if ((2 == b && 3 != a)+(2 != b && 3 == a) == 1)
//                        {
//                            if ((2 == b && 4 != e)+(2 != b && 4 == e) == 1)
//                            {
//                                if ((1 == c && 2 != d)+(1 != c && 2 == d) == 1)
//                                {
//                                    if ((5 == c && 3 != d)+(5 != c && 3 == d) == 1)
//                                    {
//                                        if ((4 == e && 1 != a)+(4 != e && 1 == a) == 1)
//                                        {
//											if(120==a*b*c*d*e)//��ˮ����Ӧ�ò��������˴��������ͬ������ɣ����԰�1.2.3.4.5�ĳ˻���һ����ֵ��������򵥵��ų��жϱ�׼
//                                            {
//                                                printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);
//                                            }
//
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
// #include <stdio.h>      
//int main()      
//{          
//	int murder;          
//	for (murder='A'; murder<='D'; murder++)          
//	{              
//		if (((murder!='A')+(murder=='C')+(murder=='D')+(murder!='D')) == 3)                
//		{                  
//			printf("murder is %c\n",murder);                       
//		}                
//	}          
//	return 0;      
//} 

