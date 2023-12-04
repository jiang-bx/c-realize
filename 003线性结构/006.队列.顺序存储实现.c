#include <stdio.h>
#include <mm_malloc.h>

const int MaxSize = 10;

typedef int ElementType;

struct QNode
{
    ElementType Data[MaxSize];
    int rear;  // 尾元素
    int front; // 头元素
};

typedef struct QNode *Queue;

Queue CreateQueue()
{
    Queue PtrQ;

    PtrQ = (Queue)malloc(sizeof(struct QNode));

    // front 永远指向头元素的前一个位置
    PtrQ->front = -1;

    PtrQ->rear = -1;

    return PtrQ;
}

int IsFullQ(Queue PtrQ)
{
    return (PtrQ->rear + 1) % MaxSize == PtrQ->front;
}

void AddQ(Queue PtrQ, ElementType item)
{
    if (IsFullQ(PtrQ))
    {
        printf("队列已满");
        return;
    }
    else
    {
        PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
        PtrQ->Data[PtrQ->rear] = item;
    }
}

int IsEmptyQ(Queue PtrQ)
{
    return PtrQ->front == PtrQ->rear;
}

ElementType DeleteQ(Queue PtrQ)
{
    if (IsEmptyQ(PtrQ))
    {
        printf("队列为空");
        return 0;
    }
    else
    {
        PtrQ->front = (PtrQ->front + 1) % MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}

int main()
{

    Queue q = CreateQueue();

    AddQ(q, 1);
    AddQ(q, 2);
    AddQ(q, 3);

    ElementType x = DeleteQ(q);

    printf("x = %d\n", x);

    AddQ(q, 4);

    printf("尾元素 = %d\n", q->Data[q->rear]);
    return 0;
}