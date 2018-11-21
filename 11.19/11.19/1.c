#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//返回二进制中1的个数
//int  count_one_bits(unsigned int value)//方法1 %2即向右移一位，余数为1，被移为1
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
//int  count_one_bits(unsigned int value)//方法2 移位操作 和1按位与 0则0 1则1  
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
//int  count_one_bits(unsigned int value)//方法3 -1后 用0缩进 代替上一位的1(1,1110;2,1100;3,1000;4,0000)
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
//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
//int main()//&的方法 2为单位移动 都是操作16次
//{
//	int num = 0;
//	int i = 0;
//	scanf("%d",&num);
//	printf("奇数序列为:");
//	for(i=31;i>=0;i-=2)
//	{
//		printf("%d ",1&(num>>i));
//	}
//	printf("\n");
//	printf("偶数序列为:");
//	for(i=30;i>=0;i-=2)
//	{
//		printf("%d ",1&(num>>i));
//	}
//	return 0;
//}
//输出一个整数的每一位。
//void print(int n)//用递归实现，不能逆向输出，所以递归条件；
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
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	int count = 0;
//	scanf("%d%d",&m,&n);//第四种方法（m^n后此部分即返回二进制中1的个数，∴省略；）
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
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include<stdio.h>
//int main()//说对一半 -> 两条件任成立一个 -> 两个条件的布尔值相加为1
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
//											if(120==a*b*c*d*e)//跳水啊，应该不存在两人打分排名相同的情况吧，所以啊1.2.3.4.5的乘积是一个定值，这是最简单的排除判断标准
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
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
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

