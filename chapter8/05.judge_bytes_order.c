/**
 * 判断字节序
 * 计算机内存：01 02 03 04
 * 小端序：0x04030201, 一般用于 CPU数据处理
 * 大端序：0x01020304, 一般用于网络传输
 */


#include "io_utils_teacher.h"

/**
 * 判断是否是大端序
 * @return
 */
int IsBigEndian(){
  union {
    char c[2];
    short s;
  } value = {.s = 0x100};

  return value.c[0] == 1;
}

/**
 * 大小端序转换, 联合体版本
 * @param original
 * @return
 */
int ToggleEndian(int original){

  union {
    char c[4];
    int i;
  } value = {.i = original};

  //swap 0 - 3
  char temp = value.c[3];
  value.c[3] = value.c[0];
  value.c[0] = temp;

  //swap 1 - 2
  temp = value.c[2];
  value.c[2] = value.c[1];
  value.c[1] = temp;

  return value.i;
}

/**
 * 大小端序转换, 指针版本
 * @param original
 * @return
 */
int ToggleEndian2(int original){
  //强制转换成 char 指针
  char *p = (char *)&original;
  int temp = p[0];
  *(p + 0) = p[3];
  *(p + 3) = temp;

  temp = p[1];
  p[1] = p[2];
  p[2] = temp;

  return original;
}

int main() {
  PRINT_INT(IsBigEndian());

  int origin = 0x12345678;
  PRINT_HEX(ToggleEndian(origin));
  PRINT_HEX(ToggleEndian2(origin));
  return 0;
}