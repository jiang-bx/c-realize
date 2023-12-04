#include <stdio.h>
#include <mm_malloc.h>

/**
 * 多项式的乘积与和
 *
 * 输入样例:
 * 一: 3 4 | -5 2 | 6 1 | -2 0 ==> 3x^4 - 5x^2 + 6x - 2
 * 二: 5 20 | -7 4 | 3 1  ==> 5x^20 -7x^4 + 3x
 *
 * 输出样例:
 * 和: 5 20 | -4 4 | -5 2 | 9 1 | -2 0  ==> 5x^20 - 4x^4 - 5x^2 + 9x - 2
 * 乘积: .... 很长 (a + b)(c + d) = ac + ad + bc + bd
 */

/**
 * 指数递降多项式如何表示:
 * 1. 数组, 需要事先确定数组的大小
 * 2. 链表, 动态性比较强
 *
 * 链表的数据结构表示:
 * 系数
 * 指数
 * 指针
 */

// 多项式指针
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    // 系数
    int coeff;
    // 指数
    int exponent;
    // 下一个节点的指针
    Polynomial link;
};

void Attach(int c, int e, Polynomial *pRear);
Polynomial ReadPoly();
Polynomial Add(Polynomial p1, Polynomial p2);
Polynomial Mult(Polynomial p1, Polynomial p2);
void PrintPoly(Polynomial p);

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    Polynomial p1, p2, addRes, multRes;
    p1 = ReadPoly();
    p2 = ReadPoly();

    addRes = Add(p1, p2);
    printf("********相加结果******** \n");
    PrintPoly(addRes);

    multRes = Mult(p1, p2);
    printf("********相乘结果******** \n");
    PrintPoly(multRes);
}

/**
 * @brief 创建多项式新节点
 *
 * @param c 系数
 * @param e 指数
 * @param pRear 指向尾节点指针的指针
 */
void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coeff = c;
    P->exponent = e;
    P->link = NULL;

    // 尾节点的 link 指向新节点
    (*pRear)->link = P;

    // 然后让尾结点也指向新节点
    *pRear = P;
}

/**
 * @brief 读取多项式
 *
 * @return Polynomial
 */
Polynomial ReadPoly()
{
    Polynomial P, Rear, t;
    int c, e, N;

    printf("请输入指数递降多项式共有几项\n");
    scanf("%d", &N);

    // 临时生成一个空的链表头结点
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;

    // Rear 中存储的是一个地址
    Rear = P;

    // 地址     变量名称   存储值
    // x0fff01  Rear     x0ffff04
    // &Rear 获取 Rear 这个变量的地址 x0fff01
    // Rear = x0ffff04, &Rear = x0fff01

    // 在 Attach 中传递 &Rear = x0fff01
    // *pRear 就是访问 x0fff01 中存储值: x0ffff04 所指向的空间

    printf("开始输入每个多项式的系数和指数\n");
    while (N)
    {
        printf("请分别输入第 %d 项的系数和指数, 用空格区分\n", N);
        scanf("%d %d", &c, &e);
        // 将当前项插入多项式尾节点, Rear 永远指向尾节点
        // 因为 Rear 是个指针, 传递时需要将指针传递
        Attach(c, e, &Rear);
        N--;
    }

    // 删除临时生成的头结点
    t = P;

    P = P->link;

    free(t);

    return P;
}

Polynomial Add(Polynomial p1, Polynomial p2)
{

    if (!p1 && !p2)
    {
        return NULL;
    }

    Polynomial t, t1, t2, rear, P;

    t1 = p1;
    t2 = p2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    rear = P;

    while (t1 && t2)
    {
        if (t1->exponent > t2->exponent)
        {
            // t1 在 p 的后面
            Attach(t1->coeff, t1->exponent, &rear);
            t1 = t1->link;
        }
        else if (t1->exponent < t2->exponent)
        {
            // t2 在 p 的后面
            Attach(t2->coeff, t2->exponent, &rear);
            t2 = t2->link;
        }
        else
        {
            // 相同, 系数相加, 并且系数相加不为 0
            if (t1->coeff + t2->coeff)
            {
                Attach(t1->coeff + t2->coeff, t1->exponent, &rear);
            }

            t1 = t1->link;
            t2 = t2->link;
        }
    }

    while (t1)
    {
        // 将 t1 加在后面
        Attach(t1->coeff, t1->exponent, &rear);
        t1 = t1->link;
    }

    while (t2)
    {
        // 将 t2 加在后面
        Attach(t2->coeff, t2->exponent, &rear);
        t2 = t2->link;
    }

    // 将空节点删除
    t = P;

    P = P->link;

    free(t);

    return P;
}

Polynomial Mult(Polynomial p1, Polynomial p2)
{
    if (!p1 && !p2)
    {
        return NULL;
    }

    Polynomial p, t1, t2, op, t;

    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    t1 = p1;

    while (t1)
    {
        t2 = p2;
        while (t2)
        {
            // 系数相乘
            int c = t1->coeff * t2->coeff;

            // 指数相加
            int e = t1->exponent + t2->exponent;

            // 添加
            op = p;
            // 如果存在比当前 指数 e 大的多项式, 就一直循环,
            // 直到找到 op 中 <= e 的项
            while (op->link && op->link->exponent > e)
            {
                op = op->link;
            }

            // 指数相等
            if (op->link && op->link->exponent == e)
            {
                // 系数相加
                if (op->link->coeff + c)
                {
                    op->link->coeff += c;
                }
                else
                {
                    // 系数相加为 0, 释放该空间
                    t = op->link;
                    op->link = t->link;
                    free(t);
                }
            }
            else
            {
                // 指数小于e, 或者大于e, 或者 op->link 不存在
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coeff = c;
                t->exponent = e;
                t->link = op->link;
                op->link = t;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t = p;

    p = p->link;

    free(t);

    return p;
}

void PrintPoly(Polynomial p)
{
    int n = 1;
    Polynomial t = p;
    while (t)
    {
        printf("第 %d 项: \n", n);
        printf("系数 = %d \n", t->coeff);
        printf("指数 = %d \n", t->exponent);
        printf("---------- 第 %d 项结束\n", n);
        t = t->link;
        n++;
    }
}