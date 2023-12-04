#include <stdio.h>
#include <mm_malloc.h>

/**
 * 二叉树的同构:
 * 给定两棵树 T1 和 T2,
 * 如果 T1 可以通过若干次左右子节点互换变成 T2
 * 则两棵树是 同构 的
 */

/**
 * 输入格式: 输入给出两棵二叉树的信息
 * 先在一行中该树的节点数
 * 第 i 行对应的编号第 i 个结点,包含左右子节点的位置信息
 * 如果子节点为空用 - 来表示
 * 第一个不定是输入的根结点
 *
 * 输入样例1:
 * 总数: 8
 * index value left right
 * 0 | A 1 2
 * 1 | B 3 4
 * 2 | C 5 -
 * 3 | D - -
 * 4 | E 6 -
 * 5 | G 7 -
 * 6 | F - -
 * 7 | H - -
 *
 * 输入样例2:
 * 总数: 8
 * index value left right
 * 0 | G - 4
 * 1 | B 7 6
 * 2 | F - -
 * 3 | A 5 1
 * 4 | H - -
 * 5 | C 0 -
 * 6 | D - -
 * 7 | E 2 -
 */

// 用结构数组表示二叉树: 静态链表
#define MaxTree 8
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};

Tree BuildTree(struct TreeNode T[]);
void PrintTree(struct TreeNode T[], int length);
Tree GetTreeRoot(struct TreeNode T[], int length);
Tree CreateTreeT1();
Tree CreateTreeT2();
int Isomorphic(Tree R1, Tree R2);

// 定义数组
struct TreeNode T1[MaxTree];
struct TreeNode T2[MaxTree];

int main()
{
    Tree R1, R2;

    // printf("----------- 开始构建T1\n");
    // R1 = BuildTree(T1);
    R1 = CreateTreeT1();
    printf("--------展示 T1, R1 = %d\n", R1);
    int length = sizeof(T1) / sizeof(T1[0]);
    PrintTree(T1, length);

    // printf("----------- 开始构建T2\n");
    // R2 = BuildTree(T2);
    R2 = CreateTreeT2();
    printf("--------展示 T2, R2 = %d\n", R2);
    int length2 = sizeof(T2) / sizeof(T2[0]);
    PrintTree(T2, length2);

    int isIsomorphism = Isomorphic(R1, R2);
    printf("T1 与 T2 是否同构结果: %d \n", isIsomorphism);

    return 0;
}

Tree GetTreeRoot(struct TreeNode T[], int length)
{
    int i;
    int check[length];

    for (i = 0; i < length; i++)
    {
        check[i] = 0;
    }

    for (i = 0; i < length; i++)
    {
        if (T[i].Left > -1)
        {
            check[T[i].Left] = 1;
        }

        if (T[i].Right > -1)
        {
            check[T[i].Right] = 1;
        }
    }

    for (i = 0; i < length; i++)
    {
        if (!check[i])
        {
            printf("--------已找到根节点编号: \n");
            printf("i = %d\n", i);
            break;
        }
    }

    return i;
}

Tree CreateTreeT1()
{
    T1[0].Element = 'A';
    T1[0].Left = 1;
    T1[0].Right = 2;

    T1[1].Element = 'B';
    T1[1].Left = 3;
    T1[1].Right = 4;

    T1[2].Element = 'C';
    T1[2].Left = 5;
    T1[2].Right = -1;

    T1[3].Element = 'D';
    T1[3].Left = -1;
    T1[3].Right = -1;

    T1[4].Element = 'E';
    T1[4].Left = 6;
    T1[4].Right = -1;

    T1[5].Element = 'G';
    T1[5].Left = 7;
    T1[5].Right = -1;

    T1[6].Element = 'F';
    T1[6].Left = -1;
    T1[6].Right = -1;

    T1[7].Element = 'H';
    T1[7].Left = -1;
    T1[7].Right = -1;

    int length = sizeof(T1) / sizeof(T1[0]);
    int root = GetTreeRoot(T1, length);

    return root;
}

Tree CreateTreeT2()
{
    T2[0].Element = 'G';
    T2[0].Left = -1;
    T2[0].Right = 4;

    T2[1].Element = 'B';
    T2[1].Left = 7;
    T2[1].Right = 6;

    T2[2].Element = 'F';
    T2[2].Left = -1;
    T2[2].Right = -1;

    T2[3].Element = 'A';
    T2[3].Left = 5;
    T2[3].Right = 1;

    T2[4].Element = 'H';
    T2[4].Left = -1;
    T2[4].Right = -1;

    T2[5].Element = 'C';
    T2[5].Left = 0;
    T2[5].Right = -1;

    T2[6].Element = 'D';
    T2[6].Left = -1;
    T2[6].Right = -1;

    T2[7].Element = 'E';
    T2[7].Left = 2;
    T2[7].Right = -1;

    int length = sizeof(T2) / sizeof(T2[0]);
    int root = GetTreeRoot(T2, length);

    return root;
}

Tree BuildTree(struct TreeNode T[])
{
    Tree Root = 0;
    int N, i;
    char E, cl, cr;

    printf("请输入节点总数\n");

    scanf("%d", &N);

    if (N)
    {
        // 记录被占用的行号
        int check[N];
        for (i = 0; i < N; i++)
        {
            check[i] = 0;
        }

        for (i = 0; i < N; i++)
        {
            printf("请输入第 %d 元素, 左子节点位置, 右子节点位置, 用空格分开, 没有子节点时 用 - 代替\n", i);
            scanf(" %c %c %c", &E, &cl, &cr);

            T[i].Element = E;

            printf("E = %c\n", E);

            if (cl != '-')
            {
                T[i].Left = cl - '0';

                // 表示已被占用
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = Null;
            }

            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = Null;
            }
        }

        // 从 check 记录中找到 根结点的位置
        for (i = 0; i < N; i++)
        {
            if (!check[i])
            {
                break;
            }
        }

        Root = i;
    }

    return Root;
}

void PrintTree(struct TreeNode T[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("编号 = %d, value = %c, 左子节点 = %d, 右子节点 = %d\n", i, T[i].Element, T[i].Left, T[i].Right);
    }
}

/**
 * @brief 判断两棵树是否同构
 *
 * @param R1
 * @param R2
 * @return int
 */
int Isomorphic(Tree R1, Tree R2)
{
    // 根节点同时不存在
    if (R1 <= -1 && R2 <= -1)
    {
        return 1;
    }

    // 节点不一样
    if ((R1 <= -1 && R2 > -1) || (R1 > -1 && R2 <= -1))
    {
        return 0;
    }

    // 根节点名称不一样
    if (T1[R1].Element != T2[R2].Element)
    {
        return 0;
    }

    // 左子树同时为空
    if (T1[R1].Left <= -1 && T2[R2].Left <= -1)
    {
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }

    // 左子树侧同时不空, 并且值相等
    if (T1[R1].Left > -1 && T2[R2].Left > -1 && T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)
    {
        return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);
    }
    else
    {
        return Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left);
    }

    return 1;
}