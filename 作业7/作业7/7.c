#define _CRT_SECURE_NO_WARNINGS
void print(int n)
{
	if(n/10>9)
		print(n/10);
	else
		printf("%d ",n%10);
}
int main()
{
    int n = 0;
	scanf("%d",&n);
	print(n);
	return 0;
}