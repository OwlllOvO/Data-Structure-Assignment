#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100015

int n;

typedef struct Node
{
    int Data;
    struct Node* Next;
} LinkStack;

LinkStack* Sa;

LinkStack* CreateStack()
{
    LinkStack* PtrS;
    PtrS = (LinkStack*)malloc(sizeof(Node));
    PtrS->Next = NULL;
    return PtrS;
}

bool isEmpty(LinkStack* PtrS)
{
    return (PtrS->Next == NULL);
}

void pushStack(int item, LinkStack* PtrS)
{
    Node* TmpCell;
    TmpCell = (LinkStack*)malloc(sizeof(Node));
    TmpCell->Data = item;
    TmpCell->Next = PtrS->Next;
    PtrS->Next = TmpCell;
}

int popStack(LinkStack* PtrS)
{
    Node* FirstCell;
    int TopData;
    if (isEmpty(PtrS))
    {
        printf ("堆栈空\n");
        return -1;
    }
    else
    {
        FirstCell = PtrS->Next;
        PtrS->Next = FirstCell->Next;
        TopData = FirstCell->Data;
        free(FirstCell);
        return TopData;
    }
}

bool scan()
{
    scanf ("%d", &n);
    if (n == -1) return 0;
    
    return 1;
    
}

void solve()
{
    if (!n)
    {
        printf ("0--->0\n");
        return;
    }
    
    Sa = CreateStack();
    int tmp = n;
    while(tmp)
    {
        pushStack(tmp % 2, Sa);
        tmp /= 2;
    }
    printf ("%d--->", n);
    while(!isEmpty(Sa))
    {
        printf ("%d", popStack(Sa));
    }
    printf ("\n");
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("LinkOut.txt", "w", stdout);
    
    while(scan())
    {
        solve();
    }
    
    
    return 0;
    
}
