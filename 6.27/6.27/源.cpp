//#define  _CRT_SECURE_NO_WARNINGS
//using namespace std;
//////#include <iostream>
//////void Perm(int list[], int k, int m)
//////{
//////	if (k == m)
//////	{
//////		for (int i = 0; i <= m; i++)
//////			cout << list[i] << " ";
//////		cout << endl;
//////	}
//////	else
//////	for (int j = k; j <= m; j++)
//////	{
//////		swap(list[k], list[j]);   ///���б�д
//////		Perm(list, k + 1, m);
//////		swap(list[k], list[j]);
//////	}
//////}
//////
//////int main()
//////{
//////	int list[] = { 1, 2, 3, 4, 5, 6 };
//////	Perm(list, 0, 3);
//////	getchar();
//////	return 0;
//////}
//////
//////#include <iostream>
//////#include<iomanip>
//////#include<stdlib.h>
//////#include<time.h>
//////#define M 11
//////typedef int KeyType;
//////typedef int ElemType;
//////struct rec{
//////	KeyType key;
//////	ElemType data;
//////};
//////typedef rec sqlist[M];
//////class guibing{
//////public:
//////	guibing(sqlist b)
//////	{
//////		for (int i = 0; i<M; i++)
//////			r[i] = b[i];
//////	}
//////	void output(sqlist r, int n)
//////	{
//////		for (int i = 0; i<n; i++)
//////			cout << setw(4) << r[i].key;
//////		cout << endl;
//////	}
//////	void xuanze(sqlist b, int m, int n)
//////	{
//////		int i, j, k;
//////		for (i = m; i<n - 1; i++)
//////		{
//////			k = i;
//////			for (j = i; j<n; j++)
//////			if (b[k].key>b[j].key) k = j;
//////			if (k != i)
//////			{
//////				rec temp = b[k];
//////				b[k] = b[i];
//////				b[i] = temp;
//////			}
//////		}
//////	}
//////	void merge(int l, int m, int h, sqlist r2)
//////	{
//////		xuanze(r, l, m);
//////		xuanze(r, m, h);
//////		output(r, M);
//////		int i, j, k;
//////		k = i = l;
//////		for (j = m; i<m&&j<h; k++)
//////		{
//////			if (r[i].key <= r[j].key)
//////			{
//////				r2[k] = r[i];
//////				i++;
//////			}
//////			else
//////			{
//////				r2[k] = r[j];
//////				j++;
//////			}
//////			output(r2, M);
//////		}
//////		while (j<h)
//////		{
//////			r2[k] = r[j];
//////			j++;
//////			k++;
//////		}
//////		while (i <= m)
//////		{
//////			r2[k] = r[i];
//////			i++;
//////			k++;
//////		}
//////		output(r2, M);
//////	}
//////private:
//////	sqlist r;
//////};
//////void main()
//////{
//////	cout << "guibingfa1���н��:\n";
//////	sqlist a, b;
//////	int i, j = 0, k = M / 2, n = M;
//////	srand(time(0));
//////	for (i = 0; i<M; i++)
//////	{
//////		a[i].key = rand() % 80; b[i].key = 0;
//////	}
//////	guibing gx(a);
//////	cout << "����ǰ����:\n";
//////	gx.output(a, M);
//////	cout << "�������������ʾ:\n";
//////	gx.merge(j, k, n, b);
//////	cout << "���������:\n";
//////	gx.output(b, M);
//////	cin.get();
//////}
////#include<windows.h>
////#include<iostream>
////#include<iomanip>
////#include<stdlib.h>
////#include<time.h>
////#define MAXI 10
////typedef int KeyType;
////typedef int ElemType;
////struct rec{
////	KeyType key;
////	ElemType data;
////};
////typedef rec sqlist[MAXI];
////class kuaisu
////{
////public:
////	kuaisu(sqlist a, int m) :n(m)
////	{
////		for (int i = 0; i<n; i++) b[i] = a[i];
////	}
////	void quicksort(int s, int t)
////	{
////		int i;
////		if (s<t){
////			i = part(s, t);
////			quicksort(s, i - 1);
////			quicksort(i + 1, t);
////		}
////		else return;
////	}
////	int part(int s, int t)
////	{
////		int i, j;
////		rec p;
////		i = s; j = t; p = b[s];
////		while (i<j)
////		{
////			while (i<j&&b[j].key >= p.key)j--;
////			b[i] = b[j];
////			while (i<j&&b[i].key <= p.key)i++;
////			b[j] = b[i];
////		}
////		b[i] = p;
////		output();
////		return i;
////	}
////	void output()
////	{
////		for (int i = 0; i<n; i++)
////			cout << setw(4) << b[i].key;
////		cout << endl;
////	}
////private:
////	sqlist b;
////	int n;
////};
////
////void main()
////{
////	cout << "kuaisu1.cpp���н��:\n";
////	sqlist a1;
////	int i, n = MAXI, low = 0, high = 9;
////	srand(time(0));
////	for (i = 0; i<n; i++)
////		a1[i].key = rand() % 80;
////	kuaisu px(a1, n);
////	cout << "�������������ʾ:\n";
////	px.quicksort(low, high);
////	cout << "���������:\n";
////	px.output();
////	cin.get();
////}
////
////
////
////#include <iostream>
////struct goodinfo
////{
////	float p; //��ƷЧ��
////	float w; //��Ʒ����
////	float X; //��Ʒ�÷ŵ�����
////	int flag; //��Ʒ���
////};//��Ʒ��Ϣ�ṹ��
////void Insertionsort(goodinfo goods[], int n)
////{
////	int j, i;
////	for (j = 2; j <= n; j++)
////	{
////		goods[0] = goods[j];
////		i = j - 1;
////		while (goods[0].p>goods[i].p)
////		{
////			goods[i + 1] = goods[i];
////			i--;
////		}
////		goods[i + 1] = goods[0];
////	}
////}//����ƷЧ�棬������ֵ����������
////void bag(goodinfo goods[], float M, int n)
////{
////	float cu;
////	int i, j;
////	for (i = 1; i <= n; i++)
////		goods[i].X = 0;
////	cu = M;  //����ʣ������
////	for (i = 1; i<n; i++)
////	{
////		if (goods[i].w>cu)//������Ʒ��������ʣ����������
////			break;
////		goods[i].X = 1;
////		cu = cu - goods[i].w;//ȷ�������µ�ʣ������
////	}
////	if (i <= n)
////		goods[i].X = cu / goods[i].w;//����Ʒ��Ҫ�ŵ���
////	for (j = 2; j <= n; j++)
////	{
////		goods[0] = goods[j];
////		i = j - 1;
////		while (goods[0].flag<goods[i].flag)
////		{
////			goods[i + 1] = goods[i];
////			i--;
////		}
////		goods[i + 1] = goods[0];
////	}
////	cout << "���Ž�Ϊ:" << endl;
////	for (i = 1; i <= n; i++)
////	{
////		cout << "��" << i << "����ƷҪ��:";
////		cout << goods[i].X << endl;
////	}
////}
////void main()
////{
////	cout << "|--------����̰�ķ��ⱳ������---------|" << endl;
////	cout << "|-------------------------------------|" << endl;
////	int j  ;
////	int n;
////	float M;
////	goodinfo *goods;//����һ��ָ��
////	while (j)
////	{
////		cout << "��������Ʒ����������";
////		cin >> n;
////		goods = new struct goodinfo[n + 1];//
////		cout << "�����뱳�������������";
////		cin >> M;
////		cout << endl;
////		int i;
////		for (i = 1; i <= n; i++)
////		{
////			goods[i].flag = i;
////			cout << "�������" << i << "����Ʒ������:";
////			cin >> goods[i].w;
////			cout << "�������" << i << "����Ʒ��Ч��:";
////			cin >> goods[i].p;
////			goods[i].p = goods[i].p / goods[i].w;//�ó���Ʒ��Ч�棬������
////			cout << endl;
////		}
////		Insertionsort(goods, n);
////		bag(goods, M, n);
////		cout << "press <1> to run agian" << endl;
////		cout << "press <0> to exit" << endl;
////		cin >> j;
////	}
////	system("pause");
////}
////
////
//////#include <stdio.h>
//////#include <stdlib.h>
//////#include <iostream>
//////#define INFINITY INT_MAX 
//////#define MAX_VERTEX_NUM 20 
//////typedef int VRType;
//////typedef int InfoType;
//////typedef char VerTexType;
//////typedef struct ArcCell
//////{
//////	VRType adj;
//////	InfoType *info;
//////}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//////typedef struct
//////{
//////	VerTexType vexs[MAX_VERTEX_NUM];
//////	AdjMatrix arcs;
//////	int vexnum, arcnum;
//////}MGraph;
//////typedef struct
//////{
//////	VerTexType adjvex;
//////	VRType lowcost;
//////}closedge[MAX_VERTEX_NUM];
//////
//////void CreateGraph(MGraph &G);
//////void MiniSpanTree_PRIM(MGraph G, VerTexType u);
//////int LocateVex(MGraph G, VerTexType u);
//////int minimum(closedge close);
//////void main(void)
//////{
//////	int i, j;
//////	MGraph G;
//////	CreateGraph(G);
//////	for (i = 0; i < G.vexnum; i++)
//////	{
//////		for (j = 0; j < G.vexnum; j++)
//////		{
//////			cout << G.arcs[i][j].adj;
//////			cout << " ";
//////		}
//////		cout << endl;
//////	}
//////	MiniSpanTree_PRIM(G, 'a');
//////}
//////void CreateGraph(MGraph &G)
//////{
//////	int weigh;
//////	int i, j = 0, k = 0;
//////	char hand, tide;
//////	cout << "input the number for vexnum and arcnum:";
//////	cin >> G.vexnum >> G.arcnum;
//////	for (i = 0; i < G.vexnum; i++)
//////	{
//////		for (j = 0; j < G.vexnum; j++)
//////			G.arcs[i][j].adj = 88;
//////	}
//////	cout << endl;
//////	cout << "input" << G.vexnum << "char for vexs:";
//////	for (i = 0; i < G.vexnum; i++)
//////		cin >> G.vexs[i];
//////	cout << endl;
//////	cout << "input" << G.arcnum << "arc(char,char,weigh):" << endl;
//////	j = 0;
//////	k = 0;
//////	for (i = 0; i < G.arcnum; i++)
//////	{
//////		cout << i << ":";
//////		cin >> hand;
//////		cin >> tide;
//////		cin >> weigh;
//////		while (hand != G.vexs[j])
//////			j++;
//////		while (tide != G.vexs[k])
//////			k++;
//////		G.arcs[j][k].adj = weigh;
//////		G.arcs[k][j].adj = weigh;
//////		j = 0;
//////		k = 0;
//////		cout << endl;
//////	}
//////}
//////void MiniSpanTree_PRIM(MGraph G, VerTexType u)
//////{
//////	int i, j, k = 0;
//////	closedge close;
//////
//////	k = LocateVex(G, u);
//////	for (j = 0; j < G.vexnum; j++)
//////	{
//////		if (j != k)
//////		{
//////			close[j].adjvex = G.vexs[k];
//////			close[j].lowcost = G.arcs[k][j].adj;
//////		}
//////	}
//////	close[j].lowcost = 88;
//////	close[j].adjvex = '\0';
//////	close[k].lowcost = 0;
//////	close[k].adjvex = u;
//////	for (i = 1; i < G.vexnum; i++)
//////	{
//////		k = minimum(close);
//////		cout << close[k].adjvex;
//////		cout << "---->";
//////		cout << G.vexs[k] << " ";
//////		cout << close[k].lowcost << endl;
//////		close[k].lowcost = 0;
//////		for (j = 0; j<G.vexnum; j++)
//////		{
//////			if (G.arcs[k][j].adj < close[j].lowcost)
//////			{
//////				close[j].adjvex = G.vexs[k];
//////				close[j].lowcost = G.arcs[k][j].adj;
//////			}
//////		}
//////	}
//////}
//////int LocateVex(MGraph G, VerTexType u)
//////{
//////	int k = 0;
//////	while (G.vexs[k++] == u)
//////		return k - 1;
//////	return 0;
//////}
//////int minimum(closedge close)
//////{
//////	int j1 = 0, client = 88, j2;
//////	while (close[j1].adjvex != '\0')
//////	{
//////		if (client > close[j1].lowcost && close[j1].lowcost != 0)
//////		{
//////			client = close[j1].lowcost;
//////			j2 = j1;
//////		}
//////		j1++;
//////	}
//////	return j2;
//////}
//
//#include<stdio.h>
//#include<conio.h>
//#include<malloc.h>
//#define MAX_VERTEX_NUM 50
//typedef struct ArcNode
//{
//	int adjvex; //�û���ָ��Ķ����λ��
//	int value;  //�ý�����ڽӽ���Ĵ���
//	struct ArcNode *nextarc; //ָ����һ������ָ��
//}ArcNode, *node;
//
//typedef struct VNode
//{
//	int data; //������Ϣ
//	ArcNode *firstArc; //ָ���һ�������ö���Ļ���ָ��
//}VNode, AdjList[MAX_VERTEX_NUM];
//
//typedef struct Graph
//{
//	AdjList vertices;
//	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
//}*ALGraph;
//int build_adList(ALGraph G, int n, int a)
//{ //�����ڽӱ�
//	int v, m, i, t, h;
//	node p, q;
//	if (n < 0) return printf("ERROR");
//	G->vexnum = n; //ͼ�Ķ�����
//	if (a < 0) return printf("ERROR");
//	G->arcnum = a; //ͼ�Ļ���
//	for (m = 0; m < n; m++)
//	{
//		G->vertices[m].data = m;
//		G->vertices[m].firstArc = NULL;
//	}
//	for (m = 1; m <= a; m++)
//	{
//		i = 1;
//		printf("�����%d����:", m);
//		scanf("%d,%d,%d", &t, &h, &v);
//		p = (ArcNode*)malloc(sizeof(ArcNode));
//		p->adjvex = h;
//		p->value = v;
//		p->nextarc = NULL;
//		while (G->vertices[i].data != t) i++; //ת����һ�����
//		if (!G->vertices[i].firstArc) //�յ�
//			G->vertices[i].firstArc = p;
//		else
//		{ //����ǰ����к�̽ڵ������
//			for (q = G->vertices[i].firstArc; q->nextarc; q = q->nextarc);
//			q->nextarc = p; //�¿��ٽ��
//		}
//	}
//	return v;
//}
//void print_Graph(ALGraph G)
//{ //��ӡ�ڽӱ�
//	ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
//	int i;
//	for (i = 1; i < G->vexnum; i++)
//	{
//		p = G->vertices[i].firstArc;
//		printf("[%d]", i);
//		while (p)
//		{
//			printf("->%d,%d", p->adjvex, p->value);//��i�������ڽӽ����Ϣ
//			p = p->nextarc;
//		}
//		printf("\n");
//	}
//}
//
//void fgraph(ALGraph G, int k, int n)
//{ //���ͼALGraph G��nΪ�������kΪͼ�Ķ���
//	//�����ǰ��ε�˳��������
//	int cost[100];
//	int d[100];
//	int path[100];
//	int j, r, i, min, w, value;
//	node p;
//	cost[n] = 0;
//	for (j = n - 1; j >= 1; j--) //��ǰ������
//	{
//		p = G->vertices[j].firstArc;
//		min = p->value + cost[p->adjvex]; //��ʼ��·����С����
//		r = p->adjvex;
//		value = p->value;
//		while (p != NULL)
//		{ //r��һ���������Ľ�㣬Ȩֵc(j,r)+cost[r]ȡ��Сֵ
//			if ((p->value + cost[p->adjvex]) < min)
//			{
//				min = p->value + cost[p->adjvex]; //p->value=c(j,r)
//				r = p->adjvex;
//				value = p->value;
//			}
//			p = p->nextarc;
//		}
//		cost[j] = value + cost[r]; //��ǰ�ڵ�Ĵ���ֵ
//		d[j] = r; //���߽׶Σ�����㵽�յ���С����·����ǰ������ı��
//	}
//	path[1] = 1; path[k] = n;
//	for (i = 2; i <= k - 1; i++) //�ҳ���С����·���ϵĽ��
//		path[i] = d[path[i - 1]];
//	printf("��С�ɱ�Ϊ:%d\n", cost[1]);
//	printf("��С�ɱ�·��Ϊ: ");
//	for (w = 1; w <= k; w++)
//		printf("%d->", path[w]);
//}
//void main()
//{
//	ALGraph g;
//	int n, a, k;
//	g = (ALGraph)malloc(sizeof(ALGraph));
//	printf("��������ͼ�ڵ���Ŀ:");
//	scanf("%d", &n);
//	printf("��������ͼ�ߵ���Ŀ:");
//	scanf("%d", &a);
//	printf("��������ͼ�Ķ���:");
//	scanf("%d", &k);
//	printf("������ͼ�Ļ�����Ϣ����ͷ����β��Ȩֵ��\n");
//	build_adList(g, n, a);
//	printf("���ͼ���ڽӱ�Ϊ:\n");
//	print_Graph(g);
//	fgraph(g, k, n);
//	getchar();
//}