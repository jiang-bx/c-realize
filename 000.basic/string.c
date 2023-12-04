#include <stdio.h>
#include <string.h>

void stringBasic();

int main()
{
    stringBasic();
    return 0;
}

void stringBasic()
{
    // 定义字符串, 默认会有一个 \0 结束符, 占一个字节
    char str1[] = "abc";
    printf("str1 size = %lu\n", sizeof(str1));  // 4
    printf("str1 = %s\n", str1);

    size_t length = strlen(str1);
    printf("length = %lu\n", length);

    char str2[10] = "abc";
    char str3[] = " def";
    strcat(str2, str3);
    puts(str2);
    printf("str2 = %s\n", str2);
}