#include <stdio.h>
#include <mm_malloc.h>

typedef struct LNode *List;
struct LNode
{
    int Value;
    List Next;
};

void BucketSort(int Arr[], int Len)
{

    if (Len <= 0)
    {
        printf("数组为空\n");
        return;
    }

    // 先找到数组中的最大值, 和最小值
    int max = Arr[0], min = Arr[0], i = 0;

    for (; i < Len; i++)
    {
        if (Arr[i] > max)
        {
            max = Arr[i];
        }

        if (Arr[i] < min)
        {
            min = Arr[i];
        }
    }

    // 桶的间距
    int Gap = (max - min) / Len + 1;

    // 桶的个数
    int bucketNum = (max - min) / Gap + 1;

    // 创建临时数组
    List *BucketArr;
    BucketArr = malloc(bucketNum * sizeof(struct LNode));

    // 将数组放入对应的桶中
    for (i = 0; i < Len; i++)
    {
        int bucketIndex = (Arr[i] - min) / Gap;

        List head, newNode;

        newNode = (List)malloc(sizeof(struct LNode));
        newNode->Value = Arr[i];
        newNode->Next = NULL;

        if (BucketArr[bucketIndex] == NULL)
        {
            head = (List)malloc(sizeof(struct LNode));
            head->Value = -1;
            head->Next = newNode;
            BucketArr[bucketIndex] = head;
        }
        else
        {

            // 这里链表需要做个排序
            head = BucketArr[bucketIndex];
            List prev = head->Next;
            List next = prev->Next;

            // 头结点插入
            if (prev->Value > Arr[i])
            {
                head->Next = newNode;
                newNode->Next = prev;
            }
            else
            {
                // 找到插入节点
                while (prev && next)
                {
                    if (prev->Value < Arr[i] && next->Value > Arr[i])
                    {
                        break;
                    }
                    prev = prev->Next;
                    next = prev->Next;
                }

                // 中间节点插入 或者 尾结点插入
                prev->Next = newNode;
                newNode->Next = next;
            }
        }
    }

    int k = 0;

    List de;

    // 遍历桶数组
    for (i = 0; i < bucketNum; i++)
    {
        printf("%d: ", i);
        // 将原数组替换
        List current = BucketArr[i];
        while (current)
        {
            printf("%d->", current->Value);

            if (current->Value > -1)
            {
                Arr[k++] = current->Value;
            }

            de = current;

            current = current->Next;

            free(de);
        }
        printf("\n");
    }

    free(BucketArr);
}

int main()
{
    int len = 30;
    int arr[30] = {754, 185, 446, 379, 514, 24, 638, 646, 749, 90, 560, 953, 523, 378, 909, 410, 620, 671, 54, 885, 429, 692, 448, 859, 711, 115, 342, 556, 208, 634};

    BucketSort(arr, len);

    printf("排序结果: \n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
