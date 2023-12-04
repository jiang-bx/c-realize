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

int main()
{
    int arr[10] = {9, 77, 44, 211, 34, 56, 6777, 8823, 1, 2343};

    InsertionSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
