#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int count_one_bits(unsigned int value)
{
	int count=0;
	while(value)
	{
		if(value%2==1) 
	  {
		count++;
	  }   
	value/=2;
	}
	return count;
}
int main()
{    unsigned int num=0;
     int ret=0;
	 scanf("%d",&num);    
	 ret=count_one_bits(num);
	 printf("count=%d\n",ret);
	 return 0;
}
