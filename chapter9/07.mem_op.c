/**
 * 几个常见的内存操作函数
 * 1. memcpy()
 * 2. memchar()
 * 3. memcmp()
 * 4. memset()
 * 5. memmove()
 */
#include <string.h>
#include <stdlib.h>
#include "io_utils_teacher.h"
int main(){

  char *mem = malloc(10);

  //把 mem 的所有内存上的值设置为 0
  memset(mem,36,10);

  PRINT_CHAR_ARRAY(mem,10);

  //memmove()
  char str[] = "HelloWorld";
  char *dest = malloc(strlen(str));
  //给 dest 赋初始值
  memset(dest,0,strlen(dest));
  memcpy(dest,str,11);
  puts(dest);

  //HelloWorld -> HelleWorld(也就是 Hell + e + lloWorld)
  memmove(dest + 4,dest + 1,1);
  puts(dest);
  free(mem);

  return 0;
}
