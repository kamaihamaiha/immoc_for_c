// 基本数据类型
/**
 * char
 * int
 * short int: int 可省略
 * long int:  int 可省略
 * float
 * double
 */

#include <stdio.h>
#include <limits.h>

void PrintVariableRange(){
  printf("signed char min: %d\n", CHAR_MIN); // 有符号的 char 类型，最小值
  printf("signed char max: %d\n", CHAR_MAX); // 有符号的 char 类型，最大值
  printf("unsigned char max: %d\n", UCHAR_MAX);// 无符号的 char 类型，最大值

  printf("\nshort...\n");
  printf("signed short min: %d\n",SHRT_MIN);
  printf("signed short max: %d\n",SHRT_MAX);
  printf("unsigned short max: %d\n",UCHAR_MAX);

  printf("\nint...\n");
  printf("signed int min: %d\n", INT_MIN);// 有符号的 int 类型，最小值
  printf("signed int max: %d\n", INT_MAX);// 有符号的 int 类型，最大值
  printf("unsigned int max: %d\n", INT_MAX);// 无符号的 int 类型，最大值

  printf("\nlong...\n");
  printf("signed long min: %ld\n", LONG_MIN);// 有符号的 long 类型，最小值
  printf("signed long max: %ld\n", LONG_MAX);// 有符号的 long 类型，最大值
  printf("unsigned long max: %ld\n", ULONG_MAX);// 无符号的 long 类型，最大值

}

int main() {



  // 采用标准头文件，宏定义方式
//  PrintVariableRange();

  // 下面采用直接计算方式




  return 0;
}