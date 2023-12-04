#include <stdio.h>
#include <mm_malloc.h>

// 定义类型
#define ElementType int

typedef struct TreeNode *AvlTree;
struct TreeNode
{
    // 数据
    ElementType Data;
    // 左子树
    AvlTree Left;
    // 右子树
    AvlTree Right;
    // 以当前 node 为根的树的高度
    int Height;
};

int GetHeight(AvlTree AVL);
int GetBalanceFactor(AvlTree AVL);
int Max(int a, int b);
AvlTree CreateAvlTree(ElementType X);
AvlTree FindMin(AvlTree AVL);
AvlTree Insert(ElementType X, AvlTree AVL);
AvlTree Delete(ElementType X, AvlTree AVL);
AvlTree MaintainBalance(AvlTree AVL);
AvlTree LeftRotate(AvlTree AVL);
AvlTree RightRotate(AvlTree AVL);
void PrintAvlTree(AvlTree AVL, int count);

// RR 例子
void RRTest()
{
    printf("---------------------------- RR 例子\n");
    AvlTree AVL = CreateAvlTree(5);
    Insert(1, AVL);
    Insert(6, AVL);
    Insert(8, AVL);
    PrintAvlTree(AVL, 0);
    Insert(9, AVL);
    PrintAvlTree(AVL, 0);
}

// LL 例子
void LLTest()
{
    printf("---------------------------- LL 例子\n");
    AvlTree AVL = CreateAvlTree(5);
    Insert(6, AVL);
    Insert(4, AVL);
    Insert(3, AVL);
    PrintAvlTree(AVL, 0);
    Insert(1, AVL);
    PrintAvlTree(AVL, 0);
}

// RL 例子
void RLTest()
{
    printf("---------------------------- RL 例子\n");
    AvlTree AVL = CreateAvlTree(5);
    Insert(1, AVL);
    Insert(6, AVL);
    Insert(8, AVL);
    PrintAvlTree(AVL, 0);
    Insert(7, AVL);
    PrintAvlTree(AVL, 0);
}

// LR 例子
void LRTest()
{
    printf("---------------------------- LR 例子\n");
    AvlTree AVL = CreateAvlTree(5);
    Insert(6, AVL);
    Insert(4, AVL);
    Insert(2, AVL);
    PrintAvlTree(AVL, 0);
    Insert(3, AVL);
    PrintAvlTree(AVL, 0);
}

void DeleteTest()
{
    printf("---------------------------- DeleteTest 例子\n");
    AvlTree AVL = CreateAvlTree(4);
    Insert(3, AVL);
    Insert(8, AVL);
    Insert(2, AVL);

    Insert(6, AVL);
    Insert(1, AVL);
    Insert(10, AVL);
    Insert(7, AVL);
    Insert(11, AVL);
    Insert(9, AVL);
    printf("------------ 最终结果\n");
    PrintAvlTree(AVL, 0);

    // 删除叶结点
    printf("------------ 删除叶结点 11 \n");
    Delete(11, AVL);
    PrintAvlTree(AVL, 0);

    printf("------------ 删除叶结点 10 \n");
    Delete(10, AVL);
    PrintAvlTree(AVL, 0);

    printf("------------ 删除叶结点 9 \n");
    Delete(9, AVL);
    PrintAvlTree(AVL, 0);
}

int main()
{
    // RRTest();
    // LLTest();
    // RLTest();
    // LRTest();
    // DeleteTest();
    return 0;
}

/**
 * @brief Create a Avl Tree object
 *
 * @param X
 * @return AvlTree
 */
AvlTree CreateAvlTree(ElementType X)
{
    AvlTree T = (AvlTree)malloc(sizeof(struct TreeNode));

    T->Data = X;
    T->Left = NULL;
    T->Right = NULL;
    T->Height = 1;

    return T;
}

/**
 * @brief Get the Height object, 获取树的高度
 *
 * @param AVL
 * @return int
 */
int GetHeight(AvlTree AVL)
{
    if (!AVL)
    {
        return 0;
    }

    return AVL->Height;
}

/**
 * @brief 取最大值
 *
 * @param a
 * @param b
 * @return int
 */
int Max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Get the Balance Factor object
 * 计算平衡因子, 左子树高度 与 右子树高度之差
 * @param AVL
 * @return int
 */
int GetBalanceFactor(AvlTree AVL)
{
    if (!AVL)
    {
        return 0;
    }

    return GetHeight(AVL->Left) - GetHeight(AVL->Right);
}

/**
 * @brief 查询最小值
 *
 * @param AVL
 * @return AvlTree
 */
AvlTree FindMin(AvlTree AVL)
{
    if (AVL)
    {
        while (AVL->Left)
        {
            AVL = AVL->Left;
        }
    }
    return AVL;
}

