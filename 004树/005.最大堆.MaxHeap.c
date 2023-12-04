#include <stdio.h>
#include <mm_malloc.h>
#include <math.h>

#define ElementType int
#define MaxData 10000000

// 定义堆的结构
struct HeapStruct
{
    // 存储堆元素的数组
    ElementType *Elements;

    // 堆的当前元素个数
    int Size;

    // 堆的最大容量
    int Capacity;
};

// 定义指针结构
typedef struct HeapStruct *MaxHeap;

MaxHeap Create(int MaxSize);
int IsFull(MaxHeap H);
int IsEmpty(MaxHeap H);
void Insert(MaxHeap H, ElementType item);
ElementType DeleteMax(MaxHeap H);
int GetMaxHeapItemLevel(int i);
void PrintMaxHeap(MaxHeap H);
void test();

int main()
{
    test();
    return 0;
}

void test()
{
    // 创建最大堆
    MaxHeap h = Create(10);
    Insert(h, 11);
    Insert(h, 33);
    Insert(h, 34);
    Insert(h, 22);
    Insert(h, 44);
    Insert(h, 55);
    Insert(h, 99);
    Insert(h, 1);
    Insert(h, 100);

    PrintMaxHeap(h);

    DeleteMax(h);

    PrintMaxHeap(h);
}

/**
 * @brief 创建最大堆
 *
 * @param MaxSize
 * @return MaxHeap
 */
MaxHeap Create(int MaxSize)
{
    MaxHeap H = malloc(sizeof(struct HeapStruct));

    // 完全二叉树, 从上至下, 从左至右存储
    // 每个子节点大于其子节点的元素值

    H->Elements = malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;

    // 定义哨兵为, 大于堆中所有可能元素的值, 便于以后操作
    H->Elements[0] = MaxData;

    return H;
}

/**
 * @brief 判断是否已满
 *
 * @param H
 * @return int
 */
int IsFull(MaxHeap H)
{
    return H->Capacity == H->Size ? 1 : 0;
}

/**
 * @brief 判断是否为空
 *
 * @param H
 * @return int
 */
int IsEmpty(MaxHeap H)
{
    return H->Size <= 0 ? 1 : 0;
}

/**
 * @brief 最大堆插入
 *
 * @param H
 * @param item
 */
void Insert(MaxHeap H, ElementType item)
{
    if (IsFull(H))
    {
        printf("最大堆已满");
        return;
    }

    // int 向下取整, 27 / 2 = 13.5 = 13 忽略小数点后面的位置

    int i = ++H->Size;

    // 需要与父节点进行比较, 如果大于了, 需要交换位置
    /**
     *          MaxData_0
     *            55_1
     *     34_2          44_3
     * 11_4    22_5  33_6
     * 存储顺序为:
     * MaxData, 55, 34, 44, 11, 22, 33
     * 判断条件: 父节点是否小于插入的值, 是的话需要交换位置, 并且继续向前判断
     * 例如:
     * 在 7 的位置插入 99
     *   与 44 比较, 将 44 的 放在 7 的位置
     *   继续与 55 比较, 将 55 放在 3 的位置
     *   继续与 0 位置比较, 0 位置为哨兵, 不符合,
     *   就将 99 插入在 1 的位置
     */
    // 关键点, 如何在数组中找到父节点
    // i = size + 1 标记了要在数组中插入的位置
    // 所以需要从后往前找
    // 例如:
    // i = 1, 父: 1 / 2 = 0.5 = 0, 0位置比较特殊: 有一个超大值存在
    // i = 2, 父: 2 / 2 = 1
    // i = 3, 父: 3 / 2 = 1.5 = 1
    // i = 4, 父: 4 / 2 = 2
    // i = 5, 父: 5 / 2 = 2.5 = 2
    // i = 6, 父: 6 / 2 = 3
    // i = 7, 父: 7 / 2 = 3.5 = 3

    // 所以: i / 2 向下取整就能找到其父节点
    // 判断条件: 父节点是否小于插入的值, 是的话需要交换位置, 并且继续向前判断
    for (; H->Elements[i / 2] < item; i /= 2)
    {
        // 父节点移动至子节点位置
        H->Elements[i] = H->Elements[i / 2];
    }

    H->Elements[i] = item;
}

/**
 * @brief 删除最大堆中的最大值
 *
 * @param H
 * @return ElementType
 */
ElementType DeleteMax(MaxHeap H)
{
    // 删除原理: 用最后一个元素的值,
    // 替换删除的元素, 然后调整堆
    // 这样就保证了堆的 完全二叉树的特性

    // 用最后的元素填充需要删除的元素,

    if (IsEmpty(H))
    {
        printf("最大堆位空!!!\n");
        return -1;
    }

    // 最大元素
    ElementType MaxItem = H->Elements[1];

    // 最后一个元素
    ElementType temp = H->Elements[H->Size];

    // size 减小
    H->Size--;

    int parent, child;

    // parent * 2 为 parent 的左子节点的位置
    //               左子节点是否超出         进入下一个节点
    for (parent = 1; parent * 2 < H->Size; parent = child)
    {
        child = parent * 2;
        // 判断左右子节点哪个最大
        if (child != H->Size && H->Elements[child] < H->Elements[child + 1])
        {
            child++;
        }

        // 如果最后一个节点的数据 大于子节点数据, 结束循环
        if (temp >= H->Elements[child])
        {
            break;
        }
        else
        {
            // 如果父节点 小于 左右子节点中的数据
            // 父节点的位置要变为子节点数据
            H->Elements[parent] = H->Elements[child];

            // 那么对应的子节点数据也需要处理
            // 进入对应的子节点 parent = child,
            // 判断是否符合条件, 符合条件就结束了循环
            // parent 就是 temp 符合的位置
        }
    }

    H->Elements[parent] = temp;

    return MaxItem;
}

/**
 * @brief Get the Max Heap Item Level object
 *
 * @param i
 * @return int
 */
int GetMaxHeapItemLevel(int i)
{
    int totalLevel = 0;

    while (i > 1)
    {
        totalLevel += 1;
        i /= 2;
    }

    return totalLevel;
}

/**
 * @brief 打印最大堆
 *
 * @param H
 */
void PrintMaxHeap(MaxHeap H)
{
    printf("----------- 开始打印最大堆:\n");
    if (IsEmpty(H))
    {
        printf("最大堆为空!!!\n");
        return;
    }

    int totalLevel = GetMaxHeapItemLevel(H->Size);

    int levelList[totalLevel + 1];

    for (int l = 0; l < totalLevel + 1; l++)
    {
        levelList[l] = 0;
    }

    for (int i = 1; i <= H->Size; i++)
    {
        int level = GetMaxHeapItemLevel(i);
        int indent = totalLevel - level;

        // 前空格
        if (levelList[level] == 0)
        {
            int beforeSpace = indent * 5;
            for (int j = 0; j < beforeSpace; j++)
            {
                printf(" ");
            }
        }

        printf("%d", H->Elements[i]);

        // 判断当前层级是否完毕
        int curLevelTotal = pow(2, level);

        // 记录层级 增加的个数
        levelList[level]++;

        if (curLevelTotal == levelList[level])
        {
            printf("\n");
        }
        else
        {
            printf("      ");
        }
    }
    printf("\n");
}