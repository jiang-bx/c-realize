#include <stdio.h>
#include <mm_malloc.h>

void SwapHandle(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void BuildMaxHeap(int list[], int start, int end)
{
    int parent = start;
    int child = parent * 2 + 1;

    while (child <= end)
    {
        if (child + 1 <= end && list[child] < list[child + 1])
        {
            child++;
        }

        if (list[parent] < list[child])
        {
            SwapHandle(&list[parent], &list[child]);

            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int Arr[], int Len)
{
    // 数组中下标为: i 的结点
    // 对应的父节点: (i - 1) / 2
    // 对应的左子节点: i * 2 + 1
    // 对应的右子节点: i * 2 + 2

    // 建立堆, 从最后往前建立堆
    int i = (Len - 1 - 1) / 2;
    for (; i >= 0; i--)
    {
        BuildMaxHeap(Arr, i, Len - 1);
    }

    for (i = Len - 1; i > 0; i--)
    {
        // 最大值与最后交换位置, 相当于弹出最大值
        SwapHandle(&Arr[0], &Arr[i]);

        // 继续建立堆, 排除最大值
        BuildMaxHeap(Arr, 0, i - 1);
    }
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    HeapSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}