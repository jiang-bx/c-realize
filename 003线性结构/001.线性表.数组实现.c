#include <stdio.h>
#include <mm_malloc.h>

const int MAX_SIZE = 10;
typedef int ElementType;
// 指针
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAX_SIZE];
    int Last;
};

// 定义表变量
struct LNode L;

// 初始化
List MakeEmpty()
{
    List PtrL;

    // malloc 动态分类内存空间
    PtrL = (List)malloc(sizeof(struct LNode));

    PtrL->Last = -1;

    return PtrL;
}

// 查找
int Find(ElementType X, List PtrL)
{
    int i = 0;

    while (i <= PtrL->Last && PtrL->Data[i] != X)
    {
        i++;
    }

    if (i > PtrL->Last)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

// 插入
void Insert(ElementType X, int i, List PtrL)
{
    int j;

    if (PtrL->Last == MAX_SIZE - 1)
    {
        printf("表满");
        return;
    }

    if (i < 1 || i > PtrL->Last + 2)
    {
        printf("位置不合法");
        return;
    }

    for (j = PtrL->Last; j >= i - 1; j--)
    {
        PtrL->Data[j + 1] = PtrL->Data[j];
    }

    PtrL->Data[i] = X;
    PtrL->Last++;
}

// 删除
void Delete(int i, List PtrL)
{
    int j;
    if (i < 1 || i > PtrL->Last + 1)
    {
        printf("不存在弟%d 个元素", i);
        return;
    }

    for (j = i; j < PtrL->Last; j++)
    {
        PtrL->Data[j - 1] = PtrL->Data[j];
    }

    PtrL->Last--;
}

int main()
{

    // PtrL->

    return 0;
}