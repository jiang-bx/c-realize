#include <stdio.h>
#include <mm_malloc.h>

typedef int ElementType;

typedef struct Node *PNode;

struct Node
{
    ElementType Data;
    PNode Next;
};

struct QNode
{
    // front 指向链表的起始位置, 方便删除
    struct Node *front;
    // rear 指向链表的结束位置, 方便插入
    struct Node *rear;
};

typedef struct QNode *Queue;

Queue CreateQueue()
{
    Queue PtrQ;

    PtrQ = (Queue)malloc(sizeof(struct QNode));

    PtrQ->front = NULL;

    PtrQ->rear = NULL;

    return PtrQ;
}

int IsEmpty(Queue PtrQ)
{
    return PtrQ->front == NULL;
}

// 入队
void AddQ(Queue PtrQ, ElementType item)
{
    PNode node = (PNode)malloc(sizeof(PNode));

    node->Data = item;
    node->Next = NULL;

    if (IsEmpty(PtrQ))
    {
        PtrQ->front = node;
        PtrQ->rear = node;
    }
    else
    {
        PtrQ->rear->Next = node;
        PtrQ->rear = node;
    }
}

ElementType DeleteQ(Queue PtrQ)
{
    if (IsEmpty(PtrQ))
    {
        printf("队列为空");
        return 0;
    }

    PNode curNode = PtrQ->front;

    ElementType item = curNode->Data;

    PtrQ->front = curNode->Next;

    if (PtrQ->front == NULL)
    {
        PtrQ->rear = NULL;
    }

    free(curNode);

    return item;
}

typedef struct QNode *Queue;

int main()
{
    return 0;
}