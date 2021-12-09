#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define ElementType char
#define MAXNUM 100015

int THEMAX(int x, int y)
{
    if (x > y) return x;
    return y;
}



typedef struct TreeNode* BinTree;
typedef BinTree Position;

struct TreeNode
{
    ElementType Data;
    BinTree Left, Right;
};

BinTree TreeInit()
{
    BinTree PtrT;
    PtrT = (BinTree) malloc (sizeof(TreeNode));
    PtrT->Data = 0;
    PtrT->Left = NULL;
    PtrT->Right = NULL;
    return PtrT;
}

//建树
void CreateBiTree(BinTree &BT)
{
    ElementType ch;
    scanf("%c", &ch);
    if (ch == '#') BT = NULL;
    else
    {
        BT = new TreeNode;
        BT->Data = ch;
        CreateBiTree(BT->Left);
        CreateBiTree(BT->Right);
    }
}

//先序遍历
void PreOrderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%c", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

//中序遍历
void InOrderTraversal(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        printf("%c", BT->Data);
        InOrderTraversal(BT->Right);
    }
}

//后序遍历
void PostOrderTraversal(BinTree BT)
{
    if (BT)
    {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%c", BT->Data);
    }
}



/* <Stack> -------------------------------------------------- */

typedef struct StackNode* Stack;

struct StackNode
{
    BinTree Data;
    Stack Next;
};

Stack SInit()
{
    Stack PtrS;
    PtrS = (Stack) malloc (sizeof(StackNode));
    PtrS->Data = TreeInit();
    PtrS->Next = NULL;
    return PtrS;
}

int SIsEmpty(Stack PtrS)
{
    return (PtrS->Next == NULL);
}

int SSize(Stack PtrS)
{
    if (SIsEmpty(PtrS)) return 0;
    return SSize(PtrS->Next) + 1;
}

bool SIsFull(Stack PtrS)
{
    if (SSize(PtrS) == MAXNUM - 1) return 1;
    return 0;
}

void SPush(BinTree x, Stack PtrS)
{
    if (SIsFull(PtrS))
    {
        printf ("STACK FULL\n");
        return;
    }
    Stack insS;
    insS = SInit();
    insS->Data = x;
    insS->Next = PtrS->Next;
    PtrS->Next = insS;
}

BinTree SPop(Stack PtrS)
{
    Stack tmpS = PtrS;
    BinTree res;
    if (SIsEmpty(tmpS)) return NULL;
    tmpS = tmpS->Next;
    res = tmpS->Data;
    PtrS->Next = tmpS->Next;
    free(tmpS);
    return res;
}

void iterInorder(BinTree PtrS)
{
    Stack tmpS;
    tmpS = SInit();
    for (;;)
    {
        for (; PtrS; PtrS = PtrS->Left)
        {
            SPush(PtrS, tmpS);
        }
        PtrS = SPop(tmpS);
        if (!PtrS) break;
        printf("%c", PtrS->Data);
        PtrS = PtrS->Right;
    }
}

/* </Stack> -------------------------------------------------- */

/* <Queue> -------------------------------------------------- */

typedef struct QueueNode* Queue;

struct QueueNode
{
    BinTree Data;
    Queue Next;
};

Queue QInit()
{
    Queue PtrQ;
    PtrQ = (Queue) malloc (sizeof(QueueNode));
    PtrQ->Data = TreeInit();
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
    if (QSize(PtrQ) == MAXNUM - 1) return 1;
    return 0;
}

void QPush(BinTree x, Queue PtrQ)
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

BinTree QPop(Queue PtrQ)
{
    Queue tmpQ = PtrQ;
    BinTree res;
    if (QIsEmpty(tmpQ)) return NULL;
    res = tmpQ->Data;
    PtrQ = PtrQ->Next;
    free(tmpQ);
    return res;
}

void levelOrder(BinTree PtrQ)
{
    Queue tmpQ;
    tmpQ = QInit();
    if (!PtrQ)return;
    QPush(PtrQ, tmpQ);
    for (;;)
    {
        PtrQ = QPop(tmpQ);
        if (PtrQ)
        {
            printf("%c", PtrQ->Data);
            if (PtrQ->Left)
                QPush(PtrQ->Left, tmpQ);
            if (PtrQ->Right)
                QPush(PtrQ->Right, tmpQ);
        }
        else break;
    }
}

/* </Queue> -------------------------------------------------- */


//叶节点

int LeafCount(BinTree BT)
{
    if (BT == NULL) return 0;
    if (BT->Left == NULL && BT->Right == NULL) return 1;
    return LeafCount(BT->Left) + LeafCount(BT->Right);
}

//树深

int Depth(BinTree BT)
{
    if (BT == NULL) return 0;
    else
    {
        int m, n;
        m = Depth(BT->Left);
        n = Depth(BT->Right);
        return THEMAX(m, n) + 1;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    BinTree T;
    CreateBiTree(T);
    
    printf("PreOrderTraversal: ");
    PreOrderTraversal(T);
    printf ("\n");
    
    printf("InOrderTraversal: ");
    InOrderTraversal(T);
    printf ("\n");
    
    printf("PostOrderTraversal: ");
    PostOrderTraversal(T);
    printf ("\n");
    
    printf("iterInorder: ");
    iterInorder(T);
    printf ("\n");
    
    printf("levelOrder: ");
    levelOrder(T);
    printf ("\n");
    
    printf("LeafCount: %d\n", LeafCount(T));
    
    printf("Depth: %d\n", Depth(T));
     
    
    
    return 0;
    
}
