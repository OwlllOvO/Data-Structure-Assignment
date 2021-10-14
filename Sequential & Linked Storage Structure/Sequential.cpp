#define _CRTSECURE_NOWARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100015

int m1, m2;
int tt;			//�� tt ������

typedef struct
{
	int Data[MAXNUM];
	int Last;
} List;

List* La, * Lb, * Lc;

List* MakeEmpty()
{
	List* PtrL;
	PtrL = (List*)malloc(sizeof(List));
	PtrL->Last = 0;

	return PtrL;
}


/*
int Find(int X, List* PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X)
		i++;
	if (i > PtrL->Last) return -1;
	else return i;
}

void Insert(int X, int i, List* PtrL)
{
	int j;
	if (PtrL->Last == MAXNUM - 1)
	{
		printf("����");
		return;
	}
	if (i < 1 || i > PtrL->Last + 2)
	{
		printf("λ�ò��Ϸ�");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--) PtrL->Data[j + 1] = PtrL->Data[j];
	PtrL->Data[i - 1] = X;
	PtrL->Last++;

	return;
}

void Delete(int i, List* PtrL)
{
	int j;
	if (i < 1 || i > PtrL->Last + 1)
	{
		printf("�����ڵ�%d��Ԫ��", i);
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
		PtrL->Data[j - 1] = PtrL->Data[j];
	PtrL->Last--;

	return;
}
*/

void init()			//��ʼ��
{
	La = MakeEmpty();
	Lb = MakeEmpty();
	Lc = MakeEmpty();

	return;
}

void Lscan(int n, List* PtrL)			//���� List ����
{
	int i;
	int a;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		PtrL->Data[i] = a;
		PtrL->Last++;
	}
}

bool scan()			//����
{
	scanf("%d", &m1);
	if (m1 == -1) return 0;

	init();

	Lscan(m1, La);

	scanf("%d", &m2);
	Lscan(m2, Lb);

	return 1;
}

void merge()			//�ϲ� La, Lb �������� Lc
{
	int pina = 1;			//a �������� pina ��
	int pinb = 1;			//b �������� pinb ��
	while (pina <= m1 && pinb <= m2)
	{
		if (La->Data[pina] <= Lb->Data[pinb])
			Lc->Data[++Lc->Last] = La->Data[pina++];
		else
			Lc->Data[++Lc->Last] = Lb->Data[pinb++];
	}

	while (pina <= m1)
		Lc->Data[++Lc->Last] = La->Data[pina++];

	while (pinb <= m2)
		Lc->Data[++Lc->Last] = Lb->Data[pinb++];

	return;

}

void print()			//������
{
	printf("Case %d:%d\n", tt, Lc->Last);
	int i;
	for (i = 1; i <= Lc->Last; i++)
	{
		printf("%d ", Lc->Data[i]);
	}
	printf("\n");

	return;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("Sequential-out.txt", "w", stdout);

	while (++tt)
	{
		if (!scan()) return 0;

		merge();

		print();
	}


	return 0;

}

