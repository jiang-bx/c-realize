#include <stdio.h>
#include <mm_malloc.h>

typedef struct LinkNode *Link;
struct LinkNode
{
    int value;
    Link next;
};

Link reversalLinkList(Link head);
Link createLinkNode(int value);
Link createLinkList(int len);
Link reverseKGroup(Link head, int k);
void printLinkList(Link head);
void test();

int main()
{
    test();
    return 0;
}

void test()
{
    // Link head = createLinkList(4);
    // printLinkList(head);

    // printf("--------- 反转链表\n");
    // Link reHead = reversalLinkList(head);
    // printLinkList(reHead);

    Link head1 = createLinkList(5);
    printLinkList(head1);

    printf("---------2 个一组 反转链表\n");
    Link reHead1 = reverseKGroup(head1, 2);
    printLinkList(reHead1);
}

/**
 * @brief Create a Link Node object
 *
 * @param value
 * @return Link
 */
Link createLinkNode(int value)
{
    Link l = (Link)malloc(sizeof(struct LinkNode));
    l->value = value;
    return l;
}

/**
 * @brief Create a Link List object
 *
 * @param len
 * @return Link
 */
Link createLinkList(int len)
{
    int i = 1;
    Link l;
    Link head = createLinkNode(i);

    l = head;

    for (; i < len; i++)
    {
        l->next = createLinkNode(i + 1);
        l = l->next;
    }

    return head;
}

/**
 * @brief 翻转单链表
 *
 * @param head
 * @return Link
 */
Link reversalLinkList(Link head)
{
    if (!head)
    {
        printf("链表为空!!!\n");
        return NULL;
    }

    Link new, old, temp;

    new = head;

    old = new->next;

    new->next = NULL;

    while (old)
    {
        // 临时存放
        temp = old->next;
        // 将旧节点指向前一个节点
        old->next = new;

        // 新节点往后移动
        new = old;

        // 旧节点继续往后移动
        old = temp;
    }

    return new;
}

/**
 * @brief k 个一组翻转单链表
 *
 * @param head
 * @param k 是一个正整数，它的值小于或等于链表的长度
 * @return Link
 */
Link reverseKGroup(Link head, int k)
{
    if (!head)
    {
        printf("链表为空!!!\n");
        return NULL;
    }

    Link pre, end, dummy;

    dummy = createLinkNode(0);
    dummy->next = head;

    pre = dummy;
    end = dummy;

    while (end->next)
    {
        for (int i = 0; i < k && end; i++)
        {
            end = end->next;
        }

        if (!end)
        {
            break;
        }

        Link start = pre->next;
        Link next = end->next;

        end->next = NULL;

        pre->next = reversalLinkList(start);

        start->next = next;
        pre = start;

        end = pre;
    }

    return dummy->next;
}

/**
 * @brief 打印链表
 *
 * @param head
 */
void printLinkList(Link head)
{
    printf("*******开始打印链表: \n");

    if (!head)
    {
        printf("链表为空!!!\n");
    }

    Link l = head;

    while (l)
    {
        printf("链表值为: %d\n", l->value);
        l = l->next;
    }

    printf("*******结束打印链表\n");
}
