#include <stdio.h>
#include <stdlib.h>

int dataType()
{
  // 整型常量
  int num = 10;

  // 开辟存储空间, 相同类型的可以连续定义
  int count, countValue;

  count = 100;

  // 单精度 float
  float floatNum = 5.2f;

  // 双精度 double
  double doubleNum = 8.2;

  printf("%f\n", doubleNum);
  // lf 代表 double
  printf("%lf\n", doubleNum);

  // 字符型
  char charStr = 'a';
  char LineFeed = '\n'; // 当做单个字符处理

  // 有类型转换的操作
  printf("%i\n", charStr);
  printf("%c\n", charStr);

  // 内存寻址: 由大到小˜˜˜˜
  short memoryNum = 10;
  short memoryVal = 10;

  // %p 占位符, &变量名: 返回变量内存地址, 也就是首位字节内存地址
  printf("%p\n", &memoryNum);
  printf("%p\n", &memoryVal);

  // 指定位宽, %mi; 指定输出长度, 不够用空格补上
  printf("%20lf\n", doubleNum);

  floatNum = 3.14;
  // printf(floatNum); 不能直接打印
  printf("%.2f\n", floatNum);

  return 0;
}

/**
 * 自动类型转换
 */
void transformHandle()
{
  // int 4 个字节(byte)
  // double 8个 字节(byte)

  // 这种情况下会丢失精度(隐式转化)
  int number = 10.8;

  // 强制类型转换(显示转换)
  int num = (int)10.8;

  printf("%i\n", number);
  printf("%i\n", num);

  // 运算符过程中: 
  double res1 = 1 / 2;
  printf("%f\n", res1);
  double res = 1 / (double)2;
  printf("%f\n", res);
}

void sizeofHandle() {
  int num1 = sizeof 10;
  printf("%i\n", num1); // 4个字节(B) * 8 位 = 32 bit

  double doubleVal = 19.1;

  int num2 = sizeof doubleVal;
  printf("%i\n", num2); // 8B * 8bit = 64Bit

  int num3 = sizeof(long);
  printf("%i\n", num3); // 8B * 8bit = 64bit

  int a = 10;
  int b = 11;
  int res;
  a = a + 1, b = b + 2, res = a + b;
  printf("%i\n", res);

  int result = 1 == 10 > 5;
  printf("%i\n", result);

  int cmp = arc4random_uniform(3);
  printf("%i\n", cmp);
}

/**
 * 数据类型
 */
int main()
{
  
  // FIXME: 记得调用该函数, 可直接调试
  // dataType();
  // 自动类型转换(隐式转换)
  // transformHandle();

  // 字节大小判断
  sizeofHandle();
  return 0;
}