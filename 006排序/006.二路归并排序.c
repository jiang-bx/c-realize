#include <stdio.h>
#include <mm_malloc.h>

/**
 * @brief 合并数组
 *
 * @param Arr 原始数组
 * @param TempA 存放排序后的临时数据
 * @param left 左边起始位置
 * @param right 右边起始位置
 * @param rightEnd 右边结束位置
 */
void Merge(int Arr[], int TempA[], int left, int right, int rightEnd)
{
    int leftEnd = right - 1;

    int originLeft = left;

    int elementCount = rightEnd - left + 1;

    while (left <= leftEnd && right <= rightEnd)
    {
        if (Arr[left] <= Arr[right])
        {
            TempA[originLeft++] = Arr[left++];
        }
        else
        {
            TempA[originLeft++] = Arr[right++];
        }
    }

    // 直接复制左边剩余
    while (left <= leftEnd)
    {
        TempA[originLeft++] = Arr[left++];
    }

    // 直接复制右边剩余
    while (right <= rightEnd)
    {
        TempA[originLeft++] = Arr[right++];
    }

    // 需要修改将排序后的数据临时数据返回
    for (int i = 0; i < elementCount; i++, rightEnd--)
    {
        Arr[rightEnd] = TempA[rightEnd];
    }
}

/**
 * @brief 递归调用
 *
 * @param Arr
 * @param TempA
 * @param left
 * @param rightEnd
 */
void MSort(int Arr[], int TempA[], int left, int rightEnd)
{
    if (left < rightEnd)
    {
        int center = (left + rightEnd) / 2;
        // 左半部分
        MSort(Arr, TempA, left, center);

        // 右半部分
        MSort(Arr, TempA, center + 1, rightEnd);

        // 合并数据
        Merge(Arr, TempA, left, center + 1, rightEnd);
    }
}

void MergeSort(int Arr[], int Len)
{
    int *TempA;
    TempA = malloc(Len * sizeof(int));

    if (TempA != NULL)
    {
        MSort(Arr, TempA, 0, Len - 1);
        free(TempA);
    }
    else
    {
        printf("空间不足");
    }
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    MergeSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}