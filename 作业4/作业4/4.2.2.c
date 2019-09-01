#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int sum=0;
	int a=1;
	int b=1;
	int i=0;
	for(;i<5;i++)
	{
		
		b=b*10+a;
		sum+=b;
		
	
		
	}
	printf("%d",sum);
	return 0;

}