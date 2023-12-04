#include <stdio.h>
#include <mm_malloc.h>

void InsertionSort(int Arr[], int Len)
{
    for (int P = 1; P < Len; P++)
    {
        int temp = Arr[P];
        int i = P;

        for (; i > 0 && Arr[i - 1] > temp; i--)
        {
            Arr[i] = Arr[i - 1];
        }

        Arr[i] = temp;
    }
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 选取主元
 *
 * @param Arr
 * @param left
 * @param right
 * @return int 返回的是主元值, 并不是主元的下标
 */
int Median3(int Arr[], int left, int right)
{
    int center = (left + right) / 2;

    if (Arr[left] > Arr[center])
    {
        Swap(&Arr[left], &Arr[center]);
    }

    if (Arr[left] > Arr[right])
    {
        Swap(&Arr[left], &Arr[right]);
    }

    if (Arr[center] > Arr[right])
    {
        Swap(&Arr[center], &Arr[right]);
    }

    // 到这里得到: Arr[left] <= Arr[center] <= Arr[right]

    // 将主元 center 移动至右边, right > center , 所以移动至 right -1
    Swap(&Arr[center], &Arr[right - 1]);

    return Arr[right - 1];
}

void QSort(int Arr[], int left, int right)
{
    // 进入插入排序的域值
    int Cutoff = 5;

    if (right - left >= Cutoff)
    {
        int Pivot = Median3(Arr, left, right);

        int i = left, j = right - 1;

        for (;;)
        {

            // 小于主元的值, 放过
            while (Arr[++i] < Pivot)
            {
            }

            // 大于主元的值, 放过
            while (Arr[--j] > Pivot)
            {
            }

            if (i < j)
            {
                Swap(&Arr[i], &Arr[j]);
            }
            else
            {
                // 结束 for 循环
                break;
            }
        }

        // 将主元交换
        Swap(&Arr[i], &Arr[right - 1]);

        QSort(Arr, left, i - 1);
        QSort(Arr, i + 1, right);
    }
    else
    {
        // 使用插入排序
        InsertionSort(Arr + left, right - left + 1);
    }
}

void QuickSort(int Arr[], int Len)
{
    QSort(Arr, 0, Len - 1);
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    QuickSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
