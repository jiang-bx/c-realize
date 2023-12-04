#include <stdio.h>
#include <string.h>

void basicPointer();
void practicePointer();
void swapHandle();
void pointer1();
void multistagePointer();
void arrayPointer();
void stringPointer();
void strLength();
int myStrlen2(char *str);
int myStrlen3(char *str);
void funcPointer();
void testFuncP1();
int sum1(int v1, int v2);

int main()
{
    // basicPointer();
    // practicePointer();
    // pointer1();
    // multistagePointer();
    // arrayPointer();
    // stringPointer();
    // strLength();
    funcPointer();
    return 0;
}

int demo(int v1, int v2, int (*p) (int, int)) {
    return p(v1, v2);
}

void funcPointer() {
    // 第一种方式
    // 定义
    void (*funcP1) ();
    // 赋值
    funcP1 = testFuncP1;
    // 执行
    (*funcP1)();
    // 或者
    funcP1();

    // 多个参数
    int (*sumP1) (int, int);
    sumP1 = sum1;
    int a = sumP1(11, 22);
    printf("a = %i\n", a);

    // 第二种方式
}

int sum1(int v1, int v2) {
    return v1 + v2;
}

void testFuncP1() {
    printf("testFuncP1 被执行\n");
}

void strLength() {
    char *name = "lng";

    size_t size1 = strlen(name);
    printf("size1 = %lu\n", size1);

    int size2 = myStrlen2(name);
    printf("size2 = %i\n", size2);

    int size3 = myStrlen3(name);
    printf("size3 = %i\n", size3);
}

int myStrlen3(char *str) {
    int count = 0; 
    while (*str++) {
        count++;
    }
    return count;
}

int myStrlen2(char *str) {
    int count = 0;

    while(str[count] != '\0') {
        count++;
    }

    return count;
}

void stringPointer() {
    // 数组字符串
    char str1[] = "abc";
    printf("str1 = %s\n", str1);
    str1[0] = 'g';
    printf("str1 = %s\n", str1);

    // 指针字符串
    char *str2 = "def";
    printf("str2 = %s\n", str2);
    // str2[0] = 'h';
    // printf("str2 = %s\n", str2);

    // 相同的值对应的地址相同
    char *str3 = "def";
    printf("str2p = %p\n", str2);
    printf("str3p = %p\n", str3);
}

void arrayPointer()
{
    int ages[3] = {1, 2, 3};

    int *p = ages;
    int *p1 = &ages[0];

    printf("ages = %p\n", ages);
    printf("p = %p\n", p);
    printf("p1 = %p\n", p1);
}

void multistagePointer()
{
    char c = 'a';
    char *cp = &c;

    // cpp 就是二级指针
    char **cpp = &cp;

    // cppp 就是三级指针
    char ***cppp = &cpp;

    // *cp == c
    // *cpp == cp
    // **cpp == *(*cpp) == *cp == c
}

void pointer1()
{
    int num = 10;
    int *p = &num;

    // 注意: p 就是指针变量, *p 表示访问指针变量指向的存储空间
    int *p1 = p;

    // 多个指针变量可以指向同一块存储空间
    int *p2 = &num;

    int a = 88;

    printf("p1 = %p\n", p1);
    // 指针变量可以修改
    p1 = &a;
    printf("p1 = %p\n", p1);
}

void practicePointer()
{
    int a = 10;
    int b = 5;

    printf("交换前: a = %i, b = %i\n", a, b);
    swapHandle(&a, &b);
    printf("交换后: a = %i, b = %i\n", a, b);
}

void swapHandle(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void basicPointer()
{
    // 指针变量存储的是指向变量的地址, 在 64 位编译器下占 8 个字节
    // 但是指针变量也有自己的地址
    int num = 10;
    int *p = &num;

    printf("num = %p\n", &num);
    printf("p = %p\n", p);

    // *指针变量表示, 将访问指针变量所指向的那一块存储空间
    *p = 55;
    printf("num = %i\n", num);
}