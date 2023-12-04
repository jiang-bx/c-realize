#include <stdio.h>
#include <mm_malloc.h>
void swapHandle(int list[], int i, int j);
void heapMaxHandle(int list[], int start, int end);
void heapMaxSort(int list[], int length);
void testSort();

int main()
{
    testSort();
    return 0;
}

void testSort()
{
    int length = 30;
    int list[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    printf("----------排序前:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", list[i]);
    }
    printf("\n");

    heapMaxSort(list, length);

    printf("----------排序后:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", list[i]);
    }
    printf("\n");
}

/**
 * @brief 交换元素位置
 *
 * @param list
 * @param i
 * @param j
 */
void swapHandle(int list[], int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

/**
 * @brief 调整数组为最大堆
 *
 * @param list
 * @param start
 * @param end
 */
void heapMaxHandle(int list[], int start, int end)
{
    // 父节点
    int parent = start;

    // 左子节点
    int child = parent * 2 + 1;

    // 左子节点 不能超出数组长度
    while (child <= end)
    {
        // 右子节点不能超出数组长度,  找到左右最大节点
        if (child + 1 <= end && list[child] < list[child + 1])
        {
            child++;
        }

        // 与父节点比较
        if (list[parent] >= list[child])
        {
            // 如果符合条件, 结束 while 循环
            break;
        }
        else
        {
            // 如果小于需要交换位置
            // 交换位置
            swapHandle(list, parent, child);

            // 继续比较子节点的子节点
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

/**
 * @brief 最大堆排序
 *
 * @param list
 * @param length
 */
void heapMaxSort(int list[], int length)
{
    // 开始调整为最大堆
    /**
     * 从最后的堆中开始调整
     * 依次往上遍历
     *
     * 原理: 找到左右子节点的最大值, 与父节点比较, 将最大值放在父节点上
     *
     * 数组中下标为: i 的结点
     * 对应的父节点: (i - 1) / 2
     * 对应的左子节点: i * 2 + 1
     * 对应的右子节点: i * 2 + 2
     */

    // 最后一个节点的父节点
    int i = (length - 1 - 1) / 2;

    // 堆化
    for (; i >= 0; i--)
    {
        // 从最后面的堆开始建堆
        heapMaxHandle(list, i, length - 1);
    }

    // 将堆中的最大值, 与最后一位元素交换位置
    // 并且重新调整,除过最后一位的堆

    for (int j = length - 1; j > 0; j--)
    {
        // 最大值 交换位置
        swapHandle(list, 0, j);

        // 从根结点开始堆键堆
        heapMaxHandle(list, 0, j - 1);
    }
}