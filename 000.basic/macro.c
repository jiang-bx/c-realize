#include <stdio.h>

#include "macro1.h"

void test1();
void test2();

// 不带参数的宏定义
#define COUNT 5

int main()
{
    // 使用宏定义
    int nums[COUNT] = {1, 2, 3, 4, 6};

    printf("nums[4] = %i\n", nums[4]);

    printf("COUNT = %i\n", COUNT);

// 结束宏定义
#undef COUNT

    // 报错
    // printf("COUNT = %i\n", COUNT);

    // test1();
    // test2();
    func1();

    return 0;
}

#define SUM(v1, v2) v1 + v2

void test1()
{
    int a = 10;
    int b = 4;

    int res = SUM(a, b);

    printf("res = %i\n", res);

#undef SUM

    // 报错
    // SUM(a, b);
}

#define A 100
#define B 90
#define DEBUG1

void test2()
{

// #if 应用
#if A == 100
    printf("A\n");
#elif B == 90
    printf("B\n");
#else
    printf("no\n");
#endif

// #ifdef 应用
#ifdef DEBUG1
    printf("已定义 DEBUG1 宏\n");
#else
    printf("未定义 DEBUG1 宏\n");
#endif

// #ifndef 应用
#ifndef DEBUG2
    printf("未定义 DEBUG2 宏\n");
#else
    printf("已定义 DEBUG1 宏\n");
#endif
}