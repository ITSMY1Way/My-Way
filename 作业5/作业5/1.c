#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("********************************\n");
	printf("*******    1. play        ******\n");
	printf("*******    0. exit        ******\n");
	printf("********************************\n");
}
void game()
{
	int ret = 0;
	int num = 0;
	ret = rand()%100+1;
	while(1)
	{
		printf("�������:>");
		scanf("%d", &num);
		if(num == ret)
		{
			printf("��ϲ��,�¶���\n");
			break;
		}
		else if(num > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����, ������ѡ��!\n");
			break;
		}
	} while (input);
	return 0;
}