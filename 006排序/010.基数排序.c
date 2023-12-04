#include <stdio.h>
#include <mm_malloc.h>

typedef struct LNode *List;
struct LNode
{
    int Data;
    List Next;
    List Last;
};

List CreateLNode(int Data)
{
    List node = malloc(sizeof(struct LNode));
    node->Data = Data;
    node->Next = NULL;
    node->Last = NULL;

    return node;
}

void InitRadixArr(List TempArr[], int binary)
{
    int i = 0;
    for (i = 0; i < binary; i++)
    {
        TempArr[i] = CreateLNode(-1);
    }
}

void AddListNode(List L, int value)
{
    List tempNode = CreateLNode(value);

    if (L->Last == NULL)
    {
        L->Next = tempNode;
    }
    else
    {
        L->Last->Next = tempNode;
    }
    L->Last = tempNode;
}

void RadixSort(int Arr[], int Len)
{
    // 10 进制
    // 先将 个位数进行排序
    int binary = 10;
    int i = 0;

    List de;

    // 个位数组
    List RadixGeArr[binary];
    InitRadixArr(RadixGeArr, binary);
    for (; i < Len; i++)
    {
        int value = Arr[i] % 10;
        AddListNode(RadixGeArr[value], Arr[i]);
    }

    // 十位数
    List RadixShiArr[binary];
    InitRadixArr(RadixShiArr, binary);

    printf("个位数输出:\n");
    for (i = 0; i < binary; i++)
    {
        printf("%d: ", i);
        List current = RadixGeArr[i];
        while (current)
        {
            if (current->Data > -1)
            {
                printf("->%d", current->Data);
                // 获取十位数值
                int value = current->Data / 10 % 10;
                AddListNode(RadixShiArr[value], current->Data);
            }

            de = current;
            current = current->Next;
            free(de);
        }
        printf("\n");
    }

    // 百位数
    List RadixBaiArr[binary];
    InitRadixArr(RadixBaiArr, binary);

    printf("十位数输出:\n");
    for (i = 0; i < binary; i++)
    {

        printf("%d: ", i);
        List current = RadixShiArr[i];

        while (current)
        {
            if (current->Data > -1)
            {
                printf("->%d", current->Data);
                // 获取百位数值
                int value = current->Data / 100 % 10;
                AddListNode(RadixBaiArr[value], current->Data);
            }

            de = current;
            current = current->Next;
            free(de);
        }
        printf("\n");
    }

    int k = 0;

    printf("百位数输出:\n");
    for (i = 0; i < binary; i++)
    {
        printf("%d: ", i);
        List current = RadixBaiArr[i];
        while (current)
        {
            if (current->Data > -1)
            {
                // 将结果输出
                Arr[k++] = current->Data;
                printf("->%d", current->Data);
            }

            de = current;
            current = current->Next;
            free(de);
        }
        printf("\n");
    }
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    RadixSort(arr, len);

    printf("排序结果:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
