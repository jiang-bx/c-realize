#include <stdio.h>
#include <mm_malloc.h>

void ShellSort(int Arr[], int Len)
{
    for (int D = Len / 2; D >= 1; D /= 2)
    {
        for (int P = D; P < Len; P++)
        {
            int temp = Arr[P];
            int i = P;

            for (; i >= D && Arr[i - D] > temp; i -= D)
            {
                Arr[i] = Arr[i - D];
            }

            Arr[i] = temp;
        }
    }
}

int main()
{
    int arr[10] = {9, 77, 44, 211, 34, 56, 6777, 8823, 1, 2343};

    ShellSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}