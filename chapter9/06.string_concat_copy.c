/**
 * 字符串的连接和复制
 * 1. 连接：strcat()
 * 2. 复制：strcpy()
 */
#include <string.h>
#include "io_utils_teacher.h"
int main() {
  char *src = "Hello World";
  char dest[20] = "C said: ";

  //连接，dest 要能被修改
  strcat(dest,src);
  puts(dest);

  //复制, 从 dest + strlen(dest) 位置开始复制
  strcpy(dest + strlen(dest),src);

  puts(dest);
  return 0;
}