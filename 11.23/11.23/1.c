#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。
int change_soda(int a)
{
	int b = 0;
	if(!(a%2))
	{
		b += change_soda(a)/2;
	}
	if()
	return a;
}
int mian()
{
	change_soda(20);
	printf("%d/n");
	return 0;
}