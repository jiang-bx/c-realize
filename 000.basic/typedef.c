#include <stdio.h>

// 为默认的数据类型起新的别名
typedef int Integer;

// 可以给已有的类型起别名
typedef Integer MyInt;

// 结构体
// struct Person
// {
//     int age;
//     char *name;
// };
// 第一种方式: 为结构体起别名
// typedef struct Person Per;

// 第二种方式: 为结构体起别名
// typedef struct Person
// {
//     int age;
//     char *name;
// } Per;

// 第三种方式: 为结构体起别名
typedef struct
{
    int age;
    char *name;
} Per;

// 为枚举类型起别名
enum Gender
{
    kEnumGenderMale,
    kEnumGenderFemale,
};
enum Gender sex = kEnumGenderFemale;

typedef enum Gender Sex;
Sex sex1 = kEnumGenderMale;

typedef enum Gender2
{
    kEnumGender2Male,
    kEnumGender2Female,
} Sex2;

Sex2 sex2 = kEnumGender2Female;

typedef enum
{
    kEnumGender3Male,
    kEnumGender3Female,
} Sex3;

Sex3 sex3 = kEnumGender3Female;

int sum(int v1, int v2);

void testConst();

int main()
{

    typedef char Ch;

    Integer num = 1;

    Ch c = 'a';

    MyInt num1 = 2;

    printf("num = %i\n", num);
    printf("num1 = %i\n", num1);
    printf("c = %c\n", c);

    // 结构体
    Per sp = {11, "aaa"};

    // 为指针类型起别名
    char *name = "lng";
    typedef char *String;
    String name1 = "xxx";
    printf("name1 = %s\n", name1);

    // 为指向函数的指针起别名
    int (*sumP)(int, int);
    sumP = sum;
    printf("sump = %i\n", sumP(11, 2));

    // 如果给函数指针起别名, 那么指向函数指针的指针名称就是他的别名
    typedef int (*functionPointer)(int, int);
    functionPointer sumP1 = sum;
    printf("sump1 = %i\n", sumP1(22, 1));

    testConst();

    return 0;
}

int sum(int v1, int v2)
{
    return v1 + v2;
}

void testConst()
{
    // const 关键字 类型修饰符,
    // const int num1 = 10;
    int const num1 = 10;
    // 不能修改
    // num1 = 11;

    const char *name = "lng";
    name = "kk";

    int num = 10;

    int num2 = 11;
    const int *p2 = &num2;
    // 不能修改指针指向内存空间的值
    // *p2 = 333;
    // 可以修改指针指向
    p2 = &num;

    int num3 = 33;
    int const *p3 = &num3;
    // 不能修改指针指向内存空间的值
    // *p3 = 3333;
    // 可以修改指针指向
    p3 = &num;

    int num4 = 44;
    int * const p4 = &num4;
    // 可以修改指针指向的内存空间值
    *p4 = 444;
    // 不可以修改指针
    // p4 = &num;

}