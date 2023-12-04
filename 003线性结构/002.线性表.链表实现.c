#include <stdio.h>
#include <mm_malloc.h>

typedef int ElementType;

typedef struct LNode *List;

struct LNode
{
    ElementType Data;
    List Next;
};

// 求表长
int Length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++;
    }

    return j;
}

// 查找
List FindKth(int i, List PtrL)
{
    List p = PtrL;

    int j = 1;

    while (p != NULL && j < i)
    {
        p = p->Next;
        j++;
    }

    return j == i ? p : NULL;
}

// 查找
List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while (p != NULL && p->Data != X)
    {
        p = p->Next;
    }

    return p;
}

// 插入
List Insert(ElementType X, int i, List PtrL)
{

    List p, s;

    if (i == 1)
    {
        s = (List)malloc(sizeof(struct LNode));

        s->Data = X;
        s->Next = PtrL;

        return s;
    }

    p = FindKth(i - 1, PtrL);

    if (p == NULL)
    {
        printf("参数出错");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

// 删除
List Delete(int i, List PtrL)
{
    List p, s;

    if (i == 1)
    {
        s = PtrL;
        if (PtrL != NULL)
        {
            PtrL = PtrL->Next;
        }
        else
        {
            return NULL;
        }
        // 释放通过 malloc 申请的内存空间
        free(s);
        return PtrL;
    }

    p = FindKth(i - 1, PtrL);

    if (p == NULL)
    {
        printf("%d个节点不存在", i - 1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("%d个节点不存在", i);
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

int main()
{
    // 创建链表
    List linkList = Insert(1, 1, NULL);

    printf("linkList length = %d\n", Length(linkList));

    linkList = Insert(2, 1, linkList);
    linkList = Insert(3, 1, linkList);
    linkList = Insert(4, 1, linkList);
    linkList = Insert(5, 1, linkList);
    linkList = Insert(6, 1, linkList);

    printf("linkList length = %d\n", Length(linkList));

    Insert(8, 6, linkList);

    printf("linkList length = %d\n", Length(linkList));
    return 0;
}