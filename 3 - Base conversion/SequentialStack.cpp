#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 100015

int n;

typedef struct
{
    int Data[MAXNUM];
    int top;
} Stack;

Stack* Sa;

Stack* MakeEmpty()
{
    Stack* PtrS;
    PtrS = (Stack*)malloc(sizeof(Stack));
    PtrS->top = 0;

    return PtrS;
}

bool scan()
{
    scanf("%d", &n);
    if (n == -1) return 0;
    
    return 1;
}

void pushStack(int item, Stack* PtrS)
{
    if (PtrS->top == MAXNUM - 1)
    {
        printf ("堆栈满\n");
        return;
    }
    else
    {
        PtrS->Data[++(PtrS->top)] = item;
        return;
    }
}

int popStack(Stack* PtrS)
{
    if (PtrS->top == -1)
    {
        printf ("堆栈空\n");
        return -1;
    }
    else
    {
        return (PtrS->Data[(PtrS->top)--]);
    }
}

void solve()
{
    if (!n)
    {
        printf ("0--->0\n");
        return;
    }
    
    Sa = MakeEmpty();
    int tmp = n;
    while (tmp)
    {
        pushStack(tmp % 2, Sa);
        tmp /= 2;
    }
    printf ("%d--->", n);
    while (Sa->top)
    {
        printf ("%d", popStack(Sa));
    }
    printf ("\n");
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("sequentialOut.txt", "w", stdout);

    while (scan())
    {
        solve();
    }


    return 0;

}
