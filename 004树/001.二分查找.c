#include <stdio.h>
#include <mm_malloc.h>

int binarySearch(int arr[], int length, int k);

int main()
{
    // printf("%d\n", 7 / 2);
    // 有序数组
    int nums[] = {5, 6, 39, 45, 51, 98, 100, 202, 226, 321, 368, 444, 501};

    printf("search 444, index = %d\n", binarySearch(nums, sizeof(nums) / sizeof(nums[0]), 444));
    printf("search 43, index = %d\n", binarySearch(nums, sizeof(nums) / sizeof(nums[0]), 43));
    return 0;
}

/**
 * @brief 有序数组二分查找
 *
 * @param arr
 * @param length
 * @param k
 * @return int
 */
int binarySearch(int arr[], int length, int k)
{
    int left, right, mid, noFound = -1;

    left = 0;
    right = length - 1;

    while (left <= right)
    {
        // 计算中间元素坐标
        mid = (left + right) / 2;

        if (k < arr[mid])
        {
            // 调整右边界
            right = mid - 1;
        }
        else if (k > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return noFound;
}