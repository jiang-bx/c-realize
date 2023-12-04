#include <stdio.h>
#include <mm_malloc.h>

void CountingSort(int Arr[], int Len)
{
    // 获取最大值
    int max = Arr[0];
    int i = 0;

    for (; i < Len; i++)
    {
        if (Arr[i] > max)
        {
            max = Arr[i];
        }
    }
    max += 1;

    // 动态创建数组
    int *TempArr;
    TempArr = malloc(max * sizeof(int));

    if (TempArr == NULL)
    {
        printf("空间不足");
        return;
    }

    // 将 Arr 中的值, 记录在 TempArr 中
    for (i = 0; i < Len; i++)
    {
        TempArr[Arr[i]]++;
    }

    int k = 0;
    for (i = 0; i < max; i++)
    {
        while (TempArr[i] > 0)
        {
            Arr[k++] = i;
            TempArr[i]--;
        }
    }

    free(TempArr);
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    CountingSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
