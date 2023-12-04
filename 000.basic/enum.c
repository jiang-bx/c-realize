#include <stdio.h>

// 外部全局变量
int a;

// 内部全局变量
static int b;

// 声明一个外部全局变量
extern int c;

void test();

int main()
{
    // 定义枚举类型
    enum Gender
    {
        male,
        female,
    };

    // 定义枚举变量
    enum Gender sp;
    printf("sp=%i\n", sp);

    sp = female;
    printf("sp=%i\n", sp);

    return 0;
}

void test()
{
    static int ff = 1;
}