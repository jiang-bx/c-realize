#include <stdio.h>
#include <mm_malloc.h>

typedef int ElementType;

typedef struct GNode *GList;

struct GNode
{
    int Tag;

    // union 共用体, 即 data 和 subList 共用存储空间
    union
    {
        ElementType Data;
        GList SubList;
    } URegion;

    GList Next;
};

int main()
{
    return 0;
}