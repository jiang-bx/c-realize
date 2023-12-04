#include <stdio.h>
#include <mm_malloc.h>

void arrayInit();
void arrayInit1();
void arrayFunc();
int arrayMax(int nums[], int length);
void arraySort();
void arraySelectSort();
void arrayBubbleSort();
void arrayHalfSearch();
void arrayInsertHalfSearch();
void twoDimensionalArray();
void changeDimensionalArray();


int main()
{
    // arrayInit();
    // arrayInit1();
    // arrayFunc();
    // arraySelectSort();
    // arrayBubbleSort();
    // arrayHalfSearch();
    // arrayInsertHalfSearch();
    // twoDimensionalArray();

    // malloc 申请分配的内存都会赋予默认值
    int* array = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, array[i]);
    }

    return 0;
}

void twoDimensionalArray()
{
    // 初始化
    int nums[2][3];

    // 初始化赋值
    int nums1[2][3] = {
        {1, 2, 3},
        {1, 2, 3}
    };
    
    printf("%i\n", nums1[1][2]);

    // 不完全初始化
    int nums2[2][3] = {
        {1, 2},
    };

    // 省略写法
    int nums3[][3] = {
        1, 2, 3,
        4, 5, 6,
        7
    };

    printf("&nums3 = %p\n", &nums3);
    printf("nums3 = %p\n", nums3);
    printf("&nums3[0] = %p\n", &nums3[0]);
    printf("&nums3[0][0] = %p\n", &nums3[0][0]);

    changeDimensionalArray(nums3);

    printf("nums3[0][0] = %i\n", nums3[0][0]);
    printf("&nums3[0][0] = %p\n", &nums3[0][0]);
}

void changeDimensionalArray(int values[][3]) {
    values[0][0] = 998;
    printf("执行完毕\n");
}

void arrayInsertHalfSearch()
{
    /**
     * 现有一个有序的数组, 要求给定一个数字,
     * 将该数字插入到数组中, 还要保证数组是有序的
     */
    //             0  1  2  3  4
    int nums[5] = {1, 3, 5, 7, 9};
    int key = 6;
    int length = sizeof(nums) / sizeof(nums[0]);

    int min, max, mid;
    min = 0;
    max = length - 1;

    /**
     *     起始 第一次  第二次  第三次
     * mid: 0    2      3      3
     * min: 0    3      3      3
     * max: 4    4      3      2
     */

    while (min <= max)
    {
        mid = (min + max) / 2;
        if (key > nums[mid])
        {
            min = mid + 1;
        }
        else if (key < nums[mid])
        {
            max = mid - 1;
        }
    }

    // 插入位置: min
    printf("插入位置为min = %i\n", min);
}

void arrayHalfSearch()
{
    int nums[5] = {1, 3, 5, 7, 9};
    int key = 9;
    int length = sizeof(nums) / sizeof(nums[0]);

    int min = 0;
    int max = length - 1;
    int mid;
    /**
    int mid = (min + max) / 2;
    while (key != nums[mid])
    {
        if (key > nums[mid]) {
            // 判断如果要找的值, 大于了取出的值, 那么 min 要改变
            min = mid + 1; // 将 min 向右移动
        } else if(key < nums[mid]) {
            // 判断如果要找的值, 小于了取出的值, 那么 max 要改变
            max = mid - 1; // 将 max 向左移动
        }

        if (min > max) {
            // 超出范围
            printf("mid = -1\n");
            return;
        }

        // 每次改变完 min 和 max 重新计算 mid
        mid = (min + max) / 2;
    }
    printf("mid = %i\n", mid);
    */

    while (min <= max)
    {
        printf("aaa\n");
        mid = (min + max) / 2;
        if (key > nums[mid])
        {
            min = mid + 1;
        }
        else if (key < nums[mid])
        {
            max = mid - 1;
        }
        else
        {
            printf("mid = %i\n", mid);
            return;
        }
    }
    printf("mid = -1\n");
}

void arrayBubbleSort()
{
    int nums[5] = {99, 12, 88, 34, 5};

    // 相邻两个元素比较, 符合条件, 元素互换
    // 每比较一次, 最值出现在最后面
    // 所以每次循环, 需要从 0 开始比较, 结束条件不需要循环到最后
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    printf("nums[0] = %i\n", nums[0]);
    printf("nums[1] = %i\n", nums[1]);
    printf("nums[2] = %i\n", nums[2]);
    printf("nums[3] = %i\n", nums[3]);
    printf("nums[4] = %i\n", nums[4]);
}

/**
 * @brief 选择排序
 */
void arraySelectSort()
{
    int nums[5] = {99, 12, 88, 34, 5};

    // 每个元素依次与其后面的每个元素比较, 符合条件, 元素互换
    // 每执行一次, 最值在最前面
    // 所以新的循环, 没必要从 0 开始

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    printf("nums[0] = %i\n", nums[0]);
    printf("nums[1] = %i\n", nums[1]);
    printf("nums[2] = %i\n", nums[2]);
    printf("nums[3] = %i\n", nums[3]);
    printf("nums[4] = %i\n", nums[4]);
}

void arrayInit()
{
    int nums[2] = {};
    printf("%i\n", nums[0]);

    char strs[2] = {'a'};
    printf("%i\n", strs[1]);

    int a = 10;
    int as[a];
    printf("as[0] = %i\n", as[0]);

    int bs[5] = {[4] = 3};
    printf("bs[3] = %i\n", bs[3]);
    printf("bs[4] = %i\n", bs[4]);
}

void arrayInit1()
{
    char chars[4] = {'l', 'u', 'c', 'k'};

    printf("chars[0] = %p\n", &chars[0]);
    printf("chars[1] = %p\n", &chars[1]);
    printf("chars[2] = %p\n", &chars[2]);
    printf("chars[3] = %p\n", &chars[3]);
    printf("chars = %p\n", &chars); // 0x7ffeeb12c60c
    printf("chars = %p\n", chars);  // 0x7ffeeb12c60c

    int nums1[2] = {1, 2};
    int nums2[3] = {5, 6, 8};

    // 报警告
    // nums2[3] = 44;
    printf("nums1[0] = %i\n", nums1[0]);
}

void arrayFunc()
{
    // values[0] = 33;
    // printf("size = %lu\n", sizeof(values)); // 8Byte

    int nums[5] = {1, 100, 77, 44, 99};
    int length = sizeof(nums) / sizeof(nums[0]);
    int maxNum = arrayMax(nums, length);

    printf("maxNum = %i\n", maxNum);
    arraySort();
    // int
}

int arrayMax(int nums[], int length)
{
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        max = max < nums[i] ? nums[i] : max;
    }

    return max;
}

void arraySort()
{
    int nums[10] = {0};

    int value = -1;

    // 基数排序

    for (int i = 0; i < 4; i++)
    {
        printf("请输入第%i 个数组\n", i + 1);
        scanf("%i", &value);
        nums[value] += 1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            printf("%i\n", i);
        }
    }
}