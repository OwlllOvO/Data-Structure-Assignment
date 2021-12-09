#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define DataType int
#define QueueType List

const int MAX_NUM = 100015;

typedef struct Node* List;

struct Node
{
    DataType Data;
    int NextNode;
    struct Node* Next;
};

List Graph[MAX_NUM];

List Linit(List PtrL)
{
    if (PtrL != NULL)
        PtrL = Linit(PtrL->Next);
    free(PtrL);

    PtrL = (List)malloc(sizeof(Node));
    PtrL->Data = 0;
    PtrL->Next = NULL;

    return PtrL;
}

void Linsert(int X, int V, List PtrL)
{
    List tmp = PtrL;
    while (tmp->Next != NULL)
    {
        tmp = tmp->Next;
    }
    tmp->Data = X;
    tmp->NextNode = V;
    tmp->Next = Linit(tmp->Next);
    tmp = tmp->Next;
}

int n, m;

void Init(int x)
{
    for (int i = 0; i <= x; i++)
    {
        Graph[i] = Linit(Graph[i]);
    }
}

bool vis[MAX_NUM];

void DFS(int now)
{
    if(vis[now]) return;
    vis[now] = 1;
    printf ("V%d ", now);
    List tmp = Graph[now];
    while(tmp->Next != NULL)
    {
        DFS(tmp->NextNode);
        tmp = tmp->Next;
    }
}


/* <Queue> -------------------------------------------------- */

typedef struct QueueNode* Queue;

struct QueueNode
{
    DataType Data;
    Queue Next;
};

Queue QInit()
{
    Queue PtrQ;
    PtrQ = (Queue) malloc (sizeof(QueueNode));
    PtrQ->Data = 0;
    PtrQ->Next = NULL;
    return PtrQ;
}

bool QIsEmpty(Queue PtrQ)
{
    return (PtrQ->Next == NULL);
}

int QSize(Queue PtrQ)
{
    if (QIsEmpty(PtrQ)) return 0;
    return QSize(PtrQ->Next) + 1;
}

bool QIsFull(Queue PtrQ)
{
    if (QSize(PtrQ) == MAX_NUM - 1) return 1;
    return 0;
}

void QPush(DataType x, Queue PtrQ)
{
    if (QIsFull(PtrQ))
    {
        printf ("QUEUE FULL\n");
        return;
    }
    Queue tmpQ;
    tmpQ = PtrQ;
    while(tmpQ->Next != NULL)
    {
        tmpQ = tmpQ->Next;
    }
    tmpQ->Data = x;
    tmpQ->Next = QInit();
}

DataType QPop(Queue PtrQ)
{
    Queue tmpQ = PtrQ;
    DataType res;
    if (QIsEmpty(tmpQ)) return NULL;
    res = tmpQ->Data;
    PtrQ = PtrQ->Next;
    free(tmpQ);
    return res;
}

void BFS(DataType now)
{
    Queue que;
    que = QInit();
    QPush(now, que);
    while(!QIsEmpty(que))
    {
        now = QPop(que);
        que = que->Next;
        vis[now] = 1;
        printf ("V%d ", now);
        List tmp;
        tmp = Graph[now];
        while(tmp->Next != NULL)
        {
            if(!vis[tmp->NextNode])
            {
                QPush(tmp->NextNode, que);
                vis[tmp->NextNode] = 1;
            }
            tmp = tmp->Next;
        }
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);
    scanf ("%d%d", &n, &m);
    Init(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Linsert(w, v, Graph[u]);
    }
    int start;
    while(scanf ("%d", &start) != EOF)
    {
        if (start == -1) return 0;
        memset(vis, 0, sizeof (vis));
        printf ("DFS From V%d: ", start);
        DFS(start);
        printf ("\n");
        memset(vis, 0, sizeof (vis));
        printf ("BFS From V%d: ", start);
        BFS(start);
        printf ("\n");
    }
    
    
    return 0;
    
}
