#include <stdio.h>
#include <mm_malloc.h>

void SelectSort(int Arr[], int Len)
{
    for (int i = 0; i < Len - 1; i++)
    {
        // 从剩余元素中找到最小值的下标
        int minIndex = i;
        for (int j = i + 1; j < Len; j++)
        {
            if (Arr[minIndex] > Arr[j])
            {
                minIndex = j;
            }
        }

        // 将极值交换位置
        int temp = Arr[minIndex];
        Arr[minIndex] = Arr[i];
        Arr[i] = temp;
    }
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    SelectSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}