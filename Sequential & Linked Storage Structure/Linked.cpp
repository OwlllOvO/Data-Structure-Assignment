#define _CRTSECURE_NOWARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int m1, m2;
int tt, tot;			//�� tt �����ݣ����� tot ����

typedef struct Node
{
	int Data;
	struct Node* Next;
}List;

List* La, * Lb, * Lc;


/*
int Length(List* PtrL)
{
	List* p = PtrL;
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}

List* FindKth(int K, List* PtrL)
{
	List* p = PtrL;
	int i = 1;
	while (p != NULL && i < K)
	{
		p = p->Next;
		i++;
	}
	if (i == K) return p;
	else return NULL;
}

List* Find(int X, List* PtrL)
{
	List* p = PtrL;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p;
}

List* Insert(int X, int i, List* PtrL)
{
	List* p, * s;
	if (i == 1)
	{
		s = (List*)malloc(sizeof(List));
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL)
	{
		printf("����i��");
		return NULL;
	}
	else
	{
		s = (List*)malloc(sizeof(List));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}

List* Delete(int i, List* PtrL)
{
	List* p, * s;
	if (i == 1)
	{
		s = PtrL;
		if (PtrL != NULL) PtrL = PtrL->Next;
		else return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL)
	{
		printf("��%d����㲻����", i - 1);
		return NULL;
	}
	else if (p->Next == NULL)
	{
		printf("��%d����㲻����", i);
		return NULL;
	}
	else
	{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}
}

*/

List* Linit(List* PtrL)			//��ʼ�� List ���ͱ���
{
	if (PtrL != NULL)
		PtrL = Linit(PtrL->Next);
	free(PtrL);

	PtrL = (List*)malloc(sizeof(List));			//����һ���¿ռ��д��
	PtrL->Data = 0;
	PtrL->Next = NULL;

	return PtrL;
}

void init()			//�����ʼ��
{
	La = Linit(La);
	Lb = Linit(Lb);
	Lc = Linit(Lc);
	tot = 0;

	return;

}

void Linsert(int X, List* PtrL)			//�� X ���뵽 PtrL ĩβ
{
	List* tmp = PtrL;
	while (tmp->Next != NULL)
	{
		tmp = tmp->Next;
	}
	tmp->Data = X;
	tmp->Next = Linit(tmp->Next);
	tmp = tmp->Next;
}

void Lscan(int n, List* PtrL)			//���� List ���ͱ���
{
	int i;
	
	for (i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		Linsert(a, PtrL);
	}

	return;
}

bool scan()			//�������
{
	scanf("%d", &m1);
	if (m1 == -1) return 0;

	init();

	Lscan(m1, La);

	scanf("%d", &m2);
	Lscan(m2, Lb);
	
	return 1;
}

void merge(List* PtrL)			//�ϲ� La, Lb �� Lc
{
	List* tmp1 = La;
	List* tmp2 = Lb;
	List* tmp3 = PtrL;
	while (tmp1->Next != NULL && tmp2->Next != NULL)
	{
		if (tmp1->Data <= tmp2->Data)
		{
			Linsert(tmp1->Data, tmp3);
			tmp3 = tmp3->Next;
			tmp1 = tmp1->Next;
			tot++;
		}
		else
		{
			Linsert(tmp2->Data, tmp3);
			tmp3 = tmp3->Next;
			tmp2 = tmp2->Next;
			tot++;
		}
	}
	while (tmp1->Next != NULL)
	{
		Linsert(tmp1->Data, tmp3);
		tmp3 = tmp3->Next;
		tmp1 = tmp1->Next;
		tot++;
	}
	while (tmp2->Next != NULL)
	{
		Linsert(tmp2->Data, tmp3);
		tmp3 = tmp3->Next;
		tmp2 = tmp2->Next;
		tot++;
	}

	return;

}

void print()			//������
{
	printf("Case %d:%d\n", tt, tot);
	List* pnt;
	pnt = Lc;
	while (pnt->Next != NULL)
	{
		printf("%d ", pnt->Data);
		pnt = pnt->Next;
	}
	printf("\n");
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("Linked-out.txt", "w", stdout);

	while (++tt)
	{
		if (!scan()) return 0;

		merge(Lc);

		print();
	}


	return 0;

}
