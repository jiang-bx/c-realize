#include <stdio.h>
#include <time.h>

clock_t start, stop;
double duration;

void printTest();
void printN1(int num);
void printN2(int num);

int main()
{
    printTest();
    return 0;
}

void printTest()
{
    int num;
    printf("请输入正整数, 会顺序打印所有\n");
    scanf("%d", &num);

    // clock 返回 cpu 时间, 并不是秒数, 1000, CLOCKS_PER_SEC 或者 CLK_TIK 包含一秒钟包含多少个 cpu 时间钟
    start = clock();
    printN1(num);

    // printN2(num);

    stop = clock();

    // * 1000 表示毫秒
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC * 1000;

    printf("耗时%lf毫秒\n", duration);
}

void printN1(int num)
{
    int i = 1;
    for (; i <= num; i++)
    {
        printf("i = %i\n", i);
    }
}

  void printN2(int num)
{
    // 递归
    if (num > 0)
    {
        printN2(num - 1);
        printf("%d\n", num);
    }
}