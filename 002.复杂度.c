#include <stdio.h>
void maxSubNum();
int maxSubNumTest1(int arr[], int len);
int maxSubNumTest2(int arr[], int len);
int maxSubNumTest3(int arr[], int len);
int maxSubNumTest4(int arr[], int len);

int main()
{
    maxSubNum();
    return 0;
}

// 求N个整数的序列连续最大子列和
void maxSubNum()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 4;

    int res1 = maxSubNumTest1(arr, 10);
    printf("res1 = %d\n", res1);

    int res2 = maxSubNumTest2(arr, 10);
    printf("res2 = %d\n", res2);

    int res3 = maxSubNumTest3(arr, 10);
    printf("res3 = %d\n", res3);

    int res4 = maxSubNumTest4(arr, 10);
    printf("res4 = %d\n", res4);
}

int maxSubNumTest1(int arr[], int len)
{
    int thisSum = 0, maxSum = 0;

    int i, j, k;

    // 时间复杂度: T = O(n^3)
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            thisSum = 0;
            for (k = i; k <= j; k++)
            {
                thisSum += arr[k];
                if (thisSum > maxSum)
                {
                    maxSum = thisSum;
                }
            }
        }
    }

    return maxSum;
}

int maxSubNumTest2(int arr[], int len)
{
    int thisSum = 0, maxSum = 0;

    int i, j;

    // 时间复杂度: T = O(n^2)
    for (i = 0; i < len; i++)
    {
        thisSum = 0;
        for (j = i; j < len; j++)
        {
            thisSum += arr[j];
            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int maxSubNumTest3(int arr[], int len)
{
    // 分而治之
    int thisSum = 0, maxSum = 0;

    int i, j;

    // 时间复杂度: T = O(n^2)
    for (i = 0; i < len; i++)
    {
        thisSum = 0;
        for (j = i; j < len; j++)
        {
            thisSum += arr[j];
            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int maxSubNumTest4(int arr[], int len)
{
    // 在线处理
    int thisSum = 0, maxSum = 0;
    int i;

    // 时间复杂度: T = O(n)
    for (i = 0; i < len; i++)
    {
        thisSum += arr[i];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
        }
    }

    return maxSum;
}