#include <stdio.h>
#include <mm_malloc.h>

const int MaxSize = 10;

typedef int ElementType;

typedef struct SNode *Stack;

struct SNode
{
    ElementType Data[MaxSize];
    int Top;
};

Stack CreateStack(int MaxSize)
{
    Stack PtrS;

    PtrS = (Stack)malloc(sizeof(struct SNode));

    PtrS->Top = -1;

    return PtrS;
}

int IsFull(Stack PtrS, int MaxSize)
{
    return PtrS->Top == MaxSize - 1 ? 1 : 0;
}

int IsEmpty(Stack PtrS)
{
    return PtrS->Top == -1 ? 1 : 0;
}

void Push(Stack PtrS, ElementType item)
{
    if (IsFull(PtrS, MaxSize))
    {
        printf("堆栈满\n");
        return;
    }
    else
    {
        PtrS->Data[++(PtrS->Top)] = item;
    }
}

ElementType Pop(Stack PtrS)
{
    if (IsEmpty(PtrS))
    {
        printf("堆栈空\n");
        return 0;
    }
    else
    {
        return PtrS->Data[(PtrS->Top)--];
    }
}

int main()
{
    Stack s = CreateStack(MaxSize);

    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    printf("栈顶 top = %d\n", s->Top);
    Push(s, 4);

    printf("元素 = %d, 栈顶 top = %d\n", Pop(s), s->Top);
    printf("元素 = %d, 栈顶 top = %d\n", Pop(s), s->Top);
    printf("元素 = %d, 栈顶 top = %d\n", Pop(s), s->Top);
    printf("元素 = %d, 栈顶 top = %d\n", Pop(s), s->Top);

    return 0;
}