#include <stdio.h>
#include <mm_malloc.h>

void BubbleSort(int Arr[], int Len);

int main()
{

    int arr[10] = {9, 77, 44, 211, 34, 56, 6777, 8823, 1, 2343};

    BubbleSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void BubbleSort(int Arr[], int Len)
{
    for (int P = Len - 1; P >= 0; P--)
    {
        int flag = 0;
        for (int i = 0; i < P; i++)
        {
            if (Arr[i] > Arr[i + 1])
            {
                int temp = Arr[i];
                Arr[i] = Arr[i + 1];
                Arr[i + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0)
        {
            break;
        }
    }
}
