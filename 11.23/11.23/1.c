#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ��
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