/**
 * @brief 向 AVL 插入数据
 *
 * @param X
 * @param AVL
 * @return AvlTree
 */
AvlTree Insert(ElementType X, AvlTree AVL)
{
    if (!AVL)
    {
        return CreateAvlTree(X);
    }
    else
    {
        if (X < AVL->Data)
        {
            AVL->Left = Insert(X, AVL->Left);
        }
        else if (X > AVL->Data)
        {
            AVL->Right = Insert(X, AVL->Right);
        }
    }

    return MaintainBalance(AVL);
}

/**
 * @brief 删除元素
 *
 * @param X
 * @param AVL
 * @return AvlTree
 */
AvlTree Delete(ElementType X, AvlTree AVL)
{
    AvlTree Temp;
    if (!AVL)
    {
        printf("没有找到该元素!!!");
        return NULL;
    }

    if (X < AVL->Data)
    {
        AVL->Left = Delete(X, AVL->Left);
    }
    else if (X > AVL->Data)
    {
        AVL->Right = Delete(X, AVL->Right);
    }
    else
    {
        /**
         * 例如:
         *       4
         *    3       8
         *  2      6     10
         * 1    5    7  9   11
         * -------------------- 删除 11:
         *       4
         *    3      8
         *  2      6    10
         * 1    5    7   9
         * -------------------- 删除 2:
         *       4
         *    3       8
         *  1      6      10
         *      5    7   9   11
         * -------------------- 删除 8:
         * 取 8 左子树的最大值, 或者 右子树的最小值
         *       4
         *    3       9
         *  2      6     10
         * 1    5    7      11
         */

        // 存在两个节点
        if (AVL->Left && AVL->Right)
        {

            Temp = FindMin(AVL->Right);
            AVL->Data = Temp->Data;
            AVL->Right = Delete(AVL->Data, AVL->Right);
        }
        else
        {
            // 包含只有一个结点, 或者无节点
            Temp = AVL;

            if (!AVL->Left)
            {
                AVL = AVL->Right;
            }
            else if (!AVL->Right)
            {
                AVL = AVL->Left;
            }
            // else
            // {
            //     AVL = NULL;
            // }

            free(Temp);
        }
    }

    if (AVL)
    {
        return MaintainBalance(AVL);
    }
    return AVL;
}

/**
 * @brief 平衡 AVL 树
 *
 * @param AVL
 * @return AvlTree
 */
AvlTree MaintainBalance(AvlTree AVL)
{
    // 更新每个结点的高度
    AVL->Height = Max(GetHeight(AVL->Left), GetHeight(AVL->Right)) + 1;

    // 计算平衡因子
    int balanceFactor = GetBalanceFactor(AVL);

    // LL 差值超过 2, 不平衡, 并且 麻烦结点在 左子树上, 进行向右旋转
    if (balanceFactor >= 2 && GetBalanceFactor(AVL->Left) > 0)
    {
        printf("LL: 发现者 = %d, 平衡因子 = %d, LeftBalance = %d\n", AVL->Data, balanceFactor, GetBalanceFactor(AVL->Left));
        PrintAvlTree(AVL, 0);
        return RightRotate(AVL);
    }

    // LR 差值超过 2, 不平衡, 并且 麻烦结点在 左子树上, 先向左旋转, 在向右旋转
    if (balanceFactor >= 2 && GetBalanceFactor(AVL->Left) <= 0)
    {
        printf("LR: 发现者 = %d, 平衡因子 = %d, LeftBalance = %d\n", AVL->Data, balanceFactor, GetBalanceFactor(AVL->Left));
        PrintAvlTree(AVL, 0);

        /**
         * 例如:
         *     5
         *   4   6
         * 2
         *   3
         * 在插入 3 时变为不平衡, 发现者为 4
         * 先将 2, 3 进行 RR 旋转变为:
         *      5
         *    4   6
         *  3
         * 2
         * 再进行 LL 旋转, 变平衡, 变为:
         *      5
         *    3   6
         *  2   4
         */

        printf("-------先进行 LL 旋转---------\n");
        // 先将 左边子树 旋转好
        AVL->Left = LeftRotate(AVL->Left);
        PrintAvlTree(AVL, 0);
        printf("-------先进行 LL 旋转结束----------\n");

        return RightRotate(AVL);
    }

    // RR 差值超过 2, 不平衡, 并且 麻烦结点在 右子树上, 进行向左旋转
    if (balanceFactor <= -2 && GetBalanceFactor(AVL->Right) <= 0)
    {
        printf("RR: 发现者 = %d, 平衡因子 = %d, RightBalance = %d\n", AVL->Data, balanceFactor, GetBalanceFactor(AVL->Right));
        PrintAvlTree(AVL, 0);
        return LeftRotate(AVL);
    }

    // RL 差值超过 2, 不平衡, 并且麻烦结点在 左子树上, 先向右旋转, 在向左旋转
    if (balanceFactor <= -2 && GetBalanceFactor(AVL->Right) > 0)
    {
        printf("RL: 发现者 = %d, 平衡因子 = %d, RightBalance = %d\n", AVL->Data, balanceFactor, GetBalanceFactor(AVL->Right));
        PrintAvlTree(AVL, 0);

        /**
         * 例如:
         *     5
         *   1   6
         *         8
         *       7
         * 在插入 7 时变为不平衡, 发现者为 6
         * 先将 8, 7 进行 LL 旋转变为:
         *     5
         *   1   6
         *         7
         *           8
         * 再进行 RR 旋转, 变平衡, 变为:
         *     5
         *   1   7
         *      6  8
         */

        printf("-------先进行 LL 旋转---------\n");
        // 先将 左边子树 旋转好
        AVL->Right = RightRotate(AVL->Right);
        PrintAvlTree(AVL, 0);
        printf("-------先进行 LL 旋转结束----------\n");
        return LeftRotate(AVL);
    }

    return AVL;
}

