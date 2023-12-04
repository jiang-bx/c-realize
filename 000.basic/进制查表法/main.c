#include <stdio.h>

void printAdvance();
void getAdvanceBinary1(int value);
void getAdvanceBinary2(int value);
void getAdvanceOtc1(int value);
void getAdvanceHex1(int value);
void getAdvanceHex2(int value);
void getAdvanceOtc2(int value);
void getAdvanceBinary3(int value);
void getAdvanceTotal(int value, int base, int offset);
void getAdvanceHex3(int value);
void getAdvanceOtc3(int value);
void getAdvanceBinary4(int value);

int main()
{
    printAdvance();
    return 0;
}

void printAdvance()
{
    // getAdvanceBinary1(10);
    // getAdvanceBinary2(10);
    // getAdvanceOtc1(10);
    // getAdvanceHex1(10);
    // getAdvanceHex2(27);
    // getAdvanceOtc2(10);
    // getAdvanceBinary3(10);
    // getAdvanceHex3(10);
    // getAdvanceOtc3(10);
    getAdvanceBinary4(10);
}

void getAdvanceHex3(int value)
{
    getAdvanceTotal(value, 15, 4);
}
void getAdvanceOtc3(int value)
{
    getAdvanceTotal(value, 7, 3);
}
void getAdvanceBinary4(int value)
{
    getAdvanceTotal(value, 1, 1);
}

/**
 * @brief Get the Advance Total object
 * 获取数值的指定进制数据
 * @param value 
 * @param base 
 * @param offset 
 */
void getAdvanceTotal(int value, int base, int offset)
{
    char charValues[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char results[32] = {};
     int pos = 32;
    while (value != 0)
    {
        int res = value & base;
        results[--pos] = charValues[res];
        value = value >> offset;
    }
    for (int i = pos; i < 32; i++)
    {
        printf("%c", results[i]);
    }
    printf("\n");
}

/**
 * @brief Get the Advance Binary3 object
 * 获取数值 2 进制
 * @param value 
 */
void getAdvanceBinary3(int value)
{
    char charValues[] = {'0', '1'};
    char results[] = {};
    int pos = 32;
    while (value != 0)
    {
        int res = value & 1;
        results[--pos] = charValues[res];
        value = value >> 1;
    }
    for (int i = pos; i < 32; i++)
    {
        printf("%c", results[i]);
    }
    printf("\n");
}

/**
 * @brief Get the Advance Otc2 object
 * 获取数值的 8 进制
 * @param value 
 */
void getAdvanceOtc2(int value)
{
    char charValues[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    char results[] = {};
    int pos = 11;
    while (value != 0)
    {
        int res = value & 7;
        results[--pos] = charValues[res];
        value = value >> 3;
    }
    // 打印处理好的数据
    for (int i = pos; i < 11; i++)
    {
        printf("%c", results[i]);
    }
    printf("\n");
}

/**
 * @brief Get the Advance Hex2 object
 * 获取数值的 16 进制
 * @param value 
 */
void getAdvanceHex2(int value)
{
    // 定义好十六进制所有的单位数
    char charValues[] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'a',
        'b',
        'c',
        'd',
        'e',
        'f'};

    // 保存结果
    char results[8] = {};
    int pos = 8;

    // 为 0 就不用再处理了
    while (value != 0)
    {
        // 从低位开始取
        int res = value & 15;
        // 将结果存贮, 由于是倒序, 需要将结果存储在最后
        results[--pos] = charValues[res];
        // 向右移动 4 位开始
        value = value >> 4;
    }

    // 打印处理好的数据
    for (int i = pos; i < 8; i++)
    {
        printf("%c", results[i]);
    }

    printf("\n");
}

/**
 * @brief Get the Advance Hex1 object
 * 获取数值的十六进制
 * @param value 
 */
void getAdvanceHex1(int value)
{
    /**
     * 十六进制处理: 与八进制类似
     * 0000 0000 0000 0000 0000 0000 0000 1010   // 10
     * 0000 0000 0000 0000 0000 0000 0000 1111   // 15
     * 
     * 原理: 十六进制最大单数: f(15), 用二进制表示就是 1111
     * 那么就将 二进制分为 32 / 4 = 8 份
     * 一次按位与 4 位, 得到一位十六进制数字
     * 得到是倒序数字
     */

    for (int i = 0; i < 8; i++)
    {
        // 从低位开始
        int res = value & 15;
        // 十六进制有 a, b, c, d, e, f 特殊处理
        if (res > 9)
        {
            char c = res - 10 + 'a';
            printf("%c", c);
        }
        else
        {
            printf("%i", res);
        }
        // 向右移动 4 位
        value = value >> 4;
    }
    printf("\n");
}

/**
 * @brief Get the Advance Otc1 object
 * 获取数值的八进制
 * @param value 
 */
void getAdvanceOtc1(int value)
{
    /**
     * 八进制数据处理:
     * 00 000 000 000 000 000 000 000 000 001 010 // 10
     * 00 000 000 000 000 000 000 000 000 000 111 // 7
     * 原理: 八进制最大的单数是 7, 用二进制表示是 111
     * 将二进制分为 11 份, 一次按位与 3 位, 就得到一位八进制数字
     * 得到是倒序数字: 21000000000 实际就是 012
     */

    for (int i = 0; i < 11; i++)
    {
        // 从低位开始
        int res = value & 7;
        printf("%i", res);
        value = value >> 3;
    }
    printf("\n");
}

/**
 * @brief Get the Advance Binary2 object
 * 根据输入值获取二进制, 从低位开始, 得到的顺序是反的
 * 01010000000000000000000000000000
 * @param value 
 */
void getAdvanceBinary2(int value)
{
    for (int i = 0; i < 32; i++)
    {
        int res = value & 1;
        printf("%i", res);
        value = value >> 1;
    }
    printf("\n");
}

/**
 * @brief Get the Advance Binary object
 * 根据输入的值获取二进制, 从高位开始
 * @param value 
 */
void getAdvanceBinary1(int value)
{
    /**
    * 
    * 10 => 1010
    * 0000 0000 0000 0000 0000 0000 0000 1010
    * 0000 0000 0000 0000 0000 0000 0000 0001
    * 
    * 原理: 与 & 1 得到原来的数字(& 一假则假) => 1&1=1, 0&1=0
    * 从最高位开始
    * 第一次开始移动: 31 位 & 1 = 0
    * 这样得到的值就是顺序的
    */
    // int 在 64 位编译器中占 32 位
    int offset = 32;
    while (offset > 0)
    {
        // 向右移动 31 位, 取高位第一个值
        int valueOffset = value >> (offset - 1);

        // 与 (&) 1 得到指定位置的值
        int res = valueOffset & 1;
        printf("%i", res);
        offset--;
    }
    printf("\n");
}