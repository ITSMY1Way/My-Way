////////////////////#include <stdio.h>
////////////////////int main()
////////////////////{
////////////////////	int i = 1;
////////////////////	while (i <= 10)
////////////////////	{
////////////////////		if (i == 5)
////////////////////			break;
////////////////////		printf("%d ", i);
////////////////////		i = i + 1;
////////////////////	}
////////////////////	return 0;
////////////////////}
////////////////////#include <stdio.h>
////////////////////int main()
////////////////////{
////////////////////	int i = 1;
////////////////////	while (i <= 10)
////////////////////	{
////////////////////		if (i == 5)
////////////////////			continue;
////////////////////		printf("%d ", i);
////////////////////		i = i + 1;
////////////////////	}
////////////////////	getchar();
////////////////////	return 0;
////////////////////}
////////////////////#include <stdio.h>
////////////////////int main()
////////////////////{
////////////////////	int i = 1;
////////////////////	while (i <= 10)
////////////////////	{
////////////////////		i = i + 1;
////////////////////		if (i == 5)
////////////////////			continue;
////////////////////		printf("%d ", i);
////////////////////	}
////////////////////	getchar();
////////////////////	return 0;
////////////////////}
////////////////////#include <stdio.h>
////////////////////int main()
////////////////////{
////////////////////	int ch = 0;
////////////////////	while ((ch = getchar()) != EOF)
////////////////////		putchar(ch);
////////////////////	return 0;
////////////////////}
////////////////////#include <stdio.h>
////////////////////int main()
////////////////////{
////////////////////	int i = 0;
////////////////////	for (i = 1; i <= 10; i++)
////////////////////	{
////////////////////		if (i == 5)
////////////////////			continue;
////////////////////		printf("%d ", i);
////////////////////	}
////////////////////	getchar();
////////////////////	return 0;
//////////////////////}
////////////////////#include <stdio.h>
////////////////////int main()
////////////////////{
////////////////////	for (int i = 0, j = 0; j = 0; i++,j++)
////////////////////	{
////////////////////		j++;
////////////////////		printf("%d",i);
////////////////////	}
////////////////////	getchar();
////////////////////	return 0;
////////////////////}
////////////////////#include <stdio.h> 
////////////////////int main() { 
////////////////////	int num = -1; 
////////////////////	int i = 0; 
////////////////////	int count = 0;//计数 
////////////////////	while(num) { 
////////////////////		count++; 
////////////////////		num = num&(num-1); 
////////////////////	}
////////////////////	printf("二进制中1的个数 = %d\n",count); 
////////////////////	getchar();
////////////////////	return 0; 
////////////////////}
//////////////////#include <stdio.h> 
//////////////////int main() { 
//////////////////	int num = -1; 
//////////////////	int i = 0; 
//////////////////	int count = 0;//计数 
//////////////////	for(i=0; i<32; i++) { 
//////////////////		if( ((num>>i)&1) == 1 ) 
//////////////////			count++; }
//////////////////	printf("二进制中1的个数 = %d\n",count); 
//////////////////	getchar();
//////////////////	return 0; }
////////////////#include <stdio.h> 
////////////////void test1(int arr[]) 
////////////////{ printf("%d\n", sizeof(arr));//(2) 
////////////////}void test2(char ch[]) { printf("%d\n", sizeof(ch));//(4) 
////////////////}int main() { int arr[10] = {0}; 
////////////////char ch[10] = {0}; printf("%d\n", sizeof(arr));//(1) 
////////////////printf("%d\n", sizeof(ch));//(3) 
////////////////test1(arr); test2(ch); getchar(); return 0;
////////////////}
//////////////#include <stdio.h> 
//////////////int main() { 
//////////////int i = 1;
//////////////int ret = (++i) + (++i) + (++i); 
//////////////printf("%d\n", ret); printf("%d\n", i); 
//////////////getchar();
//////////////return 0; }
//////////////#include <stdio.h> 
//////////////int main() 
//////////////{ int i = 0,a=0,b=2,c =3,d=4; 
//////////////i = a++||++b||d++; 
//////////////printf("a = %d\n b = %d\n c = %d\n d = %d\n i = %d\n", a, b, c, d , i); 
//////////////getchar();
//////////////return 0; }
////////////#include <stdio.h> 
////////////int main() 
////////////{
////////////	int f = -1;
////////////	float num = f;
////////////	printf("%d", num);
////////////getchar();
////////////return 0; }
//////////#include<stdio.h>
//////////#include<stdlib.h> 
//////////void move(char get, char put) {	
//////////	printf("%c——>%c\n", get, put);
//////////} 
//////////void hanoit(int n, char a, char b, char c) {	
//////////	if(n == 1){		
//////////		move(a, c);	
//////////	} 
//////////	else {		
//////////		hanoit(n - 1, a, c, b);		
//////////		move(a, c);		
//////////		hanoit(n - 1, b, a, c);	
//////////	} 
//////////} 
//////////void move(char get, char put){
//////////	
//////////}
//////////int main() {	
//////////	int m;		
//////////	scanf_s("%d", &m);	
//////////	hanoit(m, 'A', 'B', 'C'); 	
//////////	system("pause");	
//////////	return 0;
//////////}
////////#include <stdio.h>
////////#include <stdlib.h>
////////int Frog_jump(int n)
////////{
////////	if (n < 3)
////////		return n;
////////	else
////////		return Frog_jump(n - 2) + Frog_jump(n - 1);
////////}
////////int main()
////////{
////////	int n = 0;
////////	int ret = 0;
////////	printf("请输入青蛙要跳的台阶数：");
////////	scanf_s("%d", &n);
////////	ret = Frog_jump(n);
////////	printf("%d\n", ret);
////////	system("pause");
////////	return 0;
////////}
//////#include <stdio.h>
//////int main(){
//////	char a = -1;
//////	signed char b = -1;
//////	unsigned char c = -1;
//////	printf("a=%d,b=%d,c=%d", a, b, c);
//////	getchar();
//////	return 0;
//////}
//////////////////#include <stdio.h>
//////////////////int main()
//////////////////{
//////////////////	int i = 1;
//////////////////	while (i <= 10)
//////////////////	{
//////////////////		if (i == 5)
//////////////////			break;
//////////////////		printf("%d ", i);
//////////////////		i = i + 1;
//////////////////	}
//////////////////	return 0;
//////////////////}
//////////////////#include <stdio.h>
//////////////////int main()
//////////////////{
//////////////////	int i = 1;
//////////////////	while (i <= 10)
//////////////////	{
//////////////////		if (i == 5)
//////////////////			continue;
//////////////////		printf("%d ", i);
//////////////////		i = i + 1;
//////////////////	}
//////////////////	getchar();
//////////////////	return 0;
//////////////////}
//////////////////#include <stdio.h>
//////////////////int main()
//////////////////{
//////////////////	int i = 1;
//////////////////	while (i <= 10)
//////////////////	{
//////////////////		i = i + 1;
//////////////////		if (i == 5)
//////////////////			continue;
//////////////////		printf("%d ", i);
//////////////////	}
//////////////////	getchar();
//////////////////	return 0;
//////////////////}
//////////////////#include <stdio.h>
//////////////////int main()
//////////////////{
//////////////////	int ch = 0;
//////////////////	while ((ch = getchar()) != EOF)
//////////////////		putchar(ch);
//////////////////	return 0;
//////////////////}
//////////////////#include <stdio.h>
//////////////////int main()
//////////////////{
//////////////////	int i = 0;
//////////////////	for (i = 1; i <= 10; i++)
//////////////////	{
//////////////////		if (i == 5)
//////////////////			continue;
//////////////////		printf("%d ", i);
//////////////////	}
//////////////////	getchar();
//////////////////	return 0;
////////////////////}
//////////////////#include <stdio.h>
//////////////////int main()
//////////////////{
//////////////////	for (int i = 0, j = 0; j = 0; i++,j++)
//////////////////	{
//////////////////		j++;
//////////////////		printf("%d",i);
//////////////////	}
//////////////////	getchar();
//////////////////	return 0;
//////////////////}
//////////////////#include <stdio.h> 
//////////////////int main() { 
//////////////////	int num = -1; 
//////////////////	int i = 0; 
//////////////////	int count = 0;//计数 
//////////////////	while(num) { 
//////////////////		count++; 
//////////////////		num = num&(num-1); 
//////////////////	}
//////////////////	printf("二进制中1的个数 = %d\n",count); 
//////////////////	getchar();
//////////////////	return 0; 
//////////////////}
////////////////#include <stdio.h> 
////////////////int main() { 
////////////////	int num = -1; 
////////////////	int i = 0; 
////////////////	int count = 0;//计数 
////////////////	for(i=0; i<32; i++) { 
////////////////		if( ((num>>i)&1) == 1 ) 
////////////////			count++; }
////////////////	printf("二进制中1的个数 = %d\n",count); 
////////////////	getchar();
////////////////	return 0; }
//////////////#include <stdio.h> 
//////////////void test1(int arr[]) 
//////////////{ printf("%d\n", sizeof(arr));//(2) 
//////////////}void test2(char ch[]) { printf("%d\n", sizeof(ch));//(4) 
//////////////}int main() { int arr[10] = {0}; 
//////////////char ch[10] = {0}; printf("%d\n", sizeof(arr));//(1) 
//////////////printf("%d\n", sizeof(ch));//(3) 
//////////////test1(arr); test2(ch); getchar(); return 0;
//////////////}
////////////#include <stdio.h> 
////////////int main() { 
////////////int i = 1;
////////////int ret = (++i) + (++i) + (++i); 
////////////printf("%d\n", ret); printf("%d\n", i); 
////////////getchar();
////////////return 0; }
////////////#include <stdio.h> 
////////////int main() 
////////////{ int i = 0,a=0,b=2,c =3,d=4; 
////////////i = a++||++b||d++; 
////////////printf("a = %d\n b = %d\n c = %d\n d = %d\n i = %d\n", a, b, c, d , i); 
////////////getchar();
////////////return 0; }
//////////#include <stdio.h> 
//////////int main() 
//////////{
//////////	int f = -1;
//////////	float num = f;
//////////	printf("%d", num);
//////////getchar();
//////////return 0; }
////////#include<stdio.h>
////////#include<stdlib.h> 
////////void move(char get, char put) {	
////////	printf("%c——>%c\n", get, put);
////////} 
////////void hanoit(int n, char a, char b, char c) {	
////////	if(n == 1){		
////////		move(a, c);	
////////	} 
////////	else {		
////////		hanoit(n - 1, a, c, b);		
////////		move(a, c);		
////////		hanoit(n - 1, b, a, c);	
////////	} 
////////} 
////////void move(char get, char put){
////////	
////////}
////////int main() {	
////////	int m;		
////////	scanf_s("%d", &m);	
////////	hanoit(m, 'A', 'B', 'C'); 	
////////	system("pause");	
////////	return 0;
////////}
//////#include <stdio.h>
//////#include <stdlib.h>
//////int Frog_jump(int n)
//////{
//////	if (n < 3)
//////		return n;
//////	else
//////		return Frog_jump(n - 2) + Frog_jump(n - 1);
//////}
//////int main()
//////{
//////	int n = 0;
//////	int ret = 0;
//////	printf("请输入青蛙要跳的台阶数：");
//////	scanf_s("%d", &n);
//////	ret = Frog_jump(n);
//////	printf("%d\n", ret);
//////	system("pause");
//////	return 0;
//////}
//////#include <stdio.h>
//////int main(){
//////	char a = -1;
//////	signed char b = -1;
//////	unsigned char c = -1;
//////	printf("a=%d,b=%d,c=%d", a, b, c);
//////	getchar();
//////	return 0;
//////}
////#include <stdio.h>
////int main()
////{
////	unsigned short A = 10; 
////	printf("~A = %d\n", ~A);
////	getchar();
////	return 0;
////}
////
//#include <stdio.h>
//int main()
//{
//	short num = 32767;
//	short a = num + 1;
//	printf("%d\n", a);
//	//0111 1111 1111 1111 -> 1000 0000 0000 0000 
//	//(系统直接识别为最小值，不进行解码)
//	getchar();
//	return 0;
//}
#include <stdio.h>
unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello wolrd\n");
	}
	getchar();
	return 0;
}