/**
 * @brief 向左旋转 发现者
 *
 * @param AVL
 * @return AvlTree
 */
AvlTree LeftRotate(AvlTree AVL)
{
    /**
     * 例如:
     *     5:3
     * 1:1     6:3
     *             8:2
     *                 9:1
     *
     * 插入 9 时, 递归, 回归到 6 的结点时, 左右高度相减时, 平衡因子为 -2
     * 6 是发现者, 9 是麻烦结点, 9 在 发现者右子树的右边
     * 因而叫做 RR 插入, 需要 RR 旋转(右单旋)
     * 需要改变的是发现者的位置:
     *     5:3
     * 1:1      6:2
     *       8:1   9:1
     */

    // 分别: 暂存 发现者结点 7 的右子树 和 其右子树的左子树
    AvlTree avlRight = AVL->Right;
    AvlTree avlRightLeft = avlRight->Left;

    // 把发现者的结点, 放在 右子树的左子树下
    avlRight->Left = AVL;

    // 需要把 右子树的原先的左子树的放在右子树下
    /**
     * 例如:  插入 9 时, 6 为发现者结点
     *     5:3
     * 1:1     6:3
     *            8:2
     *        7:1    9:1
     * --------------------
     *     5:3
     * 1:1     8:2
     *      6:2   9:1
     *         7:1
     * 如果 右子树存在左子节点, 需要将其放在 发现者的右节点上
     */
    AVL->Right = avlRightLeft;

    // 分别更新高度
    AVL->Height = 1 + Max(GetHeight(AVL->Left), GetHeight(AVL->Right));
    avlRight->Height = 1 + Max(GetHeight(avlRight->Left), GetHeight(avlRight->Right));

    // 返回右子树
    return avlRight;
}

/**
 * @brief 向右旋转
 *
 * @param AVL
 * @return AvlTree
 */
AvlTree RightRotate(AvlTree AVL)
{
    /**
     * 例如:
     *          5:3
     *       4:3   6:1
     *    3:2
     * 1:1
     *
     * 插入 1 时, 递归, 回归到 4 的结点时, 左右高度相减时, 平衡因子为 2
     * 4 是发现者, 1 是麻烦结点, 并且 1 在 发现者左子树的左边
     * 因而叫做 LL 插入, 需要 LL 旋转(左单旋)
     * 需要改变的是发现者的位置:
     *          5:3
     *      3:2     6:1
     *   1:1   4:1
     */

    // 获取左子树
    AvlTree avlLeft = AVL->Left;

    // 获取左子树的右子树
    AvlTree avlLeftRight = avlLeft->Right;

    // 将左子树的右子树指向 AVL
    avlLeft->Right = AVL;

    // 将 AVL 的左子树指向左子树的右子树
    AVL->Left = avlLeftRight;

    // 计算高度
    AVL->Height = 1 + Max(GetHeight(AVL->Left), GetHeight(AVL->Right));
    avlLeft->Height = 1 + Max(GetHeight(avlLeft->Left), GetHeight(avlLeft->Right));

    return avlLeft;
}

void PrintAvlTree(AvlTree AVL, int count)
{
    if (AVL)
    {
        PrintAvlTree(AVL->Left, count + 1);

        for (int i = 0; i < count * 9; i++)
        {
            printf(" ");
        }

        printf("|--> %d:%d\n", AVL->Data, AVL->Height);

        PrintAvlTree(AVL->Right, count + 1);
    }
}