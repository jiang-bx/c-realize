#include <stdio.h>
#include <mm_malloc.h>

// 定义类型
#define ElementType int

typedef struct TreeNode *BinTree;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

// define 后面不能跟分号
#define Position BinTree

BinTree GetBinTree();
BinTree CreateBinTree(ElementType X);
Position Find(ElementType X, BinTree BST);
Position IterFind(ElementType X, BinTree BST);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
BinTree Insert(ElementType X, BinTree BST);
BinTree Delete(ElementType X, BinTree BST);
void PrintBinTree(BinTree BST);

int main()
{
    BinTree BST = GetBinTree();

    printf("--------开始查看 BST\n");
    PrintBinTree(BST);

    printf("------- 递归查找 5 号元素的地址\n");
    Position p1 = Find(5, BST);
    printf("p1 = %p, data = %d, left = %p, right = %p\n", p1, p1->Data, p1->Left, p1->Right);

    printf("------- 迭代查找 9 号元素的地址\n");
    Position p2 = IterFind(9, BST);
    printf("p2 = %p, data = %d, left = %p, right = %p\n", p2, p2->Data, p2->Left, p2->Right);

    printf("------- 找到最小值\n");
    Position p3 = FindMin(BST);
    printf("p3 = %p, data = %d\n", p3, p3->Data);

    printf("------- 找到最大值\n");
    Position p4 = FindMax(BST);
    printf("p4 = %p, data = %d\n", p4, p4->Data);

    printf("------- 插入 11 \n");
    BinTree p5 = Insert(11, BST);
    printf("p5 = %p, data = %d, left = %p, \n", p5, p5->Data, p5->Left);
    PrintBinTree(BST);

    printf("------- 删除 11 \n");
    BinTree p6 = Delete(11, BST);
    printf("p6 = %p, data = %d, \n", p6, p6->Data);
    PrintBinTree(BST);

    return 0;
}

BinTree GetBinTree()
{
    /**
     *           6
     *       4      8
     *     2   5   7  9
     *   1  3          10
     */
    BinTree T = CreateBinTree(6);
    T->Left = CreateBinTree(4);

    T->Left->Left = CreateBinTree(2);
    T->Left->Right = CreateBinTree(5);
    T->Left->Left->Left = CreateBinTree(1);
    T->Left->Left->Right = CreateBinTree(3);

    T->Right = CreateBinTree(8);

    T->Right->Left = CreateBinTree(7);
    T->Right->Right = CreateBinTree(9);
    T->Right->Right->Right = CreateBinTree(10);

    return T;
}

/**
 * @brief Create a Bin Tree object
 *
 * @param X
 * @return BinTree
 */
BinTree CreateBinTree(ElementType X)
{
    BinTree T = (BinTree)malloc(sizeof(struct TreeNode));
    T->Data = X;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

/**
 * @brief 查找元素 X
 *
 * @param X
 * @param BST
 * @return Position
 */
Position Find(ElementType X, BinTree BST)
{
    if (!BST)
    {
        printf("二叉树为空!!!\n");
        return NULL;
    }
    if (X > BST->Data)
    {
        // 向右查找
        return Find(X, BST->Right);
    }
    else if (X < BST->Data)
    {
        // 向左查找
        return Find(X, BST->Left);
    }
    else
    {
        return BST;
    }
}

/**
 * @brief 由于非递归函数的执行效率高, 可将 尾递归, 改为迭代函数
 *
 * @param X
 * @param BST
 * @return Position
 */
Position IterFind(ElementType X, BinTree BST)
{
    BinTree T = BST;
    while (T)
    {
        if (X > T->Data)
        {
            T = T->Right;
        }
        else if (X < T->Data)
        {
            T = T->Left;
        }
        else
        {
            return T;
        }
    }

    return NULL;
}

/**
 * @brief 查找二叉树的最小值, 递归实现
 *
 * @param BST
 * @return Position
 */
Position FindMin(BinTree BST)
{
    if (!BST)
    {
        return NULL;
    }
    else if (!BST->Left)
    {
        return BST;
    }
    else
    {
        return FindMin(BST->Left);
    }
}

/**
 * @brief 查找二叉树的最大值, 迭代实现
 *
 * @param BST
 * @return Position
 */
Position FindMax(BinTree BST)
{
    if (BST)
    {
        while (BST->Right)
        {
            BST = BST->Right;
        }
    }
    return BST;
}

/**
 * @brief 打印二叉搜索树
 *
 * @param BST
 */
void PrintBinTree(BinTree BST)
{
    // 采用中序遍历
    if (BST->Left)
    {
        PrintBinTree(BST->Left);
    }

    if (BST)
    {
        printf("Data = %d\n", BST->Data);
    }

    if (BST->Right)
    {
        PrintBinTree(BST->Right);
    }
}

/**
 * @brief 向二叉树插入 X
 *
 * @param X
 * @param BST
 * @return BinTree
 */
BinTree Insert(ElementType X, BinTree BST)
{
    BinTree T = BST;

    if (!T)
    {
        T = CreateBinTree(X);
    }
    else
    {
        if (X < T->Data)
        {
            T->Left = Insert(X, T->Left);
        }
        else if (X > T->Data)
        {
            T->Right = Insert(X, T->Right);
        }
    }

    return T;
}

/**
 * @brief 二叉搜索树 删除指定元素
 *
 * 1. 叶结点: 直接删除, 修改其父节点指针 -> null
 * 2. 结点只有一个子结点: 将其父节点的指针指向要删除节点的子节点
 * 3. 结点有左右子节点: 用另一结点代替被删除的结点: 右子树的最小元素或者左子树的最大元素
 *     原理: 右子树的最小值肯定没有两个子节点, 左子树的最大值肯定没有两个子节点
 * @param X
 * @param BST
 * @return BinTree
 */
BinTree Delete(ElementType X, BinTree BST)
{
    BinTree Temp;
    if (!BST)
    {
        printf("要删除的元素未找到!!!\n");
    }
    else if (X < BST->Data)
    {
        BST->Left = Delete(X, BST->Left);
    }
    else if (X > BST->Data)
    {
        BST->Right = Delete(X, BST->Right);
    }
    else
    {
        // 找到该节点
        if (BST->Left && BST->Right)
        {
            // 存在两个节点

            // 找到右子树的最小节点, 也可以找到左子树的最大节点
            Temp = FindMin(BST->Right);

            // 用找到的结点填充被删除的结点
            BST->Data = Temp->Data;

            // 从 原有的子树中删除,找到的结点,
            // 因为右子树的最小值, 或者左子树的最大值都是靠近树的中心点,
            // 并且可以保证都是叶结点, 不存在两个子节点的情况
            BST->Right = Delete(BST->Data, BST->Right);
        }
        else
        {
            // 如果是无子节点情况
            // 这里返回的 BST 为 NULL, 上一层的结点 left 或者 right 指向 null
            // 如果存在单个子节点
            // 就将单个子节点返回, 让上一层节点的 left 或者 right 直接指向当前节点的子节点

            // 存在一个结点或者无节点
            Temp = BST;

            if (!BST->Left)
            {
                // 有右子节点, 或者无子节点
                BST = BST->Right;
            }
            else if (!BST->Right)
            {
                // 有左子节点, 或者无子节点
                BST = BST->Left;
            }

            // 释放空间
            free(Temp);
        }
    }

    return BST;
}