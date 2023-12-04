#include <stdio.h>

void defineStruct();
void initStruct();

int main()
{
    // void defineStruct();
    // void initStruct();

    // 也可以直接在定义结构体时,直接定义变量, 直接赋值
    // struct Person
    // {
    //     int age;       // 4
    //     double height; // 8
    //     char c;        // 1
    // } sp = {1, 2.22, 'c'};
    // // sp.age = 22;

    // printf("p = %i\n", sp.age);

    // // 省略结构体名称
    // struct
    // {
    //     int a;
    // } a = {1};

    // struct Person *sip;

    // // *sip === sp;

    // sip = &sp;

    // // .运算符优先级比 *运算符高
    // (*sip).age = 2;

    // printf("p = %i\n", (*sip).age);

    // sip->age = 3;

    // printf("p = %i\n", sp.age);

    // struct Person
    // {
    //     char name;
    //     int age;
    // };

    // struct Person ps[3] =
    // {
    //     {'a', 1},
    //     {'b', 2},
    //     {'c', 3},
    // };

    // ps[0].age = 11;

    // struct Date
    // {
    //     int year;
    //     int month;
    //     int day;
    // };

    // struct Person
    // {
    //     int age;
    //     struct Date birth;
    // };

    // struct Person sp =
    //     {
    //         12,
    //         {
    //             2022,
    //             3,
    //             4,
    //         },
    //     };

    // printf("sp = %i\n", sp.birth.day);

    

    return 0;
}

// 貌似不能用
void initStruct()
{
    // 与数组类似
    struct Dog
    {
        char *name;
        int age;
        double height;
    };

    // 1. 定义同时初始化
    struct Dog sd = {"ww", 1, 1.11};

    // 2. 先定义在逐个初始化
    struct Dog sd1;
    sd1.name = "ww1";
    sd1.age = 2;
    sd1.height = 2.22;

    // 3. 先定义在一次性初始化
    struct Dog sd2;
    // 强制类型转换, 注意数组不能这样操作, 要么定义时直接赋值, 要么定义后挨个赋值
    sd2 = (struct Dog){"ww2", 3, 3.33};

    // 4. 将数据赋值给指定属性
    struct Dog sd3 = {.name = "ww3", .age = 4, .height = 4.44};
}

void defineStruct()
{
    // 基本数据类型: int double float char
    // 构造类型: array, struct

    struct Person
    {
        char *name;
        int age;
        double height;
    };

    struct Person p1;

    p1.name = "aaa";
    p1.age = 18;
    p1.height = 1.75;

    printf("sss\n");
}