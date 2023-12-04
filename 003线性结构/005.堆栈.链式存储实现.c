#include <stdio.h>
#include <mm_malloc.h>

typedef int ElementType;

typedef struct SNode *Stack;

struct SNode
{
    ElementType Data;
    struct SNode *Next;
};

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));

    S->Next = NULL;

    return S;
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void Push(ElementType X, Stack S)
{
    Stack newS = CreateStack();

    // 插入头节点之后

    newS->Data = X;
    newS->Next = S->Next;

    S->Next = newS;
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("堆栈空");
        return 0;
    }

    Stack curNode = S->Next;
    S->Next = curNode->Next;

    ElementType data = curNode->Data;

    // 释放申请的内存空间
    free(curNode);

    return data;
}

int main()
{
    return 0;